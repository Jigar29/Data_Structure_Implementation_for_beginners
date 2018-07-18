#include "nodes.h"
#include "general.h"

Ret_type_t isTreeEmpty(Tree_node_t *root)
{
	if(root == NULL)
		return true;
	else
		return false;
}
Ret_type_t getNewNode(Tree_node_t **root, Tree_List_t data)
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
		return exit_with_sucsess;
	}
	else if((*root)->data == data)
	{
		(*root) = NULL;
		free((*root));
		return exit_with_sucsess;
	}
	else
	{
		deleteFromTree((Tree_node_t **)&((*root)->left_node), data);
		deleteFromTree((Tree_node_t **)&((*root)->right_node), data);
		return exit_with_sucsess;
	}
}
Ret_type_t searchInTree(Tree_node_t *root, Tree_List_t data)
{
	//Base condition
	if(root == NULL)
		return false;
	else if(data == root->data)
		return true;

	if(data <= root->data)
		return searchInTree(root->left_node, data);
	else
		return searchInTree(root->right_node, data);
}
Tree_List_t findMinElement(Tree_node_t *root)
{
	//Base Condition
	if(root->left_node == NULL)
	{
		return root->data;
	}
	return findMinElement(root->left_node);
}
Tree_List_t findMaxElement(Tree_node_t *root)
{
	//Base Condition
	if(root->right_node == NULL)
	{
		return root->data;
	}
	return findMaxElement(root->right_node);
}

void inOrderTraversal(Tree_node_t *root)
{
	//Base Condition
	if(root == NULL)
	{
		return;
	}

	inOrderTraversal(root->left_node);
	printf("%d, ", root->data);
	inOrderTraversal(root->right_node);
}

void preOrderTraversal(Tree_node_t *root)
{
	//Base Condition
	if(root == NULL)
		return;

	printf("%d, ", root->data);
	preOrderTraversal(root->left_node);
	preOrderTraversal(root->right_node);
}
void postOrderTraversal(Tree_node_t *root)
{
	//Base Condition
	if(root == NULL)
		return;

	postOrderTraversal(root->left_node);
	postOrderTraversal(root->right_node);
	printf("%d, ", root->data);
}
