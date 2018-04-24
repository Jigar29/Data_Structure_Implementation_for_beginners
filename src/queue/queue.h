#ifndef QUEUE_QUEUE_H_
#define QUEUE_QUEUE_H_

#include "general.h"
#include "nodes.h"

Ret_type_t printQueue(List_node_t *head, List_node_t *tail);
Ret_type_t isQueueEmpty(List_node_t * head, List_node_t* tail);
Ret_type_t front(List_node_t *head, List_node_t *tail, List_t *front_data);
int getQueueSize(List_node_t * head, List_node_t *tail);
Ret_type_t enQueue(List_node_t **head, List_node_t **tail, List_t data);
Ret_type_t deQueue(List_node_t **head, List_node_t **tail, List_t *rec_data);

#endif /* QUEUE_QUEUE_H_ */
