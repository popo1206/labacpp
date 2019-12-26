//
//  Creature.h
//  laba4
//
//  Created by Полина Подчуфарова on 20/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//
/*!
 \file
 \brief Header file with Creature discription
 */
#ifndef Creature_h
#define Creature_h
#include <iostream>
using namespace std;
namespace laba4{
    /*!
     \brief  Creature class:
     This class describes one creature from skill
     */
class Creature {
   
private:
    string name;///<name of creture
    unsigned damage;///<damage of this creature
    unsigned protection;///<protection of this creature
    unsigned health;///< health of this creature
public:
    //getters
    string get_name()  const{return name;}
    unsigned get_damage() const {return damage;}
    unsigned get_protection()  const{return protection;}
    unsigned get_health ()const {return health;}
    //setters
    Creature& set_name(string name0){ name=name0; return *this; }
    Creature& set_damage(unsigned damage0){if (damage0>=0) damage=damage0; return *this;}
    Creature& set_protection(unsigned protection0){if (protection0>=0) protection=protection0; return *this;}
    Creature& set_health (unsigned health0){if (health0>=0) health=health0; return *this;}
    //constructors
    Creature():name(""), damage(0),protection(0),health(0){}
    Creature(string name0, unsigned damage0,unsigned protection0, unsigned health0 );
    Creature(const Creature &cr);//copying construction
    Creature (Creature &&cr);//moving construction
    //methods
    
    Creature& operator =(const Creature& cr);
    friend ostream& operator <<(ostream& s,const Creature& cr);
};
}
#endif /* Creature_h */
