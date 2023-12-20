//
//  Set.hpp
//  RodriguezEProj8
//
//  Created by Eduardo Rodriguez on 4/18/23.
//

#ifndef Set_hpp
#define Set_hpp
#include <iostream>
using namespace std;


template <class T>
class Set
{
public:
    Set(int max);// constructs an instance of the class Set with a max capacity
    //~Set(); // destructor that returns all dynamic memory to freestore
    
    void add_item(T new_item); // add a new item at the end to the Set
    void remove_item(T target_item); // removes a target item if present in Set
    int get_size();// returns the size of the set
    bool is_member(T target_item); // returns true if item is in Set
    int search(T target_item); // returns index of target item  else returns -1
    T* get_pointer();
    friend ostream& operator << (ostream& COUT, const Set<T> the_Set){ // prints out onto screen the list inside the Set
        for (int i=0; i< the_Set.size_of_Set; i++)
        {COUT<< the_Set.pointer_of_Set[i]<< endl;}
        return COUT;
    }
    
private:
    T* pointer_of_Set; // pointer to dynamic array
    int size_of_Set; // size of set
    int max_capacity; // max capacity
};



#endif /* Set_hpp */
