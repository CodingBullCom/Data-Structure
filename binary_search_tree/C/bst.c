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
	if (tree_root == NULL)
		return;
	printf("%d ",tree_root->data);
	preorder(tree_root->left_child);
	preorder(tree_root->right_child);
}

void inorder(bst_node *tree_root){

	if (tree_root == NULL)
		return;
	inorder(tree_root->left_child);
	printf("%d ",tree_root->data);
	inorder(tree_root->right_child);
}

void postorder(bst_node *tree_root){

	if (tree_root == NULL)
		return;
	postorder(tree_root->left_child);
	postorder(tree_root->right_child);
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

bst_node *delete_node(bst_node *tree_root, int data){
	
	if (tree_root == NULL){
		printf("\n Error! Requested data not found in tree");
		return NULL;
	}
	else if (tree_root->data == data) {

		bst_node *new_root = NULL;
		if (tree_root->left_child == NULL)
			new_root = tree_root->right_child;
		else if(tree_root->right_child == NULL)
			new_root = tree_root->left_child;
		else {
			bst_node *tmp_node = NULL;
			printf("\nCheckpoint 1");
			new_root = tree_root->right_child;
			while(new_root->left_child != NULL){
				tmp_node = new_root;
				new_root = new_root->left_child;
			}
			printf("\nCheckpoint 2");
			if(tmp_node != NULL && new_root->right_child != NULL){
				tmp_node->left_child = new_root->right_child;
				new_root->right_child = NULL;
			}
			printf("\nCheckpoint 3");
			new_root->left_child = tree_root->left_child;
			if (new_root != tree_root->right_child)
				new_root->right_child = tree_root->right_child;
			printf("\nCheckpoint 4");
		}

		free(tree_root);
		tree_root = NULL;
		return new_root;

	} else if (tree_root->data > data){
		tree_root->left_child = delete_node(tree_root->left_child, data);
	} else{
		tree_root->right_child = delete_node(tree_root->right_child, data);
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
				printf("\nEnter data to insert:: ");
				scanf("%d", &data);
				root_node = insert(root_node, data);
				break;
			case 2:
				printf("\nEnter data to remove:: ");
				scanf("%d", &data);
				root_node = delete_node(root_node, data);
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
