#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int menu(void);
int nouveauCaractere(char a, char b);
void encrypter(void);

int main(){
	int choix = menu();
	switch(choix){
		case 1 :
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
}

void encrypter(){

	FILE *fsource = NULL;
	FILE *fpero = NULL;
	FILE *fout = NULL;

	char lettrePero = '\0';
	char lettreLu = '\0';

	fpero = fopen("peroq.def", "rt");
	fsource = fopen("source.txt", "rt");
	fout = fopen("dest.crt", "w+t");

	if (fsource == NULL)
	{
		printf("Impossible d'ouvrir le fichier source.txt");
		return EXIT_FAILURE;
	}

	if (fpero == NULL) 
	{
		printf("Impossible d'ouvrir le fichier peroq.def");
		return EXIT_FAILURE;
	}

	if (fout == NULL)
	{
		printf("Impossbible d'ouvrir ou de créer le fichier dest.crt");
		return EXIT_FAILURE;
	}

	do{
		//on lit les deux fichiers conjointement
		fread(&lettreLu, sizeof(char), sizeof(char), fsource);
		fread(&lettrePero, sizeof(char), sizeof(char), fpero);

		//si on arrive à la fin du fichier perroquet, on retourne au début
		if (feof(fpero)){
			fseek(fpero, 0, SEEK_SET);
			fread(&lettrePero, sizeof(char), sizeof(char), fpero);
		}

		//printf("\n(%d)val de pero : %c\n",lettrePero, lettrePero);
		char res = nouveauCaractere(lettreLu, lettrePero);
		//printf("\n(%d)%c chiffrée par (%d)%c donne : (%d)%c",lettreLu, lettreLu, lettrePero, lettrePero, res, res);
		fwrite(&res, sizeof(char), sizeof(char), fout);

	} while(!feof(fsource));

	int retClosefsource = fclose(fsource);
	int retClosefpero = fclose(fpero);
	int retClosefout = fclose(fout);
	
	return 0;
}

int nouveauCaractere(char a, char b){
	return a-b;
}

int menu(){
	int choix = 0;
	printf("\n_________________Bienvenue sur le programme de chiffrement_______________\nQue voulez-vous faire?\n\n");
	printf("\t1-Créer votre code perroquet\n\t2-Chiffrer votre fichier\n\t3-Déchiffrer votre fichier\n");
	scanf("%d", &choix);
	while(choix<1 || choix>3){
		printf("\nErreur, vous devez choisir une option entre 1 et 3\nVeuillez recommencer: ");
		scanf("%d", &choix);
	}
	return choix;
}


