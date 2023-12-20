//
//  main.cpp
//  RodriguezEProj8
//
//  Created by Eduardo Rodriguez on 4/18/23.
//

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "Set.hpp"
#include "Set.cpp"

using namespace std;


int main() {
    Set<int> int_Set(1); // testing Set of Integers
    int_Set.add_item(0);
    int_Set.add_item(1);
    int_Set.add_item(2);
    int_Set.add_item(2); // Testing if duplicates will be ommited from being added
   
    
    cout<< "After attempting to add \"0, 1, 2, 2\" to the Int Set, the size is " << int_Set.get_size()<< endl;
    cout<< "It consists of: \n" << int_Set;
    cout<< endl << endl;
    
    cout<<"2 is member: "<< int_Set.is_member(2)<<" : meaning True"<< endl;// 1 means true
    cout<<"5 is member: "<<int_Set.is_member(5)<<" : meaning False"<< endl; // 0 means false
    cout<< endl << endl;

    Set<char> char_Set(5); // testing Set of Characters
    char_Set.add_item('H');
    char_Set.add_item('E');
    char_Set.add_item('L');
    char_Set.add_item('L');
    char_Set.add_item('O');
    
    cout<< "Our "<< char_Set.get_size() <<" char Set consist of: \n"<< char_Set;
    cout<< endl;

    cout<< "The index of 'O' is "<< char_Set.search('O')<< endl;
    cout<< endl;

    char_Set.remove_item('I');
    char_Set.remove_item('O');
    cout<< "After removing 'O', we end up with: \n"<<  char_Set;
    
    cout<< "Pointer to char Set prints out: "<< char_Set.get_pointer()<< endl << endl;
    
    return 0;
}
