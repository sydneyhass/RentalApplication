#ifndef SORT_H_
#define SORT_H_
#include "node.h"

extern void sort( Node *pHead, int (*pComparator) ( Node *pA, Node *pB ) );
extern int compareByRent( Node *pA, Node *pB );
extern int compareByDistance( Node *pA, Node *pB );
extern int compareByNumRooms( Node *pA, Node *pB );
extern int compareByAddress( Node *pA, Node *pB );
	
#endif
