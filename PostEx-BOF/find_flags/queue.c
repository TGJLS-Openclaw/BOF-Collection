#include <windows.h>
#include "bofdefs.h"

typedef struct _item{
    void * elem;
    struct _item * next;
}item, *Pitem;

typedef struct _queue{
    Pitem head;
    Pitem tail;
    void (*push)(struct _queue *, void *);
    void * (*pop)(struct _queue *);
    void (*free)(struct _queue *);
}queue, *Pqueue;

void _push(Pqueue q, void * v)
{
    Pitem i = (Pitem)intAlloc(sizeof(item));
    i->elem = v;
    if(q->head == NULL && q->tail == NULL)
    {
        q->head = i;
        q->tail = i;
        i->next = NULL;
    }else
    {
        q->tail->next = i;
        q->tail = i;
    }
}

void * _pop(Pqueue q)
{
    void * retval = NULL;
    Pitem i = NULL;
    if(q->head == NULL && q->tail == NULL)
    {
        return NULL;
    }
    retval = q->head->elem;
    if(q->head == q->tail)
    {
        intFree(q->head);
        q->head = NULL;
        q->tail = NULL;
    }
    else
    {
        i = q->head;
        q->head = q->head->next;
        intFree(i);
    }
    return retval;
}

void _free(Pqueue q)
{
    intFree(q);
}

Pqueue queueInit()
{
    Pqueue q = (Pqueue)intAlloc(sizeof(queue));
    q->head = NULL;
    q->tail = NULL;
    q->push = _push;
    q->pop = _pop;
    q->free = _free;
    return q;
}
