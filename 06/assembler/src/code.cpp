//
// Created by Oyekunle Oloyede on 21/09/2020.
//

#include "code.h"

Code::Code()
        : destTable{std::make_unique<types::DestTable>()},
          compTable{std::make_unique<types::CompTable>()},
          jumpTable{std::make_unique<types::JumpTable>()} {}
