//
// Created by Oyekunle Oloyede on 21/09/2020.
//

#include "code.h"
#include <iostream>

Code::Code()
        : destTable{std::make_unique<types::DestTable>()},
          compTable{std::make_unique<types::CompTable>()},
          jumpTable{std::make_unique<types::JumpTable>()} {}

const std::string Code::prefix = "111";

const std::string Code::dest(const std::string &key) const {
    std::cout << "*** dest: " << key << '\n';
    return destTable->table.at(key);
}

const std::string Code::comp(const std::string &key) const {
    std::cout << "*** comp: " << key << '\n';
    return compTable->table.at(key);
}

const std::string Code::jump(const std::string &key) const {
    std::cout << "*** jump: " << key << '\n';
    return jumpTable->table.at(key);
}

const std::string
Code::generateInstruction(const std::string &compV, const std::string &destV, const std::string &jumpV) const {
    return prefix + comp(compV) + dest(destV) + jump(jumpV);
}
