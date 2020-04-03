#ifndef DLINKEDLIST_H_INCLUDED
#define DLINKEDLIST_H_INCLUDED

int clientNo;
struct client {
    int data;
    struct client * pPrev;
    struct client * pNext;
}*pHead,*pTail;

struct client* createClient(int data);
int addClient(int data);
int insertClient(int data, int index);
int delete(int index);


#endif // DLINKEDLIST_H_INCLUDED
