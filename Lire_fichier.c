#include "Parametres.h"
#include "Struct.h"
#include "Comparer.h"
#include "Parametres.h"




void decouper(Le_Mot *Liste_Mots,char chaine[],int num_mot){
    int i=0,etape=0;
    while(chaine[i-1]!='*'){
        int y=0;
        char tempo[long_mot]={""};

        while(chaine[i]!='-' && chaine[i]!='*'){
            tempo[y]=chaine[i];
            i++;
            y++;
        }
        switch(etape){
            case 0 :strcpy(Liste_Mots[num_mot].Fr,tempo);
                    break;
            case 1 :strcpy(Liste_Mots[num_mot].Autre,tempo);
                    break;
            default:strcpy(Liste_Mots[num_mot].Pluriel,tempo);
                    etape=0;
                    break;
        }
        etape++;
        i++;
    }
}

int lire_fichier(Le_Mot *Liste_Mots){
    int num_mot=0;
    char chaine[3*long_mot+2]="";
    FILE *fichier=NULL;
    fichier=fopen(adresseFichier,"r");

    if (fichier != NULL){
        while(fgets(chaine,3*long_mot+3,fichier)!=NULL)
        {
            if(num_mot<nb_mots_max){
                decouper(Liste_Mots, chaine,num_mot);
                num_mot++;
            }else{
                return -1;
            }
        }
    }
    fclose(fichier);
    return num_mot;
}
