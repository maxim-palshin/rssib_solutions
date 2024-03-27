//
// Created by maxim on 27.03.2024.
//

#ifndef RSSIB_SOLUTIONS_KITFILEPARSER_H
#define RSSIB_SOLUTIONS_KITFILEPARSER_H

#include <vector>
#include <fstream>

#include "Product.h"

class KitFileParser {
public:


    KitFileParser(const std::string &file);


    std::vector<Product> getProduct(bool skipFirstLine = true);


private:
    std::ifstream _file;

    std::pair<std::string, std::size_t> _parserLine(const std::string &line);

};


#endif //RSSIB_SOLUTIONS_KITFILEPARSER_H
