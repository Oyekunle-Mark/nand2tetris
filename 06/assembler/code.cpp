//
// Created by Oyekunle Oloyede on 21/09/2020.
//

#include "code.h"

Code::Code()
        : destTable{std::make_unique<types::DestTable>()},
          compTable{std::make_unique<types::CompTable>()},
          jumpTable{std::make_unique<types::JumpTable>()} {}

const std::string Code::prefix = "111";

const std::string Code::dest(const std::string &key) const {
    return destTable->table.at(key);
}

const std::string Code::comp(const std::string &key) const {
    return compTable->table.at(key);
}

const std::string Code::jump(const std::string &key) const {
    return jumpTable->table.at(key);
}

const std::string
Code::generateInstruction(const std::string &compV, const std::string &destV, const std::string &jumpV) const {
    return prefix + comp(compV) + dest(destV) + jump(jumpV);
}
