#ifndef STACK_STACK_H_
#define STACK_STACK_H_

#include <linked_list.h>
#include <nodes.h>
#include <general.h>

void printStack(List_node_t* head);
Ret_type_t stackPop(List_node_t** head, List_t *data);
Ret_type_t stackPush(List_node_t** head, List_t data);
List_t stackTop();
List_t stackGetSize();


#endif /* STACK_STACK_H_ */
