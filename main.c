#include <time.h>
#include <conio.h>
#include "Parametres.h"
#include "Struct.h"
#include "Lire_fichier.h"
#include "menus.h"

//Main
int main(){
    Le_Mot Liste_Mots[nb_mots_max];
    int nb_mots=lire_fichier(Liste_Mots);

    if(nb_mots>-1){
        srand(time(NULL));
        menuPrin(nb_mots,Liste_Mots);
    }else{
        printf("Erreur : Trop de mots !");
    }

    return 0;
}

