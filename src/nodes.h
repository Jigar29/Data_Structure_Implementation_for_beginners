#ifndef NODES_H_
#define NODES_H_

#define List_t int
#define Tree_List_t int

typedef struct{
	List_t data;
	struct List_node_t *ptr;
}List_node_t;

typedef struct{
	List_t data;
	struct Tree_node_t *right_node;
	struct Tree_node_t *left_node;
}Tree_node_t;

#endif /* NODES_H_ */
