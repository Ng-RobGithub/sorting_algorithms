#include "deck.h"

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: Positive byte difference if s1 > s2
 * 0 if s1 == s2
 * Negative byte difference if s1 < s2
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
		return (*s1 - *s2);
	return (0);
}

/**
 * get_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
int get_value(deck_node_t *card)
{
	int value;
	const char *values[] = {"Ace", "1", "2", "3", "4", "5", "6", "7",
		"8", "9", "10", "Jack", "Queen", "King"};

	for (value = 0; value < 14; value++)
	{
		if (_strcmp(card->card->value, values[value]) == 0)
			return (value);
	}
	return (13);
}

/**
 * insertion_sort_deck - Sort a deck of cards from spades to diamonds,
 * and from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
				(insert->card->kind > iter->card->kind ||
				 (insert->card->kind == iter->card->kind &&
				  get_value(insert) > get_value(iter))))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 * from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck(deck);
}
