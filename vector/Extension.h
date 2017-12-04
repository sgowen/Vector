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

#define NG_EXTENSION (NGExtension::getInstance())

/* All allocation uses these. */
#define MALLOC(TYPE,COUNT) ((TYPE*)NG_EXTENSION->ngAlloc(sizeof(TYPE) * (COUNT), __FILE__, __LINE__))
#define CALLOC(TYPE,COUNT) ((TYPE*)NG_EXTENSION->ngCalloc(COUNT, sizeof(TYPE), __FILE__, __LINE__))
#define NEW(TYPE) CALLOC(TYPE,1)
#define REALLOC(PTR,TYPE,COUNT) ((TYPE*)NG_EXTENSION->ngRealloc(PTR, sizeof(TYPE) * (COUNT), __FILE__, __LINE__))

/* Frees memory. Can be used on const types. */
#define FREE(VALUE) NG_EXTENSION->ngFree((void*)VALUE)

/* Call destructor and then frees memory. Can be used on const types. */
#define DESTROY(TYPE,VALUE) VALUE->~TYPE(); NG_EXTENSION->ngFree((void*)VALUE)

namespace NoctisGames
{
    class NGExtension
    {
    public:
        static void setInstance(NGExtension* inNGExtension);
        
        static NGExtension* getInstance();
        
        NGExtension();
        
        virtual ~NGExtension();
        
        /// Implement this function to use your own memory allocator
        virtual void* ngAlloc(size_t size, const char* file, int line) = 0;
        
        virtual void* ngCalloc(size_t num, size_t size, const char* file, int line) = 0;
        
        virtual void* ngRealloc(void* ptr, size_t size, const char* file, int line) = 0;
        
        /// If you provide a ngAllocFunc, you should also provide a ngFreeFunc
        virtual void ngFree(void* mem) = 0;
        
    private:
        static NGExtension* _instance;
    };
    
    class DefaultNGExtension : public NGExtension
    {
    public:
        static DefaultNGExtension* getInstance();
        
        DefaultNGExtension();
        
        virtual ~DefaultNGExtension();
        
        virtual void* ngAlloc(size_t size, const char* file, int line);
        
        virtual void* ngCalloc(size_t num, size_t size, const char* file, int line);
        
        virtual void* ngRealloc(void* ptr, size_t size, const char* file, int line);
        
        virtual void ngFree(void* mem);
    };
}

#endif /* NoctisGames_Extension_h */
