//
//  main.cpp
//  laba1_2.0
//
//  Created by Полина Подчуфарова on 17/09/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//
#include <iostream>
#include "Prog1.h"
using namespace Prog1;

int main() {
    Matrix *array=nullptr;
    array=new Matrix;
    array->vec=nullptr;
    array=input(*array);
    if (!array){
        std::cout<<"error"<<std::endl;
        return 1;
    }
    output(array);
    int *b=new int[array->m_line];
    for (int i=1;i<=array->m_line;i++){
        b[i]=0;
    }
    
     b=create(*array, b);
     showVec(b,array->m_line);
    sort_main(b,array->m_line);
    showVec(b,array->m_line);
    Delete(*array);
    return 0;
}
