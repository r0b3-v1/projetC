#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void decrypter(){

	FILE *fsource = NULL;
	FILE *fpero = NULL;
	FILE *fout = NULL;

	char lettrePero = '\0';
	char lettreLu = '\0';

	testFichier("peroq.def");
	testFichier("dest.crt");

	fpero = fopen("peroq.def", "rt");
	fsource = fopen("dest.crt", "rt");
	
	fout = fopen("source.txt", "w+t");
	if (fout == NULL)
	{
		printf("Impossbible d'ouvrir ou de créer le fichier source.txt\n");
		exit(1);
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
		if(!feof(fsource)){ 
			char res = lettreLu + lettrePero;
			fwrite(&res, sizeof(char), sizeof(char), fout);
		}

	} while(!feof(fsource));

	int retClosefsource = fclose(fsource);
	int retClosefpero = fclose(fpero);
	int retClosefout = fclose(fout);
}


