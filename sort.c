#include "rental.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap( Node *pA, Node *pB );

void sort( Node *pNode, int (*pComparator) ( Node *pA, Node *pB) ) {
	int count = countNode( pNode );
	for( int i = 0; i < count; i++ ) {
		for( int j = 0; j < count - i - 1; j++ ) {
			Node* pA = getNodeAtIndex( pNode, j );
			Node* pB = getNodeAtIndex( pNode, j+1 );
			if( (*pComparator) ( pA, pB ) > 0 ) {
				swap( pA, pB );
			}
		}
	} 
}

int compareByRent( Node *pA, Node *pB ) {
	int diff = pA->pRental->nPrice - pB->pRental->nPrice;
	if( diff == 0 )
		diff = pA->pRental->nRooms - pB->pRental->nRooms;
	return diff;
}

int compareByAddress( Node *pA, Node *pB ) {
	int diff = strcmp( pA->pRental->pStreet->streetName, pB->pRental->pStreet->streetName );
	if ( diff == 0 ) 
		diff = pA->pRental->nStreetNum - pB->pRental->nStreetNum;
	return diff;
}

int compareByNumRooms( Node *pA, Node *pB ) {
	int diff = pB->pRental->nRooms - pA->pRental->nRooms;
	if( diff == 0 ) 
		diff = pA->pRental->nPrice - pB->pRental->nPrice;
	return diff;
}

int compareByDistance( Node *pA, Node *pB ) {
	int diff = pA->pRental->fDistance - pB->pRental->fDistance;
	if( diff == 0 ) 
		diff = pA->pRental->nPrice - pB->pRental->nPrice;
	return diff;
}

void swap( Node *pA, Node *pB ) {
	Rental* temp = pA->pRental;
	pA->pRental = pB->pRental;
	pB->pRental = temp;
}	


