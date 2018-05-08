//
//  MemoryManager.hpp
//  fvm
//
//  Created by Fantom Foundation
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//

#ifndef MemoryManager_hpp
#define MemoryManager_hpp

#include <vector>
#include "InternalTypes.hpp"

class MemoryManager
{
private:
    std::vector<MULTI64> _Memory;
public:
    MemoryManager();
    ~MemoryManager();
    MULTI64& GetItem(int idx);
    void SetItem(int idx, MULTI64& val);
    void CollectGarbage();
};


#endif /* MemoryManager_hpp */
