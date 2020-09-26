#include <iostream>
#include "code.h"
#include "parser.h"

int main(int argc, char *argv[]) {
//    if (argc != 2) {
//        std::cout << "Expects a file as the only command line argument\n"
//                  << "./assembler <input_file_name>\n";
//        std::exit(1);
//    }
//
//    Parser testParser{argv[1]};

    std::string command{"Helpj=jbj//o world"};
    std::cout << command.find("//");
    command = command.substr(0,command.find("//"));
    std::cout << command.substr(1, command.find('=') - 1) << command.find('p');

    return 0;
}
