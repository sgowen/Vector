//
//  Extension.cpp
//  TestHarness
//
//  Created by Stephen Gowen on 11/2/17.
//  Copyright © 2017 Noctis Games. All rights reserved.
//

#include <vector/Extension.h>

#include <iostream>
#include <assert.h>

namespace NoctisGames
{
    NGAllocator* NGAllocator::_ngAllocator = NULL;
    
    void NGAllocator::setInstance(NGAllocator* inValue)
    {
        assert(!_ngAllocator);
        
        _ngAllocator = inValue;
    }
    
    NGAllocator* NGAllocator::getInstance()
    {
        assert(_ngAllocator);
        
        return _ngAllocator;
    }
    
    NGAllocator::NGAllocator()
    {
        // Empty
    }
    
    NGAllocator::~NGAllocator()
    {
        // Empty
    }
    
    DefaultNGAllocator* DefaultNGAllocator::getInstance()
    {
        static DefaultNGAllocator ret;
        return &ret;
    }
    
    DefaultNGAllocator::DefaultNGAllocator() : NGAllocator()
    {
        // Empty
    }
    
    DefaultNGAllocator::~DefaultNGAllocator()
    {
        // Empty
    }
    
    void* DefaultNGAllocator::ngAlloc(size_t size, const char* file, int line)
    {
        printf("ng size: %lu, file: %s, line: %d \n", size, file, line);
        
        return malloc(size);
    }
    
    void* DefaultNGAllocator::ngRealloc(void* ptr, size_t size, const char* file, int line)
    {
        printf("ng size: %lu, file: %s, line: %d \n", size, file, line);
        
        return realloc(ptr, size);
    }
    
    void DefaultNGAllocator::ngFree(void* mem)
    {
        free(mem);
    }
}
