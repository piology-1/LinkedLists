# Linked List Datastructure

This is a C++ project that provides implementations of various types of linked list data structures.

## Explanation

A linked list is a fundamental data structure in computer science that consists of a collection of nodes, each containing data and a reference (or link) to the next node in the sequence. Linked lists come in different flavors, and this project aims to provide implementations for the following types:

### Singly Linked List

A singly linked list is a linear data structure where each node contains a data element and a reference to the next node in the sequence. It is a straightforward and memory-efficient way to represent sequences of data. The implementation for the singly linked list is complete and ready for use.

Status: Implemented and complete

Structure:

```bash
Head (head_ptr)                                          Tail (tail_ptr)
  |                                                         |
  v                                                         v
+---+---+    +---+---+    +---+---+    +---+---+    +---+---+    ---------
| 1 |  *---->| 2 |  *---->| 3 |  *---->| 4 |  *---->| 5 |  *---->|nullptr|
+---+---+    +---+---+    +---+---+    +---+---+    +---+---+    ---------
```

### Doubly Linked List

A doubly linked list is an extension of the singly linked list, where each node contains references to both the next and the previous nodes. This additional reference allows for efficient traversal in both directions. While it is not yet implemented, it is a potential future addition to this project.

Status: Potential future implementation

Structure:

```bash
Head (head_ptr)                                          Tail (tail_ptr)
  |                                                         |
  v                                                         v
+---+---+    +---+---+    +---+---+    +---+---+    +---+---+
| 1 |  *<--->| 2 |  *<--->| 3 |  *<--->| 4 |  *<--->| 5 |   |
+---+---+    +---+---+    +---+---+    +---+---+    +---+---+
```

### Circular Linked List

A circular linked list is a variation of the linked list where the last node is connected back to the first node, creating a closed loop. This data structure is useful in various applications, such as representing circular buffers. Although it is not currently implemented, it is under consideration for a future update.

Status: Potential future implementation

There are two ways to implement circular linked lists:

#### Singly Circular:

A singly circular linked list is a type of circular linked list where each node has a reference to the next node. The last node points back to the first node, creating a closed loop.

#### Doubly Circular:

A doubly circular linked list is another type of circular linked list, where each node has references to both the next and previous nodes. The last node points back to the first node, and the first node points to the last node, creating a bidirectional closed loop.

### Other

There may be other types of linked lists that are not the primary focus of this project at the moment. If you have additional ideas or specific types of linked lists that you'd like to see implemented, we encourage contributions and suggestions from the community. Your input can help shape the future development of this project and broaden its scope to cater to various data structure needs. Please feel free to reach out and share your ideas.

Status: Potential future implementation

## Installation

To get started with this project, follow the steps below to clone the repository from GitHub and set it up locally. Please ensure that you have the necessary dependencies installed:

### Clone the Repository

Use the following commands to clone the project from GitHub and initialize the submodule:

Clone the main repository:

```bash
git clone https://github.com/piology-1/LinkedLists.git
```

Navigate to the cloned main repository directory:

```bash
cd LinkedLists
```

Before building and using the project, all submodules need to be initialized. Due to the use of googletest as an external library, it has to be added, initialized, and updated as a git submodule.
Run the git submodule init command to initialise the submodules:

```bash
git submodule init
```

Run the git submodule update command to update the submodules to the correct state:

```bash
git submodule update

```

This will initialize the submodules and download the necessary code for your project.

### Build the Project

Build the project using the provided CMakeLists. Make sure you have the required build tools and dependencies configured on your system.

### Run Tests

For quality assurance, you can run the test files located within the [test directory](tests) to verify that everything is functioning correctly. This step ensures that the project is working as expected.

By following these installation instructions, you'll be all set to work with the project locally.
