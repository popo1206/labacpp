//
//  cycloid.cpp
//  laba2
//
//  Created by Полина Подчуфарова on 22/09/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//реализация класса Cyclo



#include <strstream>
#include <exception>
#include <stdio.h>
#include <string.h>
#include "Cycloid.h"
 
namespace Prog2 {
    Cycloid ::Cycloid(double rad) :p(0,0)
    {
    if (rad<0)
        throw std::exception();
        r=rad;
    }
    Cycloid ::Cycloid(const Point&p0,double rad) :p(p0)
    {
        if (rad<0)
            throw std::exception();
        r=rad;
    }
    Cycloid ::Cycloid(double x0,double y0,double rad) :p(x0,y0)
    {
        if (rad<0)
          throw std::exception();
        r=rad;
    }
    
    Cycloid &Cycloid:: setR (double r0)
    {
        if (r0<0)
          throw std::exception();
        r=r0;
        return *this;
    }
   
    
    
    }
