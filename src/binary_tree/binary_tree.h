#ifndef BINARY_TREE_BINARY_TREE_H_
#define BINARY_TREE_BINARY_TREE_H_

#include "nodes.h"
#include "general.h"

Ret_type_t isTreeBalanced(Tree_node_t *head);
int lenghtOfTree(Tree_node_t *head);
Ret_type_t insertToTree(Tree_node_t **head, Tree_List_t data);
Ret_type_t deleteFromTree(Tree_node_t **head, Tree_List_t data);
Ret_type_t isTreeNull(Tree_node_t *head);

#endif /* BINARY_TREE_BINARY_TREE_H_ */
