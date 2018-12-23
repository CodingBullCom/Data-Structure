// File: morris_traversal_inorder.cpp
// Created on: 14th Dec 2018
// Updated on: 14th Dec 2018
// Author: Pawan [pawan@codingbull.com]
// http://www.codingbull.com
//
// This source code is the part of free tutorial series provided by http://www.codingbull.com and
// it can be used/distributed without any restriction.

#include<iostream>

typedef struct binary_tree_node {
    int data;
    binary_tree_node* left, * right;
public:
    binary_tree_node(int data) {
      this->data = data;
      this->left = NULL;
      this->right = NULL;
    }

} node_bt;

/* Function to traverse binary tree without recursion and
   without stack */
void morris_traversal_inorder(node_bt* root)
{
    node_bt *current, *prev;

    if (root == NULL)
        return;

    current = root;
    while (current != NULL) {

        if (current->left == NULL) {
            printf("%d ", current->data);
            current = current->right;
        }
        else {

            /* Find the inorder predecessor of current */
            prev = current->left;
            while (prev->right != NULL && prev->right != current)
                prev = prev->right;

            /* Make current as right child of its inorder
               predecessor */
            if (prev->right == NULL) {
                prev->right = current;
                current = current->left;
            } else {
                prev->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            }
        }
    }
}

int main()
{

    /* Construct a binary tree like below
            1
          /   \
        2      3
      /  \
    4     5
  */
    node_bt* root = new node_bt(1);
    root->left = new node_bt(2);
    root->right = new node_bt(3);
    root->left->left = new node_bt(4);
    root->left->right = new node_bt(5);

    morris_traversal_inorder(root);

    return 0;
}
