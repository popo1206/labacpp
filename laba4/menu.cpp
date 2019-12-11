//
//  menu.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 09/12/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <stdio.h>
#include "Landscape.h"
using namespace std;
int dialog() {
    cout<<"choose a task"<<endl;
    cout<<"1.create map"<<endl;
    cout<<"2.read information about Summoners and schools"<<endl;
    cout<<"3.output map "<<endl;
    cout<<"4.output school info"<<endl;
    cout<<"5.summon troop"<<endl;
    cout<<"6.make a step"<<endl;
    int d = 0;
    cin>>d;
    return d;
}

void menu_t(int d,laba4::Landscape &L) {
    switch (d) {
        case 1: {
            int k;
            cout<<"Choose:"<<endl;
            cout<<"1.Input map"<<endl;
            cout<<"2.Genertion map"<<endl;
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
            if ((k!=1)&&(k!=2)) cout<<"You are wrong"<<endl;
            break;
        }
        case 2: {
            vector<pair<string, unsigned>> school;
            pair<string,unsigned> s;
            string name;
            try{
            L.read_school();
            for (int i=0;i<5;i++){
                s.first=L.get_School(i).get_name();
                s.second=0;
                school.push_back(s);
            }
            cout<<"Enter name of your Summoner: "; cin>>name;
                try{
            L.create_summoner(name, school, "User_Summoner");
                }
                catch(exception &x){
                    cout<<x.what()<<endl;
                }
            cout<<"Enter name of Enemy Summoner: "; cin>>name;
                try{
            L.create_summoner(name, school, "Enemy_Summoners");
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
        case 3: {
            L.print_map();
            break;
        }
        case 4: {
            
            break;
        }
      
            
        default: {
            cout<<"incorrect choice"<<endl;
        }
    }
}
    int main(int argc, const char * argv[]){
        laba4::Landscape c;
        int q;
        do{
            int  d = dialog();
            menu_t(d,c);
            cout<<"Enter 0 for exit"<<endl;;
           cin>>q;
        } while (q);
         return 0;
    }


