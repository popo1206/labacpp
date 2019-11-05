//
//  Binary.cpp
//  laba3
//
//  Created by Полина Подчуфарова on 11/10/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//task 3//var 6

#include <stdio.h>
#include "Binary.h"
namespace laba3{
   
    Signal:: Signal(Item *ch){//здесь нада  из сигнала 1100100101 превраратитьв стурктуру
        int k=0;
        n=0;
        if (ch){
                BSignal[k].level=ch->c;
                BSignal[k].duration=1;
                n++;
                }
        ch=ch->next;
        while ((ch)){
            if (BSignal[k].level==(ch->c))
                BSignal[k].duration++;
            else {
                k++;
                BSignal[k].level=(ch->c);
                BSignal[k].duration=1;
                n++;
                if (n==SZ) return;
            }
            ch=ch->next;
           
        }
    }
    void Signal:: output_signal() const{
        for (int i=0;i<n;i++){
            if (BSignal[i].level==true) std::cout<<"-";
            else std::cout<<"_";
            std::cout<<"("<< static_cast<int>(BSignal[i].duration)<<")";
        }
        std::cout<<std::endl;
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
        Signal& Signal:: input_signal(bool b,int dur){
            if (n!=SZ){
                BSignal[n].level=b;
                BSignal[n].duration=dur;
                n++;
            }
            return *this;
        }
            Signal &  Signal:: invert (){
                for (int i  = 0; i < n; i++){
                    BSignal[i].level=!BSignal[i].level;
                }
                return *this;
            }
    Signal& Signal:: add_signal(Signal &c){
            if ((c.n+n)>SZ) throw std::runtime_error("Too long signal");
        if ((c.n+n)<=SZ) {
            if ( BSignal[n-1].level==c.getBSignal(0).level) {
                if ((static_cast<int>(BSignal[n-1].duration)+static_cast<int>(c.getBSignal(0).duration))>255 )throw std::runtime_error("Too long duration");
                 BSignal[n-1].duration= BSignal[n-1].duration+c.getBSignal(0).duration;
                for (int i=1;i<c.getn();i++){
                    BSignal[i+n-1].level= c.getBSignal(i).level;
                    BSignal[i+n-1].duration= c.getBSignal(i).duration;
                }
                n=n+c.getn()-1;
            }
            else{
            for (int i=0;i<c.getn();i++){
                
                BSignal[i+n].level= c.getBSignal(i).level;
                BSignal[i+n].duration= c.getBSignal(i).duration;
            }
            n=n+c.getn();
            }
        }
        
        return *this;
    }
    Signal & Signal:: adding_another_signal(int t, Signal& c){
        int t0=t;
        int i0=0;
        
            if (n+c.n>SZ) throw std::runtime_error("Too long input signal");
        //вставка в начало
        if (t==0) {
            for (int j=n-1;j>=0;j--){//смещение
                BSignal[j+c.getn()].level=BSignal[j].level;
                BSignal[j+c.getn()].duration=BSignal[j].duration;
            }
            for (int j=0;j<c.getn();j++){//вставка
                BSignal[j].level=c.getBSignal(j).level;
                 BSignal[j].duration=c.getBSignal(j).duration;
            }
            n=n+c.n;
            create();
            return *this;
        }
        
        for (int i=0; i<n;i++){
            int per=(int)BSignal[i].duration;
            t0=t0-per;
            if (t0<=0){
                i0=i;
                break;
                    }
        }
            if(t0>0) throw std::runtime_error("Too long time");
       
        //вставка в конец
        if ((t0==0)&&(i0==n-1)){
            add_signal(c);
            return *this;
        }
        //вставка без разбиения
        if (t0==0){
            int k=0;
            for (int j=n-1;j>i0;j--){//смещение
                BSignal[j+c.getn()].level=BSignal[j].level;
                BSignal[j+c.getn()].duration=BSignal[j].duration;
            }
            for (int j=i0+1;j<=i0+c.n;j++){//вставить
                BSignal[j].level=c.getBSignal(k).level;
                 BSignal[j].duration=c.getBSignal(k).duration;
                k++;
            }
            n=n+c.n;
            create();
            return *this;
        }
        //разбиение
        int k=0;
        BSignal[i0].duration=static_cast<int>(BSignal[i0].duration)+t0;
        for (int j=n-1;j>i0;j--){//смещение
            BSignal[j+c.getn()+1].level=BSignal[j].level;
            BSignal[j+c.getn()+1].duration=BSignal[j].duration;
        }
        for (int j=i0+1;j<=i0+c.getn();j++){//вставка
            BSignal[j].level=c.getBSignal(k).level;
            BSignal[j].duration=c.getBSignal(k).duration;
            k++;
        }
        BSignal[i0+1+c.getn()].level= BSignal[i0].level;
        BSignal[i0+1+c.getn()].duration=-t0;
        n=n+c.n+1;
        create();
        return *this;
    }
    void Signal:: check_dur(unsigned char ch1, unsigned char ch2){
      int ich1=(int)ch1;
        int ich2=(int)ch2;
        int k= ich1+ich2;
        if (k>255) throw std::runtime_error("Too long duration") ;
    }
    Signal & Signal:: create (){
        for (int i=0;i<n-1;i++){
            if (BSignal[i].level==BSignal[i+1].level){
                try {
                    check_dur( BSignal[i].duration, BSignal[i].duration);
                    BSignal[i].duration=BSignal[i].duration+BSignal[i+1].duration;
                    for (int j=i+1;j<n-1;j++){
                        BSignal[j].level=BSignal[j+1].level;
                        BSignal[j].duration=BSignal[j+1].duration;
                    }
                    n--;
                }
                catch (std::exception &er){
                    std::cout<<er.what()<<std::endl;
                }
               
            }
        }
        return *this;
    }
    Signal & Signal::copy (int k){
        int n0=n;
        if (n*k>=SZ) throw std::runtime_error("Too many copies for memory");
         if (n!=1){
        while (k){
            for (int i=0;i<n0;i++){
                BSignal[i+n].level=BSignal[i].level;
                BSignal[i+n].duration=BSignal[i].duration;
            }
            n=n+n0;
            k--;
            }
            create();
        }
        if (n==1) {
            if (static_cast<int>(BSignal[0].duration)*k>255) throw std::runtime_error("Too long dur");
            BSignal[0].duration=static_cast<int>(BSignal[0].duration)*k;
        }
        return *this;
    }
    Signal & Signal::delete_fragment(int t,int dur){
       int t_begin=t;
        int t_end=t+dur;
       int i_begin=0;//номер сигнала 1 удалеямого элемента
        int i_end=0;// номер сигнала последнего удаляемого элемент
        int dur0=dur;
        if (t==0){
            int i=0;
            int h=0;
            while (dur0>0){
                dur0 =dur0-static_cast<int>(BSignal[i].duration);
                i++;
            }
            if (dur0!=0){
                BSignal[i-1].duration=-dur0;
                BSignal[0].duration=BSignal[i-1].duration;
                BSignal[0].level=BSignal[i-1].level;
                h=1;
            }
            
            if ((i-1)!=0){
                for (int j=i;j<n;j++){
                    BSignal[h].level=BSignal[j].level;
                    BSignal[h].duration=BSignal[j].duration;
                    h++;
                }
            n=h;
            }
            return *this;
        }
        
        for (int i=0; i<n;i++){
            int per=static_cast<int>(BSignal[i].duration);
            t_end=t_end-per;
            if ((t_end<0)||(t_end==0)){
                 i_end=i;
                break;
            }
        }
        if ((t_end>0)) throw std::runtime_error("Too long time or duration");
        for (int i=0; i<n;i++){
            int per=(int)BSignal[i].duration;
            t_begin=t_begin-per;
            if ((t_begin<0)||(t_begin==0)){
                i_begin=i;
                BSignal[i_begin].duration= BSignal[i_begin].duration+t_begin;
                break;
            }
        }
       
        if ((i_end)==(i_begin)) {
            return *this;
        }
        
        if (t_end==0) {
            if (i_end!=n-1)
            i_end++;
            else{  for (int k=i_begin+1;k<=i_end;k++)
                n--;
                return *this;
            }
            
        }
        else  BSignal[i_end].duration=-t_end;
        int h=1;
        
        if (((i_end-i_begin)>1)||(t_begin==0)){
            for (int i=i_end;i<n;i++){
            BSignal[i_begin+h].level=BSignal[i].level;
            BSignal[i_begin+h].duration=BSignal[i].duration;
                h++;
            }
             n=i_begin+h;
        }
        create();
        return *this;
    }
    
    
}
