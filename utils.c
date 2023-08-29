#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int testFichier(char *path){

    FILE *fichier = fopen(path, "r");
    // si le fichier n'existe pas, on renvoie -1
    if (fichier == NULL){
        printf("Le fichier %s n'existe pas, impossible de continuer\n", path);
        exit(1);
    }
    // on se déplace à la fin du fichier
    fseek(fichier, 0, SEEK_END);
    // si la position courante de la tête de lecture est à 0, alors le fichier est vide et on renvoie 1
    if(ftell(fichier) == 0){
        fclose(fichier);
        printf("Warning, Le fichier %s est vide\n", path);
        return 1;
    }

    fclose(fichier);
    return 0;
}
