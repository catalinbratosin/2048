#ifndef __UTILSH__
#define __UTILSH__

#include <ncurses.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 9

#define HEIGHT_CELL  7
#define WIDTH_CELL   14

#define HEIGHT_TABLE 32
#define WIDTH_TABLE  60


#define N_CELLS 16
#define N_LINES 4
#define N_COLS  4

#define SIZE 10

struct wndw
{
	WINDOW *win;
};

//Calculeaza numarul de 0-uri din matricea exista
void nr0(int exista[10][10], int val);

#endif
