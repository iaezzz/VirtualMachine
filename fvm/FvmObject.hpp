//
//  SystemInterface.hpp
//  fvm
//
//  Created by Fantom Foundation
//  Copyright © 2018 Fantom Foundation. All rights reserved.
//

#ifndef FvmObject_hpp
#define FvmObject_hpp

#include <stdio.h>
#include <vector>
#include <string>

#include "InternalTypes.hpp"


union MULTI64;

class FvmClass
{
private:
    std::vector<MULTI64> staticMethodVector;
    
public:
    FvmClass();
};

class FvmMethod
{
public:
    enum class MethodType
    {
        FvmMethod,
        NativeMethod
    };
};

class FvmObject
{
    int _refCount = 0;
protected:
    std::vector<MULTI64> methodVector;
    std::string objectName="fvmobject";

public:
    std::string getObjectName();
     
    FvmObject() {};
    void AddReference(){};
    void RemoveReference(){};
};


class FvmStringClass: FvmObject
{
private:
    std::string _string;
public:
    FvmStringClass()
    {
        objectName="string";
    }
    
    void setString(std::string& in)
    {
        _string = in;
    }
    
    // Standard FVM Call Structure
    void fvmGetString(std::vector<MULTI64> m, MULTI64& ret)
    {
    }

    void fvmSetString(std::vector<MULTI64> m, MULTI64& ret) // Standard FVM Call Structure
    {
    }

protected:
};



#endif /* FvmObject_hpp */
