//
// Created by Oyekunle Oloyede on 21/09/2020.
//

#include <stdexcept>
#include <cctype>
#include "parser.h"

std::string stripLine(const std::string &);

Parser::Parser(const std::string &fileName)
        : fileStream{fileName} {
    if (!fileStream) {
        throw std::runtime_error("Cannot open file!");
    }
}

bool Parser::hasMoreCommands() {
    return fileStream.peek() != EOF;
}

void Parser::advance() {
    std::getline(fileStream, currentCommand);
}

types::CommandType Parser::commandType() {
    const std::string::size_type commentSignIndex{currentCommand.find("//")};

    if (commentSignIndex != std::string::npos)
        currentCommand = currentCommand.substr(0, commentSignIndex);

    currentCommand = stripLine(currentCommand);

    if (currentCommand.empty())
        return types::CommandType::COMMENT;
    else if (currentCommand.starts_with("@"))
        return types::CommandType::A_COMMAND;
    else if (currentCommand.starts_with("("))
        return types::CommandType::L_COMMAND;
    else
        return types::CommandType::C_COMMAND;
}

const std::string Parser::symbol() const {
    if (currentCommand.starts_with("@"))
        return currentCommand.substr(1);

    return currentCommand.substr(1, currentCommand.find(')') - 1);
}

const std::string Parser::dest() const {
    const std::string::size_type equalSignIndex = currentCommand.find('=');

    if (equalSignIndex == std::string::npos)
        return std::string{"null"};

    return currentCommand.substr(0, equalSignIndex - 1);
}

std::string stripLine(const std::string &line) {
    std::string result{};

    for (auto const &c: line) {
        if (!std::isspace(c))
            result += c;
    }

    return result;
}
