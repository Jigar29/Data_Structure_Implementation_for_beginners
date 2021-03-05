/*
 * priority_queue.c
 *
 *  Created on: Aug 12, 2018
 *      Author: Jigar
 */
#include "priority_queue.h"

/***************Formulas*******************
 ******** Here i starts from 0 not 1*******
 *
 * Parent Node: |(i-1)/2|
 * Left Node: 2*i + 1
 * Right Node: 2*i + 2
 */

void printPriorityQueue(Priority_queue_node_t *pq)
{
	if(!pq)
		return;

	if(pq->size == 0)
	{
		printf("\nPriority Queue is Empty.");
		return;
	}

	printf("\n");
	for(int i =0; i<pq->size; i++)
	{
		printf("%d, ", pq->data[i].value);
	}
}

Priority_queue_t getPriorityQueueSize(Priority_queue_node_t *pq)
{
	if(!pq)
		return -1;

	return pq->size;
}

Ret_type_t isPriorityQueueFull(Priority_queue_node_t *pq)
{
	return (pq->size >= pq->priority_queue_max_size)?true:false;
}

Ret_type_t isPriorityQueueEmpty(Priority_queue_node_t *pq)
{
	return(pq->size == 0)?true:false;
}

Priority_queue_t getMinPriority(Priority_queue_node_t *pq)
{
	if(!pq)
		return -1;

	if(pq->size == 0)
	{
		printf("\nQueue is empty.");
		return -1;
	}
	return pq->data[0].value;
}

Ret_type_t insertToPriorityQueue(Priority_queue_node_t *pq, Priority_queue_t value, Priority_queue_t priority)
{
	if(!pq)
		return exit_with_abruption;

	if(isPriorityQueueFull(pq) == true)
	{
		printf("\nQueue is full.");
		return exit_with_failure;
	}

	pq->data[pq->size].value = value;
	pq->data[pq->size].priority = priority;

	pq->size++;

	int i = pq->size -1, temp = 0;
	while(i > 0)
	{
		temp = (int)((i-1)/2);
		if(pq->data[i].priority < pq->data[temp].priority)
		{
			pq->data[i].priority ^= pq->data[temp].priority;
			pq->data[temp].priority ^= pq->data[i].priority;
			pq->data[i].priority ^= pq->data[temp].priority;
			pq->data[i].value ^= pq->data[temp].value;
			pq->data[temp].value ^= pq->data[i].value;
			pq->data[i].value ^= pq->data[temp].value;
		}
		else
			break;

		i = temp;
	}
	return exit_with_sucsess;
}

Ret_type_t deleteFromPriorityQueue(Priority_queue_node_t *pq)
{
	// Null - done
	// empty - done
	// one node - done
	// no child nodes - done
	// heap is good - done
	// only one child node - done
	// 2 nodes - done
	// normal usecase

	if(!pq)
		return exit_with_abruption;

	if(isPriorityQueueEmpty(pq) == true)
	{
		printf("\nQueue is empty.");
		return exit_with_failure;
	}

	pq->data[0].priority = pq->data[pq->size-1].priority;
	pq->data[0].value = pq->data[pq->size-1].value;
	pq->size--;

	int i =0;
	while(i < pq->size)
	{
		if(((2*i + 1) > (pq->size -1)) && ((2*i + 2)>(pq->size -1)))
			break;

		if((2*i + 2) > (pq->size -1))
		{
			if(pq->data[i].priority > pq->data[2*i + 1].priority)
			{
				pq->data[i].priority ^= pq->data[2*i + 1].priority;
				pq->data[2*i + 1].priority ^= pq->data[i].priority;
				pq->data[i].priority ^= pq->data[2*i + 1].priority;
				pq->data[i].value ^= pq->data[2*i + 1].value;
				pq->data[2*i + 1].value ^= pq->data[i].value;
				pq->data[i].value ^= pq->data[2*i + 1].value;
			}
			break;
		}

		if((pq->data[i].priority <= pq->data[2*i + 1].priority) && (pq->data[i].priority <= pq->data[2*i+2].priority))
			break;

		if((pq->data[i].priority - pq->data[2*i + 1].priority) >= (pq->data[i].priority - pq->data[2*i + 2].priority))
		{
			pq->data[i].priority ^= pq->data[2*i + 1].priority;
			pq->data[2*i + 1].priority ^= pq->data[i].priority;
			pq->data[i].priority ^= pq->data[2*i + 1].priority;
			pq->data[i].value ^= pq->data[2*i + 1].value;
			pq->data[2*i + 1].value ^= pq->data[i].value;
			pq->data[i].value ^= pq->data[2*i + 1].value;

			i = 2*i+1;
		}
		else
		{
			pq->data[i].priority ^= pq->data[2*i + 2].priority;
			pq->data[2*i + 2].priority ^= pq->data[i].priority;
			pq->data[i].priority ^= pq->data[2*i + 2].priority;
			pq->data[i].value ^= pq->data[2*i + 2].value;
			pq->data[2*i + 2].value ^= pq->data[i].value;
			pq->data[i].value ^= pq->data[2*i + 2].value;

			i = 2*i + 2;
		}

	}
	return exit_with_sucsess;
}
