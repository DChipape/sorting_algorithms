#ifndef DECK_H
#define DECK_H
#include <stdlib.h>

/**
 * enum kind_e - the enumeration of the card suits
 * @SPADE: the spades suit
 * @HEART: the hearts suit
 * @CLUB: the clubs suit
 * @DIAMOND: the diamonds suit
 */

typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Plays the card
 *
 * @value: the value or number of acard
 * From an Ace to the King
 * @kind: Kind of a card
 */

typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - the deck of a card
 *
 * @card: Pointer that points to a card of the node
 * @prev: Pointer that points to the previous node of a list
 * @next: Pointer that points  to the next node of the list
 */

typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_deck(deck_node_t **deck);

#endif

