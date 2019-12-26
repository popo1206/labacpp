//
//  Resurrecting_Troop.h
//  laba4
//
//  Created by Полина Подчуфарова on 20/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//
/*!
 \file
 \brief Header file with Ordinary Resureecting Troop discription
 
 It is a derived class from Ordinary_Troops class
 */

#ifndef OResurrecting_Troop_h
#define OResurrecting_Troop_h
#include "Ordinary_Troop.h"
namespace laba4 {
    /*!
     \brief  Ordinary Resureecting Troop class:
     Troop consist from some creatures from one school and one skill
     It is a derived class from Ordinary_Troop class
     */
    class OResurrecting_Troop:public Ordinary_Troop{
    private:
        unsigned dead_creatures;///<number of dead creatures  which you can ressurect
    public:
        //getters
        unsigned get_dead_creatures()const {return dead_creatures;}
         virtual string get_type() const {return "Oresurrecting_Troop";}
        //setters
        OResurrecting_Troop& set_dead_creatures(unsigned d_cr){
            dead_creatures=d_cr;
            return *this;
        }
        //constructors
     OResurrecting_Troop():Ordinary_Troop(){dead_creatures=0;}//default construction
        OResurrecting_Troop(unsigned initiative0,unsigned dead_creatures0,unsigned moral,unsigned speed0,unsigned experience0, unsigned count0, Creature cr, School* sch,Coordinates p0):
        Ordinary_Troop(initiative0 ,moral,speed0,experience0, count0,cr, sch, p0){
            dead_creatures=dead_creatures0;
        }
        OResurrecting_Troop(const OResurrecting_Troop&);//copying
        //methods
        OResurrecting_Troop& operator=(const OResurrecting_Troop&);
       void resurrect_creatures();
        virtual ostream& print(ostream& s) const;
    };
}

#endif /* Resurrecting_Troop_h */
