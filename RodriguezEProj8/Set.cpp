//  Set.cpp
//  RodriguezEProj8
//  Created by Eduardo Rodriguez on 4/18/23.
//

#ifndef SET_CPP
#define SET_CPP
#include "Set.hpp"
#include <iostream>
#include <cstdlib>

template<class T>
Set<T>::Set(int max){
    size_of_Set=0;
    max_capacity=max;
    pointer_of_Set= new T[max];
}

/*
template<class T>
Set<T>::~Set(){
    delete [] pointer_of_Set;
    size_of_Set = 0;
 pointer_of_Set =0;
    //cout<< "The default destructor has been invoked" << endl;
}*/

template<class T>
void Set<T>:: add_item(T new_item){
    int length= size_of_Set;
    
    if (length == max_capacity){ // add storage for 10 more itmes to max_capacity
       
        
         Set<T> newArray(length+10);
        for (int i=0; i< length; i++)
        {
            newArray.pointer_of_Set[i]= pointer_of_Set[i];
        }
        T* temp_pointer= pointer_of_Set;
        pointer_of_Set= newArray.pointer_of_Set;
        delete [] temp_pointer;
         
        //cout<< "ERROR: This Set is already full!";
    }
    if (!(is_member(new_item))){
        pointer_of_Set[length]= new_item;
        size_of_Set++;
    }
};

template<class T>
void Set<T> :: remove_item(T target_item){
    if (is_member(target_item))
    {int length = size_of_Set;
        int location= search(target_item);
        
        for(int i= location; i <size_of_Set-1; i++)
        {
            pointer_of_Set[i] = pointer_of_Set[i + 1];
        }
        Set<T> newArray(length-1);
        for (int i=0; i < length-1; i++)
            {newArray.pointer_of_Set[i] = pointer_of_Set[i];}
        T *temp_pointer= pointer_of_Set;
        pointer_of_Set= newArray.pointer_of_Set;
        delete [] temp_pointer;
        size_of_Set--;
    }
    else {cout <<target_item<< " is not part of the Set"<< endl;}
}

template<class T>
int Set<T>:: get_size(){
    return size_of_Set;
}

template<class T>
bool Set<T>::is_member(T target_item){
    bool present = false;
    for(int i=0; i <size_of_Set; i++){
        if (target_item== pointer_of_Set[i])
        {
            return true;
        }
    }
    return present;
}

template<class T>
int Set<T>::search (T target_item){
    int location= -1;
    for (int i=0; i< size_of_Set; i++)
    {
        if (target_item == pointer_of_Set[i])
        {location= i;}
    }
    return location;
}

template<class T>
T* Set<T>:: get_pointer(){// returns pointer to Set
    return pointer_of_Set;
}

#endif // SET_CPP
