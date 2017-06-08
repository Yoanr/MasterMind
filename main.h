/* YOAN ROCK GROUPE 2 */
#ifndef MAIN_H
#define MAIN_H
#include<graph.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define DECALAGE_X 59 /* correspond au décalage entre 2 cases couleurs en x */
#define DECALAGE_Y 36 /* correspond au décalage entre 2 cases couleurs en y */
#define XCOORD 57 /* correspond a la coordonée en x initiale */
#define YCOORD 366/* correspond a la coordonée en y initiale */

void main(void);
void fenetre(void);
char f_choixecran(void);
void f_quitter (int *, int * );
void f_display_menu (void);
void f_zero (char[][4]);
void f_alea_att (char[4]);
char f_conv_int_char (int);
int f_verif (int,int*,const char[4],const char[][4],int*);
void f_display_combinaison (const char[4]);
int f_combi_def(char[4]);
void f_ia (char[][4],int,int,char[4],int);
void f_tableau_pn(int,char[][4],char[4],int,int);

#endif
