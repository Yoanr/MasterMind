/* YOAN ROCK GROUPE 2 */
#include"main.h"
void main(void) {
  char ecranchoisi; /* designe sur quelle bouton a cliquer l'utilisateur*/
  int game=1; /* booleen pour rester ou quitter les boucles générales*/
  int menu=1; /* variable permettant de revenir dans le menu sans quitter le jeu */
  char tabcolor[10][4]; /* tableau contenant char correspondant couleur choisie*/char tabdef[4]; /* tableau aleatoire du IA*/
  char tabfind[4]; /* trouver combinaison secrete */ 
  int tableaurempli=0;/* boolen pour fct f_ia pour permettre au IA de continuer sa reflexion */
  int indicecolonne=0; /* correspond a la colonne actuel */
  int indiceligne=0; /* correspond a la ligne actuel */
  int x,y; /* correspond aux coordonée du click */
  int valider=0;
  int i=0,i2=0,indice=0;
  int ok=0; /* boolen permettant de permettre a l'utilisateur de cliquer sur ok pour que l'ordinateur continue a trouver une nouvelle solution */
  int bool=0;
  couleur c;
  int pn=0,vpn=0,ancienvpn=0; /*nbr de pion noir*/
  int a; /*booleon pour fonction f_def*/
  fenetre();
  while(menu==1) {
    valider=0;
    game=1;
    printf("DEBUT\n");
    f_display_menu();
   	  
    /*F(CHOIX ENTRE 3 BOUTONS)  qui renvoi un char qui renseigne sur l'ecran choisie*/
    f_zero(tabcolor);
    
    ecranchoisi=f_choixecran();
    printf("ECRAN=%c\n",ecranchoisi);
    if(ecranchoisi=='a')  {  /* designe ecran attaquant*/
      ChargerImage("img/Menu_Attaquant.png",0,0,0,0,800,600);
      
      f_alea_att(tabdef);
      for(i=0;i<4;i++){
	printf("%c",tabdef[i]);
      }
      printf("\nCOMMENCEMENT\n");
      game=1;
      indiceligne=0;
      
      while(game==1) {
	if(indiceligne==9 && x>625 && x<731 && y>400 && y<459) {
	  game=0;
	  valider=0;
	}
        
	for(;indiceligne<10;indiceligne++) {
 
	  ChoisirCouleurDessin(CouleurParNom("grey"));
	  RemplirRectangle(20,YCOORD-indiceligne*DECALAGE_Y+10,10,10);
	  c=CouleurParComposante(185,122,87); /* couleur de fond pour effacer ancien carré qui indique l'indice+1 ou on se trouve */

	  ChoisirCouleurDessin(c);
	  RemplirRectangle(20,YCOORD-(indiceligne-1)*DECALAGE_Y+10,10,10);

	  indicecolonne=0;
	  valider=0;
	  while(valider!=1) {
	    
     
	    while(!SourisCliquee()) {
		
	    }
	    x=_X;
	    y=_Y;
	      
	    
	    if(x>430 && x<470 && y>35 && y<70 && indicecolonne<4) { /* ROUGE */
	      
	      ChoisirCouleurDessin(CouleurParNom("red"));
	      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,YCOORD-indiceligne*DECALAGE_Y,52,30);
	      
	      tabcolor[indiceligne][indicecolonne]='r'; 
	      indicecolonne++;
		  
	    }
	      
	      
	    if(x>514 && x<550 && y>35 && y<70 && indicecolonne<4) { /* VERT */
	      
	      ChoisirCouleurDessin(CouleurParNom("green"));
	      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,YCOORD-indiceligne*DECALAGE_Y,52,30);
	      
	      tabcolor[indiceligne][indicecolonne]='v';
	      indicecolonne++; 
		 
	    }
	      
	      
	    if(x>600 && x<640 && y>35 && y<70 && indicecolonne<4) { /* JAUNE*/
	      
	      ChoisirCouleurDessin(CouleurParNom("yellow"));
	      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,YCOORD-indiceligne*DECALAGE_Y,52,30);
	      
	      tabcolor[indiceligne][indicecolonne]='j'; 
	      indicecolonne++;
		
	    }
	      
	      
	    if(x>470 && x<506 && y>95 && y<130 && indicecolonne<4) { /* BLEU*/
	      
	      ChoisirCouleurDessin(CouleurParNom("blue"));
	      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,YCOORD-indiceligne*DECALAGE_Y,52,30);
	      
	      tabcolor[indiceligne][indicecolonne]='u'; 
	      indicecolonne++;

	    }
	    
	      
	    if(x>560 && x<600 && y>95 && y<130 && indicecolonne<4) { /*NOIR*/
	      
	      ChoisirCouleurDessin(CouleurParNom("black"));
	      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,YCOORD-indiceligne*DECALAGE_Y,52,31);
	      
	      tabcolor[indiceligne][indicecolonne]='n'; 
	      indicecolonne++;

	    }
	     
	          
	    if(x>650 && x<688 && y>95 && y<130 && indicecolonne<4) { /* BLANC*/
	     
	      ChoisirCouleurDessin(CouleurParNom("white"));
	      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,YCOORD-indiceligne*DECALAGE_Y,52,32);
	      
	      tabcolor[indiceligne][indicecolonne]='b'; 
	      indicecolonne++;

	    }  
	    

	 
	    if(x>607 && x<733 && y>330 && y<390 && indicecolonne<=4) { /*RESET*/
	      
	      printf("RESET\n");
	      for(indicecolonne=0;indicecolonne<4;indicecolonne++) {
		tabcolor[indiceligne][indicecolonne]='0';
	      }
	      indicecolonne=0;
	      ChargerImage("img/reset.png",XCOORD+indicecolonne,YCOORD-indiceligne*DECALAGE_Y,0,0,235,32); 
	    }
	  
	
	      
	    if(x>466 && x<564 && y>332 && y<390 && indicecolonne>3) { /* OK */
	      printf("OK\n");
	      f_verif(indiceligne,&game,tabdef,tabcolor,&valider);
	      valider=1;


	    }
	    if(x>436 && x<586 && y>407 && y<455) { /* QUITTER */
	      valider=1;
	      indiceligne=9;
	      f_quitter(&game,&menu);
	    }
	  
	    if(x>625 && x<731 && y>400 && y<459) { /* MENU */
	      valider=1;
	      indiceligne=9;
	      game=0;
	    }

        
      
	    int i=0;
	    for(;i<4;i++) {
	      printf("%c",tabcolor[indiceligne][i]);
	    }
          
	  }
	}
      }
    }

  

    
    if(ecranchoisi=='d') {  /*designe ecran defenseur */
      printf("defense\n");
      ChargerImage("img/Menu_Defenseur.png",0,0,0,0,800,600);
      for(i=0;i<4;i++) {
	tabdef[i]='0';
      }
      
      for(i=0;i<4;i++) {
	tabfind[i]='0';
      }
for(i=0;i<10;i++) {
      for(i2=0;i2<4;i2++) {
	tabcolor[i][i2]='0';
      }
      }

      f_combi_def(tabdef);
      
     for(indice=0;indice<4;indice++) {
       printf("%c",tabfind[i]);
      } 
	
         
      while(game==1) {
	printf("INGAME\n");
	for(indiceligne=0;indiceligne<10;++indiceligne) {
	  
	  f_ia(tabcolor,indiceligne,pn,tabfind,tableaurempli);
 
	 for(i=0;i<4;i++) {
	     printf("%c\n",tabcolor[indiceligne][i]);
	     }
	  while(!SourisCliquee()) {
	   
	   
	    }
	  x=_X;
	  y=_Y;
	  if(x>466 && x<564 && y>332 && y<390 && indiceligne<10 ) { /* OK */
	      
	    pn=f_verif(indiceligne,&game,tabdef,tabcolor,&valider);
	    ancienvpn=vpn; /* ancienne valeur pour l'indice dans la fct tableaupn */
	    vpn=vpn+pn; /* cumuler les pionnoirs */
	    	    ok=1;
	    indicecolonne=0;
	    	  }
	  
	  
	  
	   if(pn>0) {
	     printf("fonction tableauPN tabcolor=%c,pn=%d,vpn=%d, ancienvpn=%d", tabcolor[indiceligne][1],pn,vpn,ancienvpn);
	    
	     for(i=0;i<4;i++) {
	     printf("%c",tabfind[i]);
	     }
	     f_tableau_pn(indiceligne,tabcolor,tabfind,vpn,ancienvpn);
	     printf("\n");
	     printf("apres\n");
	      for(i=0;i<4;i++) {
	     printf("%c",tabfind[i]);
	     }
	      printf("\n");
	   }
for(i=0;i<4;i++) {
	     printf("%c",tabcolor[indiceligne][i]);
	     }
	  printf("\n"); 
	 	  for(indicecolonne=0;indicecolonne<4;indicecolonne++) {
	    printf("INBOUCLE\n");
	     
	    if(indiceligne<10) {
	  
	    if(tabcolor[indiceligne][indicecolonne]=='r') {
	      ChoisirCouleurDessin(CouleurParNom("red"));
	      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,YCOORD-indiceligne*DECALAGE_Y,52,32);
	    }
	    if(tabcolor[indiceligne][indicecolonne]=='v') {
	      ChoisirCouleurDessin(CouleurParNom("green"));
	      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,YCOORD-indiceligne*DECALAGE_Y,52,32);
	    }
	    if(tabcolor[indiceligne][indicecolonne]=='j') {
	      ChoisirCouleurDessin(CouleurParNom("yellow"));
	      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,YCOORD-indiceligne*DECALAGE_Y,52,32);
	    }
	    if(tabcolor[indiceligne][indicecolonne]=='u') {
	      ChoisirCouleurDessin(CouleurParNom("blue"));
	      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,YCOORD-indiceligne*DECALAGE_Y,52,32);
	    }

	    if(tabcolor[indiceligne][indicecolonne]=='n') {
	      ChoisirCouleurDessin(CouleurParNom("black"));
	      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,YCOORD-indiceligne*DECALAGE_Y,52,32);
	    }
	    if(tabcolor[indiceligne][indicecolonne]=='b') {
	      ChoisirCouleurDessin(CouleurParNom("white"));
	      RemplirRectangle(XCOORD+indicecolonne*DECALAGE_X,YCOORD-indiceligne*DECALAGE_Y,52,32);
	    }
	      
	    }
	  
	  ok=0;
	  	  
		  }
	  
	  if(pn==4) {
	    indiceligne=10;
	  }
	}
      }
      
      
    }
  
  
  
  
  
		      
		      
  
  

  
  

	    
	    

  if(ecranchoisi=='q') { /* designe utilisateur souhaite quitter*/
    valider=1;
    return;
    indiceligne=6;

  }
  }


}


    

