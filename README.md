# Binary Tree Management System for Levi Family

## Overview
This project is a C-based application that simulates managing a binary tree for a fictional "Levi" family. It includes functionalities such as adding and removing members, assigning tasks, and displaying family details using different tree traversal methods.

## Features
- **Add Member**: Allows adding a new member to the Levi family tree.
- **Remove Member**: Enables the removal of a member from the family tree.
- **Task Assignment**: Assign tasks to family members and display them.
- **Print Members**: Supports printing the family tree in Preorder, Inorder, or Postorder.
- **Family Size Calculation**: Calculates and displays the number of family members.
- **Exit Program**: Closes the application and frees up used resources.

## Compilation and Execution
### Prerequisites
- GCC compiler
- CMake version 3.22 or higher

### Compiling the Program
To compile the program, use the following commands in your terminal:
```bash
mkdir build
cd build
cmake ..
make
Running the Program
Execute the program by running:

bash
Copy code
./newEx6
Usage
When you run the program, it will present a menu with options:

scss
Copy code
(1) Add Levi
(2) Remove Levi
(3) Task All
(4) Print All
(5) Size of Levi family
(6) Exit
Choose an action by entering the corresponding number. Follow the on-screen prompts to provide further details for each action.

Program Files
ex_6.c: Main application source file.
BinTree.h: Header file with declarations for the binary tree operations.
BinTree.c: Implementation file for the binary tree functions.
CMakeLists.txt: Build configuration file.
Example
Input
yaml
Copy code
1
1234
0
4
1
Output
python
Copy code
please choose action:
(1) Add Levi
...
Contributors
This project is open for contributions. Please ensure to follow the existing coding style and add comments where necessary.

License
This project is released under the MIT License.

Author
[Ran Wurmbrand]
