#include <algorithm>
#include <iostream>
#include <iomanip>

#include "config.h"
#include "Database.h"
#include "DocumentAndKitArgument.h"
#include "DocumentAndKitStdInput.h"
#include "KitFileParser.h"
#include "DocumentFileParser.h"


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


        std::cout << "Набор содержится в документе\nСостав нобора:\nПоз Кол-во Каталог\n";

        for (auto it: documentProducts) {
            if (db.containsProductByName(it.name) && (it.count >= db.getProductByName(it.name).count)) {
                std::cout << it.position << std::setw(5) << it.count << std::setw(8) << it.name << '\n';
            }
        }


    } catch (const std::exception &exp) {
        std::cerr << exp.what() << '\n';
        return EXIT_FAILURE;
    }
}
