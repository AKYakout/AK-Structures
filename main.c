#include <stdio.h>
#include <stdlib.h>
#include "dLinkedList.h"



int main()
{

    for(int i=0; i<50; i++)
    {
        addClient(i);
       // printf("%d\n", pTail->data);
    }
    struct client* pcur = pHead;
    if(insertClient(99,25))
    {
        printf("Success\n");
        pcur = pHead;
    }
    delete(5);
    delete(0);
    delete(46);
    delete(46);
    pcur = pHead;
    for(int j=0; j<51; j++)
    {
        printf("%d\n", pcur->data);
        pcur = pcur->pNext;
    }
    return 0;
}

