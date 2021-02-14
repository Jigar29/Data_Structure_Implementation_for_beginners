/*
 * heap.c
 *
 *  Created on: Apr 23, 2018
 *      Author: Jigar
 */

#include "heap.h"

/***************Formulas*******************
 ******** Here i starts from 1 not 0*******
 *
 * Parent Node: |i/2|
 * Left Node: 2*i
 * Right Node: 2*i + 1
 */

void printHeap(Heap_node_t *heap)
{
	if(!heap)
		return;

	printf("\n");
	if(heap->size == 0)
	{
		printf("Heap is empty");
		return;
	}

	for(int i=0; i<heap->size; i++)
	{
		printf("%d, ", heap->array_adr[i]);
	}
}

Heap_t getHeapSize(Heap_node_t *heap)
{
	return heap->size;
}

Ret_type_t isHeapFull(Heap_node_t *heap)
{
	return (heap->size == heap->heap_max_size) ? true : false;
}

Ret_type_t isHeapEmpty(Heap_node_t *heap)
{
	return (heap->size) ? false : true;
}

Heap_t getMinNum(Heap_node_t *heap)
{
	return heap->array_adr[0];
}

Ret_type_t insertToHeap(Heap_node_t *heap, Heap_t data)
{
	if(!heap)
		return exit_with_abruption;

	if(isHeapFull(heap) == true)
	{
		printf("Heap is full.");
		return exit_with_failure;
	}

	if(isHeapEmpty(heap) == true)
	{
		heap->array_adr[0] = data;
		heap->size++;
		return exit_with_sucsess;
	}

	heap->array_adr[heap->size] = data;
	heap->size++;

	int temp = 0;
	int i = heap->size;
	// Arrange the element
	while(i > 1)
	{
		temp = (int)(i / 2);
		if(heap->array_adr[temp-1] > heap->array_adr[i-1])
		{
			heap->array_adr[temp-1] ^= heap->array_adr[i-1];
			heap->array_adr[i-1] ^= heap->array_adr[temp-1];
			heap->array_adr[temp-1] ^= heap->array_adr[i-1];
		}
		else
			break;

		i = temp;
	}

	return exit_with_sucsess;
}

Ret_type_t deleteFromHeap(Heap_node_t *heap)
{
	// only one node - done
	// only one child node - done
	// no child  node(2 elements) - done
	// root is min after replacement - done
	// null heap - done
	// empty heap - done
	if(!heap)
		return exit_with_abruption;

	if(isHeapEmpty(heap) == true)
	{
		printf("Heap is empty.\n");
		return exit_with_failure;
	}

	heap->array_adr[0] = heap->array_adr[heap->size - 1];
	heap->size--;

	int i =1;

	while(heap->size >= i)
	{
		if(((2*i) > heap->size) && ((2*i -1) > heap->size))
		{
			break;
		}

		if((2*i) > heap->size)
		{
			if(heap->array_adr[i-1] > heap->array_adr[2*i-1])
			{
				heap->array_adr[i-1] ^= heap->array_adr[2*i-1];
				heap->array_adr[2*i-1] ^= heap->array_adr[i-1];
				heap->array_adr[i-1] ^= heap->array_adr[2*i-1];
			}
			break;
		}

		if((heap->array_adr[i-1] <= heap->array_adr[2*i-1]) &&
				(heap->array_adr[i-1] <= heap->array_adr[2*i]))
		{
			break;
		}

		if(heap->array_adr[2*i] > heap->array_adr[2*i-1])
		{
			heap->array_adr[i-1] ^= heap->array_adr[2*i-1];
			heap->array_adr[2*i-1] ^= heap->array_adr[i-1];
			heap->array_adr[i-1] ^= heap->array_adr[2*i-1];
			i = 2*i;
		}
		else
		{
			heap->array_adr[i-1] ^= heap->array_adr[2*i];
			heap->array_adr[2*i] ^= heap->array_adr[i-1];
			heap->array_adr[i-1] ^= heap->array_adr[2*i];
			i = 2 * i +1;
		}
	}

	return exit_with_sucsess;
}
