#include "dLinkedList.h"
#include <stdio.h>

struct client* createClient(int data)
{
    struct client* pClient = (struct client*) malloc(sizeof(struct client));
    if (pClient != NULL){
         pClient->data = data;
        clientNo++;
    }

    return pClient;
}
int addClient(int data)
{    struct client* pClient = createClient(data);
    if (pClient != NULL){
        if(pHead == NULL){
            pHead = pTail = pClient;
        }
        else {
            pClient->pPrev = pTail;
            pTail = pClient;
            pClient->pPrev->pNext = pClient;
        }
        return 1;
    }
    else {
        return 0;
    }
}
int insertClient(int data, int index)
{
    if(index == clientNo)
    {
        if(addClient(data))
        return 1;
        else
        return 0;
    }else if(index == 0){
        struct client* pClient = createClient(data);
        if(pClient){
        pHead->pPrev = pClient;
        pClient->pNext = pHead;
        pHead = pClient;
        return 1;
        } else
            return 0;
    } else if(index>0 && index<clientNo){
        struct client* pClient = createClient(data);
        if(pClient){
        struct client* pCurrent = pHead;
        for(int i=0;i<index;i++){
            pCurrent = pCurrent->pNext;
        }
        pCurrent->pPrev->pNext = pClient;
        pCurrent->pPrev = pClient;
        pClient->pPrev = pCurrent->pPrev;
        pClient->pNext = pCurrent;
        return 1;
        }
        else return 0;
    }
}
int delete(int index)
{
    if(index == (clientNo-1))
    {
        struct client* pCurrent = pTail;
        if(pTail = pTail->pPrev)
        {   pTail->pNext = NULL;
        free(pCurrent);
            return 1;}
        else
            return 0;
    }

    else if(index == 0){
        struct client* pCurrent = pHead;

        if(pHead = pHead->pNext)
        {   pHead->pPrev = NULL;
            free(pCurrent);
            return 1;}
         else
            return 0;


    } else if(index>0 && index<clientNo-1){
        struct client* pCurrent = pHead;
        for(int i=0;i<index;i++){
            pCurrent = pCurrent->pNext;
        }
        pCurrent->pPrev->pNext = pCurrent->pNext;
        pCurrent->pNext->pPrev = pCurrent->pPrev;
        free(pCurrent);
        return 1;
        }
        else return 0;
    }


