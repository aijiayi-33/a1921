#ifndef jiegouti_h
#define jiegouti_h

#include <stdio.h>
#include <malloc.h>
typedef struct node
{
    int data;
    struct node *next;
}Linklist;

Linklist *creat();
void head_insert(Linklist *phead,int n);
void tail_insert(Linklist *phead,int value);

void print(Linklist *phead);
void delete(Linklist *phead,int value);

#endif
