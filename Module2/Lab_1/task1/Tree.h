#ifndef TREE
#define TREE


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>


typedef void *avl_data_t;

typedef struct avl_node avl_node_t;


typedef struct {

    int (*compare)(avl_data_t a, avl_data_t b);

    avl_data_t(*copyData)(avl_data_t data);

    void (*destroy)(avl_data_t avl);

    void (*print)(avl_data_t data);

} avl_func_p_t;


typedef struct {

    avl_node_t *root;
    size_t size;
    avl_func_p_t fp;

} avl_tree_t;






#endif