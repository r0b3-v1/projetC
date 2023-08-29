#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void ecrirePeroq(void){

    FILE *peroq = fopen("peroq.def", "w+t");
    char code[256];
    printf("Veuillez entrer le code qui servira à chiffrer vos fichiers (maximum 256 caractères):\n");
    scanf(" %99[^\n]", code);
    for (int i = 0; i < strlen(code); i++)
    {
        fwrite(&code[i],sizeof(char), sizeof(char), peroq);
    }

    fclose(peroq);

}