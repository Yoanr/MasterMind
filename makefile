main : fenetre.o  f_tableau_pn.o   f_display_combinaison.o f_choixecran.o f_verif.o main.o f_alea_att.o  f_quitter.o f_combi_def.o f_combi_def.o f_display_menu.o f_conv_int_char.o f_zero.o f_ia.o
	gcc -ansi -o exe fenetre.o f_tableau_pn.o  f_display_combinaison.o  f_verif.o f_alea_att.o f_conv_int_char.o f_choixecran.o main.o  f_quitter.o f_combi_def.o f_zero.o  f_display_menu.o f_ia.o  -lgraph


fenetre.o: fenetre.c main.h
 f_choixecran.o: f_choixecran.c main.h
 main.o: main.c main.h
 f_quitter.o:  f_quitter.c main.h
f_display_menu.o: f_display_menu.c main.h
f_zero.o: f_zero.c main.h
f_conv_int_char.o: f_conv_int_char.c main.h
f_alea_att.o: f_alea_att.c main.h
f_verif.o: f_verif.c main.h
f_display_combinaison.o:f_display_combinaison.c main.h
f_combi_def.o: f_combi_def.c main.h
f_ia.o:f_ia.c main.h
f_tableau_pn.o:f_tableau_pn.c main.h
