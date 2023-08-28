#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void lirePerroquet(char *mdp);
void menu(void);

int main(){
	menu();
	char mdp[100];
	lirePerroquet(&mdp);
	printf("le mdp est : %s", mdp);
	
	//FILE *fp = NULL;
	//char lettreLu = '\0';
	
	return 0;
}

void menu(){
	int choix = 0;
	printf("\n_________________Bienvenue sur le programme de chiffrement_______________\nQue voulez-vous faire?\n\n");
	printf("\t1-Créer votre code perroquet\n\t2-Chiffrer votre fichier\n\t3-Déchiffrer votre fichier\n");
	scanf("%d", &choix);
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

