#include "utils.h"

void win_game(int exista[SIZE][SIZE])
{
	int i, j;
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			if (exista[j][i] == 2048)
			{
				mvprintw(30, 64, "FELICITARI   apasa orice tasta pt a reveni la meniul initial");
				getch();
			}
}


void resume(struct wndw tmp_cell[SIZE][SIZE], int exista[SIZE][SIZE])
{
	int i, j;
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			if (exista[j][i] != 0)
			{
				tmp_cell[j][i].win = create_cell(HEIGHT_CELL, WIDTH_CELL, j*8+1, i*15+1, exista[j][i]);
				wrefresh(tmp_cell[j][i].win);
			}
}

int check_wingame(int exista[SIZE][SIZE])
{
	int i, j;
	for (i = 0; i < 4; ++i)
		for ( j = 0; j < 4; ++j)
			if (exista[j][i] == 2048)
				return 1;
	return 0;
}

int check_mat(int exista[SIZE][SIZE])
{
	int i, j;
	for (i = 0; i < 4; ++i)
		for ( j = 0; j < 4; ++j)
			if (exista[j][i] == 0)
				return 0;

	return 1;
}

void run_game(struct wndw my_cell[SIZE][SIZE], int exista[SIZE][SIZE])
{
	int ch;
	initscr();
	cbreak();
	noecho();
	keypad(stdscr,TRUE);

	start_color();
	init_pair(1,COLOR_RED,COLOR_YELLOW);
	init_pair(2,COLOR_YELLOW,COLOR_MAGENTA);
	init_pair(3,COLOR_BLACK,COLOR_CYAN);
	init_pair(4,COLOR_MAGENTA,COLOR_BLUE);
	init_pair(5,COLOR_WHITE,COLOR_GREEN);
	init_pair(6,COLOR_BLUE,COLOR_WHITE);
	init_pair(7,COLOR_BLACK,COLOR_RED);				//Perechiile de culori in functie de valori
	init_pair(8,COLOR_CYAN,COLOR_BLUE);
	init_pair(9,COLOR_YELLOW,COLOR_BLUE);
	init_pair(10,COLOR_RED,COLOR_GREEN);
	init_pair(11,COLOR_RED,COLOR_YELLOW);
	init_pair(100,COLOR_RED,COLOR_BLACK);

	curs_set(0);
	//halfdelay(30);

	while ((ch = getch()) != 'q')
	{
		display_highscore(exista);
		if (check_wingame(exista) == 1)  //Verifica de fiecare data daca nu cumva s-a ajuns la val 2048
		{
			clear();
			mvprintw(30, 10, "FELICITARI   apasa orice tasta pentru a reveni la meniul initial");
			refresh();
			getch();
			break;
		}

		if (check_mat(exista) == 1)   //Verifica ca mat sa nu fie inca plina de val
		{
			clear();
			mvprintw(31, 10, "Ai pierdut");
			refresh();
			getch();
			break;
		}

		switch(ch)   //In functie de input face una din urmatoarele miscari sus jos stanga dreapta
		{
		case KEY_LEFT:
			swipe_left(my_cell,exista);
			sum_left(my_cell,exista);
			swipe_left(my_cell,exista);
			add_cell(my_cell,exista);
			break;

		case KEY_RIGHT:
	    swipe_right(my_cell,exista);
			sum_right(my_cell,exista);
			swipe_right(my_cell,exista);
			add_cell(my_cell,exista);
			refresh();
			break;

		case KEY_UP:
			swipe_up(my_cell,exista);
			sum_up(my_cell,exista);
			swipe_up(my_cell,exista);
			add_cell(my_cell,exista);
			break;

		case KEY_DOWN:
			swipe_down(my_cell,exista);
			sum_down(my_cell,exista);
			swipe_down(my_cell,exista);
			add_cell(my_cell,exista);
			break;

		case ERR:
			auto_swipe(my_cell, exista);
			break;
		}
	}
}
