#ifndef BINARY_TREE_BINARY_TREE_H_
#define BINARY_TREE_BINARY_TREE_H_

#include "nodes.h"
#include "general.h"

void printTree(Tree_node_t *root, int space);
Ret_type_t isTreeBalanced(Tree_node_t *root);
int lenghtOfTree(Tree_node_t *root);
Ret_type_t insertToTree(Tree_node_t **root, Tree_List_t data);
Ret_type_t deleteFromTree(Tree_node_t **root, Tree_List_t data);
Ret_type_t isTreeEmpty(Tree_node_t *root);
Tree_List_t findMaxElement(Tree_node_t *root);
Tree_List_t findMinElement(Tree_node_t *root);
Ret_type_t searchInTree(Tree_node_t *root, Tree_List_t data);
void inOrderTraversal(Tree_node_t *root);
void preOrderTraversal(Tree_node_t *root);
void postOrderTraversal(Tree_node_t *root);

#endif /* BINARY_TREE_BINARY_TREE_H_ */
