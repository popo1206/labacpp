//
//  Landscape.cpp
//  laba4
//
//  Created by Полина Подчуфарова on 21/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#include <stdio.h>
#include "Landscape.h"
#include <iostream>
#include <fstream>
using namespace std;
namespace  laba4{
    Cell::Cell(char m){
        if (m=='.'){cell=POINT; object=EMPTY_OBJECT;}
        if (m==' '){cell=EMPTYNESS;  object=EMPTY_OBJECT;}
        if (m=='#'){cell=WALL;  object=EMPTY_OBJECT;}
        if (m=='@'){cell=EMPTY_CELL;  object=USER_SUMMONER;}
        if (m=='*'){cell=EMPTY_CELL;  object=USER_SUMMONER;}
        if (m=='U'){cell=EMPTY_CELL;  object=USER_TROOP;}
        if (m=='E'){cell=EMPTY_CELL;  object=ENEMY_TROOP;}
    }
    
    Landscape::Landscape(Summoner User, Summoner Enemy){
      User_Summoner=User;
      Enemy_Summoner=Enemy;
    }
  
    
    ostream& operator <<(ostream& s, const Landscape& a){
            cout<<a.User_Summoner<<endl;
            cout<<a.Enemy_Summoner<<endl;
            for (int i=0;i<a.m;i++){
                for (int j=0;j<a.n;j++){
                    cout<<a.rectangle[i][j];
                }
                cout<<endl;
            }
            return s;
    }
    Landscape::Landscape(const Landscape& L){
        n=L.get_n();
        m=L.get_m();
        User_Summoner=L.get_User_Summoner();
        Enemy_Summoner=L.get_Enemy_Summoner();
        rectangle=L.get_rectangle();
        tab_schools=L.get_all_school();
    }
    
    void Landscape::generation_map(int m,int n, int walls,int emptyness){
        Landscape::m=m;
        Landscape::n=n;
        for (int j=0;j<m;j++){
            vector<Cell> p(n);
        for(int i=0;i<n;i++){
            p[i]=Cell('.');
        }
            rectangle.push_back(p);
        }
        while (walls){
            int i=rand() % m ;
            int j=rand() % n ;
            rectangle[i][j].set_cell(WALL);
            walls--;
        }
         while (emptyness){
             int i=rand() % m +1;
             int j=rand() % n +1;
            rectangle[i][j].set_cell(EMPTYNESS);
             emptyness--;
         }
        rectangle[User_Summoner.get_coordinates().x][User_Summoner.get_coordinates().y].set_cell(EMPTY_CELL);
        rectangle[User_Summoner.get_coordinates().x][User_Summoner.get_coordinates().y].set_object(USER_SUMMONER);
        rectangle[Enemy_Summoner.get_coordinates().x][Enemy_Summoner.get_coordinates().y].set_cell(EMPTY_CELL);
        rectangle[Enemy_Summoner.get_coordinates().x][Enemy_Summoner.get_coordinates().y].set_object(ENEMY_SUMMONER);
    }
    void Landscape:: input_map(){
        ifstream fs1("input_map");
        if (!fs1.is_open()) throw  runtime_error("File can't open!");
        char ch;
        fs1>>n;
        fs1>>m;
        while (fs1.get(ch)){
            vector<Cell> p;
            for (int i=0;i<n;i++){
            if (fs1.get(ch)){
            Cell c(ch);
            p.push_back(c);
            }
            }
            rectangle.push_back(p);
        }
        fs1.close();
        rectangle[User_Summoner.get_coordinates().x][User_Summoner.get_coordinates().y].set_cell(EMPTY_CELL);
        rectangle[User_Summoner.get_coordinates().x][User_Summoner.get_coordinates().y].set_object(USER_SUMMONER);
        rectangle[Enemy_Summoner.get_coordinates().x][Enemy_Summoner.get_coordinates().y].set_cell(EMPTY_CELL);
        rectangle[Enemy_Summoner.get_coordinates().x][Enemy_Summoner.get_coordinates().y].set_object(ENEMY_SUMMONER);
    }
    
   
    Summoner Landscape::create_summoner(string name, vector<pair<string,unsigned>> knowledge, const string fname){
        Summoner S;
        unsigned initiative;
        unsigned health;
        unsigned energy;
        unsigned experience;
        unsigned accumulation_coeficient;
        Coordinates p0(0,0);
        ifstream fst1(fname);
        if (!fst1.is_open()) throw runtime_error ("File can't open");
        S.set_name(name);
        fst1>>initiative;
        S.set_initiative(initiative);
        fst1>>health;
        S.set_health(health);
        fst1>>energy;
        S.set_energy(energy);
        fst1>>experience;
        S.set_experience(experience);
        fst1>>accumulation_coeficient;
        S.set_accumulation_coeficient(accumulation_coeficient);
        fst1>>p0.x;
        fst1>>p0.y;
        S.set_coordinates(p0);
        for (int i=0;i<knowledge.size();i++){
            fst1>>knowledge[i].second;
            S.set_knowledge(knowledge[i]);
        }
        return S;
    }
    void Landscape:: read_school(){
          ifstream school("School");
        if (!school.is_open()) throw runtime_error("File can't open!");
        while  (!school.eof()){
            School S;
            string name;
            string school_dominant;
            unsigned number_creatures;
            school>>name;
            S.set_name(name);
            school>>school_dominant;
            S.set_school_dominant(school_dominant);
            school>>number_creatures;
            S.set_number_creatures(number_creatures);
            try{
            read_skill(S);
            tab_schools.push_back(S);
            }
            catch(exception &ex){
                throw ex;
            }
        }
        school.close();
    }
    void Landscape::read_skill(School & S){
        Skill skill;
        ifstream Sk(S.get_name());
        if (!Sk.is_open()) throw runtime_error("File can't open!");
        while (!Sk.eof()){
            string name;
            unsigned energy;
            unsigned min_knowledge;
            unsigned coefficient;
            Creature creature;
            string creature_name;
            unsigned damage;
            unsigned protection;
            unsigned health;
            Sk>>name;
            skill.set_name(name);
            Sk>>energy;
            skill.set_energy(energy);
            Sk>>min_knowledge;
            skill.set_min_knowledge(min_knowledge);
            Sk>>coefficient;
            skill.set_coefficient(coefficient);
            Sk>>creature_name;
            creature.set_name(creature_name);
            Sk>>damage;
            creature.set_damage(damage);
            Sk>>protection;
            creature.set_protection(protection);
            Sk>>health;
            creature.set_health(health);
            skill.set_creature(creature);
            S.set_data(skill);
        }
        Sk.close();
    }
    
    School* Landscape:: find_school(string name){
        for (int i=0;i<tab_schools.size();i++){
            if (tab_schools[i].get_name()==name)
                return &tab_schools[i];
        }
        return nullptr;
    }
   
    void Landscape:: install_troop_in_cell(){
        Coordinates p(0,0);
        p=User_Summoner.get_coordinates();
        unsigned long k=User_Summoner.get_size_of_troops();
        if (rectangle[p.x+1][p.y+1].get_object()==EMPTY_OBJECT){
                rectangle[p.x+1][p.y+1].set_object(USER_TROOP);
                Coordinates pp(p.x+1,p.y+1);
                User_Summoner.get_troops(k-1)->set_p(pp);
        }
        if (rectangle[p.x][p.y+1].get_object()==EMPTY_OBJECT){
                rectangle[p.x][p.y+1].set_object(USER_TROOP);
                Coordinates pp(p.x,p.y+1);
                User_Summoner.get_troops(k-1)->set_p(pp);
        }
        if (rectangle[p.x][p.y-1].get_object()==EMPTY_OBJECT){
                rectangle[p.x][p.y-1].set_object(USER_TROOP);
                Coordinates pp(p.x,p.y-1);
                User_Summoner.get_troops(k-1)->set_p(pp);
        }
        if (rectangle[p.x+1][p.y].get_object()==EMPTY_OBJECT){
                rectangle[p.x+1][p.y].set_object(USER_TROOP);
                Coordinates pp(p.x+1,p.y);
                User_Summoner.get_troops(k-1)->set_p(pp);
        }
        if (rectangle[p.x-1][p.y].get_object()==EMPTY_OBJECT){
                rectangle[p.x-1][p.y].set_object(USER_TROOP);
                Coordinates pp(p.x-1,p.y);
                User_Summoner.get_troops(k-1)->set_p(pp);
        }
    }
    void Landscape:: push_queue(Summoner* s,Immoral_Troop* tr, Try_To_Be_Smart::Priorety_Queue<Object,unsigned>& qq){
        Object ob;
        ob.Summoner=s;
        ob.Troop=tr;
      if (s!=nullptr)  qq.push(ob,ob.Summoner->get_initiative());
      if (tr!=nullptr)  qq.push(ob,ob.Troop->get_initiative());
    }
    Object& Landscape:: move_queue( Try_To_Be_Smart::Priorety_Queue<Object,unsigned>& qq){
        Object ob;
        ob=qq.top();
        qq.pop();
        if (ob.Summoner!=nullptr)  qq.push(ob,ob.Summoner->get_initiative());
        if (ob.Troop!=nullptr)  qq.push(ob,ob.Troop->get_initiative());
        return ob;
    }
    void Landscape:: print_map(){
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                cout<<rectangle[i][j];
            }
            cout<<endl;
        }
    }

    void Landscape::move_troop(char ch,Immoral_Troop *tr){
         int k=User_Summoner.get_size_of_troops();
        if (ch=='W'){
                if ((tr->get_p().y+1)<=m-1){
                if ((rectangle[tr->get_p().y+1][tr->get_p().x].get_cell()==POINT)&&(rectangle[tr->get_p().y+1][tr->get_p().x].get_object()==EMPTY_OBJECT)){
                        Coordinates p;
                        p.x=tr->get_p().x;
                        p.y=tr->get_p().y+1;
                        rectangle[tr->get_p().y][tr->get_p().x].set_object(EMPTY_OBJECT);
                        rectangle[tr->get_p().y][tr->get_p().x].set_cell(POINT);
                        rectangle[tr->get_p().y+1][tr->get_p().x].set_cell(EMPTY_CELL);
                        rectangle[tr->get_p().y+1][tr->get_p().x].set_object(USER_TROOP);
                        tr->set_p(p);
            }
                else throw runtime_error("There is a barrier.");
            }
            else throw runtime_error("Can't move there.End of map");
        }
        if (ch=='D'){
            if ((tr->get_p().x+1)<=n-1){
                if ((rectangle[tr->get_p().y][tr->get_p().x+1].get_cell()==POINT)&&(rectangle[tr->get_p().y][tr->get_p().x+1].get_object()==EMPTY_OBJECT)){
                        Coordinates p;
                        p.x=tr->get_p().x+1;
                        p.y=tr->get_p().y;
                        rectangle[tr->get_p().y][tr->get_p().x+1].set_object(USER_TROOP);
                        rectangle[tr->get_p().y][tr->get_p().x].set_object(EMPTY_OBJECT);
                        rectangle[tr->get_p().y][tr->get_p().x].set_cell(POINT);
                        rectangle[tr->get_p().y][tr->get_p().x+1].set_cell(EMPTY_CELL);
                        tr->set_p(p);
                } else throw runtime_error("There is a barrier.");
            }
            else throw runtime_error("Can't move there.End of map");
        }
        if (ch=='S'){
            if ((tr->get_p().y-1)>=0){
                if ((rectangle[tr->get_p().y-1][tr->get_p().x].get_cell()==POINT)&&(rectangle[tr->get_p().y-1][tr->get_p().x].get_object()==EMPTY_OBJECT)){
                        Coordinates p;
                        p.x=tr->get_p().x;
                        p.y=tr->get_p().y-1;
                        rectangle[tr->get_p().y-1][tr->get_p().x].set_object(USER_TROOP);
                        rectangle[tr->get_p().y][tr->get_p().x].set_object(EMPTY_OBJECT);
                        rectangle[tr->get_p().y][tr->get_p().x].set_cell(POINT);
                        rectangle[tr->get_p().y-1][tr->get_p().x].set_cell(EMPTY_CELL);
                        tr->set_p(p);
                } else throw runtime_error("There is a barrier.");
            }
            else throw runtime_error("Can't move there.End of map");
        }
        if (ch=='A'){
            if ((tr->get_p().x-1)>0){
                 if ((rectangle[tr->get_p().y][tr->get_p().x-1].get_cell()==POINT)&&(rectangle[tr->get_p().y][tr->get_p().x-1].get_object()==EMPTY_OBJECT)){
                        Coordinates p;
                        p.x=tr->get_p().x-1;
                        p.y=tr->get_p().y;
                        rectangle[tr->get_p().y][tr->get_p().x-1].set_object(USER_TROOP);
                        rectangle[tr->get_p().y][tr->get_p().x].set_object(EMPTY_OBJECT);
                        rectangle[tr->get_p().y][tr->get_p().x].set_cell(POINT);
                        rectangle[tr->get_p().y][tr->get_p().x-1].set_cell(EMPTY_CELL);
                        tr->set_p(p);
                 }  else throw runtime_error("There is a barrier.");
            }
            else throw runtime_error("Can't move there.End of map");
    }
        tr->move_troop();
        }
    }
