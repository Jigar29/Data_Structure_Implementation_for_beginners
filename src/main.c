#include <linked_list.h>
#include <stack.h>
#include <stdio.h>
#include <stdint.h>

int main()
{
	Node *head = 0;
	List_t stack_data = 0;
/*	insertToLinkedList(&head, 1, 1);
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
	printLinkedList(head);*/

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

	return 0;
}
