//
//  SystemInterface.hpp
//  fvm
//
//  Created by Fantom Foundation
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//

#ifndef SystemInterface_hpp
#define SystemInterface_hpp

#include <stdio.h>
#include "InternalTypes.hpp"
#include "FvmObject.hpp"

class SystemInterface: FvmObject
{
private:
public:
    SystemInterface() {};
    
    void GetRecipientAddress();
    void GetSenderAddress();
    void GetGasMappingTable();
    void GetBalance();
    void Transfter();

    void GetInjectionPoints();
    
protected:
};


#endif /* SystemInterface_hpp */
