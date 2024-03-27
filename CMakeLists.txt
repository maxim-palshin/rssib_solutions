cmake_minimum_required(VERSION 3.25)
project(rssib_solutions)

set(CMAKE_CXX_STANDARD 20)

add_executable(rssib_solutions main.cpp config.h
        DocumentAndKitInput.h
        DocumentAndKitStdInput.cpp DocumentAndKitStdInput.h
        Product.cpp Product.h
        Database.cpp Database.h
        KitFileParser.cpp KitFileParser.h
        DocumentFileParser.cpp DocumentFileParser.h
        DocumentAndKitArgument.cpp DocumentAndKitArgument.h DocumentFileParser.cpp)
