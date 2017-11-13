//
//  VectorUtil.h
//  Vector
//
//  Created by Stephen Gowen on 11/2/17.
//  Copyright © 2017 Noctis Games. All rights reserved.
//

#ifndef NoctisGames_VectorUtil_h
#define NoctisGames_VectorUtil_h

#include <vector/Vector.h>

namespace NoctisGames
{
    class VectorUtil
    {
    public:        
        template<typename T>
        static void cleanUpVectorOfPointers(Vector<T*>& items)
        {
            for (size_t i = 0; i < items.size(); )
            {
                T* item = items[i];
                delete item;
                
                items.erase(i);
            }
        }
        
    private:
        // ctor, copy ctor, and assignment should be private in a Singleton
        VectorUtil();
        VectorUtil(const VectorUtil&);
        VectorUtil& operator=(const VectorUtil&);
    };
}

#endif /* NoctisGames_VectorUtil_h */
