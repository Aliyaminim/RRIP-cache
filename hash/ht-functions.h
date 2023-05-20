#pragma once

long modular = 100007;

long hash_function(long data)
{
    return (data % modular);
}


NodeHtLl **create_overflow_list(HashTable * table);

void free_overflow_list(HashTable * table);

HtElem *create_elem(long data, Node_t * value);

HashTable *create_table();

void free_table(HashTable * table);

void solve_collision(long index, HtElem * elem, HashTable * table);

void ht_insert(HashTable * table, long data, Node_t * value);

void ht_delete(HashTable * table, long data);

Node_t *is_element_in_ht(HashTable * table, long data);