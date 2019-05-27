#ifndef __CHECKERS_H__
#define __CHECKERS_H__

#define BOARD_SIZE 8
#define BITBOARD_SIZE 64

int bit_value_bitboard(uint64_t bitboard, int position);

void print_bitboard(uint64_t bitboard);
void print_bitboard_board(uint64_t bitboard);

uint64_t set_positive_bit_bitboard(uint64_t bitboard, int position);
uint64_t set_negative_bit_bitboard(uint64_t bitboard, int position);

int set_lady_mask(uint64_t* bitboard, int ladyPosition);
int slash_bound(int ladyPosition);
int antislash_bound(int ladyPosition);

int get_column(int position);
int get_row(int position);
int get_position(int row, int column);

#endif