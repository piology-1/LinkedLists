# CMakeLists.txt im src/LinkedList/double/
add_library(double_linkedlist
    DoublyLinkedList.cpp
    DoublyNode.cpp 
)

target_include_directories(double_linkedlist PUBLIC include)