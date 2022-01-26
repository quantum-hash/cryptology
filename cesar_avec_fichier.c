//gcc -W -Wall -Wextra cesar_avec_fichier.c -o output

#include<stdio.h>
#include<stdlib.h>

char *cypher (char *mot, int, int);
char chiffrement (char , int, int );
void buffer ();
int main ()
{
        char *mot= malloc (256*sizeof (char));
        int choix, clef;
        printf("------------Chiffrement de César avec le fichier--------------\n");
        printf("--------------------------------------------------------------\n");


        char fichier1[ 80 ];
        FILE *inputFile;
        FILE *outputFile;

        printf( "Entrez l'adresse du fichier à (dé)coder: " );
        // Demander à l'utilisateur le fichier à (dé)coder
        scanf( "%s", fichier1 );

        inputFile = fopen( fichier1, "r" ) ; // ouverture du fichier
        //Vérifier que le fichier existe vraiment
        if( ( inputFile = fopen( fichier1, "r" ) ) == NULL )
        {
        	fprintf( stderr, "Erreur, impossible d'ouvrir le fichier %s\n", fichier1 );
        	exit( -1 );
        }

      	//choisir entre coder ou décoder

        printf("\nVoulez vous coder (1) ou décoder (0) : ");
        scanf("%d", &choix);

        printf("\n");

        //Choisir la clé du code
        printf("Veuillez saisir la longueur du décalage : ");
        scanf("%d",&clef);
        printf("\n");

        buffer();

        //Récuperer le texte contenue dans le fichier
        fgets(mot,256,inputFile);

        //Appel de fonction pour coder
        mot = cypher (mot, clef, choix);

        fclose (inputFile);

        //Création du fichier ou l'on va stocker le code
        outputFile = fopen ( "temp.cpt","w");

        //Edition du code dans le fichier créer
        fprintf(outputFile,"%s", mot);
        fclose (outputFile);


        printf ("Le fichier codé a bien été crée à l'adresse suivante : /temp.cpt\n" );



        return EXIT_SUCCESS;
}

char chiffrement (char c, int k, int choix)
{
        // Codage
        if ( choix !=0)
        {
                if (c >=65 && c <=90)   /* 65 (A) et 90 (Z) dans la table ASCII */
                {
                        c= c+k;
                        if ( c> 90 ) //
                        {
                                c= c-26;
                        }
                }
                else
                {
                        if (c >= 97 && c <=122)
                        {
                                c= c-32+k;      //97(a)-32= 65(A) ; ( Retour vers les majuscules)
                                if ( c> 90 )
                                {
                                        c= c-26;
                                }
                        }
                 }
         }
         // Décodage
         else
         {

                 if (c >=65 && c <=90)   // 65 (A) et 90 (Z) dans la table ASCII
                {
                        c= c-k;
                        if ( c< 65 )
                        {
                                c= c+26; // retour vers Z si c est inférieur à A dans la table Ascii,
                        }
                }
                else
                {
                        if (c >= 97 && c <=122)
                        {
                                c= c-32-k;      //97(a)-32= 65(A) (Retour vers les majuscules)
                                if ( c< 65 )
                                {
                                        c= c+26;
                                }
                        }
                }
        }

         return c;

}



char *cypher (char *mot, int k, int choix)
{
        int i=0;

        do
        {
                mot [i] = chiffrement ( mot[i], k, choix );
                i=i+1;
        }
        while (mot[i]!='\0');
        return mot;

}

void buffer()		//buffer() : vider le buffer, réinitialiser le 'scanf'
{
	scanf("[^\n]");
	getchar();

}
