//
//  menu.cpp
//  laba2
//
//  Created by Полина Подчуфарова on 01/10/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <stdio.h>
#include "Cycloid.h"
#include "menu.h"
namespace menu {
    int dialog() {
        print("choose a task");
        print("1 - return coordinates by adle");
        print("2 - return radius crivizna");
        print("3 - length cycloid by adle");
        print("4 - return full area");
        print("5 - return surface area of cycloid rotation around its base");
        print("6 - volume");
        print("7 - input new parametrs");
        int d = 0;
        input(d);
        return d;
    }
    
    void menu_t(int d, Prog2::Cycloid& c) {
        switch (d) {
            case 1: {
                 std::cout <<"Enter  t>=0 for calculate coordinates x and y  "<<std::endl;
                double r,t;
                Prog2::Point a;
               
                input(t);
                if (t<0)  throw std::exception();
                t=c.create_agle(t);
                try {
                    a.x=c.coordinate_x(t);
                    a.y=c.coordinate_y(t);
                    std::cout<<"x="<<a.x<<" y="<<a.y<<std::endl;
                }
                catch (std::exception &ex)
                {
                    std::cout << ex.what()<<std::endl;
                }
                std::cin.clear();
                break;
            }
            case 2: {
                 std::cout <<"Enter  t >=0 for calculate  radius krivizna  "<<std::endl;
                 double t;
                input(t);
                 if (t<0)  throw std::exception();
                t=c.create_agle(t);
                try {
                    std::cout<<"radius krivizna: "<<c.radius_krivisna(t)<<std::endl;
                }
                catch (std::exception &ex)
                {
                    std::cout << ex.what()<<std::endl;
                }
                std::cin.clear();
                break;
            }
            case 3: {
                    std::cout <<"Enter  t>=0 for calculate length  "<<std::endl;
                    double r,t;
                    Prog2::Point a;
                    r= c.getR();
                   input(t);
                   if (t<0)  throw std::exception();
                    t=c.create_agle(t);
                    std::cout<<"length: "<<c.length(t)<<std::endl;
                    std::cin.clear();
                    break;
                }
            case 4: {
                    std::cout<<"full area: "<<c.full_area()<<std::endl;
                    break;
                }
            case 5: {
                 std::cout<<"area : "<<c.area_osn()<<std::endl;
                 break;
                }
            case 6: {
                std::cout<<"volume : "<<c.volume()<<std::endl;
                break;
                }
            case 7: {
                Prog2:: Point p;
                double r;
                std::cout<<"Enter new x,y,r to continue "<<std::endl;
                std::cin>>p.x>>p.y>>r;
                if (std::cin.good()){
                        c.setP(p);
                        try{
                            c.setR(r);
                        }
                        catch (std::exception &ex){
                            std::cout <<ex.what()<<std::endl;
                        }
                }
                std::cin.clear();
                break;
            }
            default: {
                print("incorrect choice");
            }
        }
    }
}
