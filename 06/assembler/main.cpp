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

    while(parser.hasMoreCommands()) {
        parser.advance();
        auto instructionType = parser.commandType();
        std::string output{};

        if (instructionType == types::CommandType::COMMENT)
            continue;
        else if (instructionType == types::CommandType::C_COMMAND) {
//            output =
        }
    }

    return 0;
}
