#ifndef NODES_H_
#define NODES_H_

#define List_t int

typedef struct{
	List_t data;
	struct List_node_t *ptr;
}List_node_t;

typedef struct{
	List_t data;
	struct Tree_node_t *right;
	struct Tree_node_t *left;
}Tree_node_t;

#endif /* NODES_H_ */
