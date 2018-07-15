#include <linked_list.h>
#include <stack.h>
#include <stdio.h>
#include <stdint.h>
#include "queue.h"
#include "binary_tree.h"

#define binary_tree 1
//#define heap 1
//#define queue 1
//#define stack 1
//#define linkedlist 1

int main()
{
#ifdef linkedlist
	List_node_t *head = 0, *tail = 0;
	insertToLinkedList(&head, 1, 1);
	insertToLinkedList(&head, 2, 2);

	printLinkedList(head);
	appendToLinkedList(&head, 3);
	printLinkedList(head);

	prependToLinkedList(&head, 6);

	printLinkedList(head);
	printf("Head Value is = %d\n", (int)getHeadValue(head));

	if(isEmpty(head) == true)
	{
		printf("Yes the list is empty\n");
	}
	else
	{
		printf("No the list is not empty\n");
	}

	printf("Size of the List is = %d\n", sizeOfLinkedlist(head));

	if(delete(&head, 1) == exit_with_sucsess)
	{
		printf("Linked List After Deletion\n");
		printLinkedList(head);
	}
	reverseLinkedList(&head);
	printf("Reverse string is as following\n");
	printLinkedList(head);
#elif stack
	List_node_t *head = 0, *tail = 0;
	List_t stack_data = 0;
	stackPush(&head, 5);
	stackPush(&head, 6);
	printStack(head);
	printf("Top of the stack is = %d\n",stackTop(head));
	printf("Stack Size is = %d\n", stackGetSize(head));

	if(stackPop(&head, &stack_data) == exit_with_sucsess)
	{
		printStack(head);
		printf("Top of the stack is = %d\n",stackTop(head));
	}
#elif queue
	List_node_t *head = 0, *tail = 0;
	List_t queue_data = 0;

	enQueue(&head, &tail, 5);
	enQueue(&head, &tail, 7);
	enQueue(&head, &tail, 10);
	enQueue(&head, &tail, 2);

	if(front(head, tail, &queue_data) == exit_with_sucsess)
	{
		printf("The data front is %d\n", queue_data);
	}
	printf("Size of the Queue is %d\n", getQueueSize(head, tail));
	printQueue(head, tail);

	if(deQueue(&head, &tail, &queue_data)== exit_with_sucsess)
	{
		printf("Data Dequeued is = %d\n", queue_data);
		printQueue(head, tail);
	}
	if(deQueue(&head, &tail, &queue_data)== exit_with_sucsess)
	{
		printf("Data Dequeued is = %d\n", queue_data);
		printQueue(head, tail);
	}
	if(front(head, tail, &queue_data) == exit_with_sucsess)
	{
		printf("The data front is %d\n", queue_data);
	}
	printf("Size of the Queue is %d\n", getQueueSize(head, tail));
	printQueue(head, tail);

#elif binary_tree
	Tree_node_t* root_node = NULL;

	insertToTree((Tree_node_t **)&root_node, 7);
	insertToTree((Tree_node_t **)&root_node, 5);
	insertToTree((Tree_node_t **)&root_node, 9);
	insertToTree((Tree_node_t **)&root_node, 10);
	insertToTree((Tree_node_t **)&root_node, 2);
	insertToTree((Tree_node_t **)&root_node, 1);
	insertToTree((Tree_node_t **)&root_node, 8);
//	insertToTree((Tree_node_t **)&root_node, 10);
//	insertToTree((Tree_node_t **)&root_node, 2);
//	insertToTree((Tree_node_t **)&root_node, 1);
//	insertToTree((Tree_node_t **)&root_node, 8);

	{
		printf("The tree is Empty, please fill in the data first\n");
	}

#endif
	return 0;
}
