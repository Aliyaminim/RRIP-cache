#pragma once


typedef struct HtElem HtElem;

struct HtElem {
    long data;
    Node_t *value;
};

typedef struct NodeHtLl NodeHtLl;

struct NodeHtLl {
    HtElem *elem;
    NodeHtLl *next;
};

NodeHtLl *ht_ll_create();

NodeHtLl *ht_ll_insert(NodeHtLl * list, HtElem * elem);

HtElem *ht_ll_remove(NodeHtLl * list);

void ht_ll_free(NodeHtLl * list);
