#include <algorithm>
#include <iostream>
#include <iomanip>

#include "config.h"
#include "Database.h"
#include "DocumentAndKitArgument.h"
#include "DocumentAndKitStdInput.h"
#include "KitFileParser.h"
#include "DocumentFileParser.h"


struct ProductOut {
    std::string name;
    std::size_t position = 0;
    std::size_t count = 0;
};

auto product_fold(Database &db, const std::vector<Kit> &documentProducts) {
    std::map<std::string, ProductOut> map;

    for (auto it: documentProducts) {
        if (it.names.empty()) {
            continue;
        }

        for (auto i: it.names) {
            if (!db.containsProductByName(i)) {
                continue;
            }


            auto productCount = db.getProductCountByName(i);

            if ((it.count >= productCount)) {
                if (!map.contains(i)) {
                    auto &item = map[i];
                    item.count = it.count;
                    item.name = i;
                    item.position = it.position;
                } else if (it.count >= map[i].count && it.names.size() == 1) {
                    map[i].position = it.position;
                }
            }else if( map[i].count < productCount){
                auto &item = map[i];
                item.count += it.count;
                item.name = i;
                item.position = it.position;
            }

        }


    }

    for(auto it = map.begin(); it != map.end();){
        if(it->second.count < db.getProductCountByName(it->first)){
            it = map.erase(it);
        }else{
            it++;
        }
    }


    std::vector<ProductOut> result;
    std::transform(map.begin(), map.end(), std::insert_iterator(result, result.end()),
                   [](auto a) { return a.second; });

    std::sort(result.begin(), result.end(), [](auto &a, auto &b) { return a.position < b.position; });


    return result;
}


int main(int argc, char **argv) {

    if constexpr (gWindows) {
        setlocale(LC_ALL, "");
    }

    try {

        Database db;


        //Можно заменить на DocumentAnd DocumentAndKitStdInput, если нужно получить данные через cin.
        DocumentAndKitArgument documentInput(argc, argv);
        auto [kitFile, documentFile] = documentInput.getFileName();


        //        DocumentAndKitStdInput documentInput;
        //        auto [kitFile, documentFile] = documentInput.getFileName();

        KitFileParser kitFileParser(kitFile);
        auto products = kitFileParser.getProduct();
        std::for_each(products.begin(), products.end(), [&db](auto p) { db.insert(p); });


        DocumentFileParser documentFileParser(documentFile);
        auto documentProducts = documentFileParser.getProduct();
        auto kit = product_fold(db, documentProducts);


        if (kit.empty()) {
            std::cout << "Набор не содержится в документе\n";
        } else {
            std::cout << "Набор содержится в документе\nСостав нобора:\nПоз Кол-во Каталог\n";
            for (auto it: kit) {
                std::cout << it.position << std::setw(5) << db.getProductCountByName(it.name) << std::setw(8) << '"'
                          << it.name << '"' << '\n';
            }
        }


    } catch (const std::exception &exp) {
        std::cerr << exp.what() << '\n';
        return EXIT_FAILURE;
    }
}
