#ifndef __CHECKERS_H__
#define __CHECKERS_H__

#define BOARD_SIZE 8
#define BITBOARD_SIZE 64

int bit_value_bitboard(unsigned long int bitboard, int position);
void print_bitboard(unsigned long int bitboard);
void set_positive_bit_bitboard(unsigned long int* bitboard, int position);
void set_negative_bit_bitboard(unsigned long int* bitboard, int position);

#endif