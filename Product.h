//
// Created by maxim on 27.03.2024.
//

#ifndef RSSIB_SOLUTIONS_PRODUCT_H
#define RSSIB_SOLUTIONS_PRODUCT_H

#include <string>


struct Product {

    std::size_t count;
    std::string name;

    Product(std::size_t count = 0, const std::string &name = "");


};

struct ProductReceipt : public Product {
    std::size_t position;

    ProductReceipt(std::size_t position = 0, std::size_t count = 0, const std::string &name = "");

};


#endif //RSSIB_SOLUTIONS_PRODUCT_H
