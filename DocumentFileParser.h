//
// Created by maxim on 27.03.2024.
//

#ifndef RSSIB_SOLUTIONS_DOCUMENTFILEPARSER_H
#define RSSIB_SOLUTIONS_DOCUMENTFILEPARSER_H

#include <vector>
#include <fstream>

#include "Product.h"


struct Kit {
    std::size_t position = 0;
    std::size_t count = 0;
    std::vector<std::string> names;

};

class DocumentFileParser {
public:


    DocumentFileParser(const std::string &file);


    std::vector<Kit> getProduct(bool skipFirstLine = true);


private:
    std::ifstream _file;

    struct _Line {
        std::size_t position;
        std::vector<std::string> names;
        std::size_t count;

    };


    std::vector<std::string> _parserNames(std::string line);

    std::pair<std::size_t, std::size_t> _parserPositionAndCount(std::string line);


    _Line _parserLine(std::string line);


};


#endif //RSSIB_SOLUTIONS_DOCUMENTFILEPARSER_H
