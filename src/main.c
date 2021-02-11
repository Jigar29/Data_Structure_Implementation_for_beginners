#include <stdio.h>
#include <stdint.h>
#include "linked_list.h"
#include "stack.h"
#include "queue.h"
#include "binary_tree.h"
#include "circular_queue.h"
#include "heap.h"
#include "nodes.h"
#include "priority_queue.h"
#include "graph.h"

//#define binary_tree 1
//#define heap 1
//#define queue 1
//#define stack 1
//#define linkedlist 1
#define circular_queue 1
//#define priority_queue 1
//#define graph 1

int main() {
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
	insertToTree((Tree_node_t **)&root_node, 4);
	insertToTree((Tree_node_t **)&root_node, 1);
	insertToTree((Tree_node_t **)&root_node, 8);
	insertToTree((Tree_node_t **)&root_node, 0);
	insertToTree((Tree_node_t **)&root_node, 2);
	insertToTree((Tree_node_t **)&root_node, -1);
	insertToTree((Tree_node_t **)&root_node, 6);

	//printf("The minimum number in a tree is %d\n", findMinElement(root_node));
	if(searchInTree(root_node, -1) == true)
	{
		printf("The element exists in the given tree\n");
	}
	else
	{
		printf("The element does not exists in the given tree\n");
	}

	if(isTreeEmpty(root_node) == true)
	{
		printf("The tree is Empty, please fill in the data first\n");
	}
	printf("Min No is %d\n", findMinElement(root_node));
	printf("Max No is %d\n", findMaxElement(root_node));

	printTree(root_node, 0);
	printf("In-Order Traversal List\n");
	inOrderTraversal(root_node);
	printf("\nPre-Order Traversal List\n");
	preOrderTraversal(root_node);
	printf("\nPost-Order Traversal List\n");
	postOrderTraversal(root_node);

	#elif circular_queue
	Queue_t array[5];
	int data;
	Circular_queue_t queue = { .queue_max_size = 5 };
	queue.array_adr = (Queue_t*) &array[0];
	queue.front_idx = -1;
	queue.size = 0;

	pushElementInQueue(&queue, 1);
	pushElementInQueue(&queue, 2);
	pushElementInQueue(&queue, 3);
	pushElementInQueue(&queue, 4);
	pushElementInQueue(&queue, 5);
	pushElementInQueue(&queue, 6);

	printcircularQueue(&queue);
	popElementInQueue(&queue, &data);
	popElementInQueue(&queue, &data);
	popElementInQueue(&queue, &data);
	popElementInQueue(&queue, &data);
	pushElementInQueue(&queue, 4);

	printcircularQueue(&queue);
	printf("\nLast element is = %d", getLastElement(&queue));
	printf("\nFirst element is = %d", getFrontElement(&queue));

#elif heap
	Heap_t array[10] = {-1};
	Heap_node_t heap_struct = {10, -1, &array[0]};

	insertToHeap(&heap_struct, 6);
	insertToHeap(&heap_struct, 7);
	insertToHeap(&heap_struct, 8);
	insertToHeap(&heap_struct, 9);
	insertToHeap(&heap_struct, 10);
	insertToHeap(&heap_struct, 5);
	printHeap(&heap_struct);
	deleteFromHeap(&heap_struct);
	printHeap(&heap_struct);

#elif priority_queue
	Priority_queue_data_t data[10];
	Priority_queue_node_t pq = {10, -1, &data[0]};

	insertToPriorityQueue(&pq, 4, 4);
	insertToPriorityQueue(&pq, 1, 1);
	insertToPriorityQueue(&pq, 2, 2);

	deleteFromPriorityQueue(&pq);
	printPriorityQueue(&pq);
#elif graph
	Vertice_list_t *vertices_head = NULL;

	addVerticeToGraph(&vertices_head);
	addVerticeToGraph(&vertices_head);
	addVerticeToGraph(&vertices_head);

	addEdgeToVertice(getEdgeHeadFromVertice(vertices_head, 1), 2);
	addEdgeToVertice(getEdgeHeadFromVertice(vertices_head, 1), 3);
	addEdgeToVertice(getEdgeHeadFromVertice(vertices_head, 2), 3);

	printf("Neighbours are\n");
	getNeibour(vertices_head, 2);
	printf("\n");
	printVertices(vertices_head);
	printf("\n");
	printEdges(*getEdgeHeadFromVertice(vertices_head, 2));
	printf("\n");
	deleteEdgeFromVertice(getEdgeHeadFromVertice(vertices_head, 1), 2);
	printEdges(*getEdgeHeadFromVertice(vertices_head, 1));
	printf("\n");
	deleteEdgeFromVertice(getEdgeHeadFromVertice(vertices_head, 2), 1);
	printEdges(*getEdgeHeadFromVertice(vertices_head, 2));
	printf("\n");
	deleteVerticeFromGraph(&vertices_head, 1);
	printVertices(vertices_head);

#endif
	return 0;
}
