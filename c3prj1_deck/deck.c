#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
void print_hand(deck_t * hand){
   /*This should print out the contents of a hand.
   It should print each card (recall that
   you wrote print_card in Course 2), and
   a space after each card.  Do not put
   a newline after the hand, as this
   function gets called to print a hand
   in the middle of a line of output.*/
   int hand_size = hand->n_cards;
   card_t ** index = hand->cards;
   for (int i =0;i<hand_size;i++)
   {
     print_card(**(index+i);
     printf(" ");
   }
}

int deck_contains(deck_t * d, card_t c) {
   /*This function should check if a deck
   contains a particular card or not.  If
   the deck does contain the card, this
   function should return 1.  Otherwise,
   it should return 0.
   (You will use this later to
   build the deck of remaining cards
   which are not in any player's hand).*/
   int hand_size = d->n_cards;
   card_t ** index = d->cards;

   card_t current_card;
   for (int i =0;i<hand_size;i++)
   {
     current_card = **(index+i);
     if ((current_card.suit == c.suit) &(current_card.value == c.value))
     {
       return 1;
     }
   }


  return 0;
}

void shuffle(deck_t * d){
   /*This function takes in a deck an shuffles
   it, randomly permuting the order of the cards.
   There are MANY valid ways to shuffle a deck
   of cards---we'll leave the specifics
   of the algorithm design up to you.  However,
   you will want to use random() to generate
   pseudo-random numbers.  (Pseudo-random
   numbers are quite sufficient here,
   since they are not used for security
   purposes). Note that you should not need to
   use the 'srand' function.*/

   /*-- To shuffle an array a of n elements (indices 0..n-1):
for i from n−1 downto 1 do
     j ← random integer such that 0 ≤ j ≤ i
     exchange a[j] and a[i]*/
     int hand_size = d->n_cards;
     card_t ** card_temp = d->cards;

     for (int i = hand_size-1; i>0;i--)
     {
       int j = rand()%(i-0+1);
       card_t * temp = card_temp[j];
       card_temp[j] = card_temp[i];
       card_temp[i] = temp;
     }

}


void assert_full_deck(deck_t * d) {
  /*This function should check that
  the passed in deck contains ever
  valid card exactly once.  If
  the deck has any problems, this function
  should fail an assert.  This will
  be used to help you test your deck
  shuffling: we will shuffle
  a full deck, then call assert_full_deck,
  so that you can identfiy problems with
  the deck.  You can print
  any error messages you want
  if there is a problem.
  Hint: you already wrote deck_contains.*/
  card_t ** card_temp = d->cards;
  int hand_size = d->n_cards;
  for (int i =0;i<hand_size;i++)
  {
    card_t current_card = **(card_temp+i);
    int count =0;
    for(int j=0;j<hand_size;j++)
    {
      card_t card_to_compare = **(card_temp+j);
      if ((current_card.suit == card_to_compare.suit) &(current_card.value == card_to_compare.value))
      {
        count++;
      }
    }
    assert(count==1);

  }

}
