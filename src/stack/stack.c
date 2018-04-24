#include "stack.h"
#include "stdlib.h"
#include <stdio.h>

List_t stackTop(List_node_t* head)
{
	return head->data;
}

int stackGetSize(List_node_t* head)
{
	List_node_t* pointer = (List_node_t *)head;
	int stack_size = 0;

	while(pointer != 0)
	{
		pointer = (List_node_t *)pointer->ptr;
		stack_size++;
	}
	return stack_size;
}

Ret_type_t isStackEmpty(List_node_t* head)
{
	return (stackGetSize(head) == 0)?true:false;
}

void printStack(List_node_t* head)
{
	List_node_t* pointer = (List_node_t *)head;
	for(int i=0;i<stackGetSize(head);i++)
	{
		printf("%d\n", pointer->data);
		pointer = (List_node_t *)pointer->ptr;
	}
}

Ret_type_t stackPop(List_node_t** head, List_t* data)
{
	List_node_t *pointer = (List_node_t *) *head;

	if(isStackEmpty(*head) == true)
	{
		printf("The stack is empty. There is no top of the stack right now.\n");
		return exit_with_abruption;
	}

	*data = pointer->data;
	*head = (List_node_t *)pointer->ptr;

	return exit_with_sucsess;
}

Ret_type_t stackPush(List_node_t** head, List_t data)
{
	List_node_t* new_node = (List_node_t *)malloc(sizeof(List_node_t));

	new_node->data = data;
	new_node->ptr = (struct List_node_t*)(*head);

	*head = new_node;

	return exit_with_sucsess;
}
