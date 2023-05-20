#pragma once



NodeHtLl *ht_ll_create();

NodeHtLl *ht_ll_insert(NodeHtLl * list, HtElem * elem);

HtElem *ht_ll_remove(NodeHtLl * list);

void ht_ll_free(NodeHtLl * list);
