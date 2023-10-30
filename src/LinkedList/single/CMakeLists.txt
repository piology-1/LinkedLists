# CMakeLists.txt im src/LinkedList/single/
add_library(single_linkedlist
    SinglyLinkedList.cpp
    SinglyNode.cpp
)

target_include_directories(single_linkedlist PUBLIC include)

