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

bool Parser::hasMoreCommands() {
    return fileStream.peek() != EOF;
}

void Parser::advance() {
    std::getline(fileStream, currentCommand);
}

types::CommandType Parser::commandType() const {
    const std::string::size_type commentSignIndex{currentCommand.find("//")};
    std::string strippedCommand{};

    if (commentSignIndex != std::string::npos)
        strippedCommand = currentCommand.substr(0, commentSignIndex);
    else
        strippedCommand = currentCommand;

    if (strippedCommand.empty())
        return types::CommandType::COMMENT;
    else if (strippedCommand.starts_with("@"))
        return types::CommandType::A_COMMAND;
    else if (strippedCommand.starts_with("("))
        return types::CommandType::L_COMMAND;
    else
        return types::CommandType::C_COMMAND;
}
