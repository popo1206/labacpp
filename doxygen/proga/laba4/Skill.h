//
//  Skill.h
//  laba4
//
//  Created by Полина Подчуфарова on 20/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//
/*!
 \file
 \brief Header file with Skill discription
 */
#ifndef Skill_h
#define Skill_h
#include "Creature.h"
#include <iostream>
using namespace std;
namespace laba4{
    /*!
     \brief  Skill class:
     This class describes one skill from school
     */
class Skill {
    
private:
    string name;///< name of skill
    unsigned energy;///< energy which you need to summon the troops from cretures fron this skill
    unsigned min_knowledge;///< min knowledge which summoner should have about school of this skill to summon
    unsigned coefficient;///< coefficient of count
    Creature creature;///< creture in this skill
public:
    //constructors
    Skill():name(""),energy(0),min_knowledge(0),coefficient(0){
    }
    Skill(string name0,unsigned energy0, unsigned min_knowledge0,unsigned coeficient0,const Creature &cr):name(name0),energy(energy0),min_knowledge(min_knowledge0),coefficient(coeficient0),creature(cr){
    }
    Skill(const Skill&);//copying
    Skill(Skill&&);//moving
    //getters
    string get_name() const { return name;}
    unsigned get_min_knowledge() const {return min_knowledge;}
    unsigned get_coefficient() const {return coefficient;}
    unsigned get_energy() const {return energy;}
    Creature get_creature () const {return creature;}
    //setters
    Skill& set_name(string name0) { name=name0; return *this;}
    Skill& set_min_knowledge(unsigned min_knowledge0){if (min_knowledge0>=0) min_knowledge=min_knowledge0; return *this;}
    Skill& set_coefficient(unsigned coeficient0) {if (coeficient0>=0)  coefficient=coeficient0;return *this;}
    Skill &set_creature (Creature creature0)  {creature =creature0; return *this;}
    Skill& set_energy(unsigned energy0){if (energy0>=0) energy=energy0; return *this;}
    //methods
    Skill& operator =(const Skill&);
    friend ostream& operator <<(ostream& s, const Skill& sk);
};
}
#endif /* Skill_h */
