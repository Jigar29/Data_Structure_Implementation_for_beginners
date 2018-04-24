#ifndef LINKED_LIST_LINKED_LIST_H_
#define LINKED_LIST_LINKED_LIST_H_

#include "general.h"
#include "nodes.h"

void printLinkedList(List_node_t *head);
List_t getHeadValue(List_node_t *head);
Ret_type_t isEmpty(List_node_t *head);
Ret_type_t appendToLinkedList(List_node_t **head, List_t data);
Ret_type_t prependToLinkedList(List_node_t **head, List_t data);
Ret_type_t insertToLinkedList(List_node_t **head, int node_pos, List_t data);
Ret_type_t delete(List_node_t ** head, int node_pos);
int sizeOfLinkedlist(List_node_t *head);
Ret_type_t reverseLinkedList(List_node_t **head);


#endif /* LINKED_LIST_LINKED_LIST_H_ */
