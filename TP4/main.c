#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

int main()
{
    T_Arbre abr=NULL;

    char *nomFichier;
    char *nom=malloc(sizeof(100*sizeof(char)));
    char *prenom=malloc(sizeof(100*sizeof(char)));
    char *code=malloc(sizeof(4*sizeof(char)));
    // ============= MENU UTILISATEUR ============= */
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
                printf("test");

                char *nom1=malloc(sizeof(100*sizeof(char)));
                char *prenom1=malloc(sizeof(100*sizeof(char)));
                char *code1=malloc(sizeof(100*sizeof(char)));
                printf("\nVeuillez saisir en majuscule le NOM:\n");
                scanf("%s",nom1);
                strupr_(nom1);
                viderBuffer();

                printf("\nVeuillez saisir en majuscule le PRENOM:\n");
                scanf("%s",prenom1);
                strupr_(prenom1);
                viderBuffer();

                printf("\nVeuillez saisir en majuscule le CODE de l'UV:\n");
                scanf("%s",code1);
                viderBuffer();
                if (abr!=0) printf("\nOOOO %s %s %s\n", abr->nom, abr->prenom, abr->listeInscriptions->code_uv);


                //abr1 = inscrire(abr, Nom1, Prenom1, code1);
                abr = inscrire(abr, nom1, prenom1,code1);
                printf("\ntest 2 %s %s %s\n", abr->nom, abr->prenom, abr->listeInscriptions->code_uv);
                viderBuffer();
                break;


            case '2' :
                printf("Entrez le nom du fichier : ");
                scanf("%99s", nomFichier);
                viderBuffer();
                lireFichier(abr, nomFichier);
                break;

            case '3' :
                afficherInscriptions(abr);
                break;


            case '4' :
                printf("\nVeuillez saisir en majuscule le CODE de l'UV:\n");
                scanf("%s",code);
                afficherInscriptionsUV(abr, code);

                break;
            case '5' :
                
                break;

            case '6' :

                break;
            default :
                {
                printf("\n\nERREUR : votre choix n'est valide ! ");
                }
        }
        printf("\n\n\n");
        viderBuffer();
    }
    return 0;
}
