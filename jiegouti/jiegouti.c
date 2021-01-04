#include "jiegouti.h"
#include <stdio.h>
#include <malloc.h>
Linklist *creat()
{
    Linklist *phead;
    phead=(Linklist *)malloc(sizeof(Linklist));
    phead->next=NULL;
    return phead;
}

/*头插法*/

void head_insert(Linklist *phead,int n)
{
    Linklist *p;
    int i;

    for(i=0;i<n;i++)
    {
        p=(Linklist *)malloc(sizeof(Linklist));
        scanf("%d",&p->data);

        p->next=phead->next;
        phead->next=p;
    }
}

void tail_insert(Linklist *phead,int value)
{
    Linklist *p,*t;
    int i;
    t=phead;

    p=(Linklist *)malloc(sizeof(Linklist));
    p->data=value;
    while(t->next!=NULL)
        t=t->next;

    t->next=p;
    p->next=NULL; 
}
void print(Linklist *phead)
{
    Linklist *p;
    p=phead->next;
    if(p==NULL)
        printf("此链表为空.\n");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void delete(Linklist *phead,int value)
{
    Linklist *p,*t;
    t=phead;
    while(t->next!=NULL)
    {
        if(t->next->data==value)
        {
            p=t->next;
            t->next=p->next;
            free(p);
        }
        else
            t=t->next;
    }
}

