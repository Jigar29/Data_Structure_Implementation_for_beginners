#include "nodes.h"
#include "general.h"

Ret_type_t isTreeEmpty(Tree_node_t *root)
{
	if((root->left_node == NULL) && (root->right_node == NULL))
			return true;

	return false;
}

void printTree(Tree_node_t *root)
{

}

Ret_type_t isTreeBalanced(Tree_node_t *root);
int lenghtOfTree(Tree_node_t *root);

Ret_type_t insertToTree(Tree_node_t **root, Tree_List_t data)
{
	//Base Condition, Left Side Condition
	if((*root) == NULL){
		Tree_node_t* new_node = (Tree_node_t *) malloc(sizeof(Tree_node_t));
		new_node->data = data;
		new_node->left_node = new_node->right_node = NULL;
		(*root) = new_node;
		return exit_with_sucsess;
	}

	// Making the binary search tree
	if(data > (*root)->data){
		insertToTree( (Tree_node_t **) &((*root)->right_node), data);
	}
	else {
		insertToTree( (Tree_node_t **) &((*root)->left_node), data);
	}

	return exit_with_sucsess;
}

Ret_type_t deleteFromTree(Tree_node_t **root, Tree_List_t data);
