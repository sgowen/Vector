//
//  Extension.h
//  Vector
//
//  Created by Stephen Gowen on 11/2/17.
//  Copyright © 2017 Noctis Games. All rights reserved.
//

#ifndef NoctisGames_Extension_h
#define NoctisGames_Extension_h

/* All allocation uses these. */
#define MALLOC(TYPE,COUNT) ((TYPE*)noctisAlloc(sizeof(TYPE) * (COUNT), __FILE__, __LINE__))
#define REALLOC(PTR,TYPE,COUNT) ((TYPE*)noctisRealloc(PTR, sizeof(TYPE) * (COUNT), __FILE__, __LINE__))

/* Frees memory. Can be used on const types. */
#define FREE(VALUE) noctisFree((void*)VALUE)

/* Call destructor and then frees memory. Can be used on const types. */
#define DESTROY(TYPE,VALUE) VALUE->~TYPE(); noctisFree((void*)VALUE)

#include <stdlib.h>

/// Implement this function to use your own memory allocator.
void* noctisAlloc(size_t size, const char* file, int line);

void* noctisRealloc(void* ptr, size_t size, const char* file, int line);

/// If you implement noctisAlloc, you should also implement this function.
void noctisFree(void* mem);

#endif /* NoctisGames_Extension_h */
