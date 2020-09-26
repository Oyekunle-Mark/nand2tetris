//
// Created by Oyekunle Oloyede on 21/09/2020.
//

#ifndef ASSEMBLER_PARSER_H
#define ASSEMBLER_PARSER_H

#include <string>
#include <fstream>
#include "types.h"

class Parser {
public:
    Parser(const std::string &fileName);

    Parser(const Parser &) = delete;

    Parser &operator=(const Parser &) = delete;

    bool hasMoreCommands();

    void advance();

    types::CommandType commandType();

    const std::string symbol() const;

    const std::string dest() const;

    const std::string comp() const;

    const std::string jump() const;

    bool isLegitCommand();

private:
    std::ifstream fileStream;
    std::string currentCommand{};
};

#endif //ASSEMBLER_PARSER_H
