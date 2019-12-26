//
//  Landsccape.h
//  laba4
//
//  Created by Полина Подчуфарова on 19/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//
/*!
 \file
 \brief Header file with Landscape and cell discription
 This file has classes: cell: a part of Landscape, Lanscape, and class Object
 */

#ifndef Landscape_h
#define Landscape_h
#include <string>
#include "Summoner.h"
#include "School.h"
#include <vector>
#include "Priorety_Queue.h"

using namespace std;

namespace laba4 {
/*! All types of the cell like part of Landcape*/
    enum cell0 {
        POINT,///<Just a floor
        EMPTYNESS,///<Emptyness: barrier
        WALL,///<Wall :barrier
        EMPTY_CELL///This cell is busy  with object
        
    };
    /*! All types of the object in a cell which can move */
    enum object0 {
        USER_SUMMONER,///<User Summoner
        ENEMY_SUMMONER,///<Enemy Summoner
        USER_TROOP,///<User Troops
        ENEMY_TROOP,/// Enemy Troops
        EMPTY_OBJECT/// In this cell no object
        
    };
    /*! \brief This clss describes one cell of the map
     */
    class Cell {
    private:
        cell0 cell;///< Type of a cell
        object0 object;///< Type if a object on a cell
    public:
        //getters
        ///get value of part of Landscape in this cell
        cell0 get_cell(){return cell;}
        ///get value of object in this cell
        object0 get_object(){return object;}
        /// default construction
        Cell(){cell=EMPTY_CELL; object=EMPTY_OBJECT;}
        /// main constructor
        Cell(char);
        //setters
        /// change value of part of Landscape in this cell
        Cell& set_cell(cell0 c) {cell=c; return *this;}
        ///change value of object in this cell
        Cell& set_object(object0 o) {object=o; return *this;}
        ///operator of output of the cell
        friend ostream&  operator << (ostream& s, const Cell &a){
            if (a.cell==POINT)  cout<<'.';
            if (a.cell==WALL)  cout<<'#';
            if (a.cell==EMPTYNESS) cout<<' ';
            if (a.object==USER_SUMMONER)  cout<<'@';
            if (a.object==ENEMY_SUMMONER)  cout<<'*';
            if (a.object==USER_TROOP)  cout<<'U';
            if (a.object==ENEMY_TROOP)  cout<<'E';
            return s;
        }
        
    };
    /*! \brief class Object
     like struct for keeping ptr on object in queue
     Summoner or Troop
     */
    class Object{
    public:
        Summoner* Summoner;///< pointer on Summoner
        Immoral_Troop* Troop;///<pointer on Troop
    };
   /*! \brief class Landscape describes a map and two users in this game

    */
    class Landscape {
    private:
        int m;///< Size of map in width
        int n;///< Size of map in length
       vector <School> tab_schools;///<This vector has all schools in this game
        Summoner User_Summoner;///<This is one gamer
        Summoner Enemy_Summoner;///<This is another gamer
       vector<vector <Cell>> rectangle;///< This vector of vectors keep map.
    public:
       ///default construction
        Landscape():m(0),n(0) {
            Summoner User_Summoner;
            Summoner Enemy_Summoner;
        }
        ///main construction
        Landscape(Summoner User, Summoner Enemy);
        ///copying construction
        Landscape(const Landscape&);
        ///destructor
        ~Landscape(){
            tab_schools.clear();
            rectangle.clear();
            m=0;
            n=0;
        }
        //getters
        /// get number cells by X
        int get_n() const { return n; }
        ///get number cells by Y
        int get_m() const { return m; }
        ///get copy of User Summoner
        Summoner get_User_Summoner() const {return User_Summoner;}
        ///get copy of Enemy Summoner
        Summoner get_Enemy_Summoner() const {return Enemy_Summoner;}
        ///get cell in map
        Cell get_cell(int i,int j) const {return rectangle[i][j];}
        /// get element of school
        School get_School(int i) const { return tab_schools[i];}
        vector<School> get_all_school() const {return tab_schools;}
        vector<vector <Cell>> get_rectangle() const {return rectangle;}
        Summoner * get_ptr_user_summoner()  {return &User_Summoner;}
         Summoner * get_ptr_enemy_summoner() {return &Enemy_Summoner;}
        
        //setters
        Landscape& set_n(int n0) {if (n0>=0) n=n0; return *this; }
        Landscape& set_m(int m0) {if (m0>=0)m=m0; return *this; }
        Landscape& set_user_summoner(Summoner& s){User_Summoner=s; return *this;}
        Landscape& set_enemy_summoner(Summoner& s){Enemy_Summoner=s; return *this;}
        Landscape& set_tab_school(School sc){ tab_schools.push_back(sc); return *this;}
        Landscape& set_rectangle(Coordinates p0,Cell x){rectangle[p0.y][p0.x].set_cell(x.get_cell());
            rectangle[p0.x][p0.y].set_object(x.get_object()); return *this;}
         //functions
        friend ostream& operator <<(ostream& s, const  Landscape &a);
        ///generate map with 4 values m n and number of walls and emptyness
        void generation_map(int,int,int,int);
        ///input map from file "input_file" and read size of map
        void input_map(const string fname);
        ///create summoner from files and input in function vector with school knowledge
        void create_summoner(Summoner&, string,vector<pair<string,unsigned>>&,const string);
        ///get info about school in school's tab
        void read_school();
        ///input: school//do: this function is usied in read_school where info read from files which are named like schools
        void read_skill(School&);
        ///input: name of school // do: find school by name //output: ptr on this object
        School* find_school(string);
        ///input: ptr  on summoner //do: install the troop which is in the end of vector near the summoner
        void install_troop_in_cell(Summoner*);
        ///input: ptr on summoner, ptr on troop and queue//do: push new object with initiative
         void push_queue(Summoner* s,Immoral_Troop* tr, Try_To_Be_Smart::Priorety_Queue<Object,unsigned>& qq);
        ///input: queue of summoners and troops//do: delete first object from queue
        Object& move_queue(Try_To_Be_Smart::Priorety_Queue<Object,unsigned>& qq);
        ///output map
        void print_map();
        ///input: char is direction of moving// do: move troop// output: move =1,stay =1
        int move_troop(char ch,Immoral_Troop*);
        ///output info about to summoners
        void print_summoner();
        ///output info about schools
        void print_school();
        /// save info about schools
       void fprint_school();
        ///save skills used in fprint_schools
       void fprint_skill(School&);
        ///save map in file
        void fprint_map();
        ///save summoners
        void fprint_Summoner();
        ///input: summoner with his vector of knowledge, name of school,point of upgrade//do: upgrade school
        void school_upgrade(Summoner&,string,int);
        ///input: Summoner// do:accumulate summoner energy on 10 points * accumulation coefficient
        void energy_accumulation(Summoner &);
        ///input: ptr on school from what we choose skill, skill which is choosed, summoner //do: choose skiill
        void choose_skill(School*,Skill &sk,Summoner &);
       
    };
}
#endif /* Landsccape_h */
