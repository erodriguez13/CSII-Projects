// Provided by:   Eduardo Rodriguez
// Email Address: e_rodriguez13@mail.fhsu.edu
// March 11
#include <iostream>
#include "RodriguezEduardoProject5.hpp"
using namespace std;

namespace FHSULINKEDLIST {
    //int test1(); // test list head insert, list head remove, list insert, list remove, list clear, and list length, 5 points

    void list_head_insert(Node* &head_ptr, const Node::Item &entry) {
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: A new node containing the given entry has been added at the head of the linked list;
//      head_ptr now points to the head of the new, longer linked list.
// *** REMOVE void inserAtFront(Node** head, int newValue)
        Node* newFrontNode = new Node();// prepares new node
        // sets the value of data to equal entry
        newFrontNode->data = entry;
        // Put node in front of current head
        newFrontNode->link = head_ptr;
        // Moved head of list to point to new node
        head_ptr = newFrontNode;
    }

    void list_head_remove(Node *&head_ptr) {
//     Precondition: head_ptr is the head pointer of a linked list, with at least one node.
//     Postcondition: The head node has been removed and returned to the heap; head_ptr is now the head pointer of the new, shorter linked list.
        // if list is empty, do nothing
        if(head_ptr==NULL){
            return;
        }
    // if list has only one node, remove that node
        if(head_ptr->link== NULL)
        {
            delete head_ptr;
            head_ptr= NULL;
            return;
        }
    // if list has multiple nodes
    if (head_ptr->link != NULL){
        // designate first node to be deleted
       Node* toBeRemoved_ptr= head_ptr;

       // before deleting 1st node, assign head_ptr to point to the second node, which is about to be the head of the list
       head_ptr= toBeRemoved_ptr->link;
        }

    }

    void list_insert(Node *previous_ptr, const Node::Item &entry) {
        //   void list_insert(Node* previous_ptr, const Node::Item& entry)
//     Precondition: previous_ptr points to a node in a linked list.
//     Postcondition: A new node containing the given entry has been added
//     after the node that previous_ptr points to.
//Check if previous node is NULL
        if(previous_ptr==NULL){// issue error warning
            cout<< "Error: Previous can't be NULL"<< endl;
            return;
        }
        //Prepare a newNode
        Node* newNode = new Node;
        // sets the value of data to equal entry
        newNode-> data = entry;
        //attach node link of rest of link to new link
        newNode-> link= previous_ptr->link;
        // add the pointer of new Node to previous Node's link
        previous_ptr->link= newNode;
    }

    void list_remove(Node* previous_ptr) {
//     Precondition: previous_ptr points to a node in a linked list, and this is not the tail node of the list.
        if (previous_ptr == NULL || previous_ptr->link == NULL) {
            return;} // do nothing
//     Postcondition: The node after previous_ptr has been removed from the linked list.
            // designate link of the next node to be deleted
            Node* toBeRemoved_ptr;
            toBeRemoved_ptr = previous_ptr->link;
            // add pointer rest of list to the end of previous_ptr node
            previous_ptr->link = toBeRemoved_ptr->link;
        
            delete toBeRemoved_ptr;
        toBeRemoved_ptr=NULL;
        }

        void list_clear(Node *&head_ptr) {
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: All nodes of the list have been returned to the heap, and the head_ptr is now NULL.
            while (head_ptr !=
                   NULL) {// as in a queue, remove the front until all nodes are removed by calling the  list_head_remove() function
                list_head_remove(head_ptr);
            }
        }


size_t list_length(const Node *head_ptr) {
    //     Precondition: head_ptr is the head pointer of a linked list.
    //     Postcondition: The value returned is the number of nodes in the linked
    //     list. The list itself is unaltered.
    // prepare  count for to keep count
    size_t count = 0;
    //iterate through list incrementing count for each node
    while (head_ptr!=NULL){
        count++;
        head_ptr= head_ptr->link;
    }
            return count;
        }
    
   
   // int test2();  test list search, list occurrence and list locate functions. 1 point

        Node* list_search(Node* head_ptr, const Node::Item& target){ // page 754
        //     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: The pointer returned points to the first node containing the specified target in its data member.
//     If there is no such node, the null pointer is returned. The list itself is unaltered.
        Node*  here = head_ptr;
        if (here == NULL){
            return NULL;}
    //From book: Use herre node for readibility
            //iterate through list
        else
        { while ((here-> data != target) && (here->link != NULL))
                here= here-> link;
            // if data of node is the desired target, return the node here
            if (here-> data== target)
                return here;
            else
                return NULL;}
    }

    size_t list_occurrences(Node *head_ptr, const Node::Item &target) {
//     Precondition: head_ptr is the head pointer of a linked list.
        size_t count= 0;
//     Postcondition: The return value is the count of the number of times target appears as the data portion of a node on the linked list.
//     The linked list itself is unchanged.
        while (head_ptr!= NULL){// go through linked list checking each data value and move on to next node by passing the link of that node to the head_ptr
            if (target== head_ptr->data)
                count++;// increase count for every occurence
            head_ptr = head_ptr->link;
        }
        return count;
    }

     Node *list_locate(Node *head_ptr, size_t position) {
//     Precondition: head_ptr is the head pointer of a linked list, and position > 0.
//     Postcondition: The pointer returned points to the node at the specified position in the list. (The head node is position 1, the next node is
//     position 2, and so on). If there is no such position, then the null
//     pointer is returned. The list itself is unaltered.
         int index=1;
         Node* here=head_ptr;
         while (here!= NULL){// go through linked list checking each data value and move on to next node by passing the link of that node to the head_ptr
             if (index!=position)
             {
                 here = here->link;
                 index++;
             }
// return node pointer for when the index matches the desired position in the list
             if (index== position)
             return here;
         }
// if index is never position, do this
        return nullptr;
    }

    //int test3(); // test list tail attach, and list tail remove functions 2 points

    void list_tail_attach(Node *&head_ptr, const Node::Item &entry) {
//     Precondition: head_ptr is the head pointer of a linked list.
//     Postcondition: A new node containing the given entry has been added at
//     the tail of the linked list; if this happens to be the first node of
//     the linked list, then head_ptr now points to this node (otherwise
//     head_ptr is unchanged).
//create new node for new tail
      // for empty list
        if (head_ptr==NULL){
            head_ptr= new Node;
            head_ptr-> link=NULL;
            head_ptr-> data=entry;
            return;
        }
        //find end of the list and insert entry
        Node* tail_ptr= head_ptr;
        while (tail_ptr->link != NULL) {
            tail_ptr= tail_ptr->link;
        }
        list_insert(tail_ptr, entry);
    }

    void list_tail_remove(Node *&head_ptr) {
//   void list_tail_remove(Node*& head_ptr)
//     Precondition: head_ptr is the head pointer of a linked list, with at
//     least one node.
//     Postcondition: The tail node has been removed and returned to the heap;
//     if the list is now empty, then head_ptr is null; otherwise head_ptr
//     is unchanged.
        // for head pointers that are null, do nothing
        if (head_ptr==NULL) return;
    
        // for single node list
        if (head_ptr->link==NULL){
            delete head_ptr;
            head_ptr= NULL;
            return;
        }
        // for list of 2 or more nodes, find the last node
        Node* tail_ptr = head_ptr;
        
        while (tail_ptr->link != NULL) {
            tail_ptr= tail_ptr->link;
        }
        // find second to last node
        Node* second_to_last= head_ptr;
        while (second_to_last->link !=tail_ptr){
            second_to_last=second_to_last->link;}
        // remove node after second to last
        list_remove(second_to_last);
    }

    //int test4(); // test list copy function, and list front copy front functions 2 point

    void list_copy(Node *source_ptr, Node *&head_ptr) {
//   void list_copy(Node* source_ptr, Node*& head_ptr)
//     Precondition: source_ptr is the head pointer of a linked list.
//     Postcondition: head_ptr is the head pointer for a new list that contains the same items as the list pointed to by
        // for empty lists
        head_ptr=NULL;
        if (source_ptr== NULL) {
            return;}
    // for lists of one or more
       // insert first node into head_ptr
        list_head_insert(head_ptr,source_ptr->data);
            
        //make new pointer to iterate through source so as not to change the link to head of source list
        Node* here_source= source_ptr->link;
        // make new pointer to iterate through head_ptr and not change the head_ptr
        Node * here_head= head_ptr;
        // copy each data value from source onto new list and move on to the next link
        // stop when next link is "null"
        while (here_source != NULL){
            list_insert(here_head,here_source->data);
            here_source= here_source->link;
            here_head= here_head->link;
        }
        
    }

    Node *list_copy_front(Node *source_ptr, size_t n) {
//     Precondition: source_ptr is the head pointer of a linked list
//     Postcondition: The value returned is the head pointer for a new list that contains copies of the first n nodes from the list
//     that source_ptr points to. If there less than n nodes in source list, just copy all nodes and done
        Node* head_ptr=NULL;
        // for empty souces or n being equal to 0
        if(source_ptr== NULL || n==0){
            return head_ptr;
        }
    // make a pointer to makr the end of the list and a counter to compare to size_t n
        // the pointer should be "null" when the list is at the end
        Node* last_link= source_ptr;
        int count=1;
        // copy first value and move tail
        list_head_insert(head_ptr,source_ptr->data);
        // move to next node
        last_link= last_link->link;
        // designate a previous pointer to be used later of the list_insert function
        Node * previous_ptr= head_ptr;
        // append to rest of list via list_insert
        while (count<n && last_link!=NULL){
            list_insert(previous_ptr,last_link->data);
            last_link= last_link->link;
            previous_ptr=previous_ptr->link;
            count++;
        }
        // return the pointer to the head of this new list
        return head_ptr;
    }

 
}
    
