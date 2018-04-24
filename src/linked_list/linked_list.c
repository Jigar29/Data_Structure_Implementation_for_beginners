#include <linked_list.h>
#include <stdio.h>

void printLinkedList(List_node_t *head)
{
	List_node_t *pointer = (List_node_t *)head;

	if(head == 0)
	{
		printf("The list is empty. Can't Print Anything\n");
		return;
	}
	while(pointer != 0)
	{
		printf("%d", pointer->data);
		pointer = (List_node_t *)pointer->ptr;
	}
	printf("\n");
}

List_t getHeadValue(List_node_t *head)
{
	if(isEmpty(head) == true)
	{
		printf("The list is empty. Can't get the Head\n");
		return -32768;
	}
	List_node_t *pointer = (List_node_t *)head;
	return pointer->data;
}

Ret_type_t isEmpty(List_node_t *head)
{
	return (head == 0)?true:false;
}

int sizeOfLinkedlist(List_node_t *head)
{
	List_node_t *pointer = (List_node_t *)head;

	int i =0;
	while(pointer!=0)
	{
		pointer = (List_node_t *)pointer->ptr;
		i++;
	}
	return i;
}

Ret_type_t appendToLinkedList(List_node_t **head, List_t data)
{
	List_node_t *pointer = (List_node_t *)(*head);
	List_node_t *new_node = (List_node_t *)malloc(sizeof(List_node_t));

	if((*head) == 0)
	{
		return exit_with_failure;
	}

	while(pointer->ptr!= 0)
	{
		pointer = (List_node_t *)pointer->ptr;
	}

	pointer->ptr = (struct List_node_t*) new_node;
	new_node->data = data;
	new_node->ptr = 0;
	return exit_with_sucsess;
}

Ret_type_t prependToLinkedList(List_node_t **head, List_t data)
{
	List_node_t *pointer = (List_node_t *) (*head);
	List_node_t *new_node = (List_node_t *)malloc(sizeof(List_node_t));

	if((*head) == 0)
	{
		return exit_with_failure;
	}

	(*head) = (List_node_t *)new_node;
	new_node->data = data;
	new_node->ptr = (struct List_node_t *)pointer;
	return exit_with_sucsess;
}

Ret_type_t insertToLinkedList(List_node_t **head, int node_pos, List_t data)
{
	List_node_t *pointer = (List_node_t *)(*head);
	List_node_t *new_node = (List_node_t *)malloc(sizeof(List_node_t));

	if(node_pos <= 0)
		return exit_with_failure;

	if(node_pos > (sizeOfLinkedlist(*head)+1))
	{
		printf("The position asked is greater than the list size\n");
		return exit_with_failure;
	}

	for(int i=1; i<node_pos-1; i++)
	{
		pointer = (List_node_t *) pointer->ptr;
	}

	if(node_pos == 1)
	{
		if((*head) == 0)
		{
			(*head) = (List_node_t *)new_node;
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
		pointer->ptr = (struct List_node_t *)new_node;
	}

	return exit_with_sucsess;
}

Ret_type_t delete(List_node_t ** head, int node_pos)
{
	List_node_t *pointer = (List_node_t *)(*head);
	List_node_t *node_to_be_deleted = (List_node_t *)0;

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
		(*head) = (List_node_t *)pointer->ptr;
		free(pointer);
	}
	else
	{
		for(int i=1; i<node_pos-1; i++)
		{
			pointer = (List_node_t *)pointer->ptr;
		}
		node_to_be_deleted  = (List_node_t *)pointer->ptr;
		pointer->ptr = node_to_be_deleted->ptr;
		free(node_to_be_deleted);
	}
	return exit_with_sucsess;
}

Ret_type_t reverseLinkedList(List_node_t **head)
{
	List_node_t *current_node = (List_node_t *) (*head), *previous_node = 0, *next_node = 0;

	if((*head) == 0)
	{
		printf("The list is empty. It can't be reversed\n");
		return exit_with_failure;
	}

	while(current_node != 0)
	{
		next_node = (List_node_t *)current_node->ptr;
		current_node->ptr = (struct List_node_t *) previous_node;
		previous_node = current_node;
		current_node = next_node;
	}
	(*head) = (List_node_t *) previous_node;

	return exit_with_sucsess;
}
