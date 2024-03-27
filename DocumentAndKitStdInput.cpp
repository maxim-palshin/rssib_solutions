//
// Created by maxim on 27.03.2024.
//

#include "DocumentAndKitStdInput.h"
#include <iostream>
#include <filesystem>


DocumentAndKitStdInput::~DocumentAndKitStdInput() {}

DocmumentAndKitFile DocumentAndKitStdInput::getFileName() {
    std::string documentFile, kitFile;

    std::cout << "Введите путь до документа: ";
    std::cin >> documentFile;
    std::cout << "\nВведите путь до базы";
    std::cin >> kitFile;
    std::cout << '\n';

    if (!std::filesystem::exists(documentFile)) {
        throw std::runtime_error("Файл документа не существует");
    }

    if (!std::filesystem::exists(kitFile)) {
        throw std::runtime_error("Файл базы не существует");
    }

    return {kitFile, documentFile};
}
