//
//  main_creature.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 04/12/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <stdio.h>
#include "Landscape.h"
#include "gtest/gtest.h"
using namespace laba4;
TEST(Creature_Constructor, defaultConstructor)
{
    Creature I;
    ASSERT_EQ(I.get_name(), "");
    ASSERT_EQ(I.get_damage(), 0);
    ASSERT_EQ(I.get_protection(), 0);
    ASSERT_EQ(I.get_health(), 0);
    
}

TEST(Creature_Constructor, mainConstructor)
{
    Creature I("Po", 5, 7, 1);
    ASSERT_EQ(I.get_health(), 1);
    ASSERT_EQ(I.get_name(), "Po");
    ASSERT_EQ(I.get_damage(), 5);
    ASSERT_EQ(I.get_protection(), 7);
}

TEST(Creature_Constructor, copyingConstructor)
{
    Creature I("Po", 5, 7, 1);
    ASSERT_EQ(I.get_health(), 1);
    ASSERT_EQ(I.get_name(), "Po");
    ASSERT_EQ(I.get_damage(), 5);
    ASSERT_EQ(I.get_protection(), 7);
    
    Creature I1(I);
    ASSERT_EQ(I1.get_health(), 1);
    ASSERT_EQ(I1.get_name(), "Po");
    ASSERT_EQ(I1.get_damage(), 5);
    ASSERT_EQ(I1.get_protection(), 7);
}


