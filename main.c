#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "functions.h"
#include "./src/lru.h"

int main()
{
	Node_t** hash_RRIP;
    QNode** hash_LRU;
    long kol;

    long m, n, page, count_RRIP, count_LRU;
    List_t* list;
    Queue* queue;
    scanf("%ld", &m); //m is a cache size
    scanf("%ld", &n); //n is an overall number of requests

    //FIXME: temporary code
    hash_RRIP = calloc(n + 1, sizeof(Node_t *));
    assert(hash_RRIP != NULL);
    hash_LRU = calloc(n + 1, sizeof(QNode *));
    assert(hash_LRU != NULL);
    kol = n + 1;
    //

    list = create_list(m);
    queue = createQueue(m);
    count_LRU = 0;
    count_RRIP = 0;

    //work begins...
    for (long i = 0; i < n; i++) 
    {
        scanf("%ld", &page);
        
        //FIXME: temporarily we need to update hash each time
        if (kol - 1 < page) {
            hash_RRIP = (Node_t **) realloc(hash_RRIP, (page + 1) * sizeof(Node_t *));
            assert(hash_RRIP != NULL);
            for (long i = kol; i <= page; i++)
                hash_RRIP[i] = NULL;

            hash_LRU = (QNode **) realloc(hash_LRU, (page + 1) * sizeof(QNode* ));
            assert(hash_LRU != NULL);
            for (long i = kol; i <= page; i++)
                hash_LRU[i] = NULL;

            kol = page + 1;
        }
        //
        
		count_LRU += lru(page, queue, hash_LRU);
        //count_RRIP += replacement_RRIP(page, list, hash_RRIP);
    }

    printf("Number of cache hits:\nfor RRIP %ld\nfor LRU %ld\n", count_RRIP, count_LRU);

    if ((count_LRU > count_RRIP) && (count_LRU != 0))
        printf("Suprisingly LRU has performed better...\n");

	delete_list(list);
    //delete_queue(queue);

	//free(hash) is needed
    return 0;
}
