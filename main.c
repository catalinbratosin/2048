#include <stdlib.h>
#include <string.h>
#include "utils.h"

int main()
{
	int startx = 0;
	int starty = 0;
	char choices[3][15] = {"New Game","Resume","Exit"};
	int i,j;
	WINDOW *menu_win;

	struct wndw my_cell[SIZE][SIZE];
	int exista[SIZE][SIZE] = {0};
	int highlight = 1;
	int choice = 0;

	initscr();
	cbreak();
	noecho();
	keypad(stdscr,TRUE);
	curs_set(0);

	startx = ((80 - WIDTH) / 2) + 10;
	starty = ((24 - HEIGHT) / 2) + 14;
	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	print_menu(menu_win, choices, highlight,starty, startx);
	int ce_aleg;

	do
	{
		clear();
		print_menu(menu_win, choices, highlight,starty, startx);
		ce_aleg = choose_menu(menu_win, choices, highlight, starty, startx, choice);

		switch(ce_aleg)
		{
		case 1:
			clear();
			for (i = 0; i < 4; ++i)
				for (j = 0; j < 4; ++j)
					exista[j][i] = 0;

			exista[5][5]=0;
			create_table();
			first2cells(my_cell, exista);
			control_panel();
			refresh();
			run_game(my_cell, exista);
			break;

		case 2:
			clear();
			create_table();
			control_panel();
			refresh();
			resume(my_cell,exista);
			run_game(my_cell, exista);
			break;
		case 3:
			clear();
			endwin();
		break;
		}
	} while(ce_aleg != 3);

	refresh();
	endwin();
	return 0;
}
