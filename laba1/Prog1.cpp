//
//  Prog1.cpp
//  laba1_2.0
//
//  Created by Полина Подчуфарова on 17/09/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//
#include "Prog1.h"
#include <iostream>
namespace Prog1{
    Matrix *input(Matrix &array){
        Matrix *head=&array;
         Vecs *tmp=nullptr;
        int it,i,j,k;
         int *a_buf;
        const char *pr="";//the message of system down
        do{ std::cout <<pr<<std::endl;
            std::cout<<"Enter number of lines-->";
            pr="You are wrong;repeat please!";
            if (getNum(array.m_line)<0)//the mistake of input or ending of file
                return nullptr;
        } while (array.m_line<1);
        pr="";
        do{ std::cout <<pr<<std::endl;
            std::cout<<"Enter number of vecs-->";
            pr="You are wrong;repeat please!";
            if (getNum(array.n_col)<0)//the mistake of input or ending of file
                return nullptr;
        } while (array.n_col<1);
        do {
                a_buf=new int[array.n_col+1];
                for(int i=1;i<=array.n_col;i++){
                    a_buf[i]=0;
            }
            pr="";
            do{  std::cout<<pr<<std::endl;
                std::cout<<"Enter  line :"<<std::endl;
                 std::cout<<"i= ";
            if (getNum(i)<0)
                return nullptr;
                pr="Error. repeat entering please";
            } while ((i>array.m_line)||(find_line(head,i))||(i<1));
            
            do{ pr="";
            do {std::cout<<pr<<std::endl;
                std::cout<<"Enter col for line="<<i<<":"<<std::endl;
                std::cout<<"j= ";
                    if (getNum(j)<0)
                return nullptr;
              pr="Error.Repeat entering please";
                if (a_buf[j]!=0)
                    j=array.n_col+1;
           } while  ((j>array.n_col)||(j<1));
                pr="";
                do {std::cout<<pr<<std::endl;
                    std::cout<<"Enter for a["<<i<<"]["<<j<<"] non-zero item: "<<std::endl;
            if (getNum(a_buf[j])<0)
                return nullptr;
                     pr="Error.Repeat entering please";
                }while (a_buf[j]==0);
                std::cout<<"Enter 0 if you want to stop entering items "<<std::endl;
                getNum(it);
            }while (it!=0);
          
            //формируем структуру
            if (!array.vec){
                array.vec=new Vecs;
                array.vec->elem=nullptr;
                array.vec->i=i;
                tmp=array.vec;
                tmp->next=nullptr;
                Elem *ptr=nullptr;
                for (int s=1;s<=array.n_col;s++){
                    if (a_buf[s]!=0) {
                        if (!array.vec->elem){
                            tmp->elem=new Elem;
                            tmp->elem->j=s;
                            tmp->elem->item=a_buf[s];
                            ptr =tmp->elem;
                            ptr->next=nullptr;
                        } else {
                            ptr->next=new Elem;
                            ptr=ptr->next;
                            ptr->next=nullptr;
                            ptr->j=s;
                            ptr->item=a_buf[s];
                        }
                    }
            
                }
                
            } else
            { tmp=input_line(&array,i);
                if ((tmp==array.vec)&&(tmp->i>i)){
                     //если надо вставить на место первого элемента в списке
                    array.vec=new Vecs;
                    array.vec->i=i;
                    array.vec->elem=nullptr;
                    array.vec->next = tmp;
                    tmp = array.vec;
                    
                    
                } else {
                       if (tmp->next){
                           Vecs* tmp1=tmp->next;
                           Vecs* tmp2=new Vecs;
                           tmp2->i=i;
                           tmp2->elem=nullptr;
                           tmp->next=tmp2;
                           tmp=tmp->next;
                           tmp->next=tmp1;
                       }
                       else {
                           tmp->next=new Vecs;
                           tmp->next->elem=nullptr;
                           tmp->next->i=i;
                           tmp=tmp->next;
                           tmp->next=nullptr;
                           
                       }
                }
                Elem *ptr=nullptr;
                for (int s=1;s<=array.n_col;s++){
                    
                    if (a_buf[s]!=0) {
                        if (!tmp->elem){
                            tmp->elem=new Elem;
                            tmp->elem->j=s;
                            tmp->elem->item=a_buf[s];
                            ptr =tmp->elem;
                            ptr->next=nullptr;
                           
                        } else {
                            
                            ptr->next=new Elem;
                            ptr=ptr->next;
                            ptr->next=nullptr;
                            ptr->j=s;
                            ptr->item=a_buf[s];}
                    }
                   
                }
    
                
            }
            
            delete []a_buf;
            std::cout<<"Enter -1 if you want to stop entering lines"<<std::endl;
            getNum(k);
        }while (k!=-1);
       
       
        return head;
    }
    void output (Matrix *arr){
        Vecs* array=arr->vec;
        while (array){
                    Elem *ptr=array->elem;
                    std::cout<<" line :"<<array->i<<" ";
                while (ptr){
                        std::cout<<" Col :"<<ptr->j<<" item: "<<ptr->item;
                       ptr=ptr->next;
                        }
                std::cout<<" "<<std::endl;
                array=array->next;
            }
        
    }
    int *create(Matrix &array,int *b){
        Vecs *tmp=array.vec;
       
       
       while ((tmp)&&(tmp->next)){
            Elem *ptr=tmp->elem;
                        if (tmp->i+1==tmp->next->i){
                                      while (ptr){
                                            int k=find(*tmp->next,ptr->item);
                                            if (k==1) b[tmp->i]++;
                                            ptr=ptr->next;
                                
                        }
        
    } else {
        while (ptr){
         ++b[tmp->i];
        ptr=ptr->next;
        
           }
       
        
    }
            tmp=tmp->next;
        }
        if (!tmp->next){
              Elem *ptr=tmp->elem;
            //int not_null=0;
            if ((tmp==array.vec)||(array.vec->i!=1)){
                while(ptr){
                    b[tmp->i]++;
                    ptr=ptr->next;
                  
                }
            }else{
                if (array.vec->i==1){
                    while(ptr){
                        int k=find(*array.vec,ptr->item);
                        if (k==1) b[tmp->i]++;
                        ptr=ptr->next;
                        }
                    
                }
                }
        }
        return b;
    }
    
    int find(Vecs &tmp,int a){
        Elem *ptr=tmp.elem;
        while (ptr){
           if (ptr->item==a) return 0;
            ptr=ptr->next;
        }
        return 1;
    }
    void showVec(int *b,int n) {
        std::cout<<"Our vector:"<<std::endl;
        for (int i=1;i<=n;i++){
            std::cout<<b[i]<<" ";
        }
        std::cout<<std::endl;
    }
 
    int sort_main(int *b,int n){
        if (b[1]==b[2]) return 0;
        if (b[1]>b[2]){
            b=sort_max_to_min(b,n);
            return 1;
        };
        if(b[1]<b[2]) {
            b=sort_min_to_max(b,n);
            return 1;
        }
        return 1;
    }
    int * sort_max_to_min(int *arr,int n){
        // Сортировка массива пузырьком
        for (int i = 1; i <= n ; i++) {
            for (int j = 1; j <= n - i ; j++) {
                if (arr[j] < arr[j + 1]) {
                    // меняем элементы местами
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;}
            }
        }
        return arr;
    }
    int* sort_min_to_max(int *arr,int n){
        for (int i = 1; i <= n ; i++) {
            for (int j = 1; j <= n - i ; j++) {
                if (arr[j] > arr[j + 1]) {
                    // меняем элементы местами
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;}
            }
        }
        return arr;
    }
    void erase(Matrix &arr){
       
        delete[] arr.vec->elem;
      delete[] arr.vec;
        std::cout<<"Deleted"<<std::endl;
        
    }
    Vecs * input_line(Matrix *a,int i){
        Vecs *tmp=a->vec;
        Vecs* prev=a->vec;
        
        while (tmp){
            if (tmp->i>i) return prev;
            prev=tmp;
            tmp=tmp->next;
            
        }
        return prev;
    }
    int find_line(Matrix *a,int i){
        Vecs* tmp=a->vec;
        while (tmp){
            if (tmp->i==i) return 1;
            tmp=tmp->next;
        }
        return 0;
    }
    void Delete(int* a) // for arrrays
    {
        delete[] a;
    }
    void Delete( Matrix &a) // for the whole matrix
    {
        if (a.vec) {
            //Vecs*ptr = a.vec;
            while ((a.vec->next)&&(a.vec)) {
                Delete(a.vec->next->elem);
                delete a.vec->next->elem;
                a.vec->next->elem = nullptr;
                Vecs* buf = a.vec->next->next;
                int i = a.vec->next->i;
                delete a.vec->next;
                a.vec->next = buf;
                std::cout << i << " line deleted." << std::endl;
            }
            Delete(a.vec->elem);
            int i = a.vec->i;
            delete a.vec;
            a.vec = nullptr;
            std::cout << i << " line deleted." << std::endl;
        }
    }
    void Delete(Elem* a) //for the lin of the matrix
    {
        while ((a->next)&&(a)&&(a->next->next)) {
            Elem*buf = a->next->next;
            delete a->next;
            a->next = buf;
        }
    }
}

