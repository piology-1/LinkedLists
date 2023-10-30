#include "single/SinglyNode.h"

SinglyNode::SinglyNode(std::string data)
{
    this->data = data;
    this->index = INVALID_INDEX;
    this->next_node_ptr = nullptr;
}

SinglyNode::~SinglyNode()
{
    // std::cout << "Destructor of '" << data << "' called" << std::endl;
}

int SinglyNode::get_index() const
{
    if (this == nullptr)
        throw std::invalid_argument("Node hasn't been initialized yet and therefore no valid index");

    return this->index;
}

void SinglyNode::set_index(const int &index)
{
    this->index = index;
}

std::string SinglyNode::get_data() const
{
    return std::string(this->data);
}

void SinglyNode::set_data(const std::string &new_data)
{
    this->data = new_data;
}

SinglyNode *SinglyNode::get_next_node_ptr() const
{
    return this->next_node_ptr;
}

void SinglyNode::set_next_node_ptr(SinglyNode *new_next_node_ptr)
{
    this->next_node_ptr = new_next_node_ptr;
}

void SinglyNode::print() const
{

    /*
    Example display of one Node with its attributes:

    ----------------------
    | data = 'HELLO'     |
    | i =                |
    ----------------------
    | Next node address: |
    | 0                  |
    ----------------------
    */

    const std::string h_spacer(node_width, '-');

    // POINTER OF THIS NODE LINE
    std::stringstream this_ss;
    this_ss << "| Address of this node: " << this;
    std::string this_ptr_line = this_ss.str();

    int this_ptr_padding = node_width - this_ptr_line.length() - 1;
    this_ptr_line += std::string(this_ptr_padding, ' ') + "|";

    // DATA LINE
    std::string data_line = "| data = '" + this->data + "'";
    int data_padding = node_width - data_line.length() - 1; // -1 for | character
    data_line += std::string(data_padding, ' ') + "|";

    // INDEX LINE
    std::string index_line = "| i = " + std::to_string(this->index);
    int index_padding = node_width - index_line.length() - 1;
    index_line += std::string(index_padding, ' ') + "|";

    // Convert the Node* pointer to a string
    std::stringstream next_ss;
    next_ss << "| Address of the next node: " << static_cast<void *>(this->next_node_ptr);
    // POINTER OF NEXT NODE LINE
    std::string next_ptr_line = next_ss.str();
    int next_ptr_padding = node_width - next_ptr_line.length() - 1;
    next_ptr_line += std::string(next_ptr_padding, ' ') + "|";

    std::cout << h_spacer << std::endl;
    std::cout << this_ptr_line << std::endl;
    std::cout << h_spacer << std::endl;
    std::cout << data_line << std::endl;
    std::cout << index_line << std::endl;
    std::cout << h_spacer << std::endl;
    std::cout << next_ptr_line << std::endl;
    std::cout << h_spacer << std::endl;
}
