//
//  MemoryManager.cpp
//  fvm
//
//  Created by Fantom Foundation
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//

#include "MemoryManager.hpp"


MemoryManager::MemoryManager() { 
    _Memory.resize(1024);
}

MemoryManager::~MemoryManager() { 
    
}

MULTI64 &MemoryManager::GetItem(int idx) { 
    return _Memory.at(idx);
}

void MemoryManager::SetItem(int idx, MULTI64 &val) {
    _Memory.at(idx) = val;
}

void MemoryManager::CollectGarbage() { 
    // Will be implemented
}

