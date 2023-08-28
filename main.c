#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
	int choix = menu();
	switch(choix){
		case 1 :
			decrypter();
			printf("Déchiffrement réussi!\n");
		break;
		case 2 :
			encrypter();
			printf("Chiffrement réussi!\n");
		break;
		case 3 : 
		break;
		default:
			printf("Erreur dans le choix utilisateur");
			return EXIT_FAILURE;
		break;
	}
	return 0;
}

int menu(){
	int choix = 0;
	printf("\n_________________Bienvenue sur le programme de chiffrement_______________\nQue voulez-vous faire?\n\n");
	printf("\t1-Créer votre code perroquet\n\t2-Chiffrer votre fichier\n\t3-Déchiffrer votre fichier\nVotre choix: ");
	scanf("%d", &choix);
	printf("\n");
	while(choix<1 || choix>3){
		printf("\nErreur, vous devez choisir une option entre 1 et 3\nVeuillez recommencer: ");
		scanf("%d", &choix);
	}
	return choix;
}


