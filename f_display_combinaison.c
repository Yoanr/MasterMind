#include"main.h"
void f_display_combinaison (const char tabalea[4]) {
  /* couleur c;*/
  char* c;
  int i;
  int indicecolonne=0;
  for(i=0;i<=3;i++) {
    if( tabalea[i]=='v') {
      c="green";
    }
    else  if( tabalea[i]=='u') {
      c="blue";
    }
    else  if( tabalea[i]=='b') {
      c="white";
    }
    else  if( tabalea[i]=='n') {
      c="black";
	}

    else  if( tabalea[i]=='j') {
      c="yellow";
    }

    else  if( tabalea[i]=='r') {
      c="red";
    }
    ChoisirCouleurDessin(CouleurParNom(c));
    RemplirRectangle(56+(indicecolonne*DECALAGE_X),416,52,30);
    indicecolonne++;
  }
}
