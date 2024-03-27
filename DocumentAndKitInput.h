//
// Created by maxim on 27.03.2024.
//

#ifndef RSSIB_SOLUTIONS_DOCUMENTANDKITINPUT_H
#define RSSIB_SOLUTIONS_DOCUMENTANDKITINPUT_H

#include <string>

struct DocmumentAndKitFile {
    std::string kitFile;
    std::string docmumentFile;
};

class DocumentAndKitInput {
public:

    virtual ~DocumentAndKitInput() {}

    virtual DocmumentAndKitFile getFileName() = 0;


private:

};


#endif //RSSIB_SOLUTIONS_DOCUMENTANDKITINPUT_H
