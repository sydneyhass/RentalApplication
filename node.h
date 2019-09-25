#ifndef NODE_H_
#define NODE_H_
#include "rental.h"

typedef struct Node_ {
        Rental *pRental;
        struct Node_ *pNext;
} Node;

extern void printNode( Node *pNode );
extern void printList( Node *pHead );
extern Node *createNode( Street *pStreets );
extern void appendNode( Node **ppHead, Node *pNewNode );
extern int countNode( Node *pHead );
extern Node *getNodeAtIndex( Node *pHead, int i );
extern Node *removeNodeAtIndex( Node **ppHead, int i );

#endif
