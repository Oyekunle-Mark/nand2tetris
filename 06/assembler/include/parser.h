//
// Created by Oyekunle Oloyede on 21/09/2020.
//

#ifndef ASSEMBLER_PARSER_H
#define ASSEMBLER_PARSER_H

#include <string>
#include <fstream>

enum class Commandtype {
    A_COMMAND,
    C_COMMAND,
    L_COMMAND
};

class Parser {
public:
    Parser(const std::string &fileName);

    Parser(const Parser &) = delete;

    Parser &operator=(const Parser &) = delete;

    bool hasMoreCommands() const;

    void advance();

    Commandtype commandType() const;

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
