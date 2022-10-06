#include <stdio.h>

#include <stdlib.h> // rand()

#include <time.h>

#include <ctype.h> // toupper()
/*
int toupper( int character );
Cette fonction permet de convertir une lettre minuscule à une lettre majuscule.
Rappel : les fonctions de cette librairie ne traitent que les caractères purs ASCII.
Les lettres accentuées ne seront donc pas considérées comme des caractères alpha-numériques.
*/
/*

Fonction rand

    int rand();

Cette fonction renvoie une valeur aléatoirement.
Pour fonctionner correctement, le générateur de nombres aléatoires a besoin d'être initalisé via la fonction srand.

La valeur calculée est comprise entre 0 et RAND_MAX.
Cette dernière valeur est elle aussi définie dans l'entête <stdlib.h>.

l'aléatoire est un concept qu'on a du mal à traiter en informatique, étant données que nos machines sont des systèmes déterministes.
Actuellement, l'aléa est simulé via des algorithmes mathématiques qui renvoient des suites de valeurs.
Si ces algorithmes sont utilisés plusieurs fois à la suite, ils ont le défaut de toujours renvoyer la même suite de valeurs.
Pour contourner ce problème,
on initialise souvent ces algorithmes avec une valeur imprédictible : pourquoi pas le temps système de la machine.

source : https://koor.fr/C/cstdlib/rand.wp

*/
int main() {

  int niveau; // pour lire le niveau choisi
  int nombre_mystere;
  char caractere_mystere;
  int nombre_saisi;
  char caractere_saisi;
  int nb_coup_maximal;
  int intervalle_max, intervalle_min = 0;
  int nb_tentatives = 0;
  int nombre_correct = 0;
  int caractere_correct = 0;

  // On commence par initialiser le générateur de nombre pseudo-aléatoires.
  srand(time(NULL));

  printf("------------------------     Bienvenue au jeu du mystere     ------------------------\n");
  printf("------------------------     Veuillez choisir le niveau:     ------------------------\n");
  printf("------------------------     1: Niveau Facile                ------------------------\n");
  printf("------------------------     2: Niveau Moyen                 ------------------------\n");
  printf("------------------------     3: Niveau Difficile             ------------------------\n");
  printf("------------------------     0: Quitter                      ------------------------\n");

  int n =20;
  for(int i=0, j=0;(i<n) && (j<n); i++,j+=5){

    printf("(%d, %d )\n",i,j);

  }
  scanf("%d", & niveau);

  if (niveau > 0) {
    if (niveau == 1) {

    } else if (niveau == 2) {
      // Tirer une valeur aléatoire entre 0 et 10000.
      nombre_mystere = rand() % 10001; // % => Reste de la division entière
      intervalle_max = 10000;
      nb_coup_maximal = 10;
    } else {
      // Tirer une valeur aléatoire entre 10 et 100.
      nombre_mystere = 10 + rand() % 91; // % => Reste de la division entière
      // Tirer un caractere aléatoire entre A et Z.
      caractere_mystere = 'A' + rand() % 26;
      printf("caractere_mystere %c \n", caractere_mystere);
      nb_coup_maximal = 10;
      intervalle_min = 10;
      intervalle_max = 100;
    }

    printf("nombre_mystere %d \n", nombre_mystere);


    while (1) {

      if (!nombre_correct) {
        printf("\n\nDonnez le nombre mystere (entre %d et %d) : ", intervalle_min, intervalle_max);
        scanf("%d", & nombre_saisi);
      }

      nb_tentatives++;

      if (nombre_saisi == nombre_mystere) {

        nombre_correct = 1;

      } else if (nombre_saisi < nombre_mystere) {
        printf("La valeur à trouver est plus grande.\n");
      } else {
        printf("La valeur à trouver est plus petite.\n");
      }

      if (nombre_correct && niveau != 3) {
        printf("\n\nBravo! Vous avez gagne au bout de %d tentatives !\n", nb_tentatives);
        break; // pour sortir du boucle while
      } else if(nombre_correct) {
        printf("Le nombre est correct *%d \n", nombre_saisi);
      }

      if (niveau == 3) {

        if (!caractere_correct) {
          printf("Donnez le caractere mystere (entre A et Z ) : ");
          scanf(" %c", & caractere_saisi); // il faut ajouter espace avant %c dans scanf
          // https://stackoverflow.com/questions/13542055/how-to-do-scanf-for-single-char-in-c

          caractere_saisi = toupper(caractere_saisi); // pour assurer que le caractere saisi est majuscule
        }

        if (caractere_saisi == caractere_mystere) {
          caractere_correct = 1;
           printf("Le caractere est correct *%c \n", caractere_saisi);
        } else if (caractere_saisi < caractere_mystere) {
          printf("Le caractere à trouver est apres.\n");
        } else {
          printf("Le caractere à trouver est avant.\n");
        }

      }

      if (nombre_correct && caractere_correct) {
        printf("Bravo! Vous avez gagne au bout de %d tentatives !\n", nb_tentatives);
        break; // pour sortir du boucle while
      }
      if (nb_coup_maximal - nb_tentatives > 0) {
        printf("Il vous reste %d tentatives\n", nb_coup_maximal - nb_tentatives);
      } else {
        printf("Vous n'avez plus de tentatives\n");
        break; // pour sortir du boucle while
      }

    }

  }
  return 0;
}
