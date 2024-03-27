//
// Created by maxim on 27.03.2024.
//

#include "DocumentFileParser.h"

#include <regex>
#include <iostream>


DocumentFileParser::DocumentFileParser(const std::string &file) {
    _file.open(file);
    std::noskipws(_file);
}

std::vector<ProductReceipt> DocumentFileParser::getProduct(bool skipFirstLine) {
    std::vector<ProductReceipt> products;

    std::string line;

    if (skipFirstLine) {
        std::getline(_file, line);
    }

    while (std::getline(_file, line))
        try {
            if(line.empty()){
                continue;
            }

            auto r = _parserLine(line);

            for (auto name: r.names) {
                products.push_back({r.position, r.count, name});
            }


        } catch (const std::exception &exp) {
            std::cerr << "Ошибка при обработке строки:" << exp.what() << '\n';
        }


    return products;
}

std::vector<std::string> DocumentFileParser::_parserNames(std::string line) {
    std::vector<std::string> names;

    std::regex r("\"\\w+\",?", std::regex_constants::ECMAScript);
    std::smatch m;

    std::string::const_iterator startIt = line.begin();

    while (std::regex_search(startIt, line.cend(), m, r)) {
        for (auto it: m) {
            startIt = m.suffix().first;

            auto name = m.str();

            name = name.substr(1, name.size() - 2);

            if (name.ends_with("\"")) {
                name.pop_back();
            }


            names.push_back(name);
        }


    }

    return names;
}


DocumentFileParser::_Line DocumentFileParser::_parserLine(std::string line) {

    std::size_t lastIndex = 0;

    auto [position, count] = _parserPositionAndCount(line, lastIndex);

    if (lastIndex == line.npos) {
        return {};
    }

    line = line.substr(lastIndex);

    auto names = _parserNames(line);

    _Line result;

    result.names = names;
    result.position = position;
    result.count = count;


    return result;
}

std::pair<std::size_t, std::size_t> DocumentFileParser::_parserPositionAndCount(std::string line, std::size_t &i) {

    std::size_t lastIndex = line.find_first_of(" ");
    auto position = std::stoull(line.substr(0, lastIndex));
    line = line.substr(lastIndex + 1);
    lastIndex = line.find_first_of(" ");

    auto count = std::stoull(line.substr(0, lastIndex));

    i = lastIndex;

    return {position, count};
}
