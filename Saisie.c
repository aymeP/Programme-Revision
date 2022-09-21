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
        positionEntree = strchr(chaine, '\n'); // On recherchel'"Entrée"
        if (positionEntree != NULL){// Si on a trouvé le retour àla ligne
            *positionEntree = '\0'; // On remplace ce caractère par\0
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

    positionVirg = strchr(nombreTexte, ','); // On recherchel'"Entrée"
    if (positionVirg != NULL){// Si on a trouvé le retour àla ligne
        *positionVirg = '.'; // On remplace ce caractère par\0
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
    if(car=='0'){
        return 0;
    }
    if(car=='1'){
        return 1;
    }
    if(car=='2'){
        return 2;
    }
    if(car=='3'){
        return 3;
    }
    if(car=='4'){
        return 4;
    }
    if(car=='5'){
        return 5;
    }
    if(car=='6'){
        return 6;
    }
    if(car=='7'){
        return 7;
    }
    if(car=='8'){
        return 8;
    }
    return 9;
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
