#include "circular_queue.h"

Ret_type_t isCircularQueueInitialized(Circular_queue_t *queue)
{
	if(!queue) {
		return false;
	}
	else
		return true;
}

Ret_type_t isCircularQueueFull(Circular_queue_t *queue)
{
	return (queue->size == queue->queue_max_size)?true:false;
}

Ret_type_t isCircularQueueEmpty(Circular_queue_t *queue)
{
	return (queue->size == 0)?true:false;
}


void printcircularQueue(Circular_queue_t *queue)
{
	int idx = 0;
	if(isCircularQueueInitialized(queue) == false)
	{
		printf("The Queue is not initialized.\n");
		return;
	}
	if(isCircularQueueEmpty(queue) == true)
	{
		printf("The Queue is empty.\n");
		return;
	}

	idx = queue->front_idx;
	for(int i=0; i<queue->size; i++)
	{
		printf("%d, ", queue->array_adr[idx]);
		idx++;
		idx %= queue->queue_max_size;
	}
	printf("\n");
}

Queue_t getFrontElement(Circular_queue_t *queue)
{
	if(isCircularQueueInitialized(queue) == false)
		return -65656;

	if(isCircularQueueEmpty(queue) == true)
	{
		printf("Circular Queue is empty.\n");
		return -65656;
	}

	return queue->array_adr[queue->front_idx];
}

Queue_t getLastElement(Circular_queue_t *queue)
{
	if(isCircularQueueInitialized(queue) == false)
		return -65564;

	if(isCircularQueueEmpty(queue) == true)
		return -65564;

	int idx = queue->front_idx + queue->size -1;
	idx %= queue->queue_max_size;
	return queue->array_adr[idx];
}

Ret_type_t pushElementInQueue(Circular_queue_t *queue, Queue_t data)
{
	int idx;

	if(isCircularQueueInitialized(queue) == false) {
		printf("Queue not initialized\n");
		return 0;
	}

	if(isCircularQueueFull(queue) == false) {
		if(isCircularQueueEmpty(queue) == true)
			queue->front_idx = 0;

		idx = (queue->front_idx + queue->size) % queue->queue_max_size;
		queue->array_adr[idx] = data;

		queue->size++;
		queue->size %= (queue->queue_max_size+1);
	} else {
		queue->array_adr[queue->front_idx] = data;
		queue->front_idx++;
		queue->front_idx %= queue->queue_max_size;
	}

	return exit_with_sucsess;
}

Ret_type_t popElementInQueue(Circular_queue_t *queue, Queue_t *data)
{
	if(isCircularQueueInitialized(queue) == false)
	{
		return exit_with_failure;
	}

	if(isCircularQueueEmpty(queue) == true)
	{
		printf("Queue is Empty. Can not Pop anything");
		return exit_with_failure;
	}

	*data = queue->array_adr[queue->front_idx];
	queue->front_idx++;
	queue->front_idx %= queue->queue_max_size;
	queue->size--;

	return exit_with_sucsess;
}
