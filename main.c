/******************************************************************
* Program: Rental Application
* Author: Sydeny Hass
* Date: 17/03/18
* Purpose: This file is responsible for controlling a list of default 
* properties and favourite properties.  
*******************************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sort.h"
#include "node.h"

void displayMenu();
void getInput( char *userInput );
int (*pComparator) ( Node *pA, Node *pB );
void displayHeader( Node* ppHead_Active, char* listName );
void displayPrompt( Node* ppHead_Active );

int main() {
	Node* pHead_Default = NULL;
	Node* pHead_Fave = NULL;
	Node **ppHead_Active = &pHead_Default;
	char userInput[3];
	char* listName = "Undecided";
	srand( time(NULL) );
        Street streets[] = {
                { "Albert St.", 0 },
                { "Bay St.", 0 },
                { "Sussex St.", 0 },
                { "Laurier Ave.", 0 },
                { "Baseline Rd.", 0 },
                { "Kent St.", 0 },
                { "Bank St.", 0 },
                { "Sparks St.", 0 },
                { "Montreal Rd.", 0 },
                { "Vanier Pkwy.", 0 }
        };
	for(int i = 0; i < 6; i++ ) {
                Node* pNewNode = createNode( streets );
                appendNode( ppHead_Active, pNewNode );   
        }
	displayHeader( *ppHead_Active, listName );
	displayPrompt( *ppHead_Active );
	int newRental = 0;
	int quit = 0;
	int current = 0;
	getInput( userInput );
	while( quit != 1 ) {
	if( countNode( *ppHead_Active ) == current )
                current = 0;
        if( strcmp( userInput, "h" ) == 0 ) {
                displayMenu();
        }
        else if( strcmp( userInput, "a" ) == 0 ) {
		if( ppHead_Active == &pHead_Default )
			newRental ++;
		if( newRental % 2 == 0 ) 
			appendNode( &pHead_Default, createNode( streets ) );
		displayHeader( *ppHead_Active, listName );              
		displayPrompt( *ppHead_Active );
	}
        else if( strcmp( userInput, "f" ) == 0 )  { 
        	ppHead_Active = &pHead_Fave;
		listName = "Favourite"; 
		displayHeader( *ppHead_Active, listName );
		displayPrompt( *ppHead_Active );
	}
        else if( strcmp( userInput, "d" ) == 0 ) {
		ppHead_Active = &pHead_Default;
		listName = "Undecided";	
		displayHeader( *ppHead_Active, listName );
		displayPrompt( *ppHead_Active);
	}
        else if( strcmp( userInput, "l" ) == 0 ) {
		if(countNode( *ppHead_Active ) > 0 ) {
                	removeNodeAtIndex( ppHead_Active, current );
			printf( "\nRental property deleted\n" );
		}
		displayPrompt( getNodeAtIndex( *ppHead_Active, current ) );
	}
        else if( strcmp( userInput, "r" ) == 0 ) {
		if( ppHead_Active == &pHead_Fave )
			printf( "\nAlready on favourites list\n" );
		else {
			if(countNode( *ppHead_Active ) > 0 ) {
				appendNode( &pHead_Fave, removeNodeAtIndex( &pHead_Default, current ) );
				printf( "\nRental property added to favourites list\n" );
			}	
			displayPrompt( getNodeAtIndex( *ppHead_Active, current ) );
		}
	}
	else if( strcmp( userInput, "n" ) == 0 ) {
		current++;
		displayPrompt( getNodeAtIndex( *ppHead_Active, current ) );
		if( countNode( *ppHead_Active ) == current )
			displayPrompt( *ppHead_Active );
	}
        else if( strcmp( userInput, "sa" ) == 0 ) {
		sort( *ppHead_Active, &compareByAddress );
		displayHeader( *ppHead_Active, listName );
		displayPrompt( getNodeAtIndex( *ppHead_Active, current ) );
	}
        else if( strcmp( userInput, "sn" ) == 0 ) {
	        sort( *ppHead_Active, &compareByNumRooms );
		displayHeader( *ppHead_Active, listName );
		displayPrompt( getNodeAtIndex( *ppHead_Active, current ) );
	}
        else if( strcmp( userInput, "sr" ) == 0 ) {
		sort( *ppHead_Active, &compareByRent );
		displayHeader( *ppHead_Active, listName );
		displayPrompt( getNodeAtIndex( *ppHead_Active, current ) );
	}
        else if( strcmp( userInput, "sd" ) == 0 ) {
                sort( *ppHead_Active, &compareByDistance );
		displayHeader( *ppHead_Active, listName );
		displayPrompt( getNodeAtIndex( *ppHead_Active, current ) );
	}
        else if( strcmp( userInput, "q" ) == 0 )
                quit = 1;
        else {
                printf( "Invalid command\n" );
		displayMenu();
        }
		if( quit != 1) 
			getInput( userInput );
	}
	return 0;
}

void displayMenu() {
	printf( "\nValid commands are:\n" );
	printf( "\t%s\n", "h  - display this help" );
	printf( "\t%s\n", "a  - display all rental properties on the current list" );
	printf( "\t%s\n", "f  - switch to favourites list" );
	printf( "\t%s\n", "d  - switch to default list" );
	printf( "\t%s\n", "l  - 'swipe left' on the current rental property" );
	printf( "\t%s\n", "r  - 'swipe right' on the current property" );
	printf( "\t%s\n", "n  - skip to next rental property" );
	printf( "\t%s\n", "sa - sort by address " );
	printf( "\t%s\n", "sn - sort by number of rooms" );
	printf( "\t%s\n", "sr - sort by rent" );
	printf( "\t%s\n", "sd - sort by distance" );
	printf( "\t%s\n", "q  - quit the program" ); 
}

void getInput( char *userInput ) {
	printf( "\nCommand ('h' for help): " );
	scanf( "%2s", userInput ); 	
}

void displayPrompt( Node* ppHead_Active ) {
	if( countNode( ppHead_Active ) > 0 ) {
		printf( "\nWhat do you think about this rental property?\n\t" );
		printNode( ppHead_Active );
	}
	else 
		printf( "\nNo more listings to display\n" );
} 

void displayHeader( Node* ppHead_Active, char* listName ) {
	printf( "\n%s Rental Properties", listName );
	printf( "\n%-25s\t %7s  %9s  %9s\n", "Address", "# Rooms", "Rent/Room", "Distance" );
        printf( "--------------------------\t -------  ---------  ---------\n" );
	printList( ppHead_Active );
}
 
