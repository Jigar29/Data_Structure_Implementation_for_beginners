#include <linked_list.h>
#include <stdio.h>
#include "stdlib.h"

void printLinkedList(Node *head)
{
	Node *pointer = (Node *)head;

	if(head == 0)
	{
		printf("The list is empty. Can't Print Anything\n");
		return;
	}
	while(pointer != 0)
	{
		printf("%d", pointer->data);
		pointer = (Node *)pointer->ptr;
	}
	printf("\n");
}

List_t getHeadValue(Node *head)
{
	if(isEmpty(head) == true)
	{
		printf("The list is empty. Can't get the Head\n");
		return -32768;
	}
	Node *pointer = (Node *)head;
	return pointer->data;
}

Ret_type_t isEmpty(Node *head)
{
	return (head == 0)?true:false;
}

int sizeOfLinkedlist(Node *head)
{
	Node *pointer = (Node *)head;

	int i =0;
	while(pointer!=0)
	{
		pointer = (Node *)pointer->ptr;
		i++;
	}
	return i;
}

Ret_type_t appendToLinkedList(Node **head, List_t data)
{
	Node *pointer = (Node *)(*head);
	Node *new_node = (Node *)malloc(sizeof(Node));

	if((*head) == 0)
	{
		return exit_with_failure;
	}

	while(pointer->ptr!= 0)
	{
		pointer = (Node *)pointer->ptr;
	}

	pointer->ptr = (struct Node*) new_node;
	new_node->data = data;
	new_node->ptr = 0;
	return exit_with_sucsess;
}

Ret_type_t prependToLinkedList(Node **head, List_t data)
{
	Node *pointer = (Node *) (*head);
	Node *new_node = (Node *)malloc(sizeof(Node));

	if((*head) == 0)
	{
		return exit_with_failure;
	}

	(*head) = (Node *)new_node;
	new_node->data = data;
	new_node->ptr = (struct Node *)pointer;
	return exit_with_sucsess;
}

Ret_type_t insertToLinkedList(Node **head, int node_pos, List_t data)
{
	Node *pointer = (Node *)(*head);
	Node *new_node = (Node *)malloc(sizeof(Node));

	if(node_pos <= 0)
		return exit_with_failure;

	if(node_pos > (sizeOfLinkedlist(*head)+1))
	{
		printf("The position asked is greater than the list size\n");
		return exit_with_failure;
	}

	for(int i=1; i<node_pos-1; i++)
	{
		pointer = (Node *) pointer->ptr;
	}

	if(node_pos == 1)
	{
		if((*head) == 0)
		{
			(*head) = (Node *)new_node;
			new_node->ptr = 0;
			new_node->data = data;
		}
		else
		{
			prependToLinkedList(head, data);
		}
	}
	else
	{
		new_node->ptr = pointer->ptr;
		new_node->data = data;
		pointer->ptr = (struct Node *)new_node;
	}

	return exit_with_sucsess;
}

Ret_type_t delete(Node ** head, int node_pos)
{
	Node *pointer = (Node *)(*head);
	Node *node_to_be_deleted = (Node *)0;

	if(isEmpty(*head) == true)
	{
		return exit_with_failure;
	}

	if(node_pos > sizeOfLinkedlist(*head))
	{
		printf("The position asked is greater than the list size\n");
		return exit_with_failure;
	}

	if(node_pos == 1)
	{
		(*head) = (Node *)pointer->ptr;
		free(pointer);
	}
	else
	{
		for(int i=1; i<node_pos-1; i++)
		{
			pointer = (Node *)pointer->ptr;
		}
		node_to_be_deleted  = (Node *)pointer->ptr;
		pointer->ptr = node_to_be_deleted->ptr;
		free(node_to_be_deleted);
	}
	return exit_with_sucsess;
}

Ret_type_t reverseLinkedList(Node **head)
{
	Node *current_node = (Node *) (*head), *previous_node = 0, *next_node = 0;

	if((*head) == 0)
	{
		printf("The list is empty. It can't be reversed\n");
		return exit_with_failure;
	}

	while(current_node != 0)
	{
		next_node = (Node *)current_node->ptr;
		current_node->ptr = (struct Node *) previous_node;
		previous_node = current_node;
		current_node = next_node;
	}
	(*head) = (Node *) previous_node;

	return exit_with_sucsess;
}
