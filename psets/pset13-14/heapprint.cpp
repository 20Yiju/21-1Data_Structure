// On my honour, I pledge that I have neither received nor provided improper
// assistance in the completion of this assignment. Signed: ____Jungyiju______ Student Number: ____22000690_____


#include <iostream>
#include <cassert>
#include <queue>
#include <cmath>
#include "heap.h"
#include "treenode.h"
using namespace std;

// import treeprint functions
void treeprint(tree t);
void treeprint_levelorder(tree root);
void treeprint_levelorder_tasty(tree root);

// frees all nodes while traversing the tree like postorder
tree clear(tree t) {
	if (t) {
		clear(t->left);
		clear(t->right);
		delete t;
	}
	return nullptr;
}

tree buildBT(int* nodes, int i, int n) {
	DPRINT(std::cout << " buildBT i=" << i << " n=" << n << std::endl;);
	
	if (i > n) return nullptr;

	tree root = new TreeNode(nodes[i]);

	root -> left = buildBT(nodes, 2*i, n);
	root -> right = buildBT(nodes, (2*i)+1, n);
	return  root;
}

tree buildBT(heap p) {
	DPRINT(std::cout << " buildBT p" << std::endl;);
	queue<tree> que;
	int i = 2;
	int N = size(p);
	
	if(empty(p)) return nullptr;
	
	tree root = new TreeNode(p -> nodes[1]);
	que.push(root);
	while(N >= i){
		tree node = new TreeNode(p -> nodes[i]);
		tree treenode = que.front();
		if(treenode -> left == nullptr) {
			treenode -> left = node;
		}
		else if (treenode -> right == nullptr) {
			treenode -> right = node;
		}
		if(treenode -> left != nullptr && treenode -> right != nullptr) {
			que.pop();
		}	
		que.push(node);
		i++;
	}

	return  root;
}

// print a heap using treeprint() - must build a tree to call treeprint() functions
void heapprint(heap p, int mode) {
	DPRINT(cout << ">heapprint\n";);
	if (empty(p)) return;
	tree root = nullptr;

	// build tree in two different ways for pedagogical purpose 
	if (size(p) % 2 == 0) {
		cout << "\t[Tree built using recursion]\n";
		root = buildBT(p->nodes, 1, size(p));  // using recursion
}
	else {
		cout << "\t[Tree built using iteration]\n";
		root = buildBT(p);						// using iteration
	}

	if (size(p) >= 1000) {  // a magic number
		cout << "\tThere are 1,000 nodes and more, the print mode goes into ...\n";
		mode = TASTY_MODE;
	}

	// TASTY_MODE: show just the first and last three levels each 
	if ((height(p) + 1) < 7 && mode == TASTY_MODE)    // height + 1 = level
		mode = LEVEL_MODE;

	switch (mode) {
	case TREE_MODE:
		treeprint(root);
		break;
	case LEVEL_MODE:
		treeprint_levelorder(root);
		break;
	default: // TASTY_MODE: show just the first and last three levels each 
		treeprint_levelorder_tasty(root);
		cout << endl;
	}

	clear(root);
	DPRINT(cout << "<heapprint\n";);
}
