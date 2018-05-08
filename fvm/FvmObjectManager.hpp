//
//  FvmObjectManager.hpp
//  fvmcmd
//
//  Created by Fantom Foundation
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//

#ifndef FvmObjectManager_hpp
#define FvmObjectManager_hpp

#include <stdio.h>
#include "FvmObject.hpp"

class FvmObjectManager
{
private:

public:
    std::vector<std::unique_ptr<FvmObject>> objectVector;

    template <typename T>
    void registerFvmObject();
};


#endif /* FvmObjectManager_hpp */
