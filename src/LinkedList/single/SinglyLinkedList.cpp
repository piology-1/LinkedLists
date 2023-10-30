#include "single/SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList()
{
    // empty list at the beginning, set the head node_ptr to a nullptr
    head_node_ptr = nullptr;
    tail_node_ptr = nullptr;
}

SinglyLinkedList::~SinglyLinkedList()
{
    if (!is_empty())
        clear();
}

SinglyNode *SinglyLinkedList::get_node_at_index(const int &index) const
{
    SinglyNode *current_node = head_node_ptr;

    while (current_node != nullptr)
    {
        if (current_node->get_index() == index)
            return current_node; // Node found

        current_node = current_node->get_next_node_ptr();
    }

    return nullptr; // Node not found, return nullptr
}

bool SinglyLinkedList::node_in_list(const int &index) const
{
    return get_node_at_index(index) != nullptr;
}

bool SinglyLinkedList::node_in_list(const SinglyNode &node) const
{
    SinglyNode *current_node = head_node_ptr;

    while (current_node != nullptr)
    {
        if (current_node == &node)
            return true; // Given node found

        current_node = current_node->get_next_node_ptr();
    }

    return false; // End of list reached, given node not found
}

void SinglyLinkedList::set_indexes()
{
    int i = 0;
    SinglyNode *current_node = head_node_ptr;

    while (current_node != nullptr)
    {
        current_node->set_index(i);
        current_node = current_node->get_next_node_ptr();

        i++; // Post-increment operator
    }
}

void SinglyLinkedList::push_front(SinglyNode &new_node)
{
    if (node_in_list(new_node))
        throw std::runtime_error("Node already in the list");

    // Check for an empty list
    if (is_empty())
    {
        // Set head and tail pointers to the new node
        head_node_ptr = &new_node;
        tail_node_ptr = &new_node;
    }
    else
    {
        // Keep the tail pointer unchanged

        // Get a reference to the current first node in the linked list (not necessar, because we actually don't need to modify it), but for better readability
        SinglyNode *first_node_ptr = head_node_ptr;

        // Check if 'first_node_ptr' is not nullptr to avoid dereferencing a null pointer
        if (first_node_ptr != nullptr)
            // Set the 'next_node_ptr' attribute of the new added node to point to the previous first node of the list (=head)
            new_node.set_next_node_ptr(first_node_ptr);

        head_node_ptr = &new_node; // Get the address of the new added node using '&' and make the head node to point to this address

        /*
        In short:

        new_node.set_next_node_ptr(head_node_ptr);
        head_node_ptr = &new_node;
        */
    }

    // TODO: also update the index here to reflect the new positions correctly.
    set_indexes();
}

void SinglyLinkedList::push_back(SinglyNode &new_node)
{
    if (node_in_list(new_node))
        throw std::runtime_error("Node already in the list");

    if (is_empty())
    {
        head_node_ptr = &new_node;
        tail_node_ptr = &new_node;
    }
    else
    {
        // Keep the head pointer unchanged

        // Get the current last node to modify its 'next_node_ptr' before adding the new node
        SinglyNode *last_node_ptr = tail_node_ptr;

        // Check if 'last_node_ptr' is not nullptr to avoid null pointer dereference
        if (last_node_ptr != nullptr)
            // Set 'next_node_ptr' of the previous last node to point to the new node
            last_node_ptr->set_next_node_ptr(&new_node);

        // Update the tail pointer to the new node (new last node)
        tail_node_ptr = &new_node;

        /*
        In short:

        tail_node_ptr->set_next_node_ptr(&new_node);
        tail_node_ptr = &new_node;
        */
    }

    // TODO: Update the index to reflect new positions correctly.
    set_indexes();
}

void SinglyLinkedList::insert(int index, SinglyNode &new_node)
{
    bool empty = is_empty();

    /* Check the passed-in index for being out of range. */
    if (empty)
    {
        // The insert method is used to populate an empty list
        if (index != 0)
            throw std::out_of_range("Index: " + std::to_string(index) + " out of bounds");
    }

    // ==> The list has at least one node; check if the index is out of range
    else if ((index < head_node_ptr->get_index()) || (index > tail_node_ptr->get_index()))
    {
        throw std::out_of_range("Index: " + std::to_string(index) + " out of bounds");
    }

    // ==> The passed index is valid; check if the index is equal to the first or last node and use the appropriate method for it
    else if (empty || (index == head_node_ptr->get_index()))
    {
        push_front(new_node); // Also takes care of setting the indexes and updating the head_node_ptr
        return;
    }
    else if (index == tail_node_ptr->get_index())
    {
        push_back(new_node); // Also takes care of setting the indexes and updating the tail_node_ptr
        return;
    }

    // ==> At this point, the node needs to be inserted somewhere in the middle of the list => no adjustments on the head_node_ptr or the tail_node_ptr are needed.

    if (node_in_list(new_node))
        throw std::runtime_error("Node already in the list");

    SinglyNode *node_ptr_before = get_node_at_index(index - 1);
    SinglyNode *node_ptr_after = get_node_at_index(index); // NOTE: current index is node after new node
    node_ptr_before->set_next_node_ptr(&new_node);         // set node before to point to the adress of the new node
    new_node.set_next_node_ptr(node_ptr_after);

    set_indexes();
}

SinglyNode &SinglyLinkedList::get_first() const
{
    if (is_empty())
        throw std::out_of_range("List is empty"); // If the list is empty, throw an exception

    return *head_node_ptr; // Return a constant reference to the first node in the list
}

SinglyNode &SinglyLinkedList::get_last() const
{
    if (is_empty())
        throw std::out_of_range("List is empty");

    return *tail_node_ptr; // Return a constant reference to the last node in the list
}

SinglyNode &SinglyLinkedList::get_node(const int &index) const
{
    if (!node_in_list(index))
        throw std::out_of_range("Index out of range");

    return *get_node_at_index(index);
}

SinglyNode &SinglyLinkedList::pop_front()
{
    if (is_empty())
        throw std::out_of_range("List is empty"); // If the list is empty, nothing to remove (pop)

    // Get a reference to the current first node in the linked list
    SinglyNode *removed_node = head_node_ptr;

    // Update the head pointer to point to the NEW first (head) node of the list, after removing the previous first node
    head_node_ptr = head_node_ptr->get_next_node_ptr();

    // --> The previous first node is no longer part of the list because the head node ptr now points to the new first node.
    // Do not physicaly delete the removed node from memory (delete removed_node;); it's already 'removed' from the list.

    set_indexes();

    // Return a constant reference to the removed node
    return *removed_node;
}

SinglyNode &SinglyLinkedList::pop_back()
{
    if (is_empty())
        throw std::out_of_range("List is empty");

    // There is only one node in the list, so we can treat it like the first node
    if (head_node_ptr == tail_node_ptr) // same as: if (head_node_ptr->get_next_node_ptr() == nullptr)
        return pop_front();

    // Find the second last node in the current list, because the node does not have a prev_node_ptr in the class implementation (singly-linked list)
    SinglyNode *second_last_node_ptr;
    SinglyNode *current_node = head_node_ptr; // begin at the start (head) of the list

    while (true)
    {
        if (current_node->get_next_node_ptr()->get_next_node_ptr() == nullptr)
        {
            // second last node found
            second_last_node_ptr = current_node;
            break;
        }

        // 'Go' to the next node
        current_node = current_node->get_next_node_ptr();
    }

    // Get a reference to the current last node in the linked list
    SinglyNode *removed_node = tail_node_ptr;

    // Remove the last node from the list by ...
    second_last_node_ptr->set_next_node_ptr(nullptr); // ... setting the 'next_node_ptr' attribute of the second last node of the list to a nullptr
    tail_node_ptr = second_last_node_ptr;             // ... and by setting the 'tail_node_ptr' to point to the just found second last node of the list

    set_indexes();

    return *removed_node;
}

void SinglyLinkedList::remove(const SinglyNode &node)
{
    if (!node_in_list(node))
        throw std::logic_error("Given node is not part of the list");

    // Check if the given node is the first or last node in the list
    if (&node == head_node_ptr)
    {
        pop_front(); // method also adjusts the head_node_ptr
        return;
    }
    else if (&node == tail_node_ptr)
    {
        pop_back(); // method also adjusts the tail_node_ptr
        return;
    }
    // => The given node is not the first or the last node in the list, therefore no adjustments on the head_node_ptr or the tail_node_ptr are needed.

    // Find the node to be removed
    SinglyNode *node_ptr_before;
    SinglyNode *node_ptr_after;
    SinglyNode *curr_node_ptr = head_node_ptr;

    while (true)
    {

        if (curr_node_ptr->get_next_node_ptr() == &node) // next node in the loop iteration would be the actual node to be removed
        {
            // Node before the node to be removed is set to the current node
            node_ptr_before = curr_node_ptr;

            // Node after the node to be removed is set to the node after the next node
            node_ptr_after = curr_node_ptr->get_next_node_ptr()->get_next_node_ptr();

            break;
        }

        curr_node_ptr = curr_node_ptr->get_next_node_ptr();
    }

    // Remove the given node from the list by ...
    node_ptr_before->set_next_node_ptr(node_ptr_after); //... setting the 'node_ptr_before' to point to the node after the removed node
    // NOTE: Because the node is not at the end or beginning of the list at this point, the head and tail node pointers are not adjusted!

    set_indexes();
}

SinglyNode &SinglyLinkedList::remove(int index)
{

    if (!node_in_list(index))
        throw std::out_of_range("Index out of bounds");
    // throw std::logic_error("Given node is not part of the list");

    // Find the node to remove by its index
    SinglyNode *node_to_remove = get_node_at_index(index);

    remove(*node_to_remove); // Remove the node from the list --> DEREFERENCE THE NODE
    // set_indexes(); // not needed, because indexes are already set in the remove() method

    return *node_to_remove; // dereference the node to return it to return the actual node object
}

int SinglyLinkedList::index_of(const SinglyNode &node) const
{
    if (!node_in_list(node))
        throw std::logic_error("Given node is not part of the list");

    return node.get_index();
}

bool SinglyLinkedList::is_empty() const
{
    return head_node_ptr == nullptr;
}

int SinglyLinkedList::size() const
{
    if (is_empty())
        return 0;

    return tail_node_ptr->get_index() + 1; // +1 because the nodes are 0 indexed
}

void SinglyLinkedList::clear()
{
    // Iterate through the linked list, delete each node, and update the head pointer
    while (head_node_ptr != nullptr)
    {
        SinglyNode *current_node = head_node_ptr;           // Create a temporary pointer to the current node
        head_node_ptr = head_node_ptr->get_next_node_ptr(); // Update the head pointer to the next node

        // if (current_node != nullptr)
        //     delete current_node; // Delete the current node to free memory (calls the destructor of the node class?!)
    }

    /*
    NOTE:
    - Use "->" operator when working with a pointer to an object, accessing its methods and attributes using the -> operator (pointer).
    - Use "." operator when working with an object itself, accessing its methods and attributes directly using the . operator.
    */
}

void SinglyLinkedList::sort_by()
{
    throw std::logic_error("Method not yet implemented");
}

void SinglyLinkedList::display() const
{
    const int spaces_cnt = SinglyNode::node_width / 2;
    const std::string spaces(spaces_cnt, ' ');

    const std::string arrow = spaces + "|" + spaces + "\n" + spaces + "V" + spaces;

    SinglyNode *current_node = head_node_ptr;
    while (current_node != nullptr)
    {
        current_node->print();
        current_node = current_node->get_next_node_ptr();

        if (current_node != nullptr)
            std::cout << arrow << std::endl;
    }
    std::cout << std::endl;

    const std::string space(2, ' ');
    std::cout << "Head Pointer:\t" << head_node_ptr << space << "|" << space << "Tail Pointer:\t" << tail_node_ptr << std::endl;
    std::cout << "= &First Node:\t" << &get_first() << space << "|" << space << "= &Last Node:\t" << &get_last() << std::endl;
}
