/* A header file to a C program that includes functions used in
 double linked list for hash table*/

#pragma once

/* creates hash table linked list, returns a pointer to the node hash table linked list */
NodeHtLl *ht_ll_create();

/* inserts an hash table element to hash table linked list, takes the pointers to 
    the NodeHtl list and HtElem element, returns NodeHtLl pointer*/
NodeHtLl *ht_ll_insert(NodeHtLl * list, HtElem * elem);

/* removes an element from hash table linked list, takes the pointer to NodeHtLl list,
   returns HtElem pointer */
HtElem *ht_ll_remove(NodeHtLl * list);

/* simply frees hash table linked list, takes NodeHtLL list pointer */
void ht_ll_free(NodeHtLl * list);
