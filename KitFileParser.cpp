//
// Created by maxim on 27.03.2024.
//

#include "KitFileParser.h"
#include <iostream>


KitFileParser::KitFileParser(const std::string &file) {
    _file.open(file);
    std::noskipws(_file);
}

std::vector<Product> KitFileParser::getProduct(bool skipFirstLine) {
    std::vector<Product> products;

    std::string line;

    if (skipFirstLine) {
        std::getline(_file, line);
    }

    while (std::getline(_file, line))
        try {
            if(line.empty()){
                continue;
            }

            auto [name, count] = _parserLine(line);

            products.push_back({count, name});
        } catch (const std::exception &exp) {
            std::cerr << "Ошибка при обработке строки:" << exp.what() << '\n';
        }


    return products;
}

std::pair<std::string, std::size_t> KitFileParser::_parserLine(const std::string &line) {
    std::size_t lastCharacterNameIndex = line.find_last_of("\"");
    std::string name = line.substr(1, lastCharacterNameIndex - 1);
    std::size_t count = std::stoull(line.substr(lastCharacterNameIndex + 1));
    return {name, count};
}
