#include"main.h"
int f_verif (int indiceligne,int *game, const char tabalea[4], const char tabcolor[][4],int *valider) {
  int pionnoir=0,pn=0,pb=0,pionblanc=0;
  int i,i2;
  int indice=0;
  int rien=0;
  int xcoord=295,ycoord=375; /* coordonée de l'affichage du debut du rectangle */int x,y;
  couleur c;
  char nbrtentative[255];
  char permission[4];
  char permission2[4];
  for(i=0;i<4;i++) {
    permission[i]=1;
    permission2[i]=1;
  }
  printf("indiceligne:%d\n",indiceligne);
 
  for(i=0;i<4;i++) {
    if(tabalea[i]==tabcolor[indiceligne][i]){
      pionnoir++;
      permission[i]=0;
      permission2[i]=0;
    }
  }

  for(i=0;i<4;i++) {
    for(i2=0;i2<4;i2++) {

      if (tabalea[i]==tabcolor[indiceligne][i2] && permission[i] && permission2[i2] && i!=i2 ) {
	pionblanc++;
	permission[i]=0;
	permission2[i2]=0;
      }
    }
  }
  pn=pionnoir;
  pb=pionblanc;
 
  printf("PIONNOIR :%d\n", pionnoir);
  printf("PIONBLANC :%d\n",pionblanc);
  for(i=0;i<4;i++) {
    printf("%d",permission[i]);
    printf("%c",tabalea[i]);
  }
  printf("\n");
  for(i=0;i<4;i++) {
    printf("%i",permission2[i]);
    printf("%c",tabcolor[indiceligne][i]);
  }
  printf("\n");

  printf("indice : %d\n",indice);
  pn=pionnoir;
  for(;pionnoir>0;pionnoir--) {
    ChoisirCouleurDessin(CouleurParNom("black"));
    RemplirRectangle(xcoord+pionnoir*10,ycoord-indiceligne*DECALAGE_Y,5,5);
  }
  for(;pionblanc>0;pionblanc--) {
    ChoisirCouleurDessin(CouleurParNom("white"));
    RemplirRectangle((xcoord+40)+pionblanc*10,ycoord-indiceligne*DECALAGE_Y,5,5);
  }
  if(pn==4) {
    ChargerImage("./img/victoire.png",400,200,0,0,200,150);
    indiceligne++;
    sprintf(nbrtentative,"%d",indiceligne);
    c=CouleurParNom("black");
    ChoisirCouleurDessin(c);

    EcrireTexte(565,340,nbrtentative,2);
  }
  if(indiceligne==9) {
    ChargerImage("./img/button.png",430,319,0,0,345,152);
    ChargerImage("./img/defaite.png",300,200,0,0,200,150);
   
    printf("CAS DEFAITE\n");
 f_display_combinaison(tabalea);
  }
   
  /* AFFICHAGE DE LA COMBINAISON */ 
 

  while(SourisCliquee()) {
  }
  if(x>625 && x<731 && y>400 && y<459) { /* MENU */
    *valider=1;
    *game=0;
  }

  
 
  return pn;

}

