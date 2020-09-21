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

private:
    std::unique_ptr<std::map<std::string, std::string>> destTable{};
    std::unique_ptr<std::map<std::string, std::string>> compTable{};
    std::unique_ptr<std::map<std::string, std::string>> jumpTable{};
};

#endif //ASSEMBLER_CODE_H
