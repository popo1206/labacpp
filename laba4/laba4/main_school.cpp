//
//  main_school.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 04/12/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//
#include <stdio.h>
#include "Landscape.h"
#include "gtest/gtest.h"
using namespace laba4;
TEST (Constructor_School,default_Constructorl){
    School sch;
    ASSERT_EQ(sch.get_name(),"");
    ASSERT_EQ(sch.get_school_dominant(),"");
    ASSERT_EQ(sch.get_size_of_data(), 0);
    ASSERT_EQ(sch.get_number_creatures(), 0);
}
TEST (Constructor_School,main_Constructor){
    vector<Skill> data0;
    Creature cr("Creature", 10,15,10);
    Skill d("Skill",10,15,1,cr);
    data0.push_back(d);
    School sch("NN","PP",10,data0);
    ASSERT_EQ(sch.get_name(), "NN");
    ASSERT_EQ(sch.get_school_dominant(), "PP");
    ASSERT_EQ(sch.get_number_creatures(), 10);
    ASSERT_EQ(sch.get_size_of_data(), 1);
    ASSERT_EQ(sch.get_data(0).get_name(), "Skill");
    ASSERT_EQ(sch.get_data(0).get_energy(), 10);
    ASSERT_EQ(sch.get_data(0).get_coefficient(), 1);
    ASSERT_EQ(sch.get_data(0).get_min_knowledge(), 15);
    ASSERT_EQ(sch.get_data(0).get_creature().get_name(), "Creature");
     ASSERT_EQ(sch.get_data(0).get_creature().get_damage(), 10);
    ASSERT_EQ(sch.get_data(0).get_creature().get_health(), 10);
    ASSERT_EQ(sch.get_data(0).get_creature().get_protection(), 15);
}
TEST (Constructor_School,copying_Constructor){
    vector<Skill> data0;
    Creature cr("Creature", 10,15,10);
    Skill d("Skill",10,15,1,cr);
    data0.push_back(d);
    School s("NN","PP",10,data0);
    School sch(s);
    ASSERT_EQ(sch.get_name(), "NN");
    ASSERT_EQ(sch.get_school_dominant(), "PP");
    ASSERT_EQ(sch.get_number_creatures(), 10);
    ASSERT_EQ(sch.get_size_of_data(), 1);
    ASSERT_EQ(sch.get_data(0).get_name(), "Skill");
    ASSERT_EQ(sch.get_data(0).get_energy(), 10);
    ASSERT_EQ(sch.get_data(0).get_coefficient(), 1);
    ASSERT_EQ(sch.get_data(0).get_min_knowledge(), 15);
    ASSERT_EQ(sch.get_data(0).get_creature().get_name(), "Creature");
    ASSERT_EQ(sch.get_data(0).get_creature().get_damage(), 10);
    ASSERT_EQ(sch.get_data(0).get_creature().get_health(), 10);
    ASSERT_EQ(sch.get_data(0).get_creature().get_protection(), 15);
}
TEST(Methods_School,opertor_eqv){
    School sch;
    vector<Skill> data0;
    Creature cr("Creature", 10,15,10);
    Skill d("Skill",10,15,1,cr);
    data0.push_back(d);
    School s("NN","PP",10,data0);
    sch=s;
    ASSERT_EQ(sch.get_name(), "NN");
    ASSERT_EQ(sch.get_school_dominant(), "PP");
    ASSERT_EQ(sch.get_number_creatures(), 10);
    ASSERT_EQ(sch.get_size_of_data(), 1);
    ASSERT_EQ(sch.get_data(0).get_name(), "Skill");
    ASSERT_EQ(sch.get_data(0).get_energy(), 10);
    ASSERT_EQ(sch.get_data(0).get_coefficient(), 1);
    ASSERT_EQ(sch.get_data(0).get_min_knowledge(), 15);
    ASSERT_EQ(sch.get_data(0).get_creature().get_name(), "Creature");
    ASSERT_EQ(sch.get_data(0).get_creature().get_damage(), 10);
    ASSERT_EQ(sch.get_data(0).get_creature().get_health(), 10);
    ASSERT_EQ(sch.get_data(0).get_creature().get_protection(), 15);
}
TEST(Methods_School,add_skill){
    vector<Skill> data0;
    School sch("NN","PP",10,data0);
    Creature cr("Creature", 10,15,10);
    Skill d("Skill",10,15,1,cr);
    sch.add_skill(d);
    ASSERT_EQ(sch.get_data(0).get_name(), "Skill");
    ASSERT_EQ(sch.get_data(0).get_energy(), 10);
    ASSERT_EQ(sch.get_data(0).get_coefficient(), 1);
    ASSERT_EQ(sch.get_data(0).get_min_knowledge(), 15);
    ASSERT_EQ(sch.get_data(0).get_creature().get_name(), "Creature");
    ASSERT_EQ(sch.get_data(0).get_creature().get_damage(), 10);
    ASSERT_EQ(sch.get_data(0).get_creature().get_health(), 10);
    ASSERT_EQ(sch.get_data(0).get_creature().get_protection(), 15);
}
