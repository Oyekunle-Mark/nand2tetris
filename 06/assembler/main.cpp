#include <iostream>
#include "code.h"
#include "parser.h"

const std::string convertToBinary(const std::string &);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Expects a file as the only command line argument\n"
                  << "./assembler <input_file_name>\n";
        std::exit(1);
    }

    Parser parser{argv[1]};
    Code code{};

    std::ofstream outputFile{"Prog.hack"};

    if (!outputFile) {
        throw std::runtime_error("Error: cannot open Prog.hack file!");
    }

    while (parser.hasMoreCommands()) {
        parser.advance();
        auto instructionType = parser.commandType();
        std::string output{};

        if (instructionType == types::CommandType::COMMENT)
            continue;
        else if (instructionType == types::CommandType::A_COMMAND)
            output = convertToBinary(parser.symbol());
        else if (instructionType == types::CommandType::C_COMMAND)
            output = code.generateInstruction(parser.comp(), parser.dest(), parser.jump());

        outputFile << output << '\n';
    }

    outputFile.close();

    return 0;
}

const std::string convertToBinary(const std::string &symbol) {
    return std::bitset<16>(std::stoi(symbol)).to_string();
}
