/*
 * graph.h
 *
 *  Created on: Aug 12, 2018
 *      Author: Jigar
 */

#ifndef GRAPH_GRAPH_H_
#define GRAPH_GRAPH_H_

#include <stdio.h>
#include <stdlib.h>
#include "nodes.h"
#include "general.h"

Edge_node_t** getEdgeHeadFromVertice(Vertice_list_t *vertices_head, int vertice_no);
void printVertices(Vertice_list_t *vertices_head);
void printEdges(Edge_node_t *edge_head);
Ret_type_t addVerticeToGraph(Vertice_list_t **vertices_head);
Ret_type_t deleteVerticeFromGraph(Vertice_list_t **vertices_head, int vertice_no);
Ret_type_t addEdgeToVertice(Edge_node_t **edge_head, int edge_no);
Ret_type_t deleteEdgeFromVertice(Edge_node_t **edge_head, int edge_no);
void getNeibour(Vertice_list_t *vertices_head, int vertice_no);

#endif /* GRAPH_GRAPH_H_ */
