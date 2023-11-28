#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

int main()
{
    T_Arbre abr=NULL;
     FILE *file;

    char filename[100], ch;
    char nomFichier[100];
    char *nom=malloc(sizeof(100*sizeof(char)));
    char *prenom=malloc(sizeof(100*sizeof(char)));
    char *code=malloc(sizeof(4*sizeof(char)));
    char choix = '0';
    while (choix != '6') {
        printf("\n======================================");
        printf("\n1. Inscrire un etudiant a une UV");
        printf("\n2. Charger un fichier d'inscriptions");
        printf("\n3. Afficher tous les etudiants");
        printf("\n4. Afficher les inscrits a une UV");
        printf("\n5. Supprimer une inscription");
        printf("\n6. Quitter");
        printf("\n======================================");
        printf("\n   Votre choix ? ");

        choix = getchar();
        printf("\n");
        switch (choix) {
            case '1' :

                printf("\nVeuillez saisir en majuscule le NOM:\n");
                scanf("%s",nom);
                strupr_(nom);
                viderBuffer();

                printf("\nVeuillez saisir en majuscule le PRENOM:\n");
                scanf("%s",prenom);
                strupr_(prenom);
                viderBuffer();

                printf("\nVeuillez saisir en majuscule le CODE de l'UV:\n");
                scanf("%s",code);
                strupr_(code);
                abr = inscrire(abr, nom, prenom,code);

                break;


            case '2' :
                printf("Entrez le nom du fichier : ");
                scanf("%s", nomFichier);
                viderBuffer();
                abr = lireFichier(abr, nomFichier);
                break;

            case '3' :
                afficherInscriptions(abr);
                break;

            case '4' :
                printf("\nVeuillez saisir en majuscule le CODE de l'UV:\n");
                scanf("%s",code);
                strupr_(code);
                afficherInscriptionsUV(abr, code);

                break;
            case '5' :

                printf("\nVeuillez saisir en majuscule le NOM:\n");
                scanf("%s",nom);
                strupr_(nom);
                //printf("%s",nom1);
                viderBuffer();

                printf("\nVeuillez saisir en majuscule le PRENOM:\n");
                scanf("%s",prenom);
                strupr_(prenom);
                viderBuffer();

                printf("\nVeuillez saisir en majuscule le CODE de l'UV:\n");
                scanf("%s",code);
                strupr_(code);
                abr = supprimerInscription(abr, nom, prenom, code);


                break;

            case '6' :
                SupprimerTout(abr);

                break;
            default :
                {
                printf("\n\nERREUR : votre choix n'est valide ! ");
                }
        }
        printf("\n\n\n");
        //viderBuffer();
    }
    return 0;
}

