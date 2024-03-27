//
// Created by maxim on 27.03.2024.
//

#ifndef RSSIB_SOLUTIONS_DOCMUMENTANDKITSTDINPUT_H
#define RSSIB_SOLUTIONS_DOCMUMENTANDKITSTDINPUT_H

#include "DocumentAndKitInput.h"

class DocumentAndKitStdInput final : public DocumentAndKitInput {
public:

    virtual ~DocumentAndKitStdInput();


    virtual DocmumentAndKitFile getFileName() override;


private:
};


#endif //RSSIB_SOLUTIONS_DOCMUMENTANDKITSTDINPUT_H
