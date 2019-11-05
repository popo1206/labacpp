//
//  Prog1.h
//  laba1_2.0
//
//  Created by Полина Подчуфарова on 17/09/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//
#include <iostream>

namespace Prog1{
    struct Elem {
        int j;//номер столбца
        int item;//значение элемента
        struct Elem *next;
    };
    struct Vecs{
        int  i;//номер строки
        struct Elem *elem;
        struct Vecs *next;
    };
    struct Matrix{
        int m_line;//кол-во строк
        int n_col;//кол-во столбцов
        struct Vecs *vec;//
        
    };
    inline int getNum(int &a)
    {
        std::cin>>a;
        if (!std::cin.good())
            return -1;
        return 1;
    };
    Matrix *input(Matrix &);//ввод м-цы, столбцов и строк
    void output( Matrix *);// вывод матрицы на экран*/
    int find(Vecs&, int);
    int *create(Matrix &,int *);
    void showVec(int *b,int n);
    int sp_count_of_elements(Vecs* tmp);
    void sort (Vecs *tmp);
    int *sort_max_to_min(int *b,int n);
    int *sort_min_to_max(int *b,int n);
    int sort_main(int *b,int n);
    int find_line(Matrix *a,int i);
    void Delete( Matrix &a);
    void Delete(  Elem *);
    void Delete( Vecs*);
    Vecs* input_line(Matrix*,int);
    Vecs * input_line1(Vecs tmp,int i);
}
