//
//  school.h
//  laba4
//
//  Created by Полина Подчуфарова on 19/11/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//
/*!
 \file
 \brief Header file with Schools discription
 
 */
#ifndef school_h
#define school_h
#include <iostream>
#include <vector>
#include "Skill.h"
using namespace std;
namespace laba4 {
    /*!
     \brief  School class:
    This class describes one school structure
     */
class School{
private:
    string name;///< name of school
    vector<Skill> data;///< vector of skills which are in this one school
    string school_dominant;///<name of school which you are dominated
    unsigned number_creatures;///< number of creatures
public:
    //constructors
    School():name(""),school_dominant(""),number_creatures(0){Skill data;}
    School(string name0,string school_dominant0, unsigned number_creatire0,vector<Skill> data0){
        name=name0;
        school_dominant=school_dominant0;
        number_creatures=number_creatire0;
        for (int i=0;i<data0.size();i++){
            data.push_back(data0[i]);
        }
    }
    School(const School&);//copping
    School(School &&);// moving
    ~School(){
        name="";
        school_dominant="";
        number_creatures=0;
        data.clear();
    }
    //getters
    string get_name() const { return name;}
    string get_school_dominant()const  { return school_dominant;}
    unsigned get_number_creatures()const { return number_creatures;}
    Skill get_data(int k) const { return data[k];}
    __SIZE_TYPE__ get_size_of_data() const{return data.size();}
    //setters
    School &set_name(string nm){ name=nm; return *this;}
    School & set_school_dominant(string sc_dm) {  school_dominant=sc_dm; return *this;}
    School &set_number_creatures(unsigned numb){if (numb>=0) number_creatures=numb; return *this;}
    School& set_data(Skill& sk){data.push_back(sk); return *this; }
    //methods
   School& add_skill(Skill&);
    friend ostream& operator <<(ostream& s, const School& sch);
    School& operator=(const School& sch);
    
};
}
#endif /* school_h */
