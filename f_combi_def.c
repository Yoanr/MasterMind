#include"main.h"
int f_combi_def (char tabdef[4]) {
  int indicecolonne=0;
  
  int ycoord=416;
  int x;
  int y;
  int valider=0;

  while (indicecolonne<4) {

    printf("indicecolonne:%d\n",indicecolonne);
    while(!SourisCliquee()) {
       
    }

    x=_X;
    y=_Y;

    if(x>430 && x<470 && y>35 && y<70 && indicecolonne<4) { /* ROUGE */

      printf("JE SUIS ARRIVER 1\n");
      ChoisirCouleurDessin(CouleurParNom("red"));
      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,ycoord,52,30);
     
      tabdef[indicecolonne]='r';
      indicecolonne++;
      
    }

    if(x>514 && x<550 && y>35 && y<70 && indicecolonne<4) { /* VERT */
      printf("JE SUIS ARRIVER 2\n");
      ChoisirCouleurDessin(CouleurParNom("green"));
      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,ycoord,52,30);
     
      tabdef[indicecolonne]='v';
       indicecolonne++;

    }
    if(x>600 && x<640 && y>35 && y<70 && indicecolonne<4) { /* JAUNE*/
      printf("JE SUIS ARRIVER 3\n");
      ChoisirCouleurDessin(CouleurParNom("yellow"));
      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,ycoord,52,30);
     
      tabdef[indicecolonne]='j'; 
      indicecolonne++;

    }

    if(x>470 && x<506 && y>95 && y<130 && indicecolonne<4) { /* BLEU*/
      printf("JE SUIS ARRIVER 4\n");
      ChoisirCouleurDessin(CouleurParNom("blue"));
      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,ycoord,52,30);
      
      tabdef[indicecolonne]='u'; 
     indicecolonne++;

    }
    if(x>560 && x<600 && y>95 && y<130 && indicecolonne<4) { /*NOIR*/
      printf("JE SUIS ARRIVER 5\n");
      ChoisirCouleurDessin(CouleurParNom("black"));
      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,ycoord,52,31);
      
      tabdef[indicecolonne]='n'; 
     indicecolonne++;

    }


    if(x>650 && x<688 && y>95 && y<130 && indicecolonne<4) { /* BLANC*/
      printf("JE SUIS ARRIVER 6\n");
      ChoisirCouleurDessin(CouleurParNom("white"));
      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,ycoord,52,32);
      
      tabdef[indicecolonne]='b'; 
    indicecolonne++;

    }
    printf("finfonction\n");
    
  }
  return 1;
}
