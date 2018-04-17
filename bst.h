#ifndef __BST_H__
#define __BST_H__

#ifndef NULL
#define NULL 0x00
#endif

class BSTNode {
	private:
		int data;
		unsigned int depth;
		BSTNode *left;
		BSTNode *right;
	public:
		BSTNode(int d);
		~BSTNode();
		void setDepth(BSTNode *p, unsigned int d);

	friend class BST;

};

class BST {
	private:
		BSTNode *root;
		unsigned int numNodes;
		// Helpers for pub methods
		BSTNode* rinsert(BSTNode *p, int d);
		BSTNode* rsearch(BSTNode *p, int d);
		void destroyAll(BSTNode *p);
		void inorder(BSTNode *p);
		void preorder(BSTNode *p);
		void postorder(BSTNode *p);
		void setDepth(BSTNode *p, unsigned int d);
		void findMaxDepth(BSTNode *p, unsigned int* d);
		BSTNode* removeHelper(BSTNode *p, int d);
		BSTNode* successor(BSTNode *p);
		
	public:
		BST();
		~BST();
		// Public methods
		void insert(int d);
		bool search(int d);
		void updateDepth();
		unsigned int maxDepth();
		unsigned int BST_Height();
		void printInorder();
		void printPreorder();
		void printPostorder();
		void nodeCount();
		void remove(int d);
		void clear();
};

#endif