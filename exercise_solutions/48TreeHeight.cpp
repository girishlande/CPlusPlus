// Program to compute the tree height of Binary Search tree 

#include "stdafx.h"

#include <vector>
#include <iostream>
#include <random>

using namespace std;

typedef struct Node {
	struct Node* left;
	struct Node* right;
	int data;
}NODE;

NODE* createNode(int data) {
	NODE* node = new NODE();
	node->left = nullptr;
	node->right = nullptr;
	node->data = data;
	return node;
}

void addNode(NODE* root, NODE* current) {
	if (root == nullptr) {
		root = current;
		return;
	}
	if (current->data < root->data) {
		// add new node on left side
		if (root->left == nullptr) {
			root->left = current;
		}
		else {
			addNode(root->left, current);
		}
	}
	else if (current->data > root->data) {
		// add new node on right side
		if (root->right == nullptr) {
			root->right = current;
		}
		else {
			addNode(root->right, current);
		}
	}
}

void traverseTree(NODE* root) {
	if (root != nullptr) {
		cout << "=>" << root->data;
		
		if (root->left) {
			traverseTree(root->left);
		}
		if (root->right) {
			traverseTree(root->right);
		}
	}
}

size_t treeHeight(NODE* root) {
	if (root == nullptr) return 0;

	vector<NODE*> nodes;
	nodes.push_back(root);

	size_t height = 0;
	while (nodes.size()>0) {
		size_t size = nodes.size();
		vector<NODE*> temp;
		for (size_t i = 0; i < size; i++) {
			NODE* n = nodes[i];
			if (n->left) {
				temp.push_back(n->left);
			}
			if (n->right) {
				temp.push_back(n->right);
			}
		}
		nodes = temp;
		height++;
	}
	return height;
}

int main()
{
	for (size_t j = 0; j < 10; j++) {
		NODE* root = nullptr;
		for (size_t i = 0; i < 10; i++) {
			std::random_device dev;
			std::mt19937 rng(dev());
			std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 100); // distribution in range [1, 6]
			int n = dist6(rng);
			cout << n << "  ";
			NODE* node = createNode(n);
			if (root == nullptr)
				root = node;
			else
				addNode(root, node);
		}

		// Calculate height of the tree
		size_t height = treeHeight(root);
		cout << "\nHeight of the tree:" << height << "\n";
	}
    return 0;
}

