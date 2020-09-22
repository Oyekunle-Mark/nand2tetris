#include <iostream>
#include "code.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Expects a file as the only command line argument";
        std::exit(1);
    }

    return 0;
}
