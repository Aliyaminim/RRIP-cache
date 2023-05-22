/* A C file that includes realization of the functions used in
   Static Re-Reference Interval Prediction(RRIP) Cache Replacement */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "./lru/lru.h"
#include "func_RRIP.h"
#include "./hash/ht-linked-list.h"
#include "./hash/ht-functions.h"

List_t *create_list(const long size)
{
    List_t *list = calloc(1, sizeof(List_t));
    if (list == NULL) {
        fprintf(stderr, "Memory exhausted\n");
        abort();
    }
    list->head = list->fst_dist = list->tail = NULL;
    list->size = size;
    list->full_nodes = 0;

    return list;
}

/* A utility function to create a new List Node.
   The list Node will store the given 'data' */
static Node_t *newNode(const long data)
{
    Node_t *res = calloc(1, sizeof(Node_t));
    if (res == NULL) {
        fprintf(stderr, "Memory exhausted\n");
        abort();
    }
    res->next = res->prev = NULL;
    res->data = data;
    res->value = 2;

    return res;
}

/* A utility function to check if List is empty */
static int isListEmpty(const List_t * list)
{
    assert((list != NULL) && "Code doesn't work correctly");
    return list->tail == NULL;
}

/* A utility function to check if there is slot available in memory */
static int isListFull(const List_t * list)
{
    assert((list != NULL) && "Code doesn't work correctly");
    return list->size == list->full_nodes;
}

void dequeue(Node_t * node, List_t * list, HashTable * table)
{
    assert((list != NULL) && (table != NULL) && (node != NULL)
           && "Code doesn't work correctly");
    list->fst_dist = node->next;

    if (node != list->head)
        node->prev->next = node->next;
    else
        list->head = node->next;

    if (node != list->tail)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;


    list->full_nodes--;
    ht_delete(table, node->data);
    free(node);
}

void enqueue(List_t * list, HashTable * table, const long data)
{
    assert((list != NULL) && (table != NULL)
           && "Code doesn't work correctly");
    Node_t *curnode = newNode(data);

    if (isListFull(list)) {
        if (list->fst_dist == NULL) {
            int i = 3 - list->tail->value;
            Node_t *tmp = list->head;

            for (; tmp != NULL;) {
                tmp->value += i;
                if ((tmp->value == 3) && (list->fst_dist == NULL)) {
                    list->fst_dist = tmp;
                }
                tmp = tmp->next;
            }
        }

        Node_t *hlp = list->fst_dist->prev;
        dequeue(list->fst_dist, list, table);

        if (hlp != NULL) {
            if (hlp != list->tail)
                hlp->next->prev = curnode;
            else
                list->tail = curnode;
            hlp->next = curnode;
        } else {
            list->head->prev = curnode;
            list->head = curnode;
        }

        curnode->next = list->fst_dist;
        curnode->prev = hlp;

        list->full_nodes++;
        ht_insert(table, data, curnode);
    } else {
        if (isListEmpty(list)) {
            list->head = curnode;
        } else {
            list->tail->next = curnode;
            curnode->prev = list->tail;
        }
        list->tail = curnode;
        list->full_nodes++;
        ht_insert(table, data, curnode);
    }

}

void cache_hit(Node_t * node, List_t * list)
{
    assert((list != NULL) && (node != NULL)
           && "Code doesn't work correctly");
    if (list->head == node) {
        list->head->value = 0;
        return;
    }

    if (list->tail == node) {
        list->tail = node->prev;
        list->tail->next = NULL;
        list->head->prev = node;
        node->next = list->head;
        node->prev = NULL;
        list->head = node;
        node->value = 0;
        return;
    }

    if (list->fst_dist == node)
        list->fst_dist = node->next;

    node->next->prev = node->prev;
    node->prev->next = node->next;
    node->prev = NULL;
    node->next = list->head;
    list->head->prev = node;
    list->head = node;
    node->value = 0;

    return;
}

int replacement_RRIP(long page, List_t * list, HashTable * table)
{
    assert((list != NULL) && (table != NULL)
           && "Code doesn't work correctly");
    Node_t *node = NULL;

    if (node = ht_search(table, page)) {
        cache_hit(node, list);
        return 1;
    }

    else {
        enqueue(list, table, page);
        return 0;
    }
}

void dequeue_cop(Node_t * node, List_t * list, Node_t ** hash)
{
    assert((list != NULL) && (hash != NULL) && (node != NULL)
           && "Code doesn't work correctly");
    list->fst_dist = node->next;

    if (node != list->head)
        node->prev->next = node->next;
    else
        list->head = node->next;

    if (node != list->tail)
        node->next->prev = node->prev;
    else
        list->tail = node->prev;


    list->full_nodes--;
    hash[node->data] = NULL;
    free(node);
}

void enqueue_cop(List_t * list, Node_t ** hash, const long data)
{
    assert((list != NULL) && (hash != NULL)
           && "Code doesn't work correctly");
    Node_t *curnode = newNode(data);

    if (isListFull(list)) {
        if (list->fst_dist == NULL) {
            int i = 3 - list->tail->value;
            Node_t *tmp = list->head;

            for (; tmp != NULL;) {
                tmp->value += i;
                if ((tmp->value == 3) && (list->fst_dist == NULL)) {
                    list->fst_dist = tmp;
                }
                tmp = tmp->next;
            }
        }

        Node_t *hlp = list->fst_dist->prev;
        dequeue_cop(list->fst_dist, list, hash);

        if (hlp != NULL) {
            if (hlp != list->tail)
                hlp->next->prev = curnode;
            else
                list->tail = curnode;
            hlp->next = curnode;
        } else {
            list->head->prev = curnode;
            list->head = curnode;
        }

        curnode->next = list->fst_dist;
        curnode->prev = hlp;

        list->full_nodes++;
        hash[data] = curnode;
    } else {
        if (isListEmpty(list)) {
            list->head = curnode;
        } else {
            list->tail->next = curnode;
            curnode->prev = list->tail;
        }
        list->tail = curnode;
        list->full_nodes++;
        hash[data] = curnode;
    }

}

int replacement_RRIP_cop(long page, List_t * list, Node_t ** hash)
{
    assert((list != NULL) && (hash != NULL)
           && "Code doesn't work correctly");
    Node_t *node = NULL;

    if (node = hash[page])      // Change arguments
    {
        cache_hit(node, list);
        return 1;
    }

    else {
        enqueue_cop(list, hash, page);
        return 0;
    }
}

void print_list(const List_t * list)
{
    assert((list != NULL) && "Code doesn't work correctly");
    Node_t *head = list->head;

    while (head != NULL) {
        printf("%ld(%d) ", head->data, head->value);
        head = head->next;
    }

    printf("\n");
    return;
}

void delete_list(List_t * list)
{
    assert((list != NULL) && "Code doesn't work correctly");
    Node_t *next;
    Node_t *top = list->head;

    while (top != NULL) {
        next = top->next;
        free(top);
        top = next;
    }

    free(list);
}

void delete_hashRRIP(Node_t ** hash_RRIP)
{
    assert((hash_RRIP != NULL) && "Code doesn't work correctly");
    Node_t *next;
    Node_t *top = hash_RRIP[0];

    while (top != NULL) {
        next = top->next;
        free(top);
        top = next;
    }

    free(hash_RRIP);
}

void update_hash(long *phashsize, const long page, Node_t ** hash_RRIP,
                 QNode ** hash_LRU)
{
    assert((hash_RRIP != NULL) && (hash_LRU != NULL) && (phashsize != NULL)
           && "Code doesn't work correctly");

    Node_t **tmp1 =
        (Node_t **) realloc(hash_RRIP, (page + 1) * sizeof(Node_t *));
    for (long i = *phashsize; i <= page; i++)
        hash_RRIP[i] = NULL;

    QNode **tmp2 =
        (QNode **) realloc(hash_LRU, (page + 1) * sizeof(QNode *));
    for (long i = *phashsize; i <= page; i++)
        hash_LRU[i] = NULL;

    if ((tmp1 == NULL) || (tmp2 == NULL)) {
        fprintf(stderr, "Memory exhausted(during realloc)\n");
        abort();
    }

    hash_RRIP = tmp1;
    hash_LRU = tmp2;

    *phashsize = page + 1;
}
