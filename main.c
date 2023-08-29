#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
	int choix = menu();
	switch(choix){
		case 1 :
			encrypter();
			printf("Chiffrement réussi! Le résultat a été mis dans le fichier dest.crt\n");
		break;
		case 2 :
			decrypter();
			printf("Déchiffrement réussi! Le résultat a été mis dans le fichier source.txt\n");
		break;
		case 3 :
			ecrirePeroq();
			printf("Le fichier peroq.def a été mis à jour!\n");
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
	printf("\n_________________Bienvenue sur le programme de chiffrement_______________\n\nQue voulez-vous faire?\n\n");
	printf("\t1-Chiffrer votre fichier\n\t2-Déchiffrer votre fichier\n\t3-écrire votre fichier perroquet\n\nVotre choix: ");
	scanf("%d", &choix);
	printf("\n");
	while(choix<1 || choix>3){
		printf("\nErreur, vous devez choisir une option entre 1 et 3\nVeuillez recommencer: ");
		scanf("%d", &choix);
	}
	return choix;
}


