/*
 * heap.h
 *
 *  Created on: Apr 23, 2018
 *      Author: Jigar
 */

#ifndef HEAP_HEAP_H_
#define HEAP_HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include "general.h"
#include "nodes.h"

void printHeap(Heap_node_t *heap);
Ret_type_t isHeapFull(Heap_node_t *heap);
Ret_type_t isHeapEmpty(Heap_node_t *heap);
Heap_t getHeapSize(Heap_node_t *heap);
Heap_t getMinNum(Heap_node_t *heap);
Ret_type_t insertToHeap(Heap_node_t *heap, Heap_t data);
Ret_type_t deleteFromHeap(Heap_node_t *heap);

#endif /* HEAP_HEAP_H_ */
