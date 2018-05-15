#include "bst.h"
#include <iostream>

int main() {
	BST tree;
	// tree 1
	std::cout << "Tree 1" << std::endl;
	tree.insert(63);
	tree.insert(35);
	tree.insert(77);
	tree.insert(38);
	tree.insert(72);
	tree.insert(82);
	tree.insert(37);
	tree.insert(49);
	tree.insert(81);
	tree.insert(84);
	std::cout << "Foo Result is: ";
	tree.printFoo();
	std::cout << "Inorder Traversal Output is: ";
	tree.printInorder();
	std::cout << "Postorder Traversal Output is: ";
	tree.printPostorder();
	tree.clear();
	// tree 2
	std::cout << "Tree 2" << std::endl;
	tree.insert(34);
	tree.insert(20);
	tree.insert(41);
	tree.insert(14);
	tree.insert(23);
	tree.insert(38);
	tree.insert(12);
	tree.insert(15);
	tree.insert(28);
	tree.insert(37);
	tree.insert(39);
	std::cout << "Foo Result is: ";
	tree.printFoo();
	std::cout << "Inorder Traversal Output is: ";
	tree.printInorder();
	std::cout << "Postorder Traversal Output is: ";
	tree.printPostorder();
	tree.clear();
	// tree 3
	std::cout << "Tree 3" << std::endl;
	tree.insert(28);
	tree.insert(52);
	tree.insert(42);
	tree.insert(72);
	tree.insert(45);
	tree.insert(66);
	tree.insert(75);
	tree.insert(44);
	tree.insert(48);
	std::cout << "Foo Result is: ";
	tree.printFoo();
	std::cout << "Inorder Traversal Output is: ";
	tree.printInorder();
	std::cout << "Postorder Traversal Output is: ";
	tree.printPostorder();
	tree.clear();
	return 0;
}