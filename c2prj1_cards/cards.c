#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value>=2 && c.value<=VALUE_ACE);
  assert(c.suit>=SPADES && c.suit<=CLUBS);

}

const char * ranking_to_string(hand_ranking_t r) {
  if (r == STRAIGHT_FLUSH ){
    return "STRAIGHT_FLUSH";
  }
  if (r == FOUR_OF_A_KIND ){
    return "FOUR_OF_A_KIND";
  }
  if (r == FULL_HOUSE ){
    return "FULL_HOUSE";
  }
  if (r == FLUSH ){
    return "FLUSH";
  }
  if (r == STRAIGHT ){
    return "STRAIGHT";
  }
  if (r == THREE_OF_A_KIND ){
    return "THREE_OF_A_KIND";
  }
  if (r == TWO_PAIR ){
    return "TWO_PAIR";
  }
  if (r == PAIR ){
    return "PAIR";
  }
  if (r >= NOTHING) {
    return "NOTHING";
  }
  printf("Invalid Inputs");
  exit(EXIT_FAILURE);
}

char value_letter(card_t c) {
  if (c.value >= 2 && c.value <= 9) {
    return '0' + c.value;
  }
  if (c.value == 10) {
    return '0';
  }
  if (c.value == VALUE_JACK) {
    return 'J';
  }
  if (c.value == VALUE_QUEEN) {
    return 'Q';
  }
  if (c.value == VALUE_KING) {
    return 'K';
  }
  if (c.value == VALUE_ACE) {
    return 'A';
  }
  printf("Invalid Inputs");
  exit(EXIT_FAILURE);
}


char suit_letter(card_t c) {
  if (c.suit == SPADES) {
    return 's';
  }
  if (c.suit == HEARTS) {
    return 'h';
  }
  if (c.suit == DIAMONDS) {
    return 'd';
  }
  if (c.suit == CLUBS) {
    return 'c';
  }
  printf("Invalid Inputs");
  exit(EXIT_FAILURE); 
}

void print_card(card_t c) {
  char value = value_letter(c);
  char suit = suit_letter(c);
  printf("%c%c", value, suit );
}

card_t card_from_letters(char value_let, char suit_let) {
  card_t  result;
  if (value_let >= '0' + 2 && value_let <= '0' + 9) { // '0' + 2 is the 'number' corresponding to the char "2"
    result.value = value_let - '0';// this is not a char, it's an unsigned value
  } else if (value_let == '0') {
    result.value = 10;
  } else if (value_let == 'J') {
    result.value = VALUE_JACK;
  } else if (value_let == 'Q') {
    result.value = VALUE_QUEEN;
  } else if (value_let == 'K') {
    result.value = VALUE_KING;
  } else if (value_let == 'A') {
    result.value = VALUE_ACE;
  } else {
    printf("Invalid value!");
    exit(EXIT_FAILURE);
  }

  if (suit_let == 's') {
    result.suit = SPADES;
  } else if (suit_let == 'h') {
    result.suit = HEARTS;
  } else if (suit_let == 'd') {
    result.suit = DIAMONDS;
  } else if (suit_let == 'c') {
    result.suit = CLUBS;
  } else {
    printf("Invalid value!");
    exit(EXIT_FAILURE);
  }
  return result;
}

card_t card_from_num(unsigned c) {
 
  assert(c >= 0 && c < 52);

  card_t  temp = {c % 13 + 2, c / 13};
  return temp;
}
