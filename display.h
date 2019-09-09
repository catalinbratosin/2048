#ifndef __DISPLAYH__
#define __DISPLAYH__

//Afiseaza scorul actual
void display_highscore(int exista[10][10]);

//Afiseaza meniul de control
void control_panel();

//Creaza meniul principal
void print_menu(WINDOW *menu_win, char choices[3][15], int highlight, int starty, int startx);

//Meniul din care se aleg optiuniile
int choose_menu(WINDOW *menu_win, char choices[3][15], int highlight, int starty, int startx, int choice);

#endif
