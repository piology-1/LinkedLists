#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

/*
- single linked list: forwards only
- double linked list: forwards and backwards
*/

#include <iostream>
#include "SinglyNode.h"

class SinglyLinkedList
{
private:
    // Pointer to the first (head) node in the list
    SinglyNode *head_node_ptr;

    // Pointer to the last (tail) node in the list
    SinglyNode *tail_node_ptr;

    // Returns a pointer to the node at the given index
    SinglyNode *get_node_at_index(const int &index) const;

    // Checks if a node is present in the list by its index
    bool node_in_list(const int &index) const;

    // Checks if the given node is in the list
    bool node_in_list(const SinglyNode &node) const;

    // Update the indexes of nodes in the list
    void set_indexes();

public:
    SinglyLinkedList();  // Constructor
    ~SinglyLinkedList(); // Destructor

    // Adds a new node to the head (front) of the list
    void push_front(SinglyNode &new_node);

    // Adds a new node to the tail (back) of the list
    void push_back(SinglyNode &new_node);

    // Inserts a new node at the specified index
    void insert(int index, SinglyNode &new_node);

    // Returns the first (head) node of the list
    SinglyNode &get_first() const;

    // Returns the last (tail) node of the list
    SinglyNode &get_last() const;

    // Returns the node at the given index
    SinglyNode &get_node(const int &index) const;

    // Removes and returns the head node of the list
    SinglyNode &pop_front();

    // Removes and returns the tail node of the list
    SinglyNode &pop_back();

    // Removes the given node from the list
    void remove(const SinglyNode &node);

    // Removes the node at the specified index and returns it
    SinglyNode &remove(int index);

    // Returns the index of the given node
    int index_of(const SinglyNode &node) const;

    // Returns true if the list is empty
    bool is_empty() const;

    // Returns the number of nodes in the list
    int size() const;

    // Clears all nodes from the list
    void clear();

    // Sorts the linked list based on specific criteria
    void sort_by(); // A description of the sorting logic is missing here

    // Displays the contents of the linked list
    void display() const;
};

#endif
