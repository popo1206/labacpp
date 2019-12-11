//
//  main_Ordinary_Troop.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 04/12/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//


#include <stdio.h>
#include "Landscape.h"
#include "gtest/gtest.h"
#include "Ordinary_Troop.h"
using namespace laba4;
TEST(Ordinary_Troop_Constructor, defaultConstructor)
{
    Ordinary_Troop I;
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
TEST(Ordinary_Troop_Constructor, mainConstructor)
{
    Creature cr("Po", 5, 7, 1);
    School* sch = nullptr;
    Coordinates p0(0, 0);
    laba4::Ordinary_Troop I(3,5, 4, 2, 10, cr, sch, p0);
    ASSERT_EQ(I.get_moral(), 5);
    ASSERT_EQ(I.get_initiative(),3);
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
TEST(Ordinary_Troop_Constructor, copyingConstructor)
{
    Creature cr("Po", 5, 7, 1);
    School* sch = nullptr;
    Coordinates p0(0, 0);
    laba4::Ordinary_Troop I(3,5, 4, 2, 10, cr, sch, p0);
    Ordinary_Troop I1(I);
    ASSERT_EQ(I.get_moral(), 5);
    ASSERT_EQ(I.get_initiative(), 3);
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
    ASSERT_EQ(I1.get_moral(), 5);
    ASSERT_EQ(I1.get_initiative(), 3);
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

TEST(Ordinary_Troop_Methods, upmoral)
{
    Creature cr("Po", 5, 7, 1);
    School* sch = nullptr;
    Coordinates p0(0, 0);
    laba4::Ordinary_Troop I(3,5, 4, 2, 10, cr, sch, p0);
    ASSERT_EQ(I.get_moral(), 5);
    I.upmoral();
    ASSERT_EQ(I.get_moral(), 10);
}

TEST(Ordinary_Troop_Methods, balance_moral)
{
    Creature cr("Po", 5, 7, 1);
    School* sch = nullptr;
    Coordinates p0(0, 0);
    laba4::Ordinary_Troop I(3,5, 4, 2, 10, cr, sch, p0);
    ASSERT_EQ(I.get_moral(), 5);
    I.balance_moral();
    ASSERT_EQ(I.get_moral(), 4);
}


