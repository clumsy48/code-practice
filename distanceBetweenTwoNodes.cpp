#include <iostream>
#include <cstdlib>
#include "common/treeNode.h"

using namespace std;

Node *newNode(int data)
{
    // Allocate memory for new node
    Node *node = (Node *)malloc(sizeof(Node));

    // Assign data to this node
    node->data = data;

    // Initialize left and right children as NULL
    node->left = NULL;
    node->right = NULL;
    return (node);
}

Node *contructTree()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(10);
    root->left->left = newNode(8);
    root->left->right = newNode(7);
    root->right->right = newNode(9);
    root->right->left = newNode(70);
    root->right->right->right = newNode(23);
    root->right->right->right->left = newNode(24);

    return root;
}