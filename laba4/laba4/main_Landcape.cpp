//
//  main_Landcape.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 03/12/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <stdio.h>
#include "Landscape.h"
#include "gtest/gtest.h"
#include "Ordinary_Troop.h"
using namespace laba4;
TEST(Landcape_Constructor,defaultConstructor){
    Landscape s;
    Coordinates p0(0,0);
    ASSERT_EQ(s.get_m(), 0);
    ASSERT_EQ(s.get_n(), 0);
    ASSERT_EQ(s.get_User_Summoner().get_name(),"");
    ASSERT_EQ(s.get_Enemy_Summoner().get_name(),"");
    ASSERT_EQ(s.get_User_Summoner().get_energy(),0);
    ASSERT_EQ(s.get_Enemy_Summoner().get_energy(),0);
    ASSERT_EQ(s.get_User_Summoner().get_size_of_troops(), 0);
    ASSERT_EQ(s.get_Enemy_Summoner().get_size_of_troops(), 0);
    ASSERT_EQ(s.get_User_Summoner().get_health(), 0);
    ASSERT_EQ(s.get_Enemy_Summoner().get_health(), 0);
    ASSERT_EQ(s.get_User_Summoner().get_coordinates().x,p0.x);
    ASSERT_EQ(s.get_User_Summoner().get_coordinates().y,p0.y);
    ASSERT_EQ(s.get_Enemy_Summoner().get_size_of_knowledge(),0);
    ASSERT_EQ(s.get_User_Summoner().get_size_of_knowledge(),0);
    ASSERT_EQ(s.get_User_Summoner().get_experience(), 0);
    ASSERT_EQ(s.get_Enemy_Summoner().get_experience(), 0);
    ASSERT_EQ(s.get_User_Summoner().get_initiative(), 0);
    ASSERT_EQ(s.get_Enemy_Summoner().get_initiative(), 0);
}
TEST(Landcape_Constructor,mainConstructor){
    Summoner User;
    Summoner Enemy;
    Landscape s(User,Enemy);
    Coordinates p0(0,0);
    ASSERT_EQ(s.get_User_Summoner().get_name(),"");
    ASSERT_EQ(s.get_Enemy_Summoner().get_name(),"");
    ASSERT_EQ(s.get_User_Summoner().get_energy(),0);
    ASSERT_EQ(s.get_Enemy_Summoner().get_energy(),0);
    ASSERT_EQ(s.get_User_Summoner().get_size_of_troops(), 0);
    ASSERT_EQ(s.get_Enemy_Summoner().get_size_of_troops(), 0);
    ASSERT_EQ(s.get_User_Summoner().get_health(), 0);
    ASSERT_EQ(s.get_Enemy_Summoner().get_health(), 0);
    ASSERT_EQ(s.get_User_Summoner().get_coordinates().x,p0.x);
    ASSERT_EQ(s.get_User_Summoner().get_coordinates().y,p0.y);
    ASSERT_EQ(s.get_Enemy_Summoner().get_size_of_knowledge(),0);
    ASSERT_EQ(s.get_User_Summoner().get_size_of_knowledge(),0);
    ASSERT_EQ(s.get_User_Summoner().get_experience(), 0);
    ASSERT_EQ(s.get_Enemy_Summoner().get_experience(), 0);
    ASSERT_EQ(s.get_User_Summoner().get_initiative(), 0);
    ASSERT_EQ(s.get_Enemy_Summoner().get_initiative(), 0);
}
TEST(Landcape_Constructor,coppiyng_Constructor){
    vector<Immoral_Troop*> troops0;
    vector<pair<string,unsigned>> knowledge0;
    Coordinates p0(2,2);
    Coordinates pp(3,3);
    Summoner User("LL",1,100,100,0,1,troops0,knowledge0,p0);
    Summoner Enemy("KK",0,100,100,0,1,troops0,knowledge0,pp);
    Landscape s(User,Enemy);
    Landscape ss(s);
    ASSERT_EQ(ss.get_User_Summoner().get_name(),"LL");
    ASSERT_EQ(ss.get_Enemy_Summoner().get_name(),"KK");
    ASSERT_EQ(ss.get_User_Summoner().get_energy(),100);
    ASSERT_EQ(ss.get_Enemy_Summoner().get_energy(),100);
    ASSERT_EQ(ss.get_User_Summoner().get_size_of_troops(), 0);
    ASSERT_EQ(ss.get_Enemy_Summoner().get_size_of_troops(), 0);
    ASSERT_EQ(ss.get_User_Summoner().get_health(), 100);
   ASSERT_EQ(ss.get_Enemy_Summoner().get_health(), 100);
   ASSERT_EQ(ss.get_User_Summoner().get_coordinates().x,2);
   ASSERT_EQ(ss.get_User_Summoner().get_coordinates().y,2);
   ASSERT_EQ(ss.get_Enemy_Summoner().get_coordinates().x,3);
    ASSERT_EQ(ss.get_Enemy_Summoner().get_coordinates().y,3);
    ASSERT_EQ(ss.get_Enemy_Summoner().get_size_of_knowledge(),0);
    ASSERT_EQ(ss.get_User_Summoner().get_size_of_knowledge(),0);
    ASSERT_EQ(ss.get_User_Summoner().get_experience(), 0);
    ASSERT_EQ(ss.get_Enemy_Summoner().get_experience(), 0);
    ASSERT_EQ(ss.get_User_Summoner().get_initiative(), 1);
    ASSERT_EQ(ss.get_Enemy_Summoner().get_initiative(), 0);
}
TEST(Landscape_Methods,create_summoner){
    Landscape L;
    vector<pair<string, unsigned int> > p;
    Summoner User;
    User=L.create_summoner("MM", p, "User_Summoner");
    ASSERT_EQ(User.get_name(), "MM");
    ASSERT_EQ(User.get_initiative(), 1);
    ASSERT_EQ(User.get_experience(), 0);
    ASSERT_EQ(User.get_health(), 1000);
    ASSERT_EQ(User.get_energy(), 1000);
    ASSERT_EQ(User.get_size_of_knowledge(), 0);
    ASSERT_EQ(User.get_size_of_troops(),0);
    ASSERT_EQ(User.get_coordinates().x, 1);
    ASSERT_EQ(User.get_coordinates().y,1);
    Summoner Enemy;
    Enemy=L.create_summoner("PP", p, "Enemy_Summoners");
    ASSERT_EQ(Enemy.get_name(), "PP");
    ASSERT_EQ(Enemy.get_initiative(), 0);
    ASSERT_EQ(Enemy.get_experience(), 0);
    ASSERT_EQ(Enemy.get_health(), 1000);
    ASSERT_EQ(Enemy.get_energy(), 1000);
    ASSERT_EQ(Enemy.get_size_of_knowledge(), 0);
    ASSERT_EQ(Enemy.get_size_of_troops(),0);
    ASSERT_EQ(Enemy.get_coordinates().x, 3);
    ASSERT_EQ(Enemy.get_coordinates().y,3);
}
TEST(Landscape_Methods,read_first_school){
    Landscape L;
    L.read_school();
    //
    ASSERT_EQ(L.get_School(0).get_name(), "necromancy");
    ASSERT_EQ(L.get_School(0).get_school_dominant(), "animalism");
    ASSERT_EQ(L.get_School(0).get_number_creatures(), 3);
    ASSERT_EQ(L.get_School(0).get_data(0).get_name(), "Fist_Skill");
    ASSERT_EQ(L.get_School(0).get_data(0).get_energy(), 15);
    ASSERT_EQ(L.get_School(0).get_data(0).get_coefficient(), 1);
    ASSERT_EQ(L.get_School(0).get_data(0).get_min_knowledge(), 0);
    ASSERT_EQ(L.get_School(0).get_data(0).get_creature().get_name(), "First_Creature");
    ASSERT_EQ(L.get_School(0).get_data(0).get_creature().get_damage(), 15);
    ASSERT_EQ(L.get_School(0).get_data(0).get_creature().get_health(), 10);
    ASSERT_EQ(L.get_School(0).get_data(0).get_creature().get_protection(), 3);
    
    ASSERT_EQ(L.get_School(0).get_data(1).get_name(), "Second_Skill");
    ASSERT_EQ(L.get_School(0).get_data(1).get_energy(), 40);
    ASSERT_EQ(L.get_School(0).get_data(1).get_coefficient(), 1);
    ASSERT_EQ(L.get_School(0).get_data(1).get_min_knowledge(), 50);
    ASSERT_EQ(L.get_School(0).get_data(1).get_creature().get_name(), "Second_Creature");
    ASSERT_EQ(L.get_School(0).get_data(1).get_creature().get_damage(), 20);
    ASSERT_EQ(L.get_School(0).get_data(1).get_creature().get_health(), 15);
    ASSERT_EQ(L.get_School(0).get_data(1).get_creature().get_protection(), 4);
    
    ASSERT_EQ(L.get_School(0).get_data(2).get_name(), "Third_Skill");
    ASSERT_EQ(L.get_School(0).get_data(2).get_energy(), 70);
    ASSERT_EQ(L.get_School(0).get_data(2).get_coefficient(), 1);
    ASSERT_EQ(L.get_School(0).get_data(2).get_min_knowledge(), 100);
    ASSERT_EQ(L.get_School(0).get_data(2).get_creature().get_name(), "Third_Creature");
    ASSERT_EQ(L.get_School(0).get_data(2).get_creature().get_damage(), 25);
    ASSERT_EQ(L.get_School(0).get_data(2).get_creature().get_health(), 20);
    ASSERT_EQ(L.get_School(0).get_data(2).get_creature().get_protection(), 5);
    //
    
    ASSERT_EQ(L.get_School(1).get_name(), "animalism");
    ASSERT_EQ(L.get_School(1).get_school_dominant(),"demonology");
     ASSERT_EQ(L.get_School(1).get_number_creatures(), 3);
    
    ASSERT_EQ(L.get_School(1).get_data(0).get_name(), "Fist_Skill");
    ASSERT_EQ(L.get_School(1).get_data(0).get_energy(), 15);
    ASSERT_EQ(L.get_School(1).get_data(0).get_coefficient(), 1);
    ASSERT_EQ(L.get_School(1).get_data(0).get_min_knowledge(), 0);
    ASSERT_EQ(L.get_School(1).get_data(0).get_creature().get_name(), "First_Creature");
    ASSERT_EQ(L.get_School(1).get_data(0).get_creature().get_damage(), 15);
    ASSERT_EQ(L.get_School(1).get_data(0).get_creature().get_health(), 10);
    ASSERT_EQ(L.get_School(1).get_data(0).get_creature().get_protection(), 3);
    
    ASSERT_EQ(L.get_School(1).get_data(1).get_name(), "Second_Skill");
    ASSERT_EQ(L.get_School(1).get_data(1).get_energy(), 40);
    ASSERT_EQ(L.get_School(1).get_data(1).get_coefficient(), 1);
    ASSERT_EQ(L.get_School(1).get_data(1).get_min_knowledge(), 50);
    ASSERT_EQ(L.get_School(1).get_data(1).get_creature().get_name(), "Second_Creature");
    ASSERT_EQ(L.get_School(1).get_data(1).get_creature().get_damage(), 20);
    ASSERT_EQ(L.get_School(1).get_data(1).get_creature().get_health(), 15);
    ASSERT_EQ(L.get_School(1).get_data(1).get_creature().get_protection(), 4);
    
    ASSERT_EQ(L.get_School(1).get_data(2).get_name(), "Third_Skill");
    ASSERT_EQ(L.get_School(1).get_data(2).get_energy(), 70);
    ASSERT_EQ(L.get_School(1).get_data(2).get_coefficient(), 1);
    ASSERT_EQ(L.get_School(1).get_data(2).get_min_knowledge(), 100);
    ASSERT_EQ(L.get_School(1).get_data(2).get_creature().get_name(), "Third_Creature");
    ASSERT_EQ(L.get_School(1).get_data(2).get_creature().get_damage(), 25);
    ASSERT_EQ(L.get_School(1).get_data(2).get_creature().get_health(), 20);
    ASSERT_EQ(L.get_School(1).get_data(2).get_creature().get_protection(), 5);
    
    //
    ASSERT_EQ(L.get_School(2).get_name(), "demonology");
    ASSERT_EQ(L.get_School(2).get_school_dominant(), "other_realities");
     ASSERT_EQ(L.get_School(2).get_number_creatures(), 3);
    
    ASSERT_EQ(L.get_School(2).get_data(0).get_name(), "Fist_Skill");
    ASSERT_EQ(L.get_School(2).get_data(0).get_energy(), 15);
    ASSERT_EQ(L.get_School(2).get_data(0).get_coefficient(), 1);
    ASSERT_EQ(L.get_School(2).get_data(0).get_min_knowledge(), 0);
    ASSERT_EQ(L.get_School(2).get_data(0).get_creature().get_name(), "First_Creature");
    ASSERT_EQ(L.get_School(2).get_data(0).get_creature().get_damage(), 15);
    ASSERT_EQ(L.get_School(2).get_data(0).get_creature().get_health(), 10);
    ASSERT_EQ(L.get_School(2).get_data(0).get_creature().get_protection(), 3);
    
    ASSERT_EQ(L.get_School(2).get_data(1).get_name(), "Second_Skill");
    ASSERT_EQ(L.get_School(2).get_data(1).get_energy(), 40);
    ASSERT_EQ(L.get_School(2).get_data(1).get_coefficient(), 1);
    ASSERT_EQ(L.get_School(2).get_data(1).get_min_knowledge(), 50);
    ASSERT_EQ(L.get_School(2).get_data(1).get_creature().get_name(), "Second_Creature");
    ASSERT_EQ(L.get_School(2).get_data(1).get_creature().get_damage(), 20);
    ASSERT_EQ(L.get_School(2).get_data(1).get_creature().get_health(), 15);
    ASSERT_EQ(L.get_School(2).get_data(1).get_creature().get_protection(), 4);
    
    ASSERT_EQ(L.get_School(2).get_data(2).get_name(), "Third_Skill");
    ASSERT_EQ(L.get_School(2).get_data(2).get_energy(), 70);
    ASSERT_EQ(L.get_School(2).get_data(2).get_coefficient(), 1);
    ASSERT_EQ(L.get_School(2).get_data(2).get_min_knowledge(), 100);
    ASSERT_EQ(L.get_School(2).get_data(2).get_creature().get_name(), "Third_Creature");
    ASSERT_EQ(L.get_School(2).get_data(2).get_creature().get_damage(), 25);
    ASSERT_EQ(L.get_School(2).get_data(2).get_creature().get_health(), 20);
    ASSERT_EQ(L.get_School(2).get_data(2).get_creature().get_protection(), 5);
    //
    
    ASSERT_EQ(L.get_School(3).get_name(), "other_realities");
    ASSERT_EQ(L.get_School(3).get_school_dominant(), "elementalism");
     ASSERT_EQ(L.get_School(3).get_number_creatures(), 3);
    
    ASSERT_EQ(L.get_School(3).get_data(0).get_name(), "Fist_Skill");
    ASSERT_EQ(L.get_School(3).get_data(0).get_energy(), 15);
    ASSERT_EQ(L.get_School(3).get_data(0).get_coefficient(), 1);
    ASSERT_EQ(L.get_School(3).get_data(0).get_min_knowledge(), 0);
    ASSERT_EQ(L.get_School(3).get_data(0).get_creature().get_name(), "First_Creature");
    ASSERT_EQ(L.get_School(3).get_data(0).get_creature().get_damage(), 15);
    ASSERT_EQ(L.get_School(3).get_data(0).get_creature().get_health(), 10);
    ASSERT_EQ(L.get_School(3).get_data(0).get_creature().get_protection(), 3);
    
    ASSERT_EQ(L.get_School(3).get_data(1).get_name(), "Second_Skill");
    ASSERT_EQ(L.get_School(3).get_data(1).get_energy(), 40);
    ASSERT_EQ(L.get_School(3).get_data(1).get_coefficient(), 1);
    ASSERT_EQ(L.get_School(3).get_data(1).get_min_knowledge(), 50);
    ASSERT_EQ(L.get_School(3).get_data(1).get_creature().get_name(), "Second_Creature");
    ASSERT_EQ(L.get_School(3).get_data(1).get_creature().get_damage(), 20);
    ASSERT_EQ(L.get_School(3).get_data(1).get_creature().get_health(), 15);
    ASSERT_EQ(L.get_School(3).get_data(1).get_creature().get_protection(), 4);
    
    ASSERT_EQ(L.get_School(3).get_data(2).get_name(), "Third_Skill");
    ASSERT_EQ(L.get_School(3).get_data(2).get_energy(), 70);
    ASSERT_EQ(L.get_School(3).get_data(2).get_coefficient(), 1);
    ASSERT_EQ(L.get_School(3).get_data(2).get_min_knowledge(), 100);
    ASSERT_EQ(L.get_School(3).get_data(2).get_creature().get_name(), "Third_Creature");
    ASSERT_EQ(L.get_School(3).get_data(2).get_creature().get_damage(), 25);
    ASSERT_EQ(L.get_School(3).get_data(2).get_creature().get_health(), 20);
    ASSERT_EQ(L.get_School(3).get_data(2).get_creature().get_protection(), 5);
    //
    
    ASSERT_EQ(L.get_School(4).get_name(), "elementalism");
    ASSERT_EQ(L.get_School(4).get_school_dominant(), "necromancy");
     ASSERT_EQ(L.get_School(4).get_number_creatures(), 3);
    
    ASSERT_EQ(L.get_School(4).get_data(0).get_name(), "Fist_Skill");
    ASSERT_EQ(L.get_School(4).get_data(0).get_energy(), 15);
    ASSERT_EQ(L.get_School(4).get_data(0).get_coefficient(), 1);
    ASSERT_EQ(L.get_School(4).get_data(0).get_min_knowledge(), 0);
    ASSERT_EQ(L.get_School(4).get_data(0).get_creature().get_name(), "First_Creature");
    ASSERT_EQ(L.get_School(4).get_data(0).get_creature().get_damage(), 15);
    ASSERT_EQ(L.get_School(4).get_data(0).get_creature().get_health(), 10);
    ASSERT_EQ(L.get_School(4).get_data(0).get_creature().get_protection(), 3);
    
    ASSERT_EQ(L.get_School(4).get_data(1).get_name(), "Second_Skill");
    ASSERT_EQ(L.get_School(4).get_data(1).get_energy(), 40);
    ASSERT_EQ(L.get_School(4).get_data(1).get_coefficient(), 1);
    ASSERT_EQ(L.get_School(4).get_data(1).get_min_knowledge(), 50);
    ASSERT_EQ(L.get_School(4).get_data(1).get_creature().get_name(), "Second_Creature");
    ASSERT_EQ(L.get_School(4).get_data(1).get_creature().get_damage(), 20);
    ASSERT_EQ(L.get_School(4).get_data(1).get_creature().get_health(), 15);
    ASSERT_EQ(L.get_School(4).get_data(1).get_creature().get_protection(), 4);
    
    ASSERT_EQ(L.get_School(4).get_data(2).get_name(), "Third_Skill");
    ASSERT_EQ(L.get_School(4).get_data(2).get_energy(), 70);
    ASSERT_EQ(L.get_School(4).get_data(2).get_coefficient(), 1);
    ASSERT_EQ(L.get_School(4).get_data(2).get_min_knowledge(), 100);
    ASSERT_EQ(L.get_School(4).get_data(2).get_creature().get_name(), "Third_Creature");
    ASSERT_EQ(L.get_School(4).get_data(2).get_creature().get_damage(), 25);
    ASSERT_EQ(L.get_School(4).get_data(2).get_creature().get_health(), 20);
    ASSERT_EQ(L.get_School(4).get_data(2).get_creature().get_protection(), 5);
}
TEST (Lndscape_Methods,find_school){
    Landscape L;
    L.read_school();
    School *f;
    f=L.find_school("necromancy");
    ASSERT_EQ(f->get_name(), "necromancy");
    ASSERT_EQ(f->get_school_dominant(), "animalism");
    ASSERT_EQ(f->get_number_creatures(), 3);
    ASSERT_EQ(f->get_data(0).get_name(), "Fist_Skill");
    ASSERT_EQ(f->get_data(0).get_energy(), 15);
    ASSERT_EQ(f->get_data(0).get_coefficient(), 1);
    ASSERT_EQ(f->get_data(0).get_min_knowledge(), 0);
    ASSERT_EQ(f->get_data(0).get_creature().get_name(), "First_Creature");
    ASSERT_EQ(f->get_data(0).get_creature().get_damage(), 15);
    ASSERT_EQ(f->get_data(0).get_creature().get_health(), 10);
    ASSERT_EQ(f->get_data(0).get_creature().get_protection(), 3);
    
    ASSERT_EQ(f->get_data(1).get_name(), "Second_Skill");
    ASSERT_EQ(f->get_data(1).get_energy(), 40);
    ASSERT_EQ(f->get_data(1).get_coefficient(), 1);
    ASSERT_EQ(f->get_data(1).get_min_knowledge(), 50);
    ASSERT_EQ(f->get_data(1).get_creature().get_name(), "Second_Creature");
    ASSERT_EQ(f->get_data(1).get_creature().get_damage(), 20);
    ASSERT_EQ(f->get_data(1).get_creature().get_health(), 15);
    ASSERT_EQ(f->get_data(1).get_creature().get_protection(), 4);
    
    ASSERT_EQ(f->get_data(2).get_name(), "Third_Skill");
    ASSERT_EQ(f->get_data(2).get_energy(), 70);
    ASSERT_EQ(f->get_data(2).get_coefficient(), 1);
    ASSERT_EQ(f->get_data(2).get_min_knowledge(), 100);
    ASSERT_EQ(f->get_data(2).get_creature().get_name(), "Third_Creature");
    ASSERT_EQ(f->get_data(2).get_creature().get_damage(), 25);
    ASSERT_EQ(f->get_data(2).get_creature().get_health(), 20);
    ASSERT_EQ(f->get_data(2).get_creature().get_protection(), 5);
}
TEST(Landscape_Methods,install_in_troop){
    Landscape s;
    vector<pair<string, unsigned int> > p;
    Summoner user,enemy;
    user=s.create_summoner("M", p, "User_Summoner");
    Immoral_Troop troop;
    user.summon(&troop);
    s.set_user_summoner(user);
    enemy=s.create_summoner("P", p, "Enemy_Summoners");
    Immoral_Troop troop2;
    enemy.summon(&troop2);
    s.set_enemy_summoner(enemy);
    s.input_map();
     s.install_troop_in_cell();
    ASSERT_EQ(s.get_User_Summoner().get_troops(0)->get_p().x, 0);
    ASSERT_EQ(s.get_User_Summoner().get_troops(0)->get_p().y, 1);
}
TEST (Landscape_Methods,move_troop){
    Landscape s;
    Coordinates p0(3,1);
    vector<pair<string, unsigned int> > p;
    Summoner user,enemy;
    user=s.create_summoner("M", p, "User_Summoner");
    Immoral_Troop troop;
    user.summon(&troop);
    s.set_user_summoner(user);
    enemy=s.create_summoner("P", p, "Enemy_Summoners");
    Immoral_Troop troop2;
    enemy.summon(&troop2);
    s.set_enemy_summoner(enemy);
    s.get_User_Summoner().get_troops(0)->set_p(p0);
    s.input_map();
    ASSERT_ANY_THROW(s.move_troop('A',s.get_User_Summoner().get_troops(0)));
    Coordinates pp(4,0);
    s.get_User_Summoner().get_troops(0)->set_p(pp);
    ASSERT_ANY_THROW(s.move_troop('D',s.get_User_Summoner().get_troops(0)));
    Coordinates p1(1,0);
    s.get_User_Summoner().get_troops(0)->set_p(p1);
    ASSERT_ANY_THROW(s.move_troop('S',s.get_User_Summoner().get_troops(0)));
     Coordinates p2(0,4);
     s.get_User_Summoner().get_troops(0)->set_p(p2);
     ASSERT_ANY_THROW(s.move_troop('W',s.get_User_Summoner().get_troops(0)));
    Coordinates p00(0,0);
     s.get_User_Summoner().get_troops(0)->set_p(p00);
    s.move_troop('D',s.get_User_Summoner().get_troops(0));
    ASSERT_EQ( s.get_User_Summoner().get_troops(0)->get_p().x, 1);
    ASSERT_EQ( s.get_User_Summoner().get_troops(0)->get_p().y, 0);
    ASSERT_EQ(s.get_rectangle()[0][1].get_object(), USER_TROOP);
}
TEST (Lanscape_Methods,push_queue){
    Try_To_Be_Smart::Priorety_Queue<Object, unsigned> qq;
    Landscape s;
    Coordinates p0(3,1);
    vector<pair<string, unsigned int> > p;
    Summoner user,enemy;
    user=s.create_summoner("M", p, "User_Summoner");
    Immoral_Troop troop;
    user.summon(&troop);
    s.set_user_summoner(user);
    enemy=s.create_summoner("P", p, "Enemy_Summoners");
    Immoral_Troop troop2;
    enemy.summon(&troop2);
    s.set_enemy_summoner(enemy);
    Object ob;
    ob.Summoner=s.get_ptr_user_summoner();
    ob.Troop=nullptr;
    qq.push(ob, ob.Summoner->get_initiative());
    Object ob1;
    ob1.Summoner=s.get_ptr_enemy_summoner();
    ob1.Troop=nullptr;
    qq.push(ob1, ob1.Summoner->get_initiative());
    ASSERT_EQ(qq.top().Summoner->get_name(), ob.Summoner->get_name());
    s.get_User_Summoner().get_troops(0)->set_initiative(2);
    s.push_queue(nullptr, s.get_User_Summoner().get_troops(0), qq);//в класс ландшафт
    ASSERT_EQ(qq.top().Troop->get_initiative(), 2);
   ob1= s.move_queue(qq);
    ASSERT_EQ(ob1.Troop->get_initiative(), 2);
}
TEST (Lanscape_Methods, Summon_Diffrenet_Troops){
    Landscape L;
    vector<pair<string, unsigned int> > p;
    Summoner User;
    User=L.create_summoner("MM", p, "User_Summoner");
    Creature cr("Po", 5, 7, 1);
    School* sch = nullptr;
    Coordinates p0(0, 0);
    laba4::Ordinary_Troop tr(3,5, 4, 2, 10, cr, sch, p0);
    Immoral_Troop* I=&tr;
    //ASSERT_EQ(I->get_moral(), 5);
    ASSERT_EQ(I->get_initiative(), 3);
    ASSERT_EQ(I->get_p().x, 0);
    ASSERT_EQ(I->get_p().y, 0);
    ASSERT_EQ(I->get_count(), 10);
    ASSERT_EQ(I->get_speed(), 4);
    ASSERT_EQ(I->get_damage(), 50);
    ASSERT_EQ(I->get_health(), 10);
    ASSERT_EQ(I->get_experience(), 2);
    ASSERT_EQ(I->get_protection(), 70);
    ASSERT_EQ(I->get_creature().get_health(), 1);
    ASSERT_EQ(I->get_creature().get_name(), "Po");
    ASSERT_EQ(I->get_creature().get_damage(), 5);
    ASSERT_EQ(I->get_creature().get_protection(), 7);
    ASSERT_EQ(I->get_ptr_school(), nullptr);
   
    
}
int main(int argc, char * argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


