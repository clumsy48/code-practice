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
    root->right->right->left = newNode(52);
    root->right->right->right = newNode(23);
    root->right->right->right->left = newNode(24);

    return root;
}
Node *lca(Node *root, int a, int b, bool &v1, bool &v2)
{
    if (root == NULL)
        return NULL;
    if (root->data == a)
    {
        v1 = true;
        return root;
    }
    if (root->data == b)
    {
        v2 = true;
        return root;
    }
    Node *lt = lca(root->left, a, b ,v1,v2);
    Node *rt = lca(root->right, a, b,v1,v2);
    if (lt != NULL && rt != NULL)
    {
        return root;
    }
    if (lt != NULL)
        return lt;
    return rt;
}
bool find(Node *root ,int key){
  if(root==NULL) return false;
  if(root->data == key || find(root->left , key) || find(root->right , key)) return true;
  return false;
}
int main()
{
    Node *root = contructTree();
    int a = 8;
    int b = 11;
    bool v1 = false;
    bool v2 = false;
    Node *LCA = lca(root, a, b, v1, v2) ;
    if(v1 && v2 || v1 && find(LCA,b) || v2 && find(LCA,a)){
        cout << LCA->data<< endl;
    }else cout << "Not present"<< endl;
}