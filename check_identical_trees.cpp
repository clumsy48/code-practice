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

bool checkIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 != NULL && root2 != NULL)
    {
        return (root1->data == root2->data) && checkIdentical(root1->left, root2->left) && checkIdentical(root1->right, root2->right) ? true : false;
    }
    return false;
}
void printTree(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        printTree(root->left);
        printTree(root->right);
    }
}
Node *contructTree(bool ignore)
{
    Node *root = newNode(34);
    root->left = newNode(23);
    root->right = newNode(10);
    root->left->left = newNode(39);
    if(ignore)
    root->left->left->right = newNode(22);
    root->left->left->left = newNode(1);
    root->left->left->left->left = newNode(153);
    root->left->left->left->left->left = newNode(45);
    root->left->left->left->left->left->left = newNode(99);
    return root;
}

int main()
{
    Node *root1 = contructTree(true);
    Node *root2 = contructTree(false);
    bool isIdentical = checkIdentical(root1, root2);
    if (isIdentical == true)
        cout << "Trees are Identical";
    else
        cout << "Non-Identical";
    //printTree(root);

    return 0;
}
