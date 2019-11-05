//
//  main.cpp
//  laba3b_main
//
//  Created by Полина Подчуфарова on 27/10/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <iostream>
#include "BinaryB.h"
#include "menu.h"
using namespace laba3;
using namespace menu;

int main(int argc, const char * argv[]) {
    int q = 0;
    print("Какой экземляр класса хотите создать?");
    print("1) С постоянным уровнем сигнала 0/1 на максимальную длительность ");
    print("2) С инициализацией сигналом как строки символов");
    print("3) Пустой конструктор");
    // print("4) Продолжить работу с инициализироанным экземпляром ");
    int kk=0;
    input(kk);
    
    switch (kk) {
        case 1: {
            bool b;
            menu::input_lev(b);
            laba3::Signal c(b);
            do{
                int  d = dialog();
                menu_t(d,c);
                print("Enter 0 for exit");
                input(q);
            } while (q);
            break;
        }
        case 2: {
            laba3::Item *ch;
            print("Input signal");
            input_k(&ch);
            laba3::Signal c(ch);
            do{
                int  d = dialog();
                menu_t(d,c);
                print("Enter 0 for exit");
                input(q);
            } while (q);
            break;
        }
        case 3: {
            laba3::Signal c;
            do{
                int  d = dialog();
                menu_t(d,c);
                print("Enter 0 for exit");
                input(q);
            } while (q);
            break;
        }
            
        default: {
            print("incorrect choice");
        }
    }
    
    return 0;
}

