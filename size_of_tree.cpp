#include <iostream>
#include "common/treeNode.h"

using namespace std;

Node *newNode(int data)
{
    // Allocate memory for new node
    struct Node *node = (struct Node *)malloc(sizeof(Node));

    // Assign data to this node
    node->data = data;

    // Initialize left and right children as NULL
    node->left = NULL;
    node->right = NULL;
    return (node);
}

int sizeoftree(Node *root)
{
    int leftSize = 0, rightSize = 0;
    if (root == NULL)
        return 0;

    if (root->left != NULL)
        leftSize = sizeoftree(root->left);

    if (root->right != NULL)
        rightSize = sizeoftree(root->right);

    return 1 + leftSize + rightSize;
}
Node *contructTree()
{
    Node *root = newNode(34);
    root->left = newNode(23);
    root->right = newNode(10);
    root->left->left = newNode(22);
    root->left->left->left = newNode(1);
    root->left->left->left->left = newNode(153);
    root->left->left->left->left->left = newNode(45);
    root->left->left->left->left->left->left = newNode(99);
    return root;
}

int main()
{
    cout << sizeoftree(contructTree());

    return 0;
}

