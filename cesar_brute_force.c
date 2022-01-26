// gcc -W -Wall -Wextra brute_force.c -o output


#include <stdio.h>
#include <stdlib.h>

char brute_force_cesar(char a,  int dec);		//brute_force_cesar : déchiffre les caractères codés auparavant
void buffer();

int main()
{
	char chaine_de_caractere[128];
	int compteur;
	char resultat;

	printf("\t-------------------Brute-force-------------------\n");
	printf("\t-------------------------------------------------\n\n");
	printf ("- Veuillez saisir une chaine de caractere : ");
	//fgets(chaine_de_caractere, 128, stdin);
	scanf ("%s[^\n]", &chaine_de_caractere);
	buffer();
	//char *p;
	printf("\n");

	//printf("%s", chaine_de_caractere);
	for (compteur = 1 ; compteur < 26 ; compteur++)			//Tout les décalages possibles en rajoutant +1 à chaque fois jusqu'à ce que l'utilisateur souhaite arreter
	{
		char *p;
		printf ("- Veuillez appuyer sur Entrée si ce resultat ne vous parait pas coherent sinon appuyer sur Ctrl+C : ");
		for (p = chaine_de_caractere; *p != '\0'; p++)
		{
			if (*p == '$') // $ : arret de la chaine de caractere au $
			{
				break;
			}

			resultat = brute_force_cesar(*p, compteur);

			printf("%c", resultat);


		}

		printf("\n");
		char temp;
		scanf ("%c", &temp);
		//buffer();
	}

	//printf("\n");
	//printf("%c \n", res);
	return EXIT_SUCCESS;


}


char brute_force_cesar(char a, int dec)
{


	int c = a;
	if (c == 36)				// 36 ($) dans la table ASCII
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

void buffer()		//buffer() : vider le buffer, réinitialiser le 'scanf'
{
	scanf("[^\n]");
	getchar();

}
