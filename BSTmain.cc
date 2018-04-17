#include "bst.h"
#include <iostream>

int main() {
	BST tree;
	tree.insert(10);
	tree.insert(5);
	tree.insert(20);
	tree.insert(7);
	tree.insert(13);
	//std::cout << std::boolalpha << tree.search(15) << std::endl;
	//std::cout << std::boolalpha << tree.search(7) << std::endl;
	std::cout << "Tree height is: " << tree.BST_Height() << std::endl;
	tree.nodeCount();
	tree.printInorder();
	std::cout << "Removing 7" << std::endl;
	tree.remove(7);
	tree.nodeCount();
	tree.printInorder();
	std::cout << "Removing 20" << std::endl;
	tree.remove(20);
	tree.nodeCount();
	tree.printInorder();
	std::cout << "Removing 10" << std::endl;
	tree.remove(10);
	tree.nodeCount();
	tree.printInorder();
	std::cout << "Trying to remove 10 again" << std::endl;
	tree.remove(10);
	tree.nodeCount();
	tree.printInorder();
	return 0;
}