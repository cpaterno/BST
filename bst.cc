#include "bst.h"
#include <iostream>

// Node constructor
BSTNode::BSTNode(int d) {
	data = d;
	depth = 0;
	left = NULL;
	right = NULL;
}

// Node destructor
BSTNode::~BSTNode() {
	// No dynamic memory
}


//--------------------------------------------------------------------------------------------------------------------------------------------------------

// Tree constructor
BST::BST() {
	root = NULL;
	numNodes = 0;
}

// Tree destructor
BST::~BST() {
	destroyAll(root);
	root = NULL;
	numNodes = 0;
}

// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Helpers

BSTNode* BST::rinsert(BSTNode *p, int d) {
	// base case: create a node where there isn't one
	if (!p) {
		numNodes++;
		return new BSTNode(d);
	}
	// recurse to the left and 
	// update the current node's left pointer
	if (d < p->data) {
		p->left = rinsert(p->left, d);
	// recurse to the right and 
	// update the current node's right pointer
	} else if (d > p->data) {
		p->right = rinsert(p->right, d);
	}
	// recurse to the top of the call stack, updating root 
	// and all the node pointers along the way
	// also triggers if data is already present in tree
	return p;
}

BSTNode* BST::rsearch(BSTNode *p, int d) {
	// base case: data not in tree
	if (!p) return NULL;
	// data found
	if (d == p->data) {
		return p;
	// data is less than current node's data
	// look on left subtree
	} else if (d < p->data) {
		return rsearch(p->left, d);
	}
	// data is greater than current node's data
	// look on right subtree 
	return rsearch(p->right, d);
}

void BST::destroyAll(BSTNode *p) {
	// base case: p is NULL
	if (!p) return;
	// postorder traversal: visit children first then parents 
	// where the visited node is deleted
	destroyAll(p->left);
	destroyAll(p->right);
	delete p; 
}

void BST::inorder(BSTNode *p) {
	// base case: p is NULL
	if (!p) return;
	// inorder traversal: traverse as left as possible
	// then visit node, then traverse as right as possible
	// where the visited node's data is printed
	inorder(p->left);
	std::cout << p->data << " ";
	inorder(p->right);
}

void BST::preorder(BSTNode *p) {
	// base case: p is NULL
	if (!p) return;
	// preorder traversal: visit parents then children
	// where the visited node's data is printed
	std::cout << p->data << " ";
	preorder(p->left);
	preorder(p->right);
}

void BST::postorder(BSTNode *p) {
	// base case: p is NULL
	if (!p) return;
	// postorder traversal: visit leaves then parents
	// where the visited node's data is printed
	postorder(p->left);
	postorder(p->right);
	std::cout << p->data << " ";
}

// sets the depth of each node through preorder traversal
void BST::setDepth(BSTNode *p, unsigned int d) {
	if (!p) return;
	p->depth = d;
	setDepth(p->left, d + 1);
	setDepth(p->right, d + 1);
}

// returns the depth of the deepest node
void BST::findMaxDepth(BSTNode *p, unsigned int* d) {
	if (!p) return;
	findMaxDepth(p->left, d);
	if (p->depth > *d) {
		*d = p->depth;
	}
	findMaxDepth(p->right, d);
}

// finds the successor of a given node
BSTNode* BST::successor(BSTNode *p) {
	if (!p) return NULL;
	BSTNode *q = p->right;
	if (!q) return p; 
	while(q->left) {
		q = q->left;
	}
	return q;
}

// deletes node according to what case it falls under
BSTNode* BST::removeHelper(BSTNode *p, int d) {
	if (!p) return p;

	if (d < p->data) {
		p->left = removeHelper(p->left, d);
	} else if (d > p->data) {
		p->right = removeHelper(p->right, d);
	// found it so delete it based on case 1, 2 or 3
	} else {
		// case 1 and case 2
		if (!p->left) {
			BSTNode *n = p->right;
			delete p;
			numNodes--; 
			return n;
		} else if (!p->right) {
			BSTNode *n = p->left;
			delete p;
			numNodes--; 
			return n;
		// case 3
		} else {
			BSTNode *n = successor(p);
			p->data = n->data;
			p->right = removeHelper(p->right, n->data);
		}
	}
	return p; 
}


// ------------------------------------------------------------------------------------------------------------------------------------------------------
// Public methods

// insert's a node in the tree, abstracts the details from the user
void BST::insert(int d) {
	root = rinsert(root, d);
}

// searches for a node in the tree, abstracts the details from the user		
bool BST::search(int d) {
	BSTNode *temp = rsearch(root, d);
	if (temp) return true;
	return false;
}

// wrapper function, updates the depth of all the nodes
void BST::updateDepth() {
	setDepth(root, 0);
}

// returns the depth of the deepest node 
unsigned int BST::maxDepth() {
	unsigned int d = 0;
	unsigned int* dp = &d;
	findMaxDepth(root, dp);
	return d;
}

// calculates the height of the tree, abstracts the details from the user	
unsigned int BST::BST_Height() {
	setDepth(root, 0);
	unsigned int d = 0;
	unsigned int* dp = &d;
	findMaxDepth(root, dp);
	d++;
	return d;
}

// prints the data of all nodes in the tree according to inorder traversion	
void BST::printInorder() {
	inorder(root);
	std::cout << std::endl;
}

// prints the data of all nodes in the tree according to preorder traversion		
void BST::printPreorder() {
	preorder(root);
	std::cout << std::endl;
}

// prints the data of all nodes in the tree according to postorder traversion
void BST::printPostorder() {
	postorder(root);
	std::cout << std::endl;
}

// prints the number of nodes in the tree
void BST::nodeCount() {
	std::cout << "The number of nodes in the tree is " << numNodes << std::endl;
}

// removes the given node from the tree, abstracts the details away from the user
void BST::remove(int d) {
	root = removeHelper(root, d);
}

// clears all nodes in the tree
void BST::clear() {
	destroyAll(root);
	root = NULL;
	numNodes = 0;
}

BSTNode* BST::foo(BSTNode* p) {
	if (p != NULL && p->left != NULL) {
		return foo(p->left);
	}
	return p;		
}

void BST::printFoo() {
	BSTNode* ouput = foo(root);
	std::cout << ouput->data << std::endl;
}