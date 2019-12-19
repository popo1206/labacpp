//
//  menu.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 09/12/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <stdio.h>
#include "Landscape.h"
#include "OResurrecting_Troop.h"
#include "IResurrecting_Troop.h"
#include "Ordinary_Troop.h"
using namespace std;
int get_char(char& str) {
    
    int r = 0;
    do {
        std::cin >> str;
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
int dialog() {
    cout<<"?-User or Enemy Summoner"<<endl;
    cout<<"choose a task"<<endl;
    cout<<"w-game loading"<<endl;//+
    cout<<"q-output map"<<endl;//+
    cout<<"e-output school tab "<<endl;//+
    cout<<"c-summon menu"<<endl;
    cout<<"g- move menu"<<endl;
    cout<<"r-accumulate energy"<<endl;//+
    cout<<"s-save current state of the game"<<endl;//+
    char  d ;
    get_char(d);
    return d;
}

void menu_t(char d,laba4::Landscape &L) {
    laba4::Summoner S;
    switch (d) {
        case '?':{
            char sim;
            cout<<"Enter + if user and - if enemy Summoner"<<endl;
            cin>>sim;
            if (sim=='+') S=L.get_User_Summoner();
            if (sim=='-') S=L.get_Enemy_Summoner();
            if (!(sim=='+')||(sim=='-')) cout<<"You are debil."<<endl;
        }
        case 'w': {
            int k;
            cout<<"Choose:"<<endl;
            cout<<"1.Input map"<<endl;
            cout<<"2.Genertion map"<<endl;
            do{
                cin>>k;
                if (k==1) {
                    try{
                        L.input_map();}
                    catch(exception &ex){
                        cout<<ex.what()<<endl;
                    }
                    
                }
                if (k==2){
                    int m,n,wall,emptyness;
                    cout<<"Enter size of map m*n"<<endl;
                    cout<<"m: "; cin>>m; cout<<endl;
                    cout<<"n: "; cin>>n; cout<<endl;
                    cout<<"Enter number of walls: "; cin>>wall; cout<<endl;
                    cout<<"Enter number of emptyness: "; cin>>emptyness; cout<<endl;
                    L.generation_map(m, n, wall, emptyness);
                }
                if (!(k==1)||(k==2))
                    cout<<"Your input incorrect.Input again."<<endl;
            }while ( !((k==1)||(k==2)));
            vector<pair<string, unsigned>> school;
            pair<string,unsigned> s;
            string name;
            laba4::Summoner ss;
            try{
            L.read_school();
            for (int i=0;i<5;i++){
                s.first=L.get_School(i).get_name();
                s.second=0;
                school.push_back(s);
            }
            cout<<"Enter name of your Summoner: "; cin>>name;
                try{
                    L.create_summoner(ss,name, school, "User_Summoner");
            L.set_user_summoner(ss);
                }
                catch(exception &x){
                    cout<<x.what()<<endl;
                }
            cout<<"Enter name of Enemy Summoner: "; cin>>name;
                try{
                    L.create_summoner(ss,name, school, "Enemy_Summoners");
            L.set_enemy_summoner(ss);
                }
                catch(exception &x){
                    cout<<x.what()<<endl;
                }
            }
            catch (exception &ex){
                cout<<ex.what()<<endl;
            }
            break;
        }
        case 'q': {
            L.print_map();
            break;
        }
        case 'e': {
            L.print_summoner();
            L.print_school();

            break;
        }
        case 'c':{//summon menu
            int d2;
            laba4::School *sch;
            laba4:: Skill sk;
            laba4::Immoral_Troop *tr;
            cout<<"From what school do you want summon?"<<endl;
            cout<<"1.necromancy"<<endl;
            cout<<"2.animalism"<<endl;
            cout<<"3.demonology"<<endl;
            cout<<"4.other_realities"<<endl;
            cout<<"5.elementalis"<<endl;
            cin>>d2;
            switch (d2) {
                case 1:{
                    sch=L.find_school("necromancy");
                    break;
                }
                case 2:{
                    sch=L.find_school("animalism");
                    break;
                }
                case 3:{
                    sch=L.find_school("demonology");
                    break;
                }
                case 4:{
                    sch=L.find_school("other_realities");
                    break;
                }
                case 5:{
                    sch=L.find_school("elemantalis");
                    break;
                }
                    
                default:{
                    sch=nullptr;
                    cout<<"Incorrect choise"<<endl;
    
                }
            }
            try{
              
                L.choose_skill(sch,sk,S);
                
            }
            catch(exception &ex){
                cout<<ex.what()<<endl;
            }
            cout<<"What troop do you want summon?"<<endl;
            cout<<"1.Immoral Troop"<<endl;
            cout<<"2.Ordinary Troop"<<endl;
            cout<<"3.Ressurecting Ordinary Troop"<<endl;
            cout<<"4.Ressurecting Immoral Troop"<<endl;
            int d1;
          
            cin>>d1;
            switch (d1){
                case 1:{
                    laba4::Coordinates p(0,0);
                 tr=new laba4::Immoral_Troop(1,1,0,10,sk.get_creature(),sch,p);
                    break;
                }
                case 2:{
                    break;
                    
                }
                case 3:{
                    
                }
                case 4:{
                    
                }
            }
           S.summon(tr);//Summoner destructor suka
        }
        case 'g':{//move menu
            break;
        }
        case 'o':{
            L.get_User_Summoner().set_experience(10);
            try {
                int exp,d;
                std::cout<<"Your experience:" << L.get_User_Summoner().get_experience() << std::endl;
                std::cout <<"Enter count of experience:" << std::endl;
                cin>>exp;
                string a;
                std::cout <<"Choose school:" << std::endl;
                std::cout << "1 - animalism " << std::endl;
                std::cout << "2 - demonology" << std::endl;
                std::cout << "3 - elementalism" <<std::endl;
                std::cout << "4 - necromancy" << std::endl;
                std::cout <<"5 - other_realities" << std::endl;
                cin>>d;//check
                if (d == 1) {
                    a = "animalism";
                }
                if (d == 2) {
                    a = "demonology";
                }
                if (d == 3) {
                    a = "elementalism";
                }
                if (d == 4) {
                    a = "necromancy";
                }
                if (d == 5) {
                    a = "other_realities";
                }
               // L.school_upgrade(L.get_User_Summoner(),a,exp);
            }
            
            catch (std::exception & ex)
            {
             cout << ex.what() << endl;
        }
            break;
        }
        case 'r':{
            try{
           // L.energy_accumulation(L.get_User_Summoner());
            }
            catch (exception &ex){
                cout<<ex.what()<<endl;
            }
            break;
        }
    case's':{
        try{
        L.fprint_Summoner();
        L.fprint_map();
        L.fprint_school();
        }
        catch(exception &ex){
            cout<<ex.what()<<endl;
        }
            
        }
            
        default: {
            cout<<"incorrect choice"<<endl;
        }
    }
}
    int main(int argc, const char * argv[]){
        laba4::Landscape c;
        string q;
        do{
            int  d = dialog();
            menu_t(d,c);
            cout<<"Enter exit for exit"<<endl;;
           cin>>q;
        } while (q!="exit");
         return 0;
    }


