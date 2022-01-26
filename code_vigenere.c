

#include <stdio.h>
#include <string.h>



void chiffrer_vigenere(char *text, char *cle, char *ciphertext)
{

	unsigned int i , size=strlen(cle);

	for (i = 0 ; text[i] != '\0' ; i++)
	{

		if ((text[i]>= 'a') && (text [i] <= 'z'))				//condition permettant de savoir si le caractere est compris entre a et z minuscule
		{
			int rang =(text [i]+ cle[i% size]-2*'a')%26;
			ciphertext[i]='a'+rang;
		}

		else if ((text[i]>= 'A') && (text [i] <= 'Z'))				//condition permettant de savoir si le caractere est compris entre A et Z majuscule
		{
			int rang =(text [i]+ cle[i% size]-2*'A')%26;
			ciphertext[i]='A'+rang;
		}

		else
		{
			ciphertext[i]=text[i];
		}


	}

	ciphertext[i]='\0';

}



int main()
{
	int i;
	char Message[30];
	char  Messagecr[30];

	printf("Entrer votre message: ");
	scanf("%s",Message);

	  for (i = 0; Message[i]!='\0'; i++)		// si les caractères sont en minuscules, les convertir en majuscules
	  {

	   	if(Message[i] >= 'a' && Message[i] <= 'z')
	  	{

	         	Message[i] = Message[i] -32;

	        }

	   }

		char cle[30] ;
		printf("Entrer votre clef: "); 							// message afficher pour utilisateur
		scanf("%s",cle);

				for (i = 0; cle[i]!='\0'; i++) 			// si les caractères sont en minuscules, convertissez-les en majuscules
				{

					if(cle[i] >= 'a' && cle[i] <= 'z')
					 {

					      cle[i] = cle[i] -32;

					 }


				}

					chiffrer_vigenere(Message,cle, Messagecr);				// apelle de la fonction et en choisiser le nombre de decalage
					printf("Le message origine = %s\n",Message);
					printf("Le message cripté est  = %s\n",Messagecr);


	return 0;

}
