#ifndef __GAME_LOGICH__
#define __GAME_LOGICH__

//Mesaj pentru castigarea jocului
//Atunci cand parcurgand matricea suport exista gaseste printre valori un 2048
void win_game(int exista[10][10]);

//Functia de resume pentru reluarea jocului de unde a ramas
//Se foloseste de matricea exista si acolo unde gaseste val diferite de 0 creaza celule cu respectiva val
void resume(struct wndw tmp_cell[10][10], int exista[10][10]);

//Functie pentru a a stii daca jocul este castigat
int check_wingame(int exista[10][10]);

//Verifica daca mat este plina de val si in acest caz jocul este pierdut
int check_mat(int exista[10][10]);

//Jocul in sine
void run_game(struct wndw my_cell[10][10], int exista[10][10]);

#endif