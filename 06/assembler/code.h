//
// Created by Oyekunle Oloyede on 21/09/2020.
//

#ifndef ASSEMBLER_CODE_H
#define ASSEMBLER_CODE_H

#include <string>
#include <memory>
#include "types.h"

class Code {
public:
    Code();

    Code(const Code &) = delete;

    Code &operator=(const Code &) = delete;

    const std::string dest(const std::string &) const;

    const std::string comp(const std::string &) const;

    const std::string jump(const std::string &) const;

    const std::string
    generateInstruction(const std::string &compV, const std::string &destV, const std::string &jumpV) const;

private:
    static const std::string prefix;
    const std::unique_ptr<types::DestTable> destTable;
    const std::unique_ptr<types::CompTable> compTable;
    const std::unique_ptr<types::JumpTable> jumpTable;
};

#endif //ASSEMBLER_CODE_H
