#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "rental.h"

void getBaseDistance( Street *pStreets );

void getBaseDistance( Street *pStreets ) {
	for( int i = 0; i < 10; i++ )
		pStreets[i].nBaseDistance = (rand() % 36 + 5)  * 100;
}

Rental *createListing( Street *pStreets ) {
	Rental* pListing = malloc( sizeof( Rental ) );
	getBaseDistance( pStreets );
	pListing->nStreetNum = rand() % 200 + 1;
	pListing->nRooms = rand() % 4 + 1;
	pListing->nPrice = (rand() % 9 + 4) * 50;
	pListing->pStreet = &pStreets[rand() % 10];
	pListing->fDistance = (float) ( pListing->pStreet->nBaseDistance + (20 * pListing->nStreetNum) ) / 1000;
	return pListing;
}

void printListing( Rental *pListing ) {
	printf( "%3d %-22s\t %7d  %9d  %6.2f km\n", pListing->nStreetNum, pListing->pStreet->streetName, pListing->nRooms, pListing->nPrice, pListing->fDistance );
}

void printRental( Rental* pListing ) {
	printf( "Addr: %3d %s, # Rooms: %d, Rent/Room: $%d, Distance: %.2f km\n", pListing->nStreetNum, pListing->pStreet->streetName, pListing->nRooms, pListing->nPrice, pListing->fDistance );
}
