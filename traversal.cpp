#include <iostream>
#include "common/treeNode.h"

using namespace std;

Node *newNode(int data){
    // Allocate memory for new node
    struct Node *node = (struct Node *)malloc(sizeof(Node));
    // Assign data to this node
    node->data = data;
    // Initialize left and right children as NULL
    node->left = NULL;
    node->right = NULL;
    return (node);
}
void inorder(Node *root)
{
    if (root == NULL) return ;
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);  
}
void preorder(Node *root)
{
    if (root == NULL) return ;
    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);  
}
void postorder(Node *root)
{
    if (root == NULL) return ;
    postorder(root->left);
    postorder(root->right); 
    cout << root->data << endl; 
}
Node *contructTree()
{
    Node *root = newNode(34);
    root->left = newNode(23);
    root->right = newNode(10);
    root->left->left = newNode(39);
    root->left->left->right = newNode(22);
    root->left->left->right->right = newNode(2);
    root->left->left->left = newNode(1);
    root->left->left->left->left = newNode(153);
    root->left->left->left->left->left = newNode(45);
    return root;
}

int main()
{
    Node *root = contructTree();
    //inorder(root);
    preorder(root);
    return 0;
}