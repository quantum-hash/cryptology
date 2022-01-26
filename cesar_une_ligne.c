// gcc -W -Wall -Wextra cesar.c -o output
// ./output 1 3 bonjour
// run 1 3 bonjour

#include <stdio.h>
#include <stdlib.h>


char chiffrer_cesar(char c, int dec);		//chiffrer_cesar : fonction qui chriffrera les caracteres demandé par l'utilisateur
char dechiffrer_cesar(char a, int dec);		//dechiffrer_cesar : fonction qui déchriffrera les caracteres codé auparavant
void buffer();

int main(int argc, char *argv[])
{
	/*char chaine_de_caractere[128];
	int decalage, coder_ou_decoder;
	char resultat; //, res;
	printf("%d", argc);
	if (argc < 3 )
	{

		printf ("Veuillez saisir 1 pour coder et 0 pour decoder : ");		//Demander a l'utilisateur s'il souhaite coder ou decoder des caractere
		scanf ("%d", &coder_ou_decoder);
		buffer();		//fonction qui vide le buffer
		//printf("%s", chaine_de_caractere);
		printf ("Veuillez saisir le decalage : ");		//Demander le décalage qu'il souhaite pour son chiffrement
		scanf ("%d", &decalage);
		buffer();

		printf ("Veuillez saisir une chaine de caractere : ");
		//fgets(chaine_de_caractere, 128, stdin);
		scanf ("%s[^\n]", &chaine_de_caractere);
	}
	else
	{*/


	int coder_ou_decoder = atoi (argv[1]); // 1eme argument de l'entrée : qui sera soit 0 pour decoder soit 1 pour coder
	int decalage = atoi (argv[2]);         // 2eme argument de l'entrée : qui sera superieur à 1
	char *chaine_de_caractere = argv[3];   // 3eme argument de l'entrée : qui sera la chaine de caractere
	char resultat; // resultat

	//printf("\n           ██████ ███████ ███████  █████  ██████  \n          ██      ██      ██      ██   ██ ██   ██ \n          ██      █████   ███████ ███████ ██████  \n          ██      ██           ██ ██   ██ ██   ██ \n           ██████ ███████ ███████ ██   ██ ██   ██  \n\n");



	if (coder_ou_decoder == 1)		//condition de l'utilisateur lorsque qu'il veut coder
	{
		char *p;
		printf("        voici la chaine de caractere chiffrée ----> ");
		for (p = chaine_de_caractere; *p != '\0'; p++)		//appliquer le décalage demandé par l'utilisateur
		{
			if (*p == '$')
			{
				break;
			}

			resultat = chiffrer_cesar(*p, decalage);

			printf("%c", resultat);		//afficher les caracteres apres le décalage


		}
		printf("\n");		//saut de ligne
	}

	else if (coder_ou_decoder == 0)		//condition de l'utilisateur lorsque qu'il veut décoder
	{
		char *p;
		printf("        voici la chaine de caractere dechiffrée ----> ");
		for (p = chaine_de_caractere; *p != '\0'; p++)
		{
			if (*p == '$')
			{
				break;
			}
			resultat = dechiffrer_cesar(*p, decalage);

			printf("%c", resultat);		//affichage des caractéres

		}
		printf("\n");

	}

	return EXIT_SUCCESS;
}



char chiffrer_cesar(char a, int dec)   //chiffrer_cesar : fonction qui chriffrera les caracteres demandé par l'utilisateur

{

	int c = a;
	if (c == 36)			// 36 ($) dans la table ASCII
	{
		c=c+dec;
	}
	else if (c>=65 && c<=90)				// majuscule: 65 (A) et 90 (Z) dans la table ASCII
	{
		c=c+dec;

		if (c>90)
		{

			c = c-90+65;

		}
	}
	else if (c>=97 && c<=122)				//minuscule: 97 (a) et 122(z) dans la table ASCII
	{

		c=c+dec;

		if (c>122)
		{
			c = c-122+97;

		}
	}
	return c;
}

char dechiffrer_cesar(char a, int dec)   //dechiffrer_cesar : fonction qui déchriffrera les caracteres codé auparavant
{

	int c = a;
	if (c == 36)			// 36 ($) dans la table ASCII
	{
		c=c-dec;
	}
	else if (c>=65 && c<=90)				// majuscule: 65 (A) et 90 (Z) dans la table ASCII
	{
		c=c-dec;
		if (c<65)
		{
			c = c+90-65;

		}
	}
	else if (c>=97 && c<=122)				//minuscule: 97 (a) et 122(z) dans la table ASCII
	{
		c=c-dec;
		if (c<97)
		{
			c = c+122-97;

		}
	}
	return c;
}

void buffer()		//buffer() : vider le buffer, réinitialiser le 'scanf', effacer les caractères saisies par l'utilisateur en mémoire
{
	scanf("[^\n]");
	getchar();

}
