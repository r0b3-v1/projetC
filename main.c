#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void lirePerroquet(char *mdp);
int menu(void);
int chiffrer(char a, char b);

int main(){
	int choix = menu();

	int head = 0;

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
		if (lettrePero == 10){
			fseek(fpero, 0, SEEK_SET);
			fread(&lettrePero, sizeof(char), sizeof(char), fpero);
		}

		//printf("\n(%d)val de pero : %c\n",lettrePero, lettrePero);
		char res = chiffrer(lettreLu, lettrePero);
		printf("\n(%d)%c chiffrée par (%d)%c donne : (%d)%c",lettreLu, lettreLu, lettrePero, lettrePero, res, res);
		fwrite(&res, sizeof(char), sizeof(char), fout);

	} while(!feof(fsource));

	int retClosefsource = fclose(fsource);
	int retClosefpero = fclose(fpero);
	int retClosefout = fclose(fout);
	
	return 0;
}

int chiffrer(char a, char b){
	int res = a-b;
	if(res<0) res = 127+res;
	return res;
}

int menu(){
	int choix = 0;
	printf("\n_________________Bienvenue sur le programme de chiffrement_______________\nQue voulez-vous faire?\n\n");
	printf("\t1-Créer votre code perroquet\n\t2-Chiffrer votre fichier\n\t3-Déchiffrer votre fichier\n");
	scanf("%d", &choix);

	return choix;
}

//lit le fichier peroq.def et affecte son contenu dans la variable passée en argument
void lirePerroquet(char *mdp){
	FILE *fp = NULL;
	int i = 0;
	char lettreLu = '\0';
	fp = fopen("peroq.def", "rt");

	if (fp == NULL){
		printf("Erreur, le fichier perroquet n'existe pas");
		return EXIT_FAILURE;
	}
	
	do {
		fread(&lettreLu, sizeof(lettreLu), sizeof(char), fp);
		mdp[i] = lettreLu;
		i++;
	} while(!feof(fp));
	
	int retClose = fclose(fp);
	if(retClose != 0) {
		printf("Erreur close");
		return EXIT_FAILURE;
	}
	//printf("%s", mdp);
}

