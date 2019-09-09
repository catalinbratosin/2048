#include "utils.h"

void swipe_right(struct wndw tmp_cell[SIZE][SIZE], int exista[SIZE][SIZE])
{
	int i, j;
	int jcurrent, icurrent;
	for (j = 0; j < 4; ++j)
	{
		jcurrent = j;		//Tine minte pozitia curenta adica cea pe care va muta celulele
		icurrent = 3;			//Cea mai apropiata pozitie egala cu 0 din marginea dreapta
		for (i = 3; i >= 0; --i)
		{
			if (exista[j][i])
			{
				if (i != icurrent)   //Cand gaseste o pozitie a carei val este diferita de 0 si nu se afla pe poz cea mai din dreapta face mutarea
				{
					destroy_cell(tmp_cell[j][i].win);
					exista[jcurrent][icurrent] = exista[j][i];
					exista[j][i] = 0;
					tmp_cell[jcurrent][icurrent].win = create_cell(HEIGHT_CELL, WIDTH_CELL, jcurrent*8+1, icurrent*15+1, exista[jcurrent][icurrent]);
					wrefresh(tmp_cell[jcurrent][icurrent].win);
					icurrent--;
				} else icurrent--;
			}
		}
	}
}

void swipe_left(struct wndw tmp_cell[SIZE][SIZE], int exista[SIZE][SIZE])
{
	int i, j;
	int jcurrent, icurrent;
	for (j = 0; j < 4; ++j)
	{
		jcurrent = j;		//Tine minte pozitia curenta adica cea pe care va muta celulele
		icurrent = 0;		//Cea mai apropiata pozitie egala cu 0 din marginea stanga
		for (i = 0; i <= 3; ++i)
		{
			if (exista[j][i])
			{
				if (i != icurrent)		//Cand gaseste o pozitie a carei val este diferita de 0 si nu se afla pe poz cea mai din stanga face mutarea
				{
					destroy_cell(tmp_cell[j][i].win);
					exista[jcurrent][icurrent] = exista[j][i];
					exista[j][i] = 0;
					tmp_cell[jcurrent][icurrent].win = create_cell(HEIGHT_CELL, WIDTH_CELL, jcurrent*8+1, icurrent*15+1, exista[jcurrent][icurrent]);
					wrefresh(tmp_cell[jcurrent][icurrent].win);
					icurrent++;
				} else icurrent++;
			}
		}
	}
}

void swipe_up(struct wndw tmp_cell[SIZE][SIZE], int exista[SIZE][SIZE])
{
	int i, j;
	int jcurrent, icurrent;
	for (i = 0; i < 4; ++i)
	{
		jcurrent = 0;		//Tine minte pozitia curenta adica cea pe care va muta celulele
		icurrent = i;		//Cea mai apropiata pozitie egala cu 0 din marginea de sus
		for (j = 0; j <= 3; ++j)
		{
			if (exista[j][i])
			{
				if (j != jcurrent)	//Cand gaseste o pozitie a carei val este diferita de 0 si nu se afla pe poz cea mai de sus face mutarea
				{
					destroy_cell(tmp_cell[j][i].win);
					exista[jcurrent][icurrent] = exista[j][i];
					exista[j][i] = 0;
					tmp_cell[jcurrent][icurrent].win = create_cell(HEIGHT_CELL, WIDTH_CELL, jcurrent*8+1, icurrent*15+1, exista[jcurrent][icurrent]);
					wrefresh(tmp_cell[jcurrent][icurrent].win);
					jcurrent++;
				} else jcurrent++;
			}
		}
	}
}


void swipe_down(struct wndw tmp_cell[SIZE][SIZE], int exista[SIZE][SIZE])
{
	int i, j;
	int jcurrent, icurrent;
	for (i = 0; i < 4; ++i)
	{
		jcurrent = 3;		//Tine minte pozitia curenta adica cea pe care va muta celulele
		icurrent = i;		//Cea mai apropiata pozitie egala cu 0 din marginea de jos
		for (j = 3; j >= 0; --j)
		{
			if (exista[j][i])
			{
				if (j != jcurrent)	//Cand gaseste o pozitie a carei val este diferita de 0 si nu se afla pe poz cea mai de jos face mutarea
				{
					destroy_cell(tmp_cell[j][i].win);
					exista[jcurrent][icurrent] = exista[j][i];
					exista[j][i] = 0;
					tmp_cell[jcurrent][icurrent].win = create_cell(HEIGHT_CELL, WIDTH_CELL, jcurrent*8+1, icurrent*15+1, exista[jcurrent][icurrent]);
					wrefresh(tmp_cell[jcurrent][icurrent].win);
					jcurrent--;
				} else	jcurrent--;
			}
		}
	}
}

void sum_right(struct wndw tmp_cell[SIZE][SIZE], int exista[SIZE][SIZE])
{
	int i, j;
	for (j = 0; j < 4; ++j)
		for (i = 3; i >= 1; --i)
			if (exista[j][i] != 0 && exista[j][i] == exista[j][i-1])
			{
				destroy_cell(tmp_cell[j][i].win);
				destroy_cell(tmp_cell[j][i-1].win);
				exista[j][i] = exista[j][i] * 2;
				exista[5][5] = exista[5][5] + exista[j][i];
				exista[j][i-1] = 0;
				tmp_cell[j][i].win = create_cell(HEIGHT_CELL, WIDTH_CELL, j*8+1, i*15+1, exista[j][i]);
				wrefresh(tmp_cell[j][i].win);
			}
}

void sum_left(struct wndw tmp_cell[SIZE][SIZE], int exista[SIZE][SIZE])
{
	int i, j;
	for (j = 0; j < 4; ++j)
		for (i = 0; i <= 2; ++i)
			if (exista[j][i] !=0 && exista[j][i]==exista[j][i+1])
			{
				destroy_cell(tmp_cell[j][i].win);
				destroy_cell(tmp_cell[j][i+1].win);
				exista[j][i] = exista[j][i] * 2;
				exista[5][5] = exista[5][5] + exista[j][i];
				exista[j][i+1] = 0;
				tmp_cell[j][i].win = create_cell(HEIGHT_CELL, WIDTH_CELL, j*8+1, i*15+1, exista[j][i]);
				wrefresh(tmp_cell[j][i].win);
			}
}

void sum_up(struct wndw tmp_cell[SIZE][SIZE], int exista[SIZE][SIZE])
{
	int i, j;
	for (i = 0; i < 4; ++i)
		for (j = 0; j <= 2; ++j)
			if (exista[j][i] != 0 && exista[j][i] == exista[j+1][i])
			{
				destroy_cell(tmp_cell[j][i].win);
				destroy_cell(tmp_cell[j+1][i].win);
				exista[j][i] = exista[j][i] * 2;
				exista[5][5] = exista[5][5] + exista[j][i];
				exista[j+1][i] = 0;
				tmp_cell[j][i].win = create_cell(HEIGHT_CELL, WIDTH_CELL, j*8+1, i*15+1, exista[j][i]);
				wrefresh(tmp_cell[j][i].win);
			}
}

void sum_down(struct wndw tmp_cell[SIZE][SIZE], int exista[SIZE][SIZE])
{
	int i, j;
	for (i = 0; i < 4; ++i)
		for (j = 3; j >= 1; --j)
			if (exista[j][i] != 0 && exista[j][i] == exista[j-1][i])
			{
				destroy_cell(tmp_cell[j][i].win);
				destroy_cell(tmp_cell[j-1][i].win);
				exista[j][i] = exista[j][i] * 2;
				exista[5][5] = exista[5][5] + exista[j][i];
				exista[j-1][i] = 0;
				tmp_cell[j][i].win = create_cell(HEIGHT_CELL, WIDTH_CELL, j*8+1, i*15+1, exista[j][i]);
				wrefresh(tmp_cell[j][i].win);
			}
}

void auto_swipe(struct wndw tmp_cell[SIZE][SIZE], int exista[SIZE][SIZE])
{
	int empty_cell[4] = {0};
	int i = 0, j = 0, k = 0, imax = 0, max = 0;

	for (i = 0; i < 4; ++i)
	{
		struct wndw copy_cell[SIZE][SIZE];
    int copy_exista[SIZE][SIZE];

		for (j = 0; j < 4; ++j)
			for (k = 0; k < 4; ++k)
			{
				copy_cell[k][j].win = tmp_cell[k][j].win;
				copy_exista[k][j] = exista[k][j];
			}

		switch (i)
		{
		case 0:
			swipe_left(copy_cell, copy_exista);
			sum_left(copy_cell, copy_exista);
			swipe_left(copy_cell, copy_exista);
			add_cell(copy_cell, copy_exista);
			break;
		case 1:
			swipe_right(copy_cell, copy_exista);
			sum_right(copy_cell, copy_exista);
			swipe_right(copy_cell, copy_exista);
			add_cell(copy_cell, copy_exista);
			break;
		case 2:
			swipe_up(copy_cell, copy_exista);
			sum_up(copy_cell, copy_exista);
			swipe_up(copy_cell, copy_exista);
			add_cell(copy_cell, copy_exista);
			break;
		case 3:
			swipe_down(copy_cell, copy_exista);
			sum_down(copy_cell, copy_exista);
			swipe_down(copy_cell, copy_exista);
			add_cell(copy_cell, copy_exista);
			break;
		}

		nr0(copy_exista, empty_cell[i]);
		if (empty_cell[i] > max)
		{
			max = empty_cell[i];
			imax = i;
		}

		for (j = 0; j < 4; ++j)
			for (k = 0; k < 4; ++k)
			{
				copy_cell[k][j].win = newwin(HEIGHT_CELL, WIDTH_CELL, k*8+1, j*15+1);
				copy_exista[k][j] = 0;
			}
	}

	switch (imax)
	{
	case 0:
		swipe_left(tmp_cell, exista);
		sum_left(tmp_cell, exista);
		swipe_left(tmp_cell, exista);
		add_cell(tmp_cell, exista);
		break;
	case 1:
		swipe_right(tmp_cell, exista);
		sum_right(tmp_cell, exista);
		swipe_right(tmp_cell, exista);
		add_cell(tmp_cell, exista);
		break;
	case 2:
		swipe_up(tmp_cell, exista);
		sum_up(tmp_cell, exista);
		swipe_up(tmp_cell, exista);
		add_cell(tmp_cell, exista);
		break;
	case 3:
		swipe_down(tmp_cell, exista);
		sum_down(tmp_cell, exista);
		swipe_down(tmp_cell, exista);
		add_cell(tmp_cell, exista);
		break;
	}
}
