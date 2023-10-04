#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // toupper()
int
main ()
{
  char caractere_joueur;
  int niveau, nombre_joueur, coupsRestants = 15, coupsRestants2 = 10;
  printf ("********bienvenue au jeu du mystere*********\n");
  printf ("********veuillez  choisi le niveau de mystere*********\n");
  do
    {
      printf("1: Niveau 1 : Facile -> Le mystC(re est un nombre entre 0 et 100\n");
      printf("2: Niveau 2 : Facile -> Le mystC(re est un nombre entre 0 et 10000\n");
      printf("3: Niveau 3 : Facile -> Le mystC(re est un nombre entre 10 et 100 et un caractere\n");
      printf("0: Quitter le Jeu\n\n");
      
      printf ("choisi le niveau de mystere\n");
      scanf ("%d", &niveau);
      switch (niveau)
	{
	case 1:
	  {
	    int nombreMystere1 = rand () % 101;

	    while (coupsRestants > 0)
	      {
		printf ("Il vous reste %d coups Entrez votre proposition : ",
			coupsRestants);
		scanf ("%d", &nombre_joueur);

		if (nombre_joueur == nombreMystere1)    {
		    printf ("Bravo, vous avez trouvC) le nombre mystere : %d\n", nombreMystere1);
		    break;
		  }
		else if (nombre_joueur < nombreMystere1) {
		    printf ("Le nombre mystere est superieur \n");
		  }
		else {
		    printf ("Le nombre mystere est inferieur \n");
		  }

		coupsRestants--;
	      }

	    if (coupsRestants == 0) {
		printf(" vous avez terminer tous vos coups Le nombre mystere etait  : %d\n", nombreMystere1);
	      }

	    break;
	  }
	case 2:
	  {

	    int nombreMystere2 = rand () % 10001;
	    while (coupsRestants2 > 0)
	      {
		printf ("Il vous reste %d coups Entrez votre proposition : ",
			coupsRestants2);
		scanf ("%d", &nombre_joueur);

		if (nombre_joueur == nombreMystere2)
		  {
		    printf
		      ("Bravo, vous avez trouvé le nombre mystere : %d\n",
		       nombreMystere2);
		    break;
		  }
		else if (nombre_joueur < nombreMystere2)
		  {
		    printf ("Le nombre mystere est superieur \n");
		  }
		else
		  {
		    printf ("Le nombre mystere est inferieur \n");
		  }

		coupsRestants2--;
	      }

	    if (coupsRestants2 == 0)
	      {
		printf
		  (" vous avez terminer tous vos coups Le nombre mystere etait  : %d\n",
		   nombreMystere2);
	      }

	    break;
	  }
	case 3:
	  {
	    char caractere_mystere = 'A' + rand () % 26;
	    int nombreMystere3 = 10 + rand () % 91;
	    while (coupsRestants2 > 0)
	      {
	          if (nombre_joueur != nombreMystere3) {
		        printf ("Il vous reste %d coups Entrez votre nombre  : ", coupsRestants2);
		        scanf ("%d", &nombre_joueur);
	          }
	          
	       if(nombre_joueur == nombreMystere3 ){
		    printf ("Le nombre est correct %d \n", nombre_joueur);
		  }
		else if (nombre_joueur < nombreMystere3)
		  {
		    printf ("Le nombre mystere est superieur \n");
		  }
		else
		  {
		    printf ("Le nombre mystere est inferieur \n");
		  }
		  
	          if(caractere_joueur != caractere_mystere) {
        		printf ("Il vous reste %d coups Entrez votre caractere  : ", coupsRestants2);
        		scanf (" %c", &caractere_joueur);
        		caractere_joueur = toupper(caractere_joueur); // le caractere saisi est toujours majuscule

	          }
		if (caractere_joueur == caractere_mystere) {

		    printf ("Le caractere est correct %c \n", caractere_joueur);
		  }
		else if (caractere_joueur < caractere_mystere)
		  {
		    printf ("Le caractere C  trouver est apres.\n");
		  }
		else
		  {
		    printf ("Le caractere C  trouver est avant.\n");

		  }


		if (nombre_joueur == nombreMystere3 && caractere_mystere == caractere_joueur)
		  {
		    printf ("Bravo, vous avez trouvé le nombre mystere : %d caractere_mystere : %c \n", nombreMystere3, caractere_mystere);
		    break;
		  }


		coupsRestants2--;
	      }

	    if (coupsRestants2 == 0) {
		printf (" vous avez terminer tous vos coups Le nombre mystere etait  : %d  caractere_mystere : %c \n", nombreMystere3, caractere_mystere);
	      }

	    break;
	  }
	}
    
        if (niveau == 0)
        break;
    }
  while (1);
  return 0;
}
