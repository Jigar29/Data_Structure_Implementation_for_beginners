#include "queue.h"

Ret_type_t isQueueEmpty(Node * head, Node* tail)
{
	return ((head == 0)&&(tail == 0))? true: false;
}

int getQueueSize(Node * head, Node *tail)
{
	Node *pointer = head;
	int size = 0;

	if(isQueueEmpty(head, tail) == false)
	{
		size = 1;
		while(pointer != tail)
		{
			pointer = (Node *) pointer->ptr;
			size+=1;
		}
	}

	return size;
}

Ret_type_t printQueue(Node * head, Node *tail)
{
	Node *pointer = head;

	if(isQueueEmpty(head, tail) == true)
	{
		printf("The Queue is Empty. Nothing to print\n");
		return exit_with_abruption;
	}
	printf("***************************Queue***************************\n");
	for(int i=0; i<getQueueSize(head, tail); i++)
	{
		printf("%d<-", pointer->data);
		pointer = (Node *) pointer->ptr;
	}
	printf("\n");
	printf("***********************************************************\n");
	return exit_with_sucsess;
}

Ret_type_t front(Node *head, Node *tail, List_t *front_data)
{
	Node *pointer = head;
	if(isQueueEmpty(head, tail) == false)
	{
		*front_data = pointer->data;
		return exit_with_sucsess;
	}
	printf("The list is empty, The operation can not be performed\n");
	return exit_with_failure;
}

Ret_type_t enQueue(Node **head, Node **tail, List_t data)
{
	Node *new_node = (Node *) malloc(sizeof(Node));

	if(isQueueEmpty(*head, *tail) == true)
	{
		*head = new_node;
	}
	else
	{
		(*tail)->ptr = (struct Node *)new_node;
	}

	new_node->data = data;
	new_node->ptr = 0;
	*tail = new_node;
	return exit_with_sucsess;
}

Ret_type_t deQueue(Node **head, Node **tail, List_t *rec_data)
{
	Node *pointer = *head;

	if(isQueueEmpty(*head, *tail) == true)
	{
		printf("The Queue is empty, There is nothing to dequeue\n");
		return exit_with_failure;
	}

	*rec_data = (*head)->data;
	*head = (Node *)(*head)->ptr;
	free(pointer);
	return exit_with_sucsess;
}
