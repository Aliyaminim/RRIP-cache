#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "functions.h"

int main()
{
	Node_t** hash;
    long m, n, page, kol;
    List_t* list;
    scanf("%ld", &m);
    scanf("%ld", &n);

    hash = calloc(n + 1, sizeof(Node_t *));
    assert(hash != NULL);
    kol = n + 1;

    if (m == 0) {
        printf("%d\n", 0);
        return 0;
    }
    list = create_list(m);

    for (long i = 0; i < n; i++) {
        scanf("%ld", &page);
        if (kol - 1 < page) {
            hash =
                (Node_t **) realloc(hash, (page + 1) * sizeof(Node_t *));
            assert(hash != NULL);
            for (long i = kol; i <= page; i++)
                hash[i] = NULL;
            kol = page + 1;
        }
        
		enqueue(list, hash, page);
    }

	print_list(list);

	delete_list(list);

	//free(hash) is needed
    
    return 0;
}
