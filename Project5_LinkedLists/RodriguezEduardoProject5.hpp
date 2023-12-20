// Provided by:   Eduardo Rodriguez
// Email Address: e_rodriguez13@mail.fhsu.edu
// March 11
// FILE: RodriguezEduardoProject5.hpp
// PROVIDES: A toolkit of 14 functions for manipulating linked lists. Each
// node of the list contains a piece of data and a pointer to the next node.
// The type of the data is defined as Node::Item in a typedef statement.
// The complete type definitions used by the toolkit are:
//
//   struct Node                   Item may be any of the C++ built-in types
//   {                             (int, char, etc.), or a class with a default
//       typedef _____ Item;       constructor, an assignment operator,
//       Item data;                and a test for equality (x == y).
//       Node *link;
//   };

// DYNAMIC MEMORY usage by the toolkit:
//   If there is insufficient dynamic memory, then the following functions call
//   new_handler before any changes are made to the list that head_ptr points
//   to : list_head_insert, list_insert, list_copy, list_piece, list_tail_attach,
//   list_copy_front

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdlib.h> // Provides size_t
#include <iostream>
using namespace std;
namespace FHSULINKEDLIST
{
    struct Node
    {
        typedef int Item;
        Item data;
        Node* link;
    };

    // FUNCTIONS for the linked list toolkit
    // Test 1 functions
    size_t list_length(const Node* head_ptr);// finds size of linke list

    void list_head_insert(Node*& head_ptr, const Node::Item& entry); // inserts node with data entry at the front of a linked list

    void list_insert(Node* previous_ptr, const Node::Item& entry);// inserts a node on a linked list following a specified node

    void list_head_remove(Node*& head_ptr);// removes first node of a linked list

    void list_remove(Node* previous_ptr);// removes a node on a linked list following a specified node

    void list_clear(Node*& head_ptr);// Removes all nodes in a linked list

 // Test 2 Functions
    Node* list_search(Node* head_ptr, const Node::Item& target);// returns pointer to node of a linked list that has the data value match the target

    Node* list_locate(Node* head_ptr, size_t position);//returns pointer to node of a linked list that is in the nth position. nth being a parameter to this function

    size_t list_occurrences(Node* head_ptr, const Node::Item& target);// returns how many times target is on a list

// Test 3 Functions
    void list_tail_attach(Node*& head_ptr, const Node::Item& entry);// attaches a node at the end of a linked list

    void list_tail_remove(Node*& head_ptr);// removes the last node of a linked list

//Test 4 Functions
    void list_copy(Node* source_ptr, Node*& head_ptr);// copies data of a linked list (first parameter) unto a new node that has been inputted in the parameter

    Node* list_copy_front(Node* source_ptr, size_t n);// returns a node * of a copy of the data from a linked list (first parameter) unto a new node  up to the desired number of nodes
}

#endif

