//Level order traversal in Queue
#include <iostream>
#include <queue>

using namespace std;

struct Node {
  Node *left, *right;
  int data;
  Node (int data) {
    this->data = data;
    left = right = NULL;
  }
};

class BinaryTree {

public:
  Node *root;
  BinaryTree() {
    root = NULL;
  }
  void createTree();
  void printLevelOrder();
};


void BinaryTree::createTree() {
    Node *node = new Node(1);
    node->left = new Node(2);
    node->left->left = new Node(3);
    node->left->left->left = new Node(4);
    node->left->left->left->left = new Node(5);
    node->left->left->left->left->left = new Node(6);
    node->right = new Node(7);
    node->right->left = new Node(8);
    node->right->right = new Node(9);
    node->right->right->right = new Node(10);
    root = node;
    //output should be 1, 2 7, 3 8 9, 4 10, 5, 6
}

void BinaryTree::printLevelOrder() {

   if (root == NULL) return;
   queue<Node *> que;
   que.push(root);
   while (!que.empty()) {
      int count = que.size();
      while(count > 0 ) {
         Node *temp = que.front();
         if(temp->left) que.push(temp->left);
         if(temp->right) que.push(temp->right);
         cout << temp->data << " ";
         que.pop();
         count--;
       }
       cout << endl;
   }
}

int main() {
  BinaryTree tree;
  tree.createTree();
  tree.printLevelOrder();
}
