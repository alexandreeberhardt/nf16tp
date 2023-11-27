#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

int main()
{
    T_Arbre abr=NULL;
    T_Arbre abr1=NULL;
    T_Arbre noeud, noeud1, noeud2, noeud3=NULL;

    char *nomFichier;
    char *nom=malloc(sizeof(100*sizeof(char)));
    char *prenom=malloc(sizeof(100*sizeof(char)));
    char *code=malloc(sizeof(4*sizeof(char)));
    char *Nom1=malloc(sizeof(100*sizeof(char)));
    char *Prenom1=malloc(sizeof(100*sizeof(char)));
    char *code1=malloc(sizeof(4*sizeof(char)));
    // ============= MENU UTILISATEUR ============= */
    char choix = '0';
    while (choix != '9') {
        printf("\n======================================");
        printf("\n1. Inscrire un etudiant a une UV");
        printf("\n2. Charger un fichier d'inscriptions");
        printf("\n3. Afficher tous les etudiants");
        printf("\n4. Afficher les inscrits a une UV");
        printf("\n5. Supprimer une inscription");
        printf("\n6. ");
        printf("\n7. ");
        printf("\n8. ");
        printf("\n9. Quitter");
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

                break;

            case '5' :
                printf("test");

                /*char *Nom1=malloc(sizeof(100*sizeof(char)));
                char *prenom1=malloc(sizeof(100*sizeof(char)));
                char *code1=malloc(sizeof(100*sizeof(char)));*/
                Nom1 = "AUBIN";
                prenom1 = "LOLA";
                code1= "NF16";
                //noeud = creerNoeud(nom, prenom,code);
                //printf("test 1 %s %s %s", noeud->nom, noeud->prenom, noeud->listeInscriptions->code_uv);
                //noeud1 = rechercherNoeud(noeud, nom, prenom);
                //printf("%s %s %s", noeud1->nom, noeud1->prenom, noeud1->listeInscriptions->code_uv);
                //noeud2 = NULL;
                abr = inscrire(abr, Nom1, prenom1,code1);
                printf("\ntest 2 %s %s %s\n", abr->nom, abr->prenom, abr->listeInscriptions->code_uv);

                Nom1 = "LR";
                prenom1 = "LINN";
                code1= "AD04";
                abr = inscrire(abr, Nom1, prenom1,code1);
                printf("\ntest 3 %s %s %s\n", abr->nom, abr->prenom, abr->listeInscriptions->code_uv);
                noeud3 = abr->filsGauche;
                printf("\ntest 4 %s %s %s\n", noeud3->nom, noeud3->prenom, noeud3->listeInscriptions->code_uv);

                Nom1 = "XAMOR";
                prenom1 = "XALO";
                code1= "AD04";
                noeud3 = inscrire(abr, Nom1, prenom1,code1);
                printf("\ntest 4 %s %s %s\n", noeud3->nom, noeud3->prenom, noeud3->listeInscriptions->code_uv);
                noeud3 = abr->filsGauche;

                printf("\ntest 5 %s %s %s\n", noeud3->nom, noeud3->prenom, noeud3->listeInscriptions->code_uv);
                noeud3 = abr->filsGauche->filsGauche;

                printf("\ntest 6 %s %s %s\n", noeud3->nom, noeud3->prenom, noeud3->listeInscriptions->code_uv);

                printf("\ntete %s %s %s\n", abr->nom, abr->prenom, abr->listeInscriptions->code_uv);
                afficherInscriptions(abr);
                break;

            case '9' :

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
