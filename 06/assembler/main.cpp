#include <iostream>
#include "code.h"
#include "parser.h"
#include "symbolTable.h"

const std::string convertToBinary(const std::string &);

void buildLabels(const char *, SymbolTable &);

bool isNumeric(const std::string &);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Expects a file as the only command line argument\n"
                  << "./assembler <input_file_name>\n";
        std::exit(1);
    }

    Parser parser{argv[1]};
    Code code{};
    SymbolTable sTable{};

    buildLabels(argv[1], sTable);

    std::ofstream outputFile{"Prog.hack"};

    if (!outputFile) {
        throw std::runtime_error("Error: cannot open Prog.hack file!");
    }

    std::size_t ramVariableAddress{16};

    while (parser.hasMoreCommands()) {
        parser.advance();
        auto instructionType = parser.commandType();
        std::string output{};

        if (instructionType == types::CommandType::COMMENT || instructionType == types::CommandType::L_COMMAND)
            continue;
        else if (instructionType == types::CommandType::A_COMMAND) {
            const auto currentSymbol{parser.symbol()};

            if (isNumeric(currentSymbol))
                output = convertToBinary(parser.symbol());
            else {
                std::size_t address{};

                if (sTable.contains(currentSymbol))
                    address = sTable.getAddress(currentSymbol);
                else {
                    sTable.addEntry(currentSymbol, ramVariableAddress);
                    address = ramVariableAddress;
                    ++ramVariableAddress;
                }

                output = convertToBinary(std::to_string(address));
            }
        } else if (instructionType == types::CommandType::C_COMMAND)
            output = code.generateInstruction(parser.comp(), parser.dest(), parser.jump());

        outputFile << output << '\n';
    }

    outputFile.close();

    return 0;
}

const std::string convertToBinary(const std::string &symbol) {
    return std::bitset<16>(std::stoi(symbol)).to_string();
}

void buildLabels(const char *fileName, SymbolTable &sTable) {
    Parser parser{fileName};
    std::size_t position{};

    while (parser.hasMoreCommands()) {
        parser.advance();
        auto instructionType = parser.commandType();

        if (instructionType == types::CommandType::C_COMMAND || instructionType == types::CommandType::A_COMMAND)
            ++position;
        else if (instructionType == types::CommandType::L_COMMAND)
            sTable.addEntry(parser.symbol(), position);
    }
}

bool isNumeric(const std::string &symbol) {
    return !symbol.empty() &&
           std::find_if(symbol.begin(), symbol.end(), [](unsigned char c) { return !std::isdigit(c); }) == symbol.end();
}
