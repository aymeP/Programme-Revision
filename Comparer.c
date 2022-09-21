#include "Parametres.h"

int comparer(char *txt1, char *txt2){
    if (!strcmp(txt1,txt2)){
        //Identiques
        return 1;
    }else{
        //Differents
        return 0;
    }
}
