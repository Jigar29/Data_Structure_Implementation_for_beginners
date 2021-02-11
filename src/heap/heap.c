/*
 * heap.c
 *
 *  Created on: Apr 23, 2018
 *      Author: Jigar
 */

#include "heap.h"

void printHeap(Heap_node_t *heap)
{
	Heap_t heap_size = getHeapSize(heap);

	for(int i=0; i<heap_size;i++)
	{
		printf("%d, ", heap->array_adr[i]);
	}
	printf("\n");
}

Heap_t getHeapSize(Heap_node_t *heap)
{
	if(heap->current_pos == -1)
	{
		return 0;
	}
	else
		return (heap->current_pos + 1);
}

Ret_type_t isHeapFull(Heap_node_t *heap)
{
	return (getHeapSize(heap) == heap->heap_max_size)?true:false;
}

Ret_type_t isHeapEmpty(Heap_node_t *heap)
{
	return (getHeapSize(heap) == 0)?true:false;
}

Heap_t getMinNum(Heap_node_t *heap)
{
	if(isHeapEmpty(heap) == true)
	{
		printf("The Heap is empty\n");
		return -65556;
	}

	return heap->array_adr[0];
}

Ret_type_t insertToHeap(Heap_node_t *heap, Heap_t data)
{
	if(isHeapFull(heap) == true)
		return exit_with_failure;

	//Adding value to the last of the element
	heap->current_pos += 1;
	heap->array_adr[heap->current_pos] = data;

	int i=heap->current_pos;
	Heap_t temp = 0, temp_addr = 0;
	while(i > 0)
	{
		if(i %2 == 0)
		{
			temp_addr = (int) ((i -2)/2);
			if(heap->array_adr[temp_addr] > heap->array_adr[i])
			{
				temp = heap->array_adr[temp_addr];
				heap->array_adr[temp_addr] = heap->array_adr[i];
				heap->array_adr[i] = temp;
			}
			i = temp_addr;
		}
		else
		{
			temp_addr = (i -1)/2;
			if(heap->array_adr[temp_addr] > heap->array_adr[i])
			{
				temp = heap->array_adr[temp_addr];
				heap->array_adr[temp_addr] = heap->array_adr[i];
				heap->array_adr[i] = temp;
			}
			i = temp_addr;
		}
	}
	return exit_with_sucsess;
}

Ret_type_t deleteFromHeap(Heap_node_t *heap)
{
	if(isHeapEmpty(heap) == true)
	{
		printf("The Heap is empty, there is nothing to delete\n");
		return exit_with_failure;
	}

	heap->array_adr[0] = heap->array_adr[heap->current_pos];
	heap->current_pos -=1;

	int i=0;
	Heap_t temp = 0, temp_addr = 0;
	while((2*i + 1 <= heap->current_pos) || (2*i + 2 <= heap->current_pos))
	{
		if((2*i + 2) > heap->current_pos)
		{
			temp_addr = 2*i + 1;
			if(heap->array_adr[temp_addr] < heap->array_adr[i])
			{
				temp = heap->array_adr[temp_addr];
				heap->array_adr[temp_addr] = heap->array_adr[i];
				heap->array_adr[i] = temp;
			}
			i = temp_addr;
		}
		else
		{
			temp_addr = 2*i + 1;
			if(heap->array_adr[temp_addr] > heap->array_adr[temp_addr+1])
			{
				if(heap->array_adr[temp_addr +1] < heap->array_adr[i])
				{
					temp = heap->array_adr[temp_addr+1];
					heap->array_adr[temp_addr+1] = heap->array_adr[i];
					heap->array_adr[i] = temp;
				}
				i = temp_addr+1;
			}
			else
			{
				if(heap->array_adr[temp_addr] < heap->array_adr[i])
				{
					temp = heap->array_adr[temp_addr];
					heap->array_adr[temp_addr] = heap->array_adr[i];
					heap->array_adr[i] = temp;
				}
				i =temp_addr;
			}
		}
	}

	return exit_with_sucsess;
}
