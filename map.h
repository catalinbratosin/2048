#ifndef __MAPH__
#define __MAPH__

//Creaza o celula in matricea jocului de anumite dimensiuni si cu o anumita valare (2/4)
WINDOW *create_cell(int height, int width, int starty, int startx, int val);

//Distruge celula impreuna cu toate componentele ei
void destroy_cell(WINDOW *tmp_cell);

//Adauga o celula noua cu val de 2 sau 4 in mod aleator verificand in matricea de nr exista ca este un spatiu gol
void add_cell(struct wndw tmp_cell[10][10], int exista[10][10]);

//Creaza scheletul tabelei jocului
void create_table();

//Genereaza primele 2 casute in mod random la inceputul jocului
void first2cells(struct wndw tmp_cell[10][10], int exista[10][10]);

#endif