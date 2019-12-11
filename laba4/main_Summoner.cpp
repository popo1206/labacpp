//
//  main_Summoner.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 04/12/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <stdio.h>
#include "Landscape.h"
#include "gtest/gtest.h"
using namespace laba4;
TEST(Constructor_Summoner,default_constructor){
    Summoner s;
    vector<Immoral_Troop*> troops;
    vector<pair<string,unsigned>> knowledge;
    Coordinates p;
    ASSERT_EQ(s.get_name(), "");
    ASSERT_EQ(s.get_initiative(), 0);
    ASSERT_EQ(s.get_health(), 0);
    ASSERT_EQ(s.get_energy(), 0);
    ASSERT_EQ(s.get_max_energy(), 100);
    ASSERT_EQ(s.get_max_health(), 1000);
    ASSERT_EQ(s.get_experience(), 0);
    ASSERT_EQ(s.get_accumulation_coeficient(), 0);
    ASSERT_EQ(s.get_size_of_troops(),0);
    ASSERT_EQ(s.get_size_of_knowledge(), 0);
}
TEST(Constructor_Summoner,main_constructor){
    vector<Immoral_Troop*> troops;
    vector<pair<string,unsigned>> knowledge;
    Coordinates p(0,0);
    Summoner s("PO", 1, 17,100,0,1,troops,knowledge,p);
    ASSERT_EQ(s.get_name(), "PO");
    ASSERT_EQ(s.get_initiative(), 1);
    ASSERT_EQ(s.get_health(), 17);
    ASSERT_EQ(s.get_energy(), 100);
    ASSERT_EQ(s.get_max_energy(), 100);
    ASSERT_EQ(s.get_max_health(), 1000);
    ASSERT_EQ(s.get_experience(), 0);
    ASSERT_EQ(s.get_accumulation_coeficient(), 1);
    ASSERT_EQ(s.get_size_of_troops(),0);
    ASSERT_EQ(s.get_size_of_knowledge(), 0);
}
TEST(Constructor_Summoner,copying_constructor){
    vector<Immoral_Troop*> troops;
    vector<pair<string,unsigned>> knowledge;
    Coordinates p(0,0);
    Summoner ss("PO", 1, 17,100,0,1,troops,knowledge,p);
    Summoner s(ss);
    ASSERT_EQ(s.get_name(), "PO");
    ASSERT_EQ(s.get_initiative(), 1);
    ASSERT_EQ(s.get_health(), 17);
    ASSERT_EQ(s.get_energy(), 100);
    ASSERT_EQ(s.get_max_energy(), 100);
    ASSERT_EQ(s.get_max_health(), 1000);
    ASSERT_EQ(s.get_experience(), 0);
    ASSERT_EQ(s.get_accumulation_coeficient(), 1);
    ASSERT_EQ(s.get_size_of_troops(),0);
    ASSERT_EQ(s.get_size_of_knowledge(), 0);
}
TEST (Constructor_Summoner, moving_constructor){
    vector<Immoral_Troop*> troops;
    vector<pair<string,unsigned>> knowledge;
    Coordinates p(0,0);
    Summoner ss("PO", 1, 17,100,0,1,troops,knowledge,p);
    Summoner s (move(ss));
    ASSERT_EQ(s.get_name(), "PO");
    ASSERT_EQ(s.get_initiative(), 1);
    ASSERT_EQ(s.get_health(), 17);
    ASSERT_EQ(s.get_energy(), 100);
    ASSERT_EQ(s.get_max_energy(), 100);
    ASSERT_EQ(s.get_max_health(), 1000);
    ASSERT_EQ(s.get_experience(), 0);
    ASSERT_EQ(s.get_accumulation_coeficient(), 1);
    ASSERT_EQ(s.get_size_of_troops(),0);
    ASSERT_EQ(s.get_size_of_knowledge(), 0);
    ASSERT_EQ(ss.get_name(), "");
    ASSERT_EQ(ss.get_initiative(), 0);
    ASSERT_EQ(ss.get_health(), 0);
    ASSERT_EQ(ss.get_energy(), 0);
    ASSERT_EQ(ss.get_experience(), 0);
    ASSERT_EQ(ss.get_accumulation_coeficient(), 0);
    ASSERT_EQ(ss.get_size_of_troops(),0);
    ASSERT_EQ(ss.get_size_of_knowledge(), 0);
}
TEST (Methods_Summoner,operator_eqv ){
    vector<Immoral_Troop*> troops;
    vector<pair<string,unsigned>> knowledge;
    Coordinates p(0,0);
    Summoner ss("PO", 1, 17,100,0,1,troops,knowledge,p);
    Summoner s;
    s=ss;
    ASSERT_EQ(s.get_name(), "PO");
    ASSERT_EQ(s.get_initiative(),1);
    ASSERT_EQ(s.get_health(), 17);
    ASSERT_EQ(s.get_energy(), 100);
    ASSERT_EQ(s.get_max_energy(), 100);
    ASSERT_EQ(s.get_max_health(), 1000);
    ASSERT_EQ(s.get_experience(), 0);
    ASSERT_EQ(s.get_accumulation_coeficient(), 1);
    ASSERT_EQ(s.get_size_of_troops(),0);
    ASSERT_EQ(s.get_size_of_knowledge(), 0);
}
TEST (Methods_Summoner,accumulate_energy){
    vector<Immoral_Troop*> troops;
    vector<pair<string,unsigned>> knowledge;
    Coordinates p(0,0);
    Summoner ss("PO", true, 17,10,0,1,troops,knowledge,p);
     ASSERT_EQ(ss.get_energy(), 10);
    ss.accumulate_energy();
    ASSERT_EQ(ss.get_energy(), 30);
   
}
TEST(Methods_Summoner,upschool){
    vector<Immoral_Troop*> troops;
    vector<pair<string,unsigned>> knowledge;
    Coordinates p(0,0);
    pair<string,unsigned> k;
    k.first="School";
    k.second=15;
    knowledge.push_back(k);
    k.first="School2";
    k.second=40;
    knowledge.push_back(k);
    Summoner ss("PO", 1, 17,10,1000,10,troops,knowledge,p);
    ASSERT_EQ(ss.get_knowledge(0).first, "School");
    ASSERT_EQ(ss.get_knowledge(0).second, 15);
    ASSERT_EQ(ss.get_knowledge(1).first, "School2");
    ASSERT_EQ(ss.get_knowledge(1).second, 40);
    ASSERT_EQ(ss.get_experience(), 1000);
    ss.upschool("School", 40);
    ASSERT_EQ(ss.get_knowledge(0).first, "School");
    ASSERT_EQ(ss.get_knowledge(0).second, 55);
    ASSERT_EQ(ss.get_experience(), 960);
}
TEST (Methods_Summoner,summon){
    vector<Immoral_Troop*> troops;
    vector<pair<string,unsigned>> knowledge;
    Coordinates p(0,0);
    Creature cr("Po",5,7,1);
    School* sch=nullptr;
    Coordinates p0(1,1);
    laba4:: Immoral_Troop I(1,4,2,10,cr, sch,p0);
   
    Summoner ss("PO", 1, 17,10,0,1,troops,knowledge,p);
    ss.summon(&I);
    ASSERT_EQ(ss.get_troops(0)->get_initiative(),1);
    ASSERT_EQ(ss.get_troops(0)->get_p().x ,1);
    ASSERT_EQ(ss.get_troops(0)->get_p().y ,1);
    ASSERT_EQ(ss.get_troops(0)->get_count(),10);
    ASSERT_EQ(ss.get_troops(0)->get_speed(), 4);
    ASSERT_EQ(ss.get_troops(0)->get_damage(),50 );
    ASSERT_EQ(ss.get_troops(0)->get_health(),10);
    ASSERT_EQ(ss.get_troops(0)->get_experience(),2);
    ASSERT_EQ(ss.get_troops(0)->get_protection(), 70);
    ASSERT_EQ(ss.get_troops(0)->get_creature().get_health(), 1);
    ASSERT_EQ(ss.get_troops(0)->get_creature().get_name() , "Po");
    ASSERT_EQ(ss.get_troops(0)->get_creature().get_damage(), 5);
    ASSERT_EQ(ss.get_troops(0)->get_creature().get_protection(), 7);
    ASSERT_EQ(ss.get_troops(0)->get_ptr_school(), nullptr);
}
/*TEST(Methods_Summoner,change_initiative){
    vector<Immoral_Troop*> troops;
    vector<pair<string,unsigned>> knowledge;
    Coordinates p(0,0);
    Creature cr("Po",5,7,1);
    School* sch=nullptr;
    Coordinates p0(1,1);
    laba4:: Immoral_Troop I(1,4,2,10,cr, sch,p0);
    troops.push_back(&I);
    Summoner ss("PO", true, 17,10,0,1,troops,knowledge,p);
    ASSERT_EQ(ss.get_troops(0)->get_initiative(), 1);
    ss.change_initiative();
     ASSERT_EQ(ss.get_troops(0)->get_initiative(),true);
}*/
TEST (Methods_Summoner,take_damage){
    vector<Immoral_Troop*> troops;
    vector<pair<string,unsigned>> knowledge;
    Coordinates p(0,0);
    Summoner ss("PO", true, 17,100,0,1,troops,knowledge,p);
    Immoral_Troop I;
    
}
