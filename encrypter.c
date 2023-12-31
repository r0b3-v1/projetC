#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int encrypter()
{

	FILE *fsource = NULL;
	FILE *fpero = NULL;
	FILE *fout = NULL;

	char lettrePero = '\0';
	char lettreLu = '\0';

	testFichier("peroq.def");
	testFichier("source.txt");
	if(checkPeroq()) return 1;

	fpero = fopen("peroq.def", "rt");
	fsource = fopen("source.txt", "rt");

	fout = fopen("dest.crt", "w+t");

	if (fout == NULL)
	{
		printf("Impossbible d'ouvrir ou de créer le fichier dest.crt\n");
		exit(1);
	}

	fread(&lettreLu, sizeof(char), sizeof(char), fsource);
	fread(&lettrePero, sizeof(char), sizeof(char), fpero);
	
	do
	{
		// si on arrive à la fin du fichier perroquet, on retourne au début
		if (feof(fpero))
		{
			fseek(fpero, 0, SEEK_SET);
			fread(&lettrePero, sizeof(char), sizeof(char), fpero);
		}

		char res = lettreLu - lettrePero;
		fwrite(&res, sizeof(char), sizeof(char), fout);

		// on lit les deux fichiers conjointement
		fread(&lettreLu, sizeof(char), sizeof(char), fsource);
		fread(&lettrePero, sizeof(char), sizeof(char), fpero);

	} while (!feof(fsource));

	int retClosefsource = fclose(fsource);
	int retClosefpero = fclose(fpero);
	int retClosefout = fclose(fout);
	// suppression du fichier source après le chiffrement
	remove("./source.txt");
	return 0;
}
