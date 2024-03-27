//
// Created by maxim on 27.03.2024.
//

#include "Product.h"

Product::Product(std::size_t count, const std::string &name)
        : count(count), name(name) {

}

ProductReceipt::ProductReceipt(std::size_t position, std::size_t count, const std::string &name)
        : position(position), Product(count, name) {

}
