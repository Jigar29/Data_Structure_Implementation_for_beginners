#ifndef LINKED_LIST_LINKED_LIST_H_
#define LINKED_LIST_LINKED_LIST_H_

#include "general.h"
#include "nodes.h"

void printLinkedList(Node *head);
List_t getHeadValue(Node *head);
Ret_type_t isEmpty(Node *head);
Ret_type_t appendToLinkedList(Node **head, List_t data);
Ret_type_t prependToLinkedList(Node **head, List_t data);
Ret_type_t insertToLinkedList(Node **head, int node_pos, List_t data);
Ret_type_t delete(Node ** head, int node_pos);
int sizeOfLinkedlist(Node *head);
Ret_type_t reverseLinkedList(Node **head);


#endif /* LINKED_LIST_LINKED_LIST_H_ */