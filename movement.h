#ifndef __MOVEMENTH__
#define __MOVEMENTH__

//Muta toate casutele/celulele matricei jocului in partea dreapta
void swipe_right(struct wndw tmp_cell[10][10], int exista[10][10]);

//Muta toate casutele/celulele matricei jocului in partea stanga
void swipe_left(struct wndw tmp_cell[10][10], int exista[10][10]);

//Muta toate casutele/celulele matricei jocului in partea de sus
void swipe_up(struct wndw tmp_cell[10][10], int exista[10][10]);

//Muta toate casutele/celulele matricei jocului in partea de jos
void swipe_down(struct wndw tmp_cell[10][10], int exista[10][10]);

//Face adunarea pe linii pornind din dreapta in stanga si cand gaseste 2 calule cu aceiasi val le aduna in celula din dreapta iar cea din stanga dispare
void sum_right(struct wndw tmp_cell[10][10], int exista[10][10]);

//Face adunarea pe linii pornind din stanga in dreapta si cand gaseste 2 calule cu aceiasi val le aduna in celula din stanga iar cea din dreapta dispare
void sum_left(struct wndw tmp_cell[10][10], int exista[10][10]);

//Face adunarea pe coloane pornind de sus in jos si cand gaseste 2 calule cu aceiasi val le aduna in celula de sus iar cea de jos dispare
void sum_up(struct wndw tmp_cell[10][10], int exista[10][10]);

//Face adunarea pe coloane pornind de jos in sus si cand gaseste 2 calule cu aceiasi val le aduna in celula de jos iar cea de sus dispare
void sum_down(struct wndw tmp_cell[10][10], int exista[10][10]);

//facem o simulare folosind o matrice copie si numaram prin alta 
	//functie numarul de celule goale. la final comparam nr si alegem prima
	//varianta cea mai mare de 0-uri 
void auto_swipe(struct wndw tmp_cell[10][10], int exista[10][10]);

#endif