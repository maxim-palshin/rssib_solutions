//
// Created by maxim on 27.03.2024.
//

#ifndef RSSIB_SOLUTIONS_DOCMUMENTANDKITARGUMENT_H
#define RSSIB_SOLUTIONS_DOCMUMENTANDKITARGUMENT_H

#include "DocumentAndKitInput.h"
#include <stdexcept>

/*!
\brief Класс для получения имен файлов через аргумент командной строки.
 Первым файлом должен быть kit втормы docmument


 argv[1] == kit
 argv[2] == docmument
*/
class DocumentAndKitArgument final : public DocumentAndKitInput {
public:


    DocumentAndKitArgument(int size, char **argv);

    virtual ~DocumentAndKitArgument() {}


    virtual DocmumentAndKitFile getFileName() override;


private:
    int _size;
    char **_argv;
};


#endif //RSSIB_SOLUTIONS_DOCMUMENTANDKITARGUMENT_H
