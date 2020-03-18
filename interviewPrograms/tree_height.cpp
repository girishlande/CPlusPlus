#include <algorithm>
#include <iostream>
#include <memory>
#include <queue>
using namespace std;

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// write a program to get height of the tree
// write definition of following function
int getTreeHeight(Node* root);

Node* createNode(int data)
{
    Node* root = new Node();
    root->data = data;
    root->left = nullptr;
    root->right = nullptr;
    return root;
}

int main()
{
    Node* root = createNode(1);
    Node* a1 = createNode(2);
    Node* a2 = createNode(3);
    Node* a3 = createNode(4);
    Node* a4 = createNode(5);
    Node* a5 = createNode(6);
    root->left = a1;
    root->right = a2;
    a1->right = a3;
    a3->left = a4;
    a3->right = a5;
    cout << "Height of tree:" << getTreeHeight(root) << endl;

    return 0;
}

int getTreeHeight(Node* root)
{
    queue<Node*> q;
    q.push(root);
    int height = 1;
    while (!q.empty()) {
        int count = q.size();
        for (int i = 0; i < count; ++i) {
            Node* node = q.front();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            q.pop();
        }
        height++;
    }
    return height;
}