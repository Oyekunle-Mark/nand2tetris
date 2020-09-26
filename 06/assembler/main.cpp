#include <iostream>
#include "code.h"
#include "parser.h"

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
            output += "0" + std::bitset<15>(std::stoi(parser.symbol())).to_string();
        else if (instructionType == types::CommandType::C_COMMAND)
            output = code.generateInstruction(parser.comp(), parser.dest(), parser.jump());

        outputFile << output << '\n';
    }

    outputFile.close();

    return 0;
}
