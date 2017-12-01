//
//  main.cpp
//  Vector
//
//  Created by Stephen Gowen on 11/2/17.
//  Copyright © 2017 Noctis Games. All rights reserved.
//

#include <vector/VectorTest.h>
#include <vector/Extension.h>

int main(int argc, const char * argv[])
{
    using namespace NoctisGames;
    
    NGAllocator::setInstance(DefaultNGAllocator::getInstance());
    
    VectorTest::test();
}
