#include <iostream>
#include "code.h"

int main() {
    Code c{};

    std::cout << c.dest("null") + c.comp("M") << std::endl;
    return 0;
}
