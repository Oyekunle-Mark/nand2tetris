//
// Created by Oyekunle Oloyede on 27/09/2020.
//

#include "symbolTable.h"

SymbolTable::SymbolTable()
        : symTable{std::make_unique<types::SymTable>()} {}

void SymbolTable::addEntry(const std::string &symbol, const std::size_t address) {
    symTable->table.insert(std::pair<std::string, std::size_t>(symbol, address));
}

bool SymbolTable::contains(const std::string &symbol) const {
    return symTable->table.count(symbol);
}

std::size_t SymbolTable::getAddress(const std::string &symbol) const {
    return symTable->table.at(symbol);
}
