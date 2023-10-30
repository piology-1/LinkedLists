#include <gtest/gtest.h>
#include "single/SinglyLinkedList.h"
#include "single/SinglyNode.h"

TEST(SinglyLinkedListTests, ClearTest)
{
    /*
    IMPORTANT NOTE:
    There appears to be an issue with the clear() method of the singly linked list, specifically related to the delete statement.
    !!! CAUTION !!! --> The delete statement is currently commented out, and as a result, memory is not being deallocated!!!
    */

    // Arrange
    SinglyLinkedList s_list;

    SinglyNode first_node = SinglyNode("0");
    SinglyNode second_node = SinglyNode("1");
    SinglyNode third_node = SinglyNode("2");

    s_list.push_front(first_node);
    s_list.push_back(second_node);
    s_list.push_back(third_node);

    // Act: Clear the list
    s_list.clear();

    // Assert
    ASSERT_EQ(s_list.is_empty(), true);
    ASSERT_EQ(s_list.size(), 0);
    ASSERT_THROW(s_list.get_first(), std::out_of_range);
    ASSERT_THROW(s_list.get_last(), std::out_of_range);
    ASSERT_THROW(s_list.get_node(0), std::out_of_range);
}

TEST(SinglyLinkedListTests, IsEmptyTest)
{
    SinglyLinkedList s_list;

    ASSERT_EQ(s_list.is_empty(), true);

    SinglyNode first_node = SinglyNode("0");
    SinglyNode second_node = SinglyNode("1");

    s_list.push_front(second_node);
    s_list.push_front(first_node);

    ASSERT_EQ(s_list.is_empty(), false);
}

TEST(SinglyLinkedListTests, PushFrontTest)
{
    // TEST SETUP
    SinglyLinkedList s_list;
    SinglyNode s_node("TestNode"); // Stack-allocated SinglyNode 's_node' (automatic destruction).
    // auto s_node = *new SinglyNode("TestNode"); // Heap-allocated SinglyNode with a pointer, manual memory release required to prevent leaks.

    // CALL FUNCTION TO BE TESTED
    s_list.push_front(s_node);

    // CHECK EXPECTED RESULTS (ASSERTIONS)
    EXPECT_EQ(s_list.size(), 1);
    EXPECT_EQ(s_list.get_first().get_data(), "TestNode");
    EXPECT_EQ(s_list.get_last().get_data(), "TestNode");
    EXPECT_EQ(s_list.get_node(0).get_data(), "TestNode");
    EXPECT_EQ(s_list.get_first().get_index(), 0);
    EXPECT_EQ(s_list.index_of(s_node), 0);

    // CLEAN UP (IF NEEDED)

    // The destructors for s_list and s_node will be
    // automatically called when they go out of scope.
}

TEST(SinglyLinkedListTests, PushBackTest)
{
    SinglyLinkedList s_list;
    SinglyNode s_node("TestNode");

    s_list.push_back(s_node);

    EXPECT_EQ(s_list.size(), 1);
    EXPECT_EQ(s_list.get_first().get_data(), "TestNode");
    EXPECT_EQ(s_list.get_last().get_data(), "TestNode");
    EXPECT_EQ(s_list.get_node(0).get_data(), "TestNode");
    EXPECT_EQ(s_list.get_first().get_index(), 0);
    EXPECT_EQ(s_list.index_of(s_node), 0);
}

TEST(SinglyLinkedListTests, InsertTest)
{
    SinglyLinkedList s_list;
    SinglyNode s_node("InsertedTestNode (0)");

    // Fill the list [-2, -1, InsertedTestNode (0), 1, 2]
    s_list.push_back(*new SinglyNode("1"));
    s_list.push_front(*new SinglyNode("-1"));
    s_list.push_back(*new SinglyNode("2"));
    s_list.push_front(*new SinglyNode("-2"));

    s_list.insert(2, s_node);

    EXPECT_EQ(s_list.size(), 5);
    EXPECT_EQ(s_list.get_first().get_data(), "-2");
    EXPECT_EQ(s_list.get_last().get_data(), "2");
    EXPECT_EQ(s_list.get_node(2).get_data(), "InsertedTestNode (0)");
    EXPECT_EQ(s_list.index_of(s_node), 2);
}

TEST(SinglyLinkedListTests, OutOfRangeTests)
{
    SinglyLinkedList s_list; // Empty list at the beginning

    // Assert that accessing elements or performing operations on an empty list
    ASSERT_THROW(s_list.get_first(), std::out_of_range);
    ASSERT_THROW(s_list.get_last(), std::out_of_range);
    ASSERT_THROW(s_list.get_node(5), std::out_of_range);
    ASSERT_THROW(s_list.pop_front(), std::out_of_range);
    ASSERT_THROW(s_list.pop_back(), std::out_of_range);
    ASSERT_THROW(s_list.remove(10), std::out_of_range);

    SinglyNode s_node("InsertedTestNode"); // Add a node to the list
    SinglyNode s_node2("InsertedTestNode2");

    // Test insert with an out-of-range index on an emtpy list
    ASSERT_THROW(s_list.insert(100, s_node), std::out_of_range);

    // Fill the list with some random elements
    s_list.push_back(*new SinglyNode("another node1"));
    s_list.push_front(*new SinglyNode("another node2"));
    s_list.push_back(*new SinglyNode("another node3"));

    // Test insert with an out-of-range index on an emtpy list
    ASSERT_THROW(s_list.insert(10, s_node2), std::out_of_range);

    // // Test get_node with an out-of-range index
    ASSERT_THROW(s_list.get_node(50), std::out_of_range);
}

TEST(SinglyLinkedListTests, AddDuplicateNodeTests)
{
    SinglyLinkedList s_list;
    SinglyNode existing_node("ExistingNode");

    s_list.push_back(existing_node);

    // Test push_back
    ASSERT_THROW(s_list.push_back(existing_node), std::runtime_error);

    // Test push_front
    ASSERT_THROW(s_list.push_front(existing_node), std::runtime_error);

    // Test insert
    ASSERT_THROW(s_list.insert(0, existing_node), std::runtime_error);
}

TEST(SinglyLinkedListTests, PopFrontTest)
{
    SinglyLinkedList s_list;

    SinglyNode first_node = SinglyNode("0");
    SinglyNode second_node = SinglyNode("1");
    SinglyNode third_node = SinglyNode("2");

    s_list.push_front(second_node);
    s_list.push_back(third_node);
    s_list.push_front(first_node);

    // Use a reference to access the actual removed SinglyNode object, avoiding copy.
    SinglyNode &removed = s_list.pop_front();

    ASSERT_EQ(s_list.size(), 2);
    ASSERT_EQ(removed.get_index(), first_node.get_index());
    ASSERT_EQ(removed.get_data(), first_node.get_data());
    ASSERT_EQ(&removed, &first_node); // test address
}

TEST(SinglyLinkedListTests, PopBackTest)
{
    SinglyLinkedList s_list;

    SinglyNode first_node = SinglyNode("0");
    SinglyNode second_node = SinglyNode("1");
    SinglyNode third_node = SinglyNode("2");

    s_list.push_front(second_node);
    s_list.push_back(third_node);
    s_list.push_front(first_node);

    SinglyNode &removed = s_list.pop_back();

    ASSERT_EQ(s_list.size(), 2);
    ASSERT_EQ(removed.get_index(), third_node.get_index());
    ASSERT_EQ(removed.get_data(), third_node.get_data());
    ASSERT_EQ(&removed, &third_node);
}

TEST(SinglyLinkedListTests, RemoveByIndexTest)
{
    SinglyLinkedList s_list;

    SinglyNode first_node = SinglyNode("0");
    SinglyNode second_node = SinglyNode("1");
    SinglyNode third_node = SinglyNode("2");

    s_list.push_front(second_node);
    s_list.push_back(third_node);
    s_list.push_front(first_node);

    ASSERT_THROW(s_list.remove(10), std::out_of_range);

    SinglyNode &removed = s_list.remove(1);

    ASSERT_EQ(s_list.size(), 2);
    ASSERT_EQ(removed.get_index(), second_node.get_index());
    ASSERT_EQ(removed.get_data(), second_node.get_data());
    ASSERT_EQ(&removed, &second_node); // test address
}

TEST(SinglyLinkedListTests, RemoveByNodeTest)
{
    SinglyLinkedList s_list;

    SinglyNode first_node = SinglyNode("0");
    SinglyNode second_node = SinglyNode("1");
    SinglyNode third_node = SinglyNode("2");

    SinglyNode nonexistent_node = SinglyNode("100"); // not added

    s_list.push_front(second_node);
    s_list.push_back(third_node);
    s_list.push_front(first_node);

    // Try to remove a nonexistent node from the list
    ASSERT_THROW(s_list.remove(nonexistent_node), std::logic_error);

    s_list.remove(second_node);

    ASSERT_EQ(s_list.size(), 2);
}

TEST(SinglyLinkedListTests, SortByTest)
{
    SinglyLinkedList s_list;

    ASSERT_THROW(s_list.sort_by(), std::logic_error);
}

void print_example_list()
{
    system("cls");

    std::cout << "===== Linked List Datastructure Example =====\n\n";

    SinglyLinkedList s_list;

    /* Fill the list with some Nodes */
    std::cout << "Filling the list ..." << std::endl;
    s_list.push_front(*new SinglyNode("3"));
    s_list.push_back(*new SinglyNode("4"));
    s_list.push_front(*new SinglyNode("2"));
    s_list.push_back(*new SinglyNode("5"));
    s_list.push_back(*new SinglyNode("6"));
    s_list.push_front(*new SinglyNode("1"));

    s_list.display();
    std::cout << std::endl;

    std::cout << "Press any key to continue with the tests ...";
    std::cin.ignore(); // Wait for any key
    std::cout << std::endl
              << std::endl;
}
int main(int argc, char **argv)
{
    print_example_list();

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}