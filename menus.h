#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "Parametres.h"
#include "Struct.h"
#include "Saisie.h"

//Quitter une page
void quitter_page();

//Menu Exo
int nbAlea(int L_num_q[],int nb_mots,int *TailleL);

int controle_reponse(char rep[]);

int question(Le_Mot Liste_Mots[],int numQ, int L_num_q[], int nb_mots,int *TailleL);

void exo(int nb_mots, Le_Mot Liste_Mots[]);


//Menu Acces Liste
void sauvegarder_liste(Le_Mot Liste_Mots[], int nb_mots);

int ajouter_mot(Le_Mot Liste_Mots[],int nb_mots,char langue[]);

int ajouter(Le_Mot Liste_Mots[], int nb_mots);

void afficher_mot(char mot[]);

void afficher_liste(Le_Mot Liste_Mots[], int nb_mots);

void modifier_mot(Le_Mot Liste_Mots[], int i);

void modifier(Le_Mot Liste_Mots[], int nb_mots);

int acces_liste(Le_Mot Liste_Mots[], int nb_mots);



//Menu Principal
void menuPrin(int nb_mots, Le_Mot Liste_Mots[]);

#endif // MENUS_H_INCLUDED
