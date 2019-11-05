//
//  menu.cpp
//  laba3
//
//  Created by Полина Подчуфарова on 12/10/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//
#include <stdio.h>
#include "Binary.h"
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
        int d = 0;
        input(d);
        return d;
    }
    
    void menu_t(int d,laba3::Signal &c) {
        switch (d) {
            case 1: {
                int k;
                std::cout<<"Input number of singals from 1 to "<<c.getBMAX_SIZE()<<std::endl;
                std::cin>>k;
                for (int i=0;i<k;i++){
                    bool b;
                    int dur;
                    input_lev(b);
                    std::cout<<"Input duration"<<std::endl;
                    input(dur);
                    try{
                        if ((dur>255)||(dur<=0)) throw std::exception();
                        c.input_signal(b,dur);
                    }
                    catch (std::exception){
                        std::cout<<"Error duration"<<std::endl;
                    }
                    
                }
                   c.create();
                break;
            }
            case 2: {
                c.output_signal();
               
                break;
            }
            case 3: {
                c.invert();
                break;
            }
            case 4: {
                Item *ch;
                print("Enter signal");
                input_k(&ch);
                laba3::Signal c1(ch);
                try {
                c.add_signal(c1);
                }
                catch(std::exception &er){
                    std::cout<<er.what()<<std::endl;
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
                try {
                input(t);
                if (t<0) throw std::runtime_error("Time can't be <0");
                try{
                c.adding_another_signal(t,c1);
                }
                catch (std::exception &er){
                    std::cout<<er.what()<<std::endl;
                }
                }
                catch(std::exception &ex){
                    std::cout<<ex.what()<<std::endl;
                }
                break;
            }
            case 6: {
                int k;
                print("Enter  number of copies");
                try {
                input(k);
                    if (k<=0) throw std::runtime_error("Copies can't be <=0");
                try {
                c.copy(k);
                }
                catch (std::exception &er){
                    std::cout<<er.what()<<std::endl;
                }
                }
                catch (std::exception &ex){
                    std::cout<<ex.what()<<std::endl;
                }
                break;
            }
            case 7: {
                try {
                int t,dur;
                print("Enter time");
                input(t);
                print("Enter duration");
                input(dur);
                    if ((t<0)||(dur<=0)) throw  std::runtime_error("Time or duration is incorrect");
                try {
                c.delete_fragment(t, dur);
                }
                catch (std::exception &er){
                    std::cout<<er.what()<<std::endl;
                }
                } catch (std:: exception &ex){
                    std::cout<<ex.what()<<std::endl;
                }
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

