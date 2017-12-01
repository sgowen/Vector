//
//  Extension.h
//  Vector
//
//  Created by Stephen Gowen on 11/2/17.
//  Copyright © 2017 Noctis Games. All rights reserved.
//

#ifndef NoctisGames_Extension_h
#define NoctisGames_Extension_h

#include <stdlib.h>

#define NG_ALLOCATOR (NGAllocator::getInstance())

/* All allocation uses these. */
#define MALLOC(TYPE,COUNT) ((TYPE*)NG_ALLOCATOR->ngAlloc(sizeof(TYPE) * (COUNT), __FILE__, __LINE__))
#define NEW(TYPE) ((TYPE*)NG_ALLOCATOR->ngAlloc(sizeof(TYPE), __FILE__, __LINE__))
#define REALLOC(PTR,TYPE,COUNT) ((TYPE*)NG_ALLOCATOR->ngRealloc(PTR, sizeof(TYPE) * (COUNT), __FILE__, __LINE__))

/* Frees memory. Can be used on const types. */
#define FREE(VALUE) NG_ALLOCATOR->ngFree((void*)VALUE)

/* Call destructor and then frees memory. Can be used on const types. */
#define DESTROY(TYPE,VALUE) VALUE->~TYPE(); NG_ALLOCATOR->ngFree((void*)VALUE)

namespace NoctisGames
{
    class NGAllocator
    {
    public:
        static void setInstance(NGAllocator* inNGAllocator);
        
        static NGAllocator* getInstance();
        
        NGAllocator();
        
        virtual ~NGAllocator();
        
        /// Implement this function to use your own memory allocator
        virtual void* ngAlloc(size_t size, const char* file, int line) = 0;
        
        virtual void* ngRealloc(void* ptr, size_t size, const char* file, int line) = 0;
        
        /// If you provide a ngAllocFunc, you should also provide a ngFreeFunc
        virtual void ngFree(void* mem) = 0;
        
    private:
        static NGAllocator* _ngAllocator;
    };
    
    class DefaultNGAllocator : public NGAllocator
    {
    public:
        static DefaultNGAllocator* getInstance();
        
        DefaultNGAllocator();
        
        virtual ~DefaultNGAllocator();
        
        virtual void* ngAlloc(size_t size, const char* file, int line);
        
        virtual void* ngRealloc(void* ptr, size_t size, const char* file, int line);
        
        virtual void ngFree(void* mem);
    };
}

#endif /* NoctisGames_Extension_h */
