#include "utils.h"

void nr0(int exista[SIZE][SIZE], int val)
{
	int i, j;
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			if (exista[j][i] == 0)
				val++;
}
