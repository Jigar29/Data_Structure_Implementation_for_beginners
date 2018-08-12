/*
 * circular_queue.h
 *
 *  Created on: Aug 10, 2018
 *      Author: Jigar
 */

#ifndef CIRCULAR_QUEUE_CIRCULAR_QUEUE_H_
#define CIRCULAR_QUEUE_CIRCULAR_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "nodes.h"

Queue_t getCircularQueueSize(Circular_queue_t *queue);
void printcircularQueue(Circular_queue_t *queue);
Ret_type_t isCircularQueueEmpty(Circular_queue_t *queue);
Ret_type_t isCircularQueueFull(Circular_queue_t *queue);
Queue_t getFrontElement(Circular_queue_t *queue);
Queue_t getLastElement(Circular_queue_t *queue);
Ret_type_t pushElementInQueue(Circular_queue_t *queue, Queue_t data);
Ret_type_t popElementInQueue(Circular_queue_t *queue, Queue_t *data);

#endif /* CIRCULAR_QUEUE_CIRCULAR_QUEUE_H_ */
