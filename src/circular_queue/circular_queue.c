#include "circular_queue.h"

Ret_type_t isQueueInitialized(Circular_queue_t *queue)
{
	if((queue->front_index_num == -1) && (queue->rear_index_num == -1))
		return false;
	else
		return true;
}

Queue_t getFrontElement(Circular_queue_t *queue)
{
	if(isCircularQueueEmpty(queue) == true)
		return -65656;
	return queue->araay_adr[queue->front_index_num];
}

Queue_t getLastElement(Circular_queue_t *queue)
{
	if(isCircularQueueEmpty(queue) == true)
		return -65564;
	return queue->araay_adr[queue->rear_index_num];
}


void printcircularQueue(Circular_queue_t *queue)
{
	Queue_t queue_size= getCircularQueueSize(queue);
	if(queue_size == 0)
	{
		printf("The Queue is empty, cannot print anything\n");
	}

	for(int i=0; i<queue_size; i++)
	{
		printf("%d, ", queue->araay_adr[(queue->front_index_num + i) % queue->queue_max_size]);
	}
}

Queue_t getCircularQueueSize(Circular_queue_t *queue)
{
	if(queue->rear_index_num > queue->front_index_num)
	{
		return (queue->rear_index_num - queue->front_index_num +1);
	}
	else if(queue->rear_index_num < queue->front_index_num)
	{
		return (queue->queue_max_size + queue->rear_index_num - queue->front_index_num + 1);
	}
	else if((queue->rear_index_num == -1) && (queue->front_index_num == -1))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

Ret_type_t isCircularQueueFull(Circular_queue_t *queue)
{
	return (getCircularQueueSize(queue) == (queue->queue_max_size))?true:false;
}

Ret_type_t isCircularQueueEmpty(Circular_queue_t *queue)
{
	return (getCircularQueueSize(queue) == 0)?true:false;
}

Ret_type_t pushElementInQueue(Circular_queue_t *queue, Queue_t data)
{
	if(isCircularQueueFull(queue) == true)
	{
		return exit_with_failure;
	}

	if(isQueueInitialized(queue) == false)
	{
		queue->front_index_num = queue->rear_index_num = 0;
		queue->araay_adr[queue->rear_index_num] = data;
	}
	else
	{
		queue->rear_index_num = (queue->rear_index_num + 1) % (queue->queue_max_size);
		queue->araay_adr[queue->rear_index_num] = data;
	}

	return exit_with_sucsess;
}

Ret_type_t popElementInQueue(Circular_queue_t *queue, Queue_t *data)
{
	if(isCircularQueueEmpty(queue) == true)
	{
		return exit_with_failure;
	}

	*data = queue->araay_adr[queue->front_index_num];
	if(queue->front_index_num == queue->rear_index_num)
	{
		queue->front_index_num = queue->rear_index_num = -1;
	}
	else
		queue->front_index_num = (queue->front_index_num + 1) % (queue->queue_max_size);
	return exit_with_sucsess;
}
