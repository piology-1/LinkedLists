add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

### Singly Linked List Test ###
add_executable(SinglyLinkedListTest SinglyLinkedListTest.cpp)

target_link_libraries(SinglyLinkedListTest
  PRIVATE
  GTest::GTest
  single_linkedlist)

add_test(SinglyLinkedList_gtests SinglyLinkedListTest)


### Doubly Linked List Test ###
add_executable(DoublyLinkedListTest DoublyLinkedListTest.cpp)

target_link_libraries(DoublyLinkedListTest
  PRIVATE
  GTest::GTest
  double_linkedlist)

add_test(DoublyLinkedList_gtests DoublyLinkedListTest)