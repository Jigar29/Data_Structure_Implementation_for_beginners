#include "circular_queue.h"

Ret_type_t isQueueInitialized(Circular_queue_t *queue)
{
	if((queue->front_index_num == -1) && (queue->rear_index_num == -1))
	{
		printf("Queue is not initialized\n");
		return false;
	}
	return true;
}

Queue_t getFrontElement(Circular_queue_t *queue)
{
	return (queue->araay_adr[queue->front_index_num]);
}

Queue_t getLastElement(Circular_queue_t *queue)
{
	return (queue->araay_adr[queue->rear_index_num -1]);
}

void printcircularQueue(Circular_queue_t *queue)
{
	Queue_t queue_size = getCircularQueueSize(queue);

	if(queue_size == 0)
	{
		printf("Queue is empty, can't print anything\n");
		return;
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
		return (queue->rear_index_num - queue->front_index_num);
	}
	else if(queue->rear_index_num < queue->front_index_num)
	{
		return (queue->queue_max_size - queue->front_index_num + queue->rear_index_num);
	}
	else
	{
		printf("Queue is Empty\n");
		return 0;
	}
}

Ret_type_t isCircularQueueFull(Circular_queue_t *queue)
{
	return (getCircularQueueSize(queue) == queue->queue_max_size)?true:false;
}

Ret_type_t isCircularQueueEmpty(Circular_queue_t *queue)
{
	return (getCircularQueueSize(queue) == 0)?true:false;
}

Ret_type_t pushElementInQueue(Circular_queue_t *queue, Queue_t data)
{
	//Error checks
	if(isCircularQueueFull(queue) == true)
	{
		printf("The queue is full, can't append anything more into the queue\n");
		return exit_with_failure;
	}

	if(isQueueInitialized(queue) == false)
	{
		queue->front_index_num = queue->rear_index_num = 0;
	}

	if(queue->rear_index_num == queue->queue_max_size)
	{
		queue->rear_index_num =0;
	}
	queue->araay_adr[queue->rear_index_num] = data;
	queue->rear_index_num = (queue->rear_index_num +1) % (queue->queue_max_size + 1);
	return exit_with_sucsess;
}

Ret_type_t popElementInQueue(Circular_queue_t *queue, Queue_t *data)
{
	//Error Checks
	if(isCircularQueueEmpty(queue) == true)
	{
		printf("The Queue is empty, can't pop out anything\n");
		return exit_with_failure;
	}

	if(queue->front_index_num == queue->queue_max_size)
	{
		queue->front_index_num = 0;
	}

	*data = queue->araay_adr[queue->front_index_num];
	queue->front_index_num = (queue->front_index_num + 1) % (queue->queue_max_size+1);
	return exit_with_sucsess;
}
