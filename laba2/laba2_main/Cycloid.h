//
//  cycloid.h
//  laba2
//
//  Created by Полина Подчуфарова on 22/09/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//для определения класса 

#ifndef Cycloid_h
#define Cycloid_h
#include <math.h>
//#include <iostream>
const double pi = 3.1415926535;
namespace Prog2{
    struct Point {
        double x;
        double y;
        Point (double x0 = 1,double y0 = 0):x(x0),y(y0){}
    };
    class Cycloid{
    private:
        Point p;//точка
        double r;//радиус окружности
    public :
        //конструкторы
          Cycloid(double rad=1);
          Cycloid(const Point &p0,double rad=1);
          Cycloid(double x0,double y0,double rad=1);
        //сеттеры
        Cycloid& setP(const Point &p0){p=p0;return *this;}
        Cycloid& setR(double r0);
        //геттеры
        Point getP() const {return p;}
        double getR() const {return r;}
        //другие методы
        double coordinate_x(double t) const {return r*(t-cos(t))+p.x;}//точка x от угла поворота порождающего круга
        double coordinate_y(double t) const {return r*(1-cos(t))+p.y;}//точка y от угла поворота порождающего круга
        double radius_krivisna(double t) const {return 4*r*abs(sin(t/29));}//радиус кривизны от угла поворота порождающего круга
        double length (double t) const {return 4*r*(1-cos(t/2));}///длина циклоиды от угла поворота порождающего круга
        double full_area() const {return 3*pi*r*r; }//полная площадь
        double area_osn() const {return 64/3*pi*r*r;}//площадь поверхности вращения циклоиды вокруг основания
        double volume() const {return 5*pi*pi*r*r*r;}//объем тела вращения
        double create_agle(double t0){ return ((t0*pi)/180);}
        
    };
};


#endif /* cycloid_h */
