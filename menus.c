#include <time.h>
#include <conio.h>
#include "Parametres.h"
#include "Struct.h"
#include "Saisie.h"
#include "Comparer.h"
#include "Lire_fichier.h"


//Quitter une page
void quitter_page(){
    printf("\n\nPresser un touche pr quitter ");
    getch();
}


//Menu Exo
int nbAlea(int L_num_q[],int nb_mots,int *TailleL){
    int contient=0;
    int nbgen;
    do{
        //generer nb
        nbgen=rand()%nb_mots;
        //check si dans liste
        int i=0;
        contient=0;
        while((i<*TailleL)&&(!contient)){
            if(L_num_q[i]==nbgen){
                contient=1;
            }
            i++;
        }
    }while(contient);
    L_num_q[*TailleL]=nbgen;
    *TailleL+=1;
    return 1;
}

int controle_reponse(char rep[]){
    char reponse[long_mot];
    //controler reponse
    int essai=0;
    while(essai<3){
        lire(reponse,long_mot);
        if(comparer(reponse,rep)){
            printf("Juste!\n\n");
            return 1;
        }else{
            if(essai!=2){
                printf("Faux ! Reessayer : ");
            }else{
                printf("Faux ! C'etait : %s\n\n\n",rep);
            }
        }
        essai++;
    }
    return 0;
}

int question(Le_Mot Liste_Mots[],int numQ, int L_num_q[], int nb_mots,int *TailleL){
    //Generation d'un entier correcte
    nbAlea(L_num_q,nb_mots,TailleL);
    int point=0;
    char que[long_mot],rep[long_mot];

    //Poser la question
    strcpy(que,Liste_Mots[L_num_q[numQ]].Fr);
    if(strlen(Liste_Mots[L_num_q[numQ]].Pluriel)!=0){
        if(rand()%2){
            strcpy(rep,Liste_Mots[L_num_q[numQ]].Pluriel);
            printf("Question %i\nTraduire en allemand le mot \"%s (au pluriel)\"\n",numQ+1,que);
        }else{
            strcpy(rep,Liste_Mots[L_num_q[numQ]].Autre);
            printf("Question %i - Traduire en allemand le mot \"%s\"\n",numQ+1,que);
        }
    }else{
        strcpy(rep,Liste_Mots[L_num_q[numQ]].Autre);
        printf("Question %i - Traduire en allemand le mot \"%s\"\n",numQ+1,que);
    }

    point = controle_reponse(rep);

    return point;
}

void exo(int nb_mots, Le_Mot Liste_Mots[]){
    int nbQuestions,score=0,L_num_q[nb_mots],TailleL=0;
    system("cls");


    printf("--Exo--\nCombien de questions voulez-vous (max %i) ? ",nb_mots);
    nbQuestions=lireEntier(0,nb_mots);

    system("cls");
    for(int i=0;i<nbQuestions;i++){
        score=score + question(Liste_Mots,i,L_num_q,nb_mots,&TailleL);
    }
    printf("Score : %i/%i\n",score,nbQuestions);

    quitter_page();
}


//Menu Acces Liste
void sauvegarder_liste(Le_Mot Liste_Mots[], int nb_mots){
    FILE* fichier = NULL;
    fichier = fopen(adresseFichier,"w+");
    if (fichier != NULL)
    {
        for (int i=0;i<nb_mots;i++)
        {
            fprintf(fichier,"%s-%s-%s*\n",Liste_Mots[i].Fr,Liste_Mots[i].Autre,Liste_Mots[i].Pluriel);
        }
        fclose(fichier);
    }
}

int ajouter_mot(Le_Mot Liste_Mots[],int nb_mots,char langue[]){
    char mot[long_mot]="";
    printf("Saisir le mot %s : ",langue);
    lire(mot,long_mot);
    if(comparer(mot,"echap")){
        printf("Annuler\n");
    }else{
        if(comparer(langue,"en francais")){
            strcpy(Liste_Mots[nb_mots].Fr,mot);
        }else if(comparer(langue,"en allemand")){
            strcpy(Liste_Mots[nb_mots].Autre,mot);
        }else if(comparer(langue,"au pluriel")){
            strcpy(Liste_Mots[nb_mots].Pluriel,mot);
        }
        return 1;
    }
    return 0;
}

int ajouter(Le_Mot Liste_Mots[], int nb_mots){
    system("cls");
    if(nb_mots<nb_mots_max){
        printf("--Ajouter un mot--\nSaisir \"echap\"pour annuler\n");
        if(ajouter_mot(Liste_Mots,nb_mots,"en francais")){
            if(ajouter_mot(Liste_Mots,nb_mots,"en allemand")){
                if(ajouter_mot(Liste_Mots,nb_mots,"au pluriel")){
                    printf("Ajoute!");
                    nb_mots++;
                    sauvegarder_liste(Liste_Mots,nb_mots);
                }
            }
        }
    }else{
        printf("Vous ne pouvez pas ajouter de mot!");
    }
    quitter_page();
    return nb_mots;
}

void afficher_mot(char mot[]){
    int nbManquant=0;
    nbManquant=(long_mot+3-strlen(mot))/8;
    if((long_mot+3-strlen(mot))%8){
        nbManquant++;
    }
    printf("%s",mot);
    for(int i=0;i<nbManquant;i++){
        printf("\t");
    }
}

void afficher_liste(Le_Mot Liste_Mots[], int nb_mots){
    system("cls");
    printf("--Afficher la liste (%i mots)--\n\nFrancais\t\t\t\t\tAllemand\t\t\t\t\tPluriel\n\n", nb_mots);
    for (int i=0;i<nb_mots;i++){
        afficher_mot(Liste_Mots[i].Fr);
        afficher_mot(Liste_Mots[i].Autre);
        afficher_mot(Liste_Mots[i].Pluriel);
        printf("\n");
        //printf("%s\t%s\t%s\n",Liste_Mots[i].Fr,Liste_Mots[i].Autre,Liste_Mots[i].Pluriel);
    }

    quitter_page();
}

void modifier_mot(Le_Mot Liste_Mots[], int i){
    printf("Modifier le mot : %s - %s - %s ? (y/n) ",Liste_Mots[i].Fr,Liste_Mots[i].Autre,Liste_Mots[i].Pluriel);
    if (lireCaractere()=='y'){
        printf("\nQuelle partie ?\n1.Fr\n2.All\n3.Plur\nChoix : ");
        int choix = lireChiffre(1,3);
        printf("\nSaisir le nouveau mot : ");
        char nvMot[long_mot];
        lire(nvMot,long_mot);
        switch(choix){
            case 1: strcpy(Liste_Mots[i].Fr,nvMot);
                    break;
            case 2: strcpy(Liste_Mots[i].Autre,nvMot);
                    break;
            default:strcpy(Liste_Mots[i].Pluriel,nvMot);
                    break;
        }
        printf("Le nouveau mot est donc : %s - %s - %s",Liste_Mots[i].Fr,Liste_Mots[i].Autre,Liste_Mots[i].Pluriel);
    }
}

void modifier(Le_Mot Liste_Mots[], int nb_mots){
    system("cls");
    printf("--Modifier--\nSaisir un mot a modifier : ");
    char mot[long_mot];
    lire(mot,long_mot);
    int i=0;
    while(!comparer(mot,Liste_Mots[i].Fr) && !comparer(mot,Liste_Mots[i].Autre) && !comparer(mot,Liste_Mots[i].Pluriel) && i<nb_mots){
        i++;
    }
    if(i==nb_mots){
        printf("Le mot n'est pas dans la liste\n");
    }else{
        modifier_mot(Liste_Mots,i);
        sauvegarder_liste(Liste_Mots,nb_mots);
    }

    quitter_page();
}

int acces_liste(Le_Mot Liste_Mots[], int nb_mots){
    int nbMenu=0;
    while(nbMenu>-1){
        switch(nbMenu){
            case 0: system("cls");
                    printf("--Acces a la liste--\n1.Consulter\n2.Ajouter\n3.Modifier\n4.Quitter\nChoisir une action : ");
                    nbMenu=lireChiffre(1,4);
                    break;
            case 1: afficher_liste(Liste_Mots,nb_mots);
                    nbMenu=0;
                    break;
            case 2: nb_mots=ajouter(Liste_Mots,nb_mots);
                    nbMenu=0;
                    break;
            case 3: modifier(Liste_Mots,nb_mots);
                    nbMenu=0;
                    break;
            case 4: nbMenu=-1;
                    break;
        }
    }
    return nb_mots;
}



//Menu Principal
void menuPrin(int nb_mots, Le_Mot Liste_Mots[]){
    int nbMenu=0;
    while(nbMenu>-1){
        switch(nbMenu){
            case 0: system("cls");
                    printf("--Menu principal--\n1. Lancer un exo\n2. Acceder a la liste de mots\n3. Quitter\nChoisir une action : ");
                    nbMenu=lireChiffre(1,3);
                    break;
            case 1: exo(nb_mots, Liste_Mots);
                    nbMenu=0;
                    break;
            case 2: nb_mots=acces_liste(Liste_Mots, nb_mots);
                    nbMenu=0;
                    break;
            case 3: nbMenu=-1;
                    break;
        }
     }
}
