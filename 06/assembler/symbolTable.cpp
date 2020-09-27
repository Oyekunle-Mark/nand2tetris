//
// Created by Oyekunle Oloyede on 27/09/2020.
//

#include "symbolTable.h"

SymbolTable::SymbolTable()
        : symTable{std::make_unique<types::SymTable>()} {}

void SymbolTable::addEntry(const std::string &symbol, const std::string &address) {
    symTable->table.insert(std::pair<std::string, std::string>(symbol, address));
}

bool SymbolTable::contains(const std::string &symbol) const {
    return symTable->table.count(symbol);
}

std::string SymbolTable::getAddress(const std::string &symbol) const {
    return symTable->table.at(symbol);
}
