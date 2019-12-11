//
//  main.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 19/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <iostream>
#include "Landscape.h"
#include "gtest/gtest.h"
using namespace laba4;
TEST(Immoral_Troop_Constuctor, defaultConstructor)
{
    laba4:: Immoral_Troop I;
    ASSERT_EQ(I.get_initiative(),false);
    ASSERT_EQ(I.get_p().x ,0);
    ASSERT_EQ(I.get_p().y ,0);
    ASSERT_EQ(I.get_count(),0);
    ASSERT_EQ(I.get_speed(), 0);
    ASSERT_EQ(I.get_damage(), 0);
    ASSERT_EQ(I.get_health(), 0);
    ASSERT_EQ(I.get_experience(), 0);
    ASSERT_EQ(I.get_creature().get_health(), 0);
    ASSERT_EQ(I.get_creature().get_name() , "");
    ASSERT_EQ(I.get_creature().get_damage(), 0);
    ASSERT_EQ(I.get_creature().get_protection(), 0);
    ASSERT_EQ(I.get_ptr_school(), nullptr);
    
}
TEST(Immoral_Troop_Constuctor, mainConstructor)
{
    Creature cr("Po",5,7,1);
    School* sch=nullptr;
    Coordinates p0(0,0);
    laba4:: Immoral_Troop I(1,4,2,10,cr, sch,p0);
    ASSERT_EQ(I.get_initiative(),1);
    ASSERT_EQ(I.get_p().x ,0);
    ASSERT_EQ(I.get_p().y ,0);
    ASSERT_EQ(I.get_count(),10);
    ASSERT_EQ(I.get_speed(), 4);
    ASSERT_EQ(I.get_damage(),50 );
    ASSERT_EQ(I.get_health(),10);
    ASSERT_EQ(I.get_experience(),2);
    ASSERT_EQ(I.get_protection(), 70);
    ASSERT_EQ(I.get_creature().get_health(), 1);
    ASSERT_EQ(I.get_creature().get_name() , "Po");
    ASSERT_EQ(I.get_creature().get_damage(), 5);
    ASSERT_EQ(I.get_creature().get_protection(), 7);
    ASSERT_EQ(I.get_ptr_school(), nullptr);
    
}
TEST(Immoral_Troop_Constuctor, copyingConstructor)
{
    Creature cr("Po",5,7,1);
    School* sch=nullptr;
    Coordinates p0(0,0);
    laba4:: Immoral_Troop I1(1,4,2,10,cr, sch,p0);
    Immoral_Troop I(I1);
    ASSERT_EQ(I.get_initiative(),1);
    ASSERT_EQ(I.get_p().x ,0);
    ASSERT_EQ(I.get_p().y ,0);
    ASSERT_EQ(I.get_count(),10);
    ASSERT_EQ(I.get_speed(), 4);
    ASSERT_EQ(I.get_damage(),50 );
    ASSERT_EQ(I.get_health(),10);
    ASSERT_EQ(I.get_experience(),2);
    ASSERT_EQ(I.get_protection(), 70);
    ASSERT_EQ(I.get_creature().get_health(), 1);
    ASSERT_EQ(I.get_creature().get_name() , "Po");
    ASSERT_EQ(I.get_creature().get_damage(), 5);
    ASSERT_EQ(I.get_creature().get_protection(), 7);
    ASSERT_EQ(I.get_ptr_school(), nullptr);
    ASSERT_EQ(I1.get_initiative(),1);
    ASSERT_EQ(I1.get_p().x ,0);
    ASSERT_EQ(I1.get_p().y ,0);
    ASSERT_EQ(I1.get_count(),10);
    ASSERT_EQ(I1.get_speed(), 4);
    ASSERT_EQ(I1.get_damage(),50 );
    ASSERT_EQ(I1.get_health(),10);
    ASSERT_EQ(I1.get_experience(),2);
    ASSERT_EQ(I1.get_protection(), 70);
    ASSERT_EQ(I1.get_creature().get_health(), 1);
    ASSERT_EQ(I1.get_creature().get_name() , "Po");
    ASSERT_EQ(I1.get_creature().get_damage(), 5);
    ASSERT_EQ(I1.get_creature().get_protection(), 7);
    ASSERT_EQ(I1.get_ptr_school(), nullptr);
}
TEST(Immoral_Troop_Constuctor, movingConstructor)
{
    Creature cr("Po",5,7,1);
    School* sch=nullptr;
    Coordinates p0(0,0);
    laba4:: Immoral_Troop I1(1,4,2,10,cr, sch,p0);
    Immoral_Troop I(std::move(I1));
    ASSERT_EQ(I.get_initiative(),1);
    ASSERT_EQ(I.get_p().x ,0);
    ASSERT_EQ(I.get_p().y ,0);
    ASSERT_EQ(I.get_count(),10);
    ASSERT_EQ(I.get_speed(), 4);
    ASSERT_EQ(I.get_damage(),50 );
    ASSERT_EQ(I.get_health(),10);
    ASSERT_EQ(I.get_experience(),2);
    ASSERT_EQ(I.get_protection(), 70);
    ASSERT_EQ(I.get_creature().get_health(), 1);
    ASSERT_EQ(I.get_creature().get_name() , "Po");
    ASSERT_EQ(I.get_creature().get_damage(), 5);
    ASSERT_EQ(I.get_creature().get_protection(), 7);
    ASSERT_EQ(I.get_ptr_school(), nullptr);
}
TEST(Immoral_Troop_Methods, Operator_eqv)
{
    Creature cr("Po",5,7,1);
    School* sch=nullptr;
    Coordinates p0(0,0);
    laba4:: Immoral_Troop I1(1,4,2,10,cr, sch,p0);
    Immoral_Troop I;
    I=I1;
    ASSERT_EQ(I.get_initiative(),1);
    ASSERT_EQ(I.get_p().x ,0);
    ASSERT_EQ(I.get_p().y ,0);
    ASSERT_EQ(I.get_count(),10);
    ASSERT_EQ(I.get_speed(), 4);
    ASSERT_EQ(I.get_damage(),50 );
    ASSERT_EQ(I.get_health(),10);
    ASSERT_EQ(I.get_experience(),2);
    ASSERT_EQ(I.get_protection(), 70);
    ASSERT_EQ(I.get_creature().get_health(), 1);
    ASSERT_EQ(I.get_creature().get_name() , "Po");
    ASSERT_EQ(I.get_creature().get_damage(), 5);
    ASSERT_EQ(I.get_creature().get_protection(), 7);
    ASSERT_EQ(I.get_ptr_school(), nullptr);
}
/*TEST(Immoral_Troop_Methods, move_Troop_forward_right)
{
    Creature cr("Po",5,7,1);
    School* sch=nullptr;
    Coordinates p0(8,8);
    laba4:: Immoral_Troop I(1,4,2,10,cr, sch,p0);
    I.move_troop('W', 10, 10);
    ASSERT_EQ(I.get_p().y ,9);
    I.move_troop('W', 10, 10);
    ASSERT_EQ(I.get_p().y ,9);
    I.move_troop('D', 10, 10);
    ASSERT_EQ(I.get_p().x ,9);
    I.move_troop('D', 10, 10);
    ASSERT_EQ(I.get_p().x ,9);
}*/
/*TEST(Immoral_Troop_Methods, move_Troop_back_left)
{
    Creature cr("Po",5,7,1);
    School* sch=nullptr;
    Coordinates p0(1,1);
    laba4:: Immoral_Troop I(1,4,2,10,cr, sch,p0);
    I.move_troop('S', 10, 10);
    ASSERT_EQ(I.get_p().y ,0);
    I.move_troop('S', 10, 10);
    ASSERT_EQ(I.get_p().y ,0);
    I.move_troop('A', 10, 10);
    ASSERT_EQ(I.get_p().x ,0);
    I.move_troop('A', 10, 10);
    ASSERT_EQ(I.get_p().x ,0);
}*/
TEST(Immoral_Troop_Methods, take_damage)
{
    Creature cr("Po",5,7,1);
    School school;
    school.set_name("Recesive");
    school.set_school_dominant("Dominant");
    School* sch=&school;
    Coordinates p0(0,0);
    Immoral_Troop I(1,4,2,10,cr, sch,p0);
    Creature cr1("M",6,2,1);
    School school1;
    school1.set_name("Dominant");
    school1.set_school_dominant("Domin_dominant");
    School* sch1=&school1;
    School s;
    s.set_name("Gg");
    s.set_school_dominant("Recesive");
    School *ss=&s;
    Immoral_Troop I1(1,5,4,12,cr1,sch1,p0);
    I.take_damage(I1);
    ASSERT_EQ(I.get_health(),3 );//урон со стороны доминантной школы
    ASSERT_EQ(I.get_count(), 3);
    I1.set_ptr_school(ss);//теперь наносит урон школа рецессив
    I.take_damage(I1);
    ASSERT_EQ(I.get_health(),3);//урон со стороны доминантной школы
    ASSERT_EQ(I.get_count(), 3);
}

