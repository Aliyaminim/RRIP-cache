#pragma once
struct node_t
{
        struct node_t* next;
        struct node_t* prev;
        int data;
};

struct list_t
{
        struct node_t* head;
        struct node_t* tail;
};

struct node_t* append(struct node_t* bottom, int a);
struct list_t* create_list();
void print_list(struct list_t* list);
void print_list(struct list_t* list);
