//
// Created by Oyekunle Oloyede on 27/09/2020.
//

#ifndef ASSEMBLER_SYMBOLTABLE_H
#define ASSEMBLER_SYMBOLTABLE_H

#include <memory>
#include "types.h"

class SymbolTable {
public:
    SymbolTable();

    void addEntry(const std::string &symbol, const std::size_t address);

    bool contains(const std::string &symbol) const;

    std::size_t getAddress(const std::string &symbol) const;

private:
    const std::unique_ptr<types::SymTable> symTable;
};


#endif //ASSEMBLER_SYMBOLTABLE_H
