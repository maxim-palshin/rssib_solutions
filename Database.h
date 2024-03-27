//
// Created by maxim on 27.03.2024.
//

#ifndef RSSIB_SOLUTIONS_DATABASE_H
#define RSSIB_SOLUTIONS_DATABASE_H

#include <map>

#include "Product.h"


//! Класс где хранятся наборы
class Database {
public:


    void insert(const Product &product);


    bool containsProductByName(const std::string &name) const;

    Product getProductByName(const std::string &name) const;


private:
    std::map<std::string, Product> _data;
};


#endif //RSSIB_SOLUTIONS_DATABASE_H
