#ifndef SINGLYNODE_H
#define SINGLYNODE_H

#include <iostream>
#include <string>
#include <sstream>

#define INVALID_INDEX -1;

class SinglyNode
{
private:
    int index; // Index of the node in the list

    std::string data; // e.g. a Name of a person

    SinglyNode *next_node_ptr; // Pointer to the next node in the list.

public:
    SinglyNode(std::string data); // Constructor
    ~SinglyNode();                // Destructor

    // Getter und Setter für 'index'
    int get_index() const;
    void set_index(const int &index);

    // Getter und Setter für 'data'
    std::string get_data() const;
    void set_data(const std::string &new_data);

    // Getter und Setter für 'next_node_ptr'
    SinglyNode *get_next_node_ptr() const;
    void set_next_node_ptr(SinglyNode *new_next_node_ptr);

    static const int node_width = 51;
    void print() const;
};

#endif
