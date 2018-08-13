/*
 * graph.c
 *
 *  Created on: Aug 12, 2018
 *      Author: Jigar
 */

#include"graph.h"

void printVertices(Vertice_list_t *vertices_head)
{
	while(vertices_head  != NULL)
	{
		printf("%p, ", vertices_head->pointer_to_edges);
		vertices_head = (Vertice_list_t *) vertices_head->next;
	}
}
void printEdges(Edge_node_t *edge_head)
{
	while(edge_head  != NULL)
	{
		printf("%d, ", edge_head->edge_no);
		edge_head = (Edge_node_t *) edge_head->next;
	}
}

Edge_node_t** getEdgeHeadFromVertice(Vertice_list_t *vertices_head, int vertice_no) //to be fixed for vertice_no bound
{
	while(vertice_no >1)
	{
		vertices_head = (Vertice_list_t *) vertices_head->next;
		vertice_no--;
	}
	return &(vertices_head->pointer_to_edges);
}
Ret_type_t addVerticeToGraph(Vertice_list_t **vertices_head)
{
	Vertice_list_t *pointer = *vertices_head;
	Vertice_list_t *new_node = (Vertice_list_t *)malloc(sizeof(Vertice_list_t));

	new_node->next = NULL;
	new_node->pointer_to_edges = NULL;

	if((*vertices_head) == NULL)
	{
		(*vertices_head) = new_node;
		return exit_with_sucsess;
	}

	while(pointer->next != NULL)
	{
		pointer = (Vertice_list_t *)pointer->next;
	}

	pointer->next = (struct Vertice_list_t *) new_node;

	return exit_with_sucsess;
}

Ret_type_t deleteVerticeFromGraph(Vertice_list_t **vertices_head, int vertice_no) //To be fixed for vertice exceeding limit
{
	Vertice_list_t *temp_pointer = *vertices_head;
	Vertice_list_t *temp2_pointer = NULL;
	if(*vertices_head == NULL)
	{
		printf("The list is empty\n");
		return exit_with_failure;
	}

	if(vertice_no == 1)
	{
		(*vertices_head) = (Vertice_list_t *) (*vertices_head)->next;
		free(temp_pointer);
		return exit_with_sucsess;
	}

	while(vertice_no > 2)
	{
		temp_pointer = (Vertice_list_t *) temp_pointer->next;
		vertice_no--;
	}

	temp2_pointer= (Vertice_list_t *)temp_pointer->next;
	temp_pointer->next = (temp2_pointer->next);
	free(temp2_pointer);
	return exit_with_sucsess;
}

Ret_type_t addEdgeToVertice(Edge_node_t **edge_head, int edge_no) //Todo : what if the edge is already there
{
	Edge_node_t *pointer = *edge_head;
	Edge_node_t *new_node = (Edge_node_t *)malloc(sizeof(Edge_node_t));

	new_node->next = NULL;
	new_node->edge_no = edge_no;

	if((*edge_head) == NULL)
	{
		(*edge_head) = new_node;
		return exit_with_sucsess;
	}

	while(pointer->next != NULL)
	{
		pointer = (Edge_node_t *)pointer->next;
	}

	pointer->next = (struct Edge_node_t *) new_node;

	return exit_with_sucsess;
}

Ret_type_t deleteEdgeFromVertice(Edge_node_t **edge_head, int edge_no)  //To be fixed for edge_no exceeding limit
{
	Edge_node_t *temp_pointer = *edge_head;
	Edge_node_t *temp2_pointer = NULL;
	if(*edge_head == NULL)
	{
		printf("The list is empty\n");
		return exit_with_failure;
	}

	if(edge_no == 1)
	{
		(*edge_head) = (Edge_node_t *) (*edge_head)->next;
		free(temp_pointer);
		return exit_with_sucsess;
	}

	while(edge_no>2)
	{
		temp_pointer = (Edge_node_t *) temp_pointer->next;
		edge_no--;
	}

	temp2_pointer= (Edge_node_t *) temp_pointer->next;
	temp_pointer->next = (temp2_pointer->next);
	free(temp2_pointer);
	return exit_with_sucsess;
}

void getNeibour(Vertice_list_t *vertices_head, int vertice_no)
{
	printEdges(*getEdgeHeadFromVertice(vertices_head, vertice_no));
}
