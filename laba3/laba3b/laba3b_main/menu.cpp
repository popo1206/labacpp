//
//  menu.cpp
//  laba3b_main
//
//  Created by Полина Подчуфарова on 27/10/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <stdio.h>
#include "BinaryB.h"
#include "menu.h"

using namespace laba3;
namespace menu {
    int input_k(Item **ch){
        char buf[81], *str;
        Item head = {true, NULL };
        Item *last = &head;
        int n,rc = 1;
        do{
            std::cin>>buf;
            n=std::cin.good();
            
            if(n < 0){
                delete(head.next);
                head.next = NULL;
                rc = 0;
                continue;
            }
            
            if(n > 0){
                for(str = buf; *str != '\0'; ++str){
                    last->next = new Item;
                    last = last->next;
                    if (static_cast<int>(*str)-48==1){
                        last->c=true;
                        last->next = nullptr;
                        n=0;
                    }
                    else {
                        if (static_cast<int>(*str)-48==0){
                            last->c=false;
                            last->next = nullptr;
                            n=0;
                        }
                        else{
                            std::cout<<("Eror, you should enter 1 or 0")<<std::endl;
                            delete(head.next);
                            head={true, NULL };
                            last = &head;
                            rc = 0;
                            n=1;
                        }
                    }
                    
                }
                
            }
            else
                scanf("%*c");
        } while(n > 0);
        *ch = head.next;
        return rc;
    }
    
    
    int dialog() {
        print("choose a task");
        print("1) Ввод экземпляров класса");
        print("2) Вывод экземпляров класса");
        print("3) Инвертировать сигнал");
        print("4) Дополнение сигнала другим сигналом");
        print("5) Вставка в определенный момент времени (тип int) другого сигнала");
        print("6) Копирование сигнала определнное число раз");
        print("7) удаление фрагмента сигнала в определенное время (тип int) определенной длительности");
        print("8) проверить оператор =");

        int d = 0;
        input(d);
        return d;
    }
    
    void menu_t(int d,laba3::Signal &c) {
        switch (d) {
            case 1: {
                try { std::cin >> c; }
                catch (std::exception &ex)
                {
                    std::cout << ex.what() << std::endl;
                }
                break;
            }
            case 2: {
                std::cout << c;
                break;
            }
            case 3: {
           !c;
                break;
            }
            case 4: {
                Item *ch;
                print("Enter signal");
                input_k(&ch);
                laba3::Signal c1(ch);
                try {
                c+=c1;
                }
                catch (std::exception &ex){
                    std::cout<<ex.what()<<std::endl;
                }
                break;
            }
            case 5: {
                int t;
                Item *ch;
                print("Enter signal");
                input_k(&ch);
                laba3::Signal c1(ch);
                print("Enter time");
                input(t);
                try{
                    c(t,c1);
                }
                catch (std::exception &ex){
                    std::cout<<ex.what()<<std::endl;
                }
                break;
            }
            case 6: {
                int k;
                print("Enter  number of copies");
                input(k);
                try {
                c(k);
                }
                catch (std::exception &ex){
                    std::cout<<ex.what()<<std::endl;
                }
                break;
            }
            case 7: {
                int t,dur;
                print("Enter time");
                input(t);
                print("Enter duration");
                input(dur);
                try {
                    c(t,dur);
                }
                catch (std::exception &ex){
                    std::cout<<ex.what()<<std::endl;
                }
                break;
            }
            case 8:{
              laba3::Signal s1;
              std::cin >> s1;
                c=s1;
                break;
            }
                
            default: {
                print("incorrect choice");
            }
        }
    }
    void input_lev(bool& b){
        int k,m=0;
        std::cout<<"Input level"<<std::endl;
        do {
            std::cin>>k;
            if (k==1){ b=true; m=0;}
            if (k==0) {b=false; m=0;}
            if ((k!=0)&&(k!=1)) {
                std::cout<<("incorrect entering")<<std::endl;
                m=1;
            }
        }while (m==1);
    }
}

