//
//  main_OResurrecting.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 04/12/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//


#include <stdio.h>
#include "Landscape.h"
#include "gtest/gtest.h"
#include "OResurrecting_Troop.h"
using namespace laba4;
TEST(OResurrecting_Troop_Constructor, defaultConstructor)
{
    OResurrecting_Troop I;
    ASSERT_EQ(I.get_dead_creatures(), 0);
    ASSERT_EQ(I.get_moral(), 0);
    ASSERT_EQ(I.get_initiative(), false);
    ASSERT_EQ(I.get_p().x, 0);
    ASSERT_EQ(I.get_p().y, 0);
    ASSERT_EQ(I.get_count(), 0);
    ASSERT_EQ(I.get_speed(), 0);
    ASSERT_EQ(I.get_damage(), 0);
    ASSERT_EQ(I.get_health(), 0);
    ASSERT_EQ(I.get_experience(), 0);
    ASSERT_EQ(I.get_creature().get_health(), 0);
    ASSERT_EQ(I.get_creature().get_name(), "");
    ASSERT_EQ(I.get_creature().get_damage(), 0);
    ASSERT_EQ(I.get_creature().get_protection(), 0);
    ASSERT_EQ(I.get_ptr_school(), nullptr);
}
TEST(OResurrecting_Troop_Constructor, mainConstructor)
{
    Creature cr("Po", 5, 7, 1);
    School* sch = nullptr;
    Coordinates p0(0, 0);
    laba4::OResurrecting_Troop I(1,3, 5, 4, 2, 10, cr, sch, p0);
    ASSERT_EQ(I.get_dead_creatures(), 3);
    ASSERT_EQ(I.get_moral(), 5);
    ASSERT_EQ(I.get_initiative(), 1);
    ASSERT_EQ(I.get_p().x, 0);
    ASSERT_EQ(I.get_p().y, 0);
    ASSERT_EQ(I.get_count(), 10);
    ASSERT_EQ(I.get_speed(), 4);
    ASSERT_EQ(I.get_damage(), 50);
    ASSERT_EQ(I.get_health(), 10);
    ASSERT_EQ(I.get_experience(), 2);
    ASSERT_EQ(I.get_protection(), 70);
    ASSERT_EQ(I.get_creature().get_health(), 1);
    ASSERT_EQ(I.get_creature().get_name(), "Po");
    ASSERT_EQ(I.get_creature().get_damage(), 5);
    ASSERT_EQ(I.get_creature().get_protection(), 7);
    ASSERT_EQ(I.get_ptr_school(), nullptr);
}
TEST(OResurrecting_Troop_Constructor, copyingConstructor)
{
    Creature cr("Po", 5, 7, 1);
    School* sch = nullptr;
    Coordinates p0(0, 0);
    laba4::OResurrecting_Troop I(1,3, 5, 4, 2, 10, cr, sch, p0);
    OResurrecting_Troop I1(I);
    ASSERT_EQ(I.get_dead_creatures(), 3);
    ASSERT_EQ(I.get_moral(), 5);
    ASSERT_EQ(I.get_initiative(), 1);
    ASSERT_EQ(I.get_p().x, 0);
    ASSERT_EQ(I.get_p().y, 0);
    ASSERT_EQ(I.get_count(), 10);
    ASSERT_EQ(I.get_speed(), 4);
    ASSERT_EQ(I.get_damage(), 50);
    ASSERT_EQ(I.get_health(), 10);
    ASSERT_EQ(I.get_experience(), 2);
    ASSERT_EQ(I.get_protection(), 70);
    ASSERT_EQ(I.get_creature().get_health(), 1);
    ASSERT_EQ(I.get_creature().get_name(), "Po");
    ASSERT_EQ(I.get_creature().get_damage(), 5);
    ASSERT_EQ(I.get_creature().get_protection(), 7);
    ASSERT_EQ(I.get_ptr_school(), nullptr);
    
    ASSERT_EQ(I1.get_dead_creatures(), 3);
    ASSERT_EQ(I1.get_moral(), 5);
    ASSERT_EQ(I1.get_initiative(), 1);
    ASSERT_EQ(I1.get_p().x, 0);
    ASSERT_EQ(I1.get_p().y, 0);
    ASSERT_EQ(I1.get_count(), 10);
    ASSERT_EQ(I1.get_speed(), 4);
    ASSERT_EQ(I1.get_damage(), 50);
    ASSERT_EQ(I1.get_health(), 10);
    ASSERT_EQ(I1.get_experience(), 2);
    ASSERT_EQ(I1.get_protection(), 70);
    ASSERT_EQ(I1.get_creature().get_health(), 1);
    ASSERT_EQ(I1.get_creature().get_name(), "Po");
    ASSERT_EQ(I1.get_creature().get_damage(), 5);
    ASSERT_EQ(I1.get_creature().get_protection(), 7);
    ASSERT_EQ(I1.get_ptr_school(), nullptr);
}

TEST(OResurrecting_Troop_Methods, ressurect_creatures)
{
    Creature cr("Po", 5, 7, 1);
    School* sch = nullptr;
    Coordinates p0(0, 0);
    laba4::OResurrecting_Troop I(1,5, 5, 4, 2, 10, cr, sch, p0);
    ASSERT_EQ(I.get_dead_creatures(), 5);
    ASSERT_EQ(I.get_health(), 10);
    ASSERT_EQ(I.get_count(), 10);
    I.resurrect_creatures();
    ASSERT_EQ(I.get_dead_creatures(), 2);
    ASSERT_EQ(I.get_health(), 13);
    ASSERT_EQ(I.get_count(), 13);
    I.resurrect_creatures();
    ASSERT_EQ(I.get_dead_creatures(), 0);
    ASSERT_EQ(I.get_health(), 15);
    ASSERT_EQ(I.get_count(), 15);
}

