//
// Created by maxim on 27.03.2024.
//

#include "Database.h"
#include <stdexcept>

void Database::insert(const Product &product) {

    _data.insert({product.name, product});
}

bool Database::containsProductByName(const std::string &name) const {
    return _data.contains(name);
}

Product Database::getProductByName(const std::string &name) const {
    return _data.at(name);
}
