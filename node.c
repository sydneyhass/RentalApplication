#include "rental.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
 
void printList( Node *pHead ) {
		for(Node *pNode = pHead; pNode != NULL; pNode = pNode->pNext )
			printListing( pNode->pRental );
}

void printNode( Node *pNode ) {
	printRental( pNode->pRental );
}

Node *createNode( Street *pStreets) {
	Node* pNode = calloc( 1, sizeof( Node ) );
	pNode->pRental = createListing( pStreets );
	pNode->pNext = NULL;
	return pNode;
}

void appendNode( Node **ppHead, Node *pNewNode ) {
	if( *ppHead == NULL )
		*ppHead = pNewNode;
	else {	
		Node* pNode = *ppHead;
		while( pNode->pNext != NULL )
			pNode = pNode->pNext;
		pNode->pNext = pNewNode;
	}
}

int countNode( Node *pHead ) {
	Node* pNode = pHead;
	int counter = 0;
	while( pNode != NULL ) {
		counter++;
		pNode = pNode->pNext;
	}
	return counter;	
}

Node *getNodeAtIndex( Node *pHead, int iTarget ) {
	Node* pNode = pHead;
	for( int i = 0; i != iTarget && pNode != NULL; i++ )
		pNode = pNode->pNext;	
	return pNode;
}

Node *removeNodeAtIndex( Node **ppHead, int i ) {
	Node *pDoomNode = *ppHead;
	if( *ppHead == NULL )
		pDoomNode = NULL;
	if( i == 0 ) {
		*ppHead = pDoomNode->pNext;
		pDoomNode->pNext = NULL;
	} else {
		Node *pBeforeNode = malloc( sizeof ( Node ) );
		pBeforeNode = getNodeAtIndex( pDoomNode, i-1 );
		if( pBeforeNode == NULL ) 
			pDoomNode = NULL;
		else {
			pDoomNode = pBeforeNode->pNext;
			pBeforeNode->pNext = pDoomNode->pNext;
			pDoomNode->pNext = NULL;
		}
	}
	return pDoomNode;
}
