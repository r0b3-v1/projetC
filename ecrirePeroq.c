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

// fonction qui vérifie si le code entré par l'utilisateur correspond à celui dans le fichier peroq.def
int checkPeroq(){
    FILE *pero = fopen("peroq.def", "r");
    char code[100];
    char str[100];
    printf("Veuillez entrer votre code\n");
    scanf("%s",str);
    fgets(code, 100, pero);
    
    fclose(pero);
    if(strcmp(str, code)){
        printf("Votre code ne correspond pas, veuillez recommencer\n");
        return 1;
    }

    return 0;
}