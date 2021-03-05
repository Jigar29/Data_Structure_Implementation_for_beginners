/*
 * heap.c
 *
 *  Created on: Apr 23, 2018
 *      Author: Jigar
 */

#include "heap.h"

/***************Formulas*******************
 ******** Here i starts from 0 not 1*******
 *
 * Parent Node: |(i-1)/2|
 * Left Node: 2*i + 1
 * Right Node: 2*i + 2
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

	heap->array_adr[heap->size] = data;
	heap->size++;

	int temp = 0;
	int i = heap->size-1;
	// Arrange the element
	while(i > 0)
	{
		temp = (int)((i-1) / 2);
		if(heap->array_adr[temp] > heap->array_adr[i])
		{
			heap->array_adr[temp] ^= heap->array_adr[i];
			heap->array_adr[i] ^= heap->array_adr[temp];
			heap->array_adr[temp] ^= heap->array_adr[i];
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

	int i =0;

	while(i < heap->size)
	{
		if(((2*i + 1) > (heap->size - 1)) && ((2*i + 2) > (heap->size - 1)))
		{
			break;
		}

		if((2*i + 2) > (heap->size - 1))
		{
			if(heap->array_adr[i] > heap->array_adr[2*i + 1])
			{
				heap->array_adr[i] ^= heap->array_adr[2*i + 1];
				heap->array_adr[2*i + 1] ^= heap->array_adr[i];
				heap->array_adr[i] ^= heap->array_adr[2*i + 1];
			}
			break;
		}

		if((heap->array_adr[i] <= heap->array_adr[2*i + 1]) &&
				(heap->array_adr[i] <= heap->array_adr[2*i + 2]))
		{
			break;
		}

		if((heap->array_adr[i] - heap->array_adr[2*i + 1]) >=
				(heap->array_adr[i] - heap->array_adr[2*i + 2]))
		{
			heap->array_adr[i] ^= heap->array_adr[2*i + 1];
			heap->array_adr[2*i + 1] ^= heap->array_adr[i];
			heap->array_adr[i] ^= heap->array_adr[2*i + 1];
			i = 2*i + 1;
		}
		else
		{
			heap->array_adr[i] ^= heap->array_adr[2*i + 2];
			heap->array_adr[2*i + 2] ^= heap->array_adr[i];
			heap->array_adr[i] ^= heap->array_adr[2*i + 2];
			i = 2*i + 2;
		}
	}

	return exit_with_sucsess;
}
