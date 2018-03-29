#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left_child;
	struct node *right_child;
} bst_node;

bst_node *create_node(int data){

	bst_node *new_node = (bst_node *)malloc(sizeof(bst_node));
	new_node->data = data;
	new_node->left_child = NULL;
	new_node->right_child = NULL;
	return new_node;
}

void preorder(bst_node *tree_root){
	if (tree_root)
		printf("%d ",tree_root->data);
	if (tree_root->left_child)
		preorder(tree_root->left_child);
	if (tree_root->right_child)
		preorder(tree_root->right_child);
}

void inorder(bst_node *tree_root){

	if (tree_root->left_child)
		inorder(tree_root->left_child);

       	if (tree_root)
		printf("%d ",tree_root->data);

	if (tree_root->right_child)
		inorder(tree_root->right_child);
}

void postorder(bst_node *tree_root){
	if (tree_root->left_child)
		postorder(tree_root->left_child);
	if (tree_root->right_child)
		postorder(tree_root->right_child);
	if (tree_root)
		printf("%d ", tree_root->data);
}

bst_node *insert(bst_node *tree_root, int data){
	
	bst_node *new_node = create_node(data); 
	if (tree_root == NULL)
		return new_node;
	else if (tree_root->data > data) {
		if(tree_root->left_child == NULL)
			tree_root->left_child = new_node;
		else
			insert(tree_root->left_child, data);
	} else {
 		if(tree_root->right_child == NULL)
			tree_root->right_child = new_node;
		else
			insert(tree_root->right_child, data);
	}
	return tree_root;
}

int main(){

	int option, data;
	bst_node *root_node;	 
	while(1){
        	printf("\n1. Insert\n2. Delete\n3. In-Order\n4. Pre-Order\n5. Post-Order\n6. Exit\n");
		printf("Enter your option:: \n");
		scanf("%d", &option);
		switch(option){
			case 1:
				printf("\nEnter data:: ");
				scanf("%d", &data);
				root_node = insert(root_node, data);
				break;
			case 2:
				break;
			case 3:
				printf("\nIn-Order Traversal\n");
				inorder(root_node);
				break;
			case 4:
				printf("\nPre-Order Traversal\n");
				preorder(root_node);
				break;
			case 5:
				printf("\nPost-Order Traversal\n");
				postorder(root_node);
				break;
			case 6:
				exit(0);
		} 
	}
	return 0;
}
