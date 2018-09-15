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
void printKDistanceFromRoot(Node *root,int distance){
     if(root == NULL ) return ;
     if(distance == 0){
       cout << root->data << endl;
     }
     printKDistanceFromRoot(root->left,distance-1);
     printKDistanceFromRoot(root->right,distance-1);
}
int printKDistance(Node *root ,int distance,int key){
    if(root == NULL ) return -1;
    if(root->data == key){
        printKDistanceFromRoot(root,distance);
        return 0;
    }
    int lt = printKDistance(root->left,distance,key);
    if(lt != -1){
        if(0 == distance-lt-1) cout << root->data << endl;
        else printKDistanceFromRoot(root->right,distance-lt-2);
        return lt+1;
    }
    int rt = printKDistance(root->right,distance,key);
     if(rt != -1){
        if(0 == distance-rt-1) cout << root->data << endl;
        else printKDistanceFromRoot(root->left,distance-rt-2);
        return rt+1;
    }
    return -1;
}
int main()
{
    Node *root = contructTree();
    printKDistance(root,2,9);
    //inorder(root);
    //postorder(root);

    return 0;
}
