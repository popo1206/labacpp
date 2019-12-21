//
//  main_skill.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 04/12/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <stdio.h>
#include "Landscape.h"
#include "gtest/gtest.h"
using namespace laba4;
TEST(Skill_Constructor, defaultConstructor)
{
    Skill I;
    ASSERT_EQ(I.get_name(), "");
    ASSERT_EQ(I.get_energy(), 0);
    ASSERT_EQ(I.get_min_knowledge(), 0);
    ASSERT_EQ(I.get_coefficient(), 0);
    ASSERT_EQ(I.get_creature().get_health(), 0);
    ASSERT_EQ(I.get_creature().get_name(), "");
    ASSERT_EQ(I.get_creature().get_damage(), 0);
    ASSERT_EQ(I.get_creature().get_protection(), 0);
}

TEST(Skill_Constructor, mainConstructor)
{
    Creature cr("Po", 5, 7, 1);
    Skill I("Ko", 3, 4, 1, cr);
    ASSERT_EQ(I.get_name(), "Ko");
    ASSERT_EQ(I.get_energy(), 3);
    ASSERT_EQ(I.get_min_knowledge(), 4);
    ASSERT_EQ(I.get_coefficient(), 1);
    ASSERT_EQ(I.get_creature().get_health(), 1);
    ASSERT_EQ(I.get_creature().get_name(), "Po");
    ASSERT_EQ(I.get_creature().get_damage(), 5);
    ASSERT_EQ(I.get_creature().get_protection(), 7);
}

TEST(Skill_Constructor, copyingConstructor)
{
    Creature cr("Po", 5, 7, 1);
    Skill I("Ko", 3, 4, 1, cr);
    ASSERT_EQ(I.get_name(), "Ko");
    ASSERT_EQ(I.get_energy(), 3);
    ASSERT_EQ(I.get_min_knowledge(), 4);
    ASSERT_EQ(I.get_coefficient(), 1);
    ASSERT_EQ(I.get_creature().get_health(), 1);
    ASSERT_EQ(I.get_creature().get_name(), "Po");
    ASSERT_EQ(I.get_creature().get_damage(), 5);
    ASSERT_EQ(I.get_creature().get_protection(), 7);
    
    Skill I1(I);
    ASSERT_EQ(I1.get_name(), "Ko");
    ASSERT_EQ(I1.get_energy(), 3);
    ASSERT_EQ(I1.get_min_knowledge(), 4);
    ASSERT_EQ(I1.get_coefficient(), 1);
    ASSERT_EQ(I1.get_creature().get_health(), 1);
    ASSERT_EQ(I1.get_creature().get_name(), "Po");
    ASSERT_EQ(I1.get_creature().get_damage(), 5);
    ASSERT_EQ(I1.get_creature().get_protection(), 7);
}

