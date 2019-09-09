#include "utils.h"

WINDOW *create_cell(int height, int width, int starty, int startx, int val)
{
	WINDOW *tmp_cell;

	int copie_val, l;
	copie_val = val;
	l = 0;

	while (copie_val != 1) //Atribuie lui l puterea la care se afla variabila val
	{
		l++;
		copie_val = copie_val / 2;
	}
	tmp_cell = newwin(height, width, starty, startx);
	mvwprintw(tmp_cell, height/2, width/2, "%d", val);
	wbkgd(tmp_cell, COLOR_PAIR(l)); //Am codificat fiecare pereche de culori de la 1-11 in functie de puterile lui 2
	wrefresh(tmp_cell);				// val = 2 ^ l
	return tmp_cell;
}

void destroy_cell(WINDOW *tmp_cell)
{
	mvwprintw(tmp_cell, HEIGHT_CELL/2, WIDTH_CELL/2, "      ");
	wborder(tmp_cell, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');	//sterge marginile
	wbkgd(tmp_cell, COLOR_PAIR(100));			//ii atribuie o pereche de culori neutra

	wrefresh(tmp_cell);
	delwin(tmp_cell);
}

void add_cell(struct wndw tmp_cell[SIZE][SIZE], int exista[SIZE][SIZE])
{
	int x, y, z;
	int arrayVal[5] = {2, 4, 2, 2, 2};
	srand(time(NULL) % 100);
	do
	{
		x = rand() % 4;
		y = rand() % 4;
	} while (exista[y][x] != 0);

	z = rand() % 5;
	exista[y][x] = arrayVal[z];
	tmp_cell[y][x].win = create_cell(HEIGHT_CELL, WIDTH_CELL, y*8+1, x*15+1, exista[y][x]);
	wrefresh(tmp_cell[y][x].win);
}

void create_table()
{
	int i, j;
	addch(ACS_ULCORNER);
	mvaddch(HEIGHT_TABLE, 0, ACS_LLCORNER);
	mvaddch(0, WIDTH_TABLE, ACS_URCORNER);
	mvaddch(HEIGHT_TABLE, WIDTH_TABLE, ACS_LRCORNER);

	for (i = 1; i < WIDTH_TABLE; ++i)
		mvaddch(0,i,ACS_HLINE);

	for (i = 1; i < HEIGHT_TABLE; ++i)
		mvaddch(i,0,ACS_VLINE);

	for (i = 1; i < WIDTH_TABLE; ++i)
		mvaddch(HEIGHT_TABLE,i,ACS_HLINE);

	for (i = 1; i < HEIGHT_TABLE; ++i)
		mvaddch(i,WIDTH_TABLE,ACS_VLINE);

	for (i = 1; i < N_LINES; ++i)
	{
		mvaddch(8*i, 0, ACS_LTEE);
		mvaddch(8*i, WIDTH_TABLE, ACS_RTEE);

		for (j = 1; j < WIDTH_TABLE; ++j)
			mvaddch(8*i,j,ACS_HLINE);
	}

	for (i = 1; i < N_COLS; ++i)
	{
		mvaddch(0, 15*i, ACS_TTEE);
		mvaddch(HEIGHT_TABLE, 15*i, ACS_BTEE);

		for (j = 1; j < HEIGHT_TABLE; ++j)
			mvaddch(j, 15*i, ACS_VLINE);
	}

	for (i = 1; i <= 3; ++i)
		for (j = 1; j <= 3; ++j)
			mvaddch(i*8,j*15,ACS_PLUS);

	mvprintw(40, 0, "AICI");
	refresh();
}

void first2cells(struct wndw tmp_cell[SIZE][SIZE], int exista[SIZE][SIZE])
{
	int val;
	int x1, y1, x2, y2, z;
	const int arrayVal[5] = {2, 4, 2, 2, 2};
	srand(time(NULL));
	x1 = rand() % 4;
	y1 = rand() % 4;
	z = rand() % 5;

	val = arrayVal[z];
	tmp_cell[y1][x1].win = create_cell(HEIGHT_CELL, WIDTH_CELL, y1*8+1, x1*15+1, val);
	exista[y1][x1] = val;
	refresh();
	srand(time(NULL) % 10);
	while (true)
	{
		x2 = rand() % 4;
		y2 = rand() % 4;
		if (x1 != x2 || y1 != y2)
		{
			z = rand() % 5;
			val = arrayVal[z];
			tmp_cell[y2][x2].win = create_cell(HEIGHT_CELL, WIDTH_CELL, y2*8+1, x2*15+1, val);
			exista[y2][x2] = val;
			refresh();
			break;
		}
	}
	refresh();
}
