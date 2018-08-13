/*
 * priority_queue.c
 *
 *  Created on: Aug 12, 2018
 *      Author: Jigar
 */
#include "priority_queue.h"

void printPriorityQueue(Priority_queue_node_t *pq)
{
	Priority_queue_t pq_size = getPriorityQueueSize(pq);

	for(int i=0; i<pq_size;i++)
	{
		printf("%d, ", pq->data[i].value);
	}
	printf("\n");
}

Priority_queue_t getPriorityQueueSize(Priority_queue_node_t *pq)
{
	if(pq->current_pos == -1)
	{
		return 0;
	}
	else
		return (pq->current_pos + 1);
}

Ret_type_t isPriorityQueueFull(Priority_queue_node_t *pq)
{
	return (getPriorityQueueSize(pq) == pq->priority_queue_max_size)?true:false;
}

Ret_type_t isPriorityQueueEmpty(Priority_queue_node_t *pq)
{
	return (getPriorityQueueSize(pq) == 0)?true:false;
}

Priority_queue_t getMinPriority(Priority_queue_node_t *pq)
{
	if(isPriorityQueueEmpty(pq) == true)
	{
		printf("The Priority Queue is empty\n");
		return -65556;
	}

	return pq->data[0].value;
}

Ret_type_t insertToPriorityQueue(Priority_queue_node_t *pq, Priority_queue_t value, Priority_queue_t priority)
{
	if(isPriorityQueueFull(pq) == true)
		return exit_with_failure;

	//Adding value to the last of the element
	pq->current_pos += 1;
	pq->data[pq->current_pos].value = value;
	pq->data[pq->current_pos].priority = priority;

	int i= pq->current_pos;
	Priority_queue_t temp = 0, temp_priority = 0, temp_addr = 0;
	while(i > 0)
	{
		if(i %2 == 0)
		{
			temp_addr = (int) ((i -2)/2);
			if(pq->data[temp_addr].priority > pq->data[i].priority)
			{
				temp = pq->data[temp_addr].value;
				temp_priority = pq->data[temp_addr].priority;

				pq->data[temp_addr].value = pq->data[i].value;
				pq->data[temp_addr].priority = pq->data[i].priority;

				pq->data[i].value = temp;
				pq->data[i].priority = temp_priority;
			}
			i = temp_addr;
		}
		else
		{
			temp_addr = (i -1)/2;
			if(pq->data[temp_addr].priority > pq->data[i].priority)
			{
				temp = pq->data[temp_addr].value;
				temp_priority = pq->data[temp_addr].priority;

				pq->data[temp_addr].value = pq->data[i].value;
				pq->data[temp_addr].priority = pq->data[i].priority;

				pq->data[i].value = temp;
				pq->data[i].priority = temp_priority;
			}
			i = temp_addr;
		}
	}
	return exit_with_sucsess;
}

Ret_type_t deleteFromPriorityQueue(Priority_queue_node_t *pq)
{
	if(isPriorityQueueEmpty(pq) == true)
	{
		printf("The Priority Queue is empty, there is nothing to delete\n");
		return exit_with_failure;
	}

	pq->data[0].value = pq->data[pq->current_pos].value;
	pq->data[0].priority = pq->data[pq->current_pos].priority;

	pq->current_pos -=1;

	int i=0;
	Priority_queue_t temp = 0, temp_priority =0 ,temp_addr = 0;
	while((2*i + 1 <= pq->current_pos) || (2*i + 2 <= pq->current_pos))
	{
		if((2*i + 2) > pq->current_pos)
		{
			temp_addr = 2*i + 1;
			if(pq->data[temp_addr].priority < pq->data[i].priority)
			{
				temp = pq->data[temp_addr].value;
				temp_priority = pq->data[temp_addr].priority;

				pq->data[temp_addr].value = pq->data[i].value;
				pq->data[temp_addr].priority = pq->data[i].priority;

				pq->data[i].value = temp;
				pq->data[i].priority = temp_priority;
			}
			i = temp_addr;
		}
		else
		{
			temp_addr = 2*i + 1;
			if(pq->data[temp_addr].priority > pq->data[temp_addr+1].priority)
			{
				if(pq->data[temp_addr +1].priority < pq->data[i].priority)
				{
					temp = pq->data[temp_addr+1].value;
					temp_priority = pq->data[temp_addr+1].priority;

					pq->data[temp_addr+1].value = pq->data[i].value;
					pq->data[temp_addr+1].priority = pq->data[i].priority;

					pq->data[i].value = temp;
					pq->data[i].priority = temp_priority;
				}
				i = temp_addr+1;
			}
			else
			{
				if(pq->data[temp_addr].priority < pq->data[i].priority)
				{
					temp = pq->data[temp_addr].value;
					temp_priority = pq->data[temp_addr].priority;

					pq->data[temp_addr].value = pq->data[i].value;
					pq->data[temp_addr].priority = pq->data[i].priority;

					pq->data[i].value = temp;
					pq->data[i].priority = temp_priority;
				}
				i =temp_addr;
			}
		}
	}

	return exit_with_sucsess;
}
