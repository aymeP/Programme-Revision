#include "Parametres.h"
#include <conio.h>



void viderBuffer(){
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}

char lireCaractere(){
    return getche();
}

void lire(char *chaine, int longueur){
    char *positionEntree = NULL;

    if (fgets(chaine, longueur, stdin) != NULL) {
        positionEntree = strchr(chaine, '\n'); // On recherchel'"Entr�e"
        if (positionEntree != NULL){// Si on a trouv� le retour �la ligne
            *positionEntree = '\0'; // On remplace ce caract�re par\0
        }else{
            viderBuffer();
        }
    }else{
        viderBuffer();
    }
}


double lireNb(){
char nombreTexte[100] = {0}; // 100 cases devraient suffire
lire(nombreTexte, 100);

char *positionVirg = NULL;

    positionVirg = strchr(nombreTexte, ','); // On recherchel'"Entr�e"
    if (positionVirg != NULL){// Si on a trouv� le retour �la ligne
        *positionVirg = '.'; // On remplace ce caract�re par\0
    }

    return strtod(nombreTexte, NULL);
}

int lireEntier(int borneInf,int borneSup){
    int valid;
    scanf("%d",&valid);
    viderBuffer();
    while ((valid < borneInf) || (valid > borneSup))
    {
        if (borneInf == borneSup)
        {
            printf("Veuillez saisir le nombre valide.\nLe nombre valide est : %d\n",borneInf);
            scanf("%d",&valid);
            viderBuffer();
        } else
        {
            printf("Veuillez saisir un nombre valide.\nLe nombre doit se situer entre %d et %d : ",borneInf,borneSup);
            scanf("%d",&valid);
            viderBuffer();
        }
    }
    return valid;
}

int entier(char car){
    switch(car){
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        default:
            return 9;
    }
}
    

int lireChiffre(int borneInf,int borneSup){
    int valid=entier(getche());
    while ((valid < borneInf) || (valid > borneSup))
    {
        if (borneInf == borneSup)
        {
            printf("Veuillez saisir le nombre valide.\nLe nombre valide est : %d\n",borneInf);
        } else
        {
            printf("Veuillez saisir un nombre valide.\nLe nombre doit se situer entre %d et %d : ",borneInf,borneSup);
        }
        valid=entier(getche());
    }
    return valid;
}
