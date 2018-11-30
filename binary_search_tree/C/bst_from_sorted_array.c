#include<stdio.h>
#include<stdlib.h>

typedef struct bst {
    int data;
    struct bst *left;
    struct bst *right;
} bst;

bst *create_node(int data) {
  bst *temp = (bst *)malloc(sizeof(bst));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

bst *bst_using_sorted_data(int *arr, int left, int right) {
  if (left > right )
    return NULL;
  int mid = (left + right)/2;
  bst *root = create_node(arr[mid]);
  root->left = bst_using_sorted_data(arr, left, mid-1);
  root->right = bst_using_sorted_data(arr, mid+1, right);
  return root;
}

void inorder(bst *root) {
  if (root == NULL) return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bst *root = bst_using_sorted_data(arr, 0, 10);
    inorder(root);
    printf("\n");
}
