#include "stack.h"
#include "stdlib.h"
#include <stdio.h>

List_t stackTop(Node* head)
{
	return head->data;
}

int stackGetSize(Node* head)
{
	Node* pointer = (Node *)head;
	int stack_size = 0;

	while(pointer != 0)
	{
		pointer = (Node *)pointer->ptr;
		stack_size++;
	}
	return stack_size;
}

Ret_type_t isStackEmpty(Node* head)
{
	return (stackGetSize(head) == 0)?true:false;
}

void printStack(Node* head)
{
	Node* pointer = (Node *)head;
	for(int i=0;i<stackGetSize(head);i++)
	{
		printf("%d\n", pointer->data);
		pointer = (Node *)pointer->ptr;
	}
}

Ret_type_t stackPop(Node** head, List_t* data)
{
	Node *pointer = (Node *) *head;

	if(isStackEmpty(*head) == true)
	{
		printf("The stack is empty. There is no top of the stack right now.\n");
		return exit_with_abruption;
	}

	*data = pointer->data;
	*head = (Node *)pointer->ptr;

	return exit_with_sucsess;
}

Ret_type_t stackPush(Node** head, List_t data)
{
	Node* new_node = (Node *)malloc(sizeof(Node));

	new_node->data = data;
	new_node->ptr = (struct Node*)(*head);

	*head = new_node;

	return exit_with_sucsess;
}
