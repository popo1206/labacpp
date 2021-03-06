//
//  Header.h
//  laba3
//
//  Created by Полина Подчуфарова on 09/10/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//
#include <iostream>
#ifndef Binar_h
#define Binar_h
namespace laba3{
    struct Binary {
        bool level;
        char unsigned duration;
    };
    struct Item{
        bool c;
        struct Item *next;
    };
    class Signal{
    private:
        static const int SZ=10;
        Binary BSignal[SZ];
        int n;//кол-во имеющихся сигналов
    public:
        Signal (int n0=0){n=n0;}
        Signal (bool k, char unsigned dur=255,int n0=1){ BSignal[0].level=k;n=n0; BSignal[0].duration=dur;}
        Signal (Item *);
        //сеттер
        Signal& setBSignal(const Binary &p0,int k){BSignal[k]=p0;return *this;}
        //геттеры
         Binary getBSignal(int k) const {return  BSignal[k];}
         const int getBMAX_SIZE() const {return SZ ;}
        int getn() const  {return n;}
        //методы
        Signal& input_signal(bool,int);// ввод экземпляров класса
        void output_signal() const;//вывод экзмепляров классса
        Signal & invert ();//инвертировать сигнал
        Signal & add_signal(Signal&);//дополнение сигнала другим сигналом
        Signal & adding_another_signal(int,Signal &);//вставка в опрделенный момент времени t
        Signal & copy(int);
        Signal &create();
        void check_dur(unsigned char,unsigned char);
        Signal & delete_fragment(int,int);
    };
};
#endif /* Header_h */
