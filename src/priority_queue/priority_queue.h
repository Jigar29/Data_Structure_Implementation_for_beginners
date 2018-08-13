/*
 * priority_queue.h
 *
 *  Created on: Aug 12, 2018
 *      Author: Jigar
 */

#ifndef PRIORITY_QUEUE_PRIORITY_QUEUE_H_
#define PRIORITY_QUEUE_PRIORITY_QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "nodes.h"

void printPriorityQueue(Priority_queue_node_t *pq);
Ret_type_t isPriorityQueueFull(Priority_queue_node_t *pq);
Ret_type_t isPriorityQueueEmpty(Priority_queue_node_t *pq);
Priority_queue_t getPriorityQueueSize(Priority_queue_node_t *pq);
Priority_queue_t getMinPriority(Priority_queue_node_t *pq);
Ret_type_t insertToPriorityQueue(Priority_queue_node_t *pq, Priority_queue_t value, Priority_queue_t priority);
Ret_type_t deleteFromPriorityQueue(Priority_queue_node_t *pq);

#endif /* PRIORITY_QUEUE_PRIORITY_QUEUE_H_ */
