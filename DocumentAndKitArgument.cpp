//
// Created by maxim on 27.03.2024.
//

#include "DocumentAndKitArgument.h"

DocumentAndKitArgument::DocumentAndKitArgument(int size, char **argv) : _argv(argv), _size(size) {

}

DocmumentAndKitFile DocumentAndKitArgument::getFileName() {
    if (_size < 3) {
        throw std::runtime_error("size < 3");
    }

    return {_argv[1], _argv[2]};
}
