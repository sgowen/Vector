//
//  main.cpp
//  Vector
//
//  Created by Stephen Gowen on 11/2/17.
//  Copyright © 2017 Noctis Games. All rights reserved.
//

#include <container/VectorTest.h>

int main(int argc, const char * argv[])
{
    using namespace NoctisGames;
    
    VectorTest::onBegin();
    VectorTest::testVectorInt();
    VectorTest::testVectorString();
    VectorTest::testVectorCustom();
    VectorTest::onEnd();
}
