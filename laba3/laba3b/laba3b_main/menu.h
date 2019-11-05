//
//  menu.h
//  laba3b_main
//
//  Created by Полина Подчуфарова on 27/10/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <iostream>
#include "BinaryB.h"
#ifndef menu_h
#define menu_h
using namespace laba3;
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
    void menu_t(int,laba3:: Signal&);
    int input_k(Item **);
    void input_lev(bool& b);
}
#endif /* menu_h */

