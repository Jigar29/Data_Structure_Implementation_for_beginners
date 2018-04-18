#ifndef QUEUE_QUEUE_H_
#define QUEUE_QUEUE_H_

#include "general.h"
#include "nodes.h"

Ret_type_t printQueue(Node *head, Node *tail);
Ret_type_t isQueueEmpty(Node * head, Node* tail);
Ret_type_t front(Node *head, Node *tail, List_t *front_data);
int getQueueSize(Node * head, Node *tail);
Ret_type_t enQueue(Node **head, Node **tail, List_t data);
Ret_type_t deQueue(Node **head, Node **tail, List_t *rec_data);

#endif /* QUEUE_QUEUE_H_ */
