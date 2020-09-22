//
// Created by Oyekunle Oloyede on 21/09/2020.
//

#include <stdexcept>
#include "parser.h"

Parser::Parser(const std::string &fileName)
        : fileStream{fileName} {
    if (!fileStream) {
        throw std::runtime_error("Cannot open file!");
    }
}
