//
//  menu.h
//  laba2
//
//  Created by Полина Подчуфарова on 01/10/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//
#include <iostream>
#include "Cycloid.h"
#ifndef menu_h
#define menu_h

namespace menu{
    template<class T>
    void print(T a) {
        std::cout << a << std::endl;
    }
    
    template <class T>
    int input(T& a) {
        int r = 0;
        do {
            std::cin >> a;
            if (std::cin.eof()) {
                std::cin.clear();
                return -1;
            }
            if (!std::cin.good()) {
                std::cin.clear();
                while (std::cin.get() != '\n');
                r++;
            }
            else r = 0;
        } while (r);
        return r;
    }
    int dialog();
    void menu_t(int, Prog2::Cycloid&);
}

#endif /* menu_h */
