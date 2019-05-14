#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

int stdin_scan_input();
int click_input();
int get_position(int x, int y);
void shuffle(Board* board, int position, int counter);

#endif