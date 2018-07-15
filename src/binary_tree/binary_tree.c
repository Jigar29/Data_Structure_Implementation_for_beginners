#include "nodes.h"
#include "general.h"

Ret_type_t getNewNode(Tree_node_t **root, int data)
{
	Tree_node_t *new_node = (Tree_node_t *)malloc(sizeof(Tree_node_t));
	if(new_node == NULL)
		return exit_with_failure;
	new_node->data= data;
	new_node->left_node = new_node->right_node = NULL;

	(*root) = new_node;
	return exit_with_sucsess;
}

void printTree(Tree_node_t *root, int space)
{
  // Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += 10;

	// Process right child first
	printTree((Tree_node_t *)root->right_node, space);

	// Print current node after space
	// count
	printf("\n");
	for (int i = 10; i < space; i++)
		printf(" ");
	printf("%d\n", root->data);

	// Process left child
	printTree((Tree_node_t *)root->left_node, space);
}
Ret_type_t isTreeBalanced(Tree_node_t *root)
{

}
int lenghtOfTree(Tree_node_t *root)
{

}

Ret_type_t insertToTree(Tree_node_t **root, Tree_List_t data)
{
	//Base Condition
	if((*root)== NULL)
	{
		getNewNode(root, data);
		return exit_with_sucsess;
	}
	else if(data <= (*root)->data)
	{
		insertToTree((Tree_node_t **)&((*root)->left_node), data);
		return exit_with_sucsess;
	}
	else if(data > (*root)->data)
	{
		insertToTree((Tree_node_t **)&((*root)->right_node), data);
		return exit_with_sucsess;
	}

	return exit_with_sucsess;
}

Ret_type_t deleteFromTree(Tree_node_t **root, Tree_List_t data)
{
	//Base condition
	if((*root) == NULL)
	{
		return false;
	}
	else if((*root)->data == data)
	{
		(*root) = NULL;
		free((*root));
		return true;
	}
	else
	{
		deleteFromTree((Tree_node_t **)&((*root)->left_node), data);
		deleteFromTree((Tree_node_t **)&((*root)->right_node), data);
		return false;
	}
}
Ret_type_t isTreeEmpty(Tree_node_t *root)
{
	if(root == NULL)
		return true;
	else
		return false;
}
