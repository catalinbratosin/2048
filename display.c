#include "utils.h"

void display_highscore(int exista[SIZE][SIZE])
{
	mvprintw(46, 45, "      ");
	mvprintw(46, 45, "%d", exista[SIZE/2][SIZE/2]);
}

void control_panel()
{
	int i = 40, j;
	mvaddch(i, 0, ACS_ULCORNER);
	for (j = 0; j < 20; ++j)
		addch(ACS_HLINE);

	printw("  ~Control Panel~  ");
	for (j = 0; j < 20; ++j)
		addch(ACS_HLINE);

	mvaddch(i, WIDTH_TABLE, ACS_URCORNER);
	mvprintw(42, 2, "Date & Time : ");
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	printw("%d-%d-%d   %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	mvprintw(44, 40, "H I G H S C O R E");
	mvaddch(44, 2, ACS_UARROW);
	printw(" : Sageata sus");
	mvprintw(45, 2, "> : Sageata dreapta");
	mvprintw(46, 2, "V : Sageata jos");
	mvprintw(47, 2, "< : Sageata stanga");
	mvprintw(48, 2, "q : Quit");

	for (j = 1; j < 10; ++j)
	{
		mvaddch(i + j, 0, ACS_VLINE);
		mvaddch(i + j, WIDTH_TABLE, ACS_VLINE);
	}

	mvaddch(50, 0, ACS_LLCORNER);
	mvaddch(50, WIDTH_TABLE, ACS_LRCORNER);
	for (j = 1; j < WIDTH_TABLE; ++j)
		mvaddch(50, j, ACS_HLINE);

	refresh();
}

void print_menu(WINDOW *menu_win, char choices[3][15], int highlight, int starty, int startx)
{
	int x, y, i;

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);

	attron(COLOR_PAIR(1));

	keypad(menu_win, TRUE);
	mvprintw(10, 26, "+------------------------------------------------+");
	mvprintw(11, 26, "|   222222     0000000     4    4      8888888   |");
	mvprintw(12, 26, "|        2     0     0     4    4      8     8   |");
	mvprintw(13, 26, "|        2     0     0     4    4      8     8   |");
	mvprintw(14, 26, "|   222222     0     0     444444      8888888   |");
	mvprintw(15, 26, "|   2          0     0          4      8     8   |");
	mvprintw(16, 26, "|   2          0     0          4      8     8   |");
	mvprintw(17, 26, "|   222222     0000000          4      8888888   |");
	mvprintw(18, 26, "+------------------------------------------------+");
	refresh();

	x = 6;
	y = 3;
	box(menu_win, 0, 0);
	for (i = 0; i < 3; ++i)
	{
		if (highlight == i + 1)
		{
			wattron(menu_win, A_REVERSE);
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, A_REVERSE);
		} else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}

int choose_menu(WINDOW *menu_win, char choices[3][15], int highlight, int starty, int startx, int choice)
{
	int c;
	print_menu(menu_win, choices, highlight, starty, startx);
	while(1)
	{
		c = wgetch(menu_win);
		switch(c)
		{
		case KEY_UP:
			if (highlight == 1)
				highlight = 3;
			else
				--highlight;
			break;

		case KEY_DOWN:
			if (highlight == 3)
				highlight = 1;
			else
				++highlight;
			break;

		case 10:
			choice = highlight;
			break;
		}

		print_menu(menu_win, choices, highlight, starty, startx);
		if(choice != 0)
			break;
	}
	int alegere = 3;
	if (strcmp(choices[highlight-1], "New Game") == 0)
		alegere=1;
	else if (strcmp(choices[highlight-1], "Resume") == 0)
		alegere=2;

	return alegere;
}
