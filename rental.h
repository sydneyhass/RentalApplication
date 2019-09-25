#ifndef RENTAL_H_
#define RENTAL_H_

typedef struct {
        char *streetName;
        int nBaseDistance;
} Street;

typedef struct {
        Street *pStreet;
        int nStreetNum;
        int nPrice;
        int nRooms;
        float fDistance;
} Rental;

extern void printListing( Rental *pListing );
extern Rental *createListing( Street *pStreets );
extern void printRental( Rental* pListing );
#endif
