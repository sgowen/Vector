//
//  Extension.cpp
//  TestHarness
//
//  Created by Stephen Gowen on 11/2/17.
//  Copyright © 2017 Noctis Games. All rights reserved.
//

#include <vector/Extension.h>

#include <iostream>

void* noctisAlloc(size_t size, const char* file, int line)
{
    printf("noctisAlloc size: %lu, file: %s, line: %d \n", size, file, line);
    
    return malloc(size);
}

void* noctisRealloc(void* ptr, size_t size, const char* file, int line)
{
    printf("noctisRealloc size: %lu, file: %s, line: %d \n", size, file, line);
    
    return realloc(ptr, size);
}

void noctisFree(void* mem)
{
    free(mem);
}
