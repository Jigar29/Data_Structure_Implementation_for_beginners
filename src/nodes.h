#ifndef NODES_H_
#define NODES_H_

#define List_t int
#define Tree_List_t int
#define Queue_t int
#define Heap_t int

typedef struct{
	List_t data;
	struct List_node_t *ptr;
}List_node_t;

typedef struct{
	List_t data;
	struct Tree_node_t *right_node;
	struct Tree_node_t *left_node;
}Tree_node_t;

typedef struct{
	Queue_t front_index_num;
	Queue_t rear_index_num;
	Queue_t queue_max_size;
	Queue_t *araay_adr;
}Circular_queue_t;

typedef struct{
	Heap_t heap_max_size;
	Heap_t current_pos;
	Heap_t *araay_adr;
}Heap_node_t;
#endif /* NODES_H_ */
