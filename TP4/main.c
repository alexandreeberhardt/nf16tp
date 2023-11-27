#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

int main()
{
    T_Arbre abr = NULL;
                   char nom[100], prenom[100], codeUV[10];

    char *code=malloc(sizeof(4*sizeof(char)));
    char *nomFichier=malloc(sizeof(100*sizeof(char)));
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

    // Demander à l'utilisateur de saisir le nom, le prénom et le code de l'UV
    printf("Entrez le nom de l'etudiant : ");
    scanf("%99s", nom); // Utilisation de %99s pour éviter le dépassement de tampon
    printf("Entrez le prenom de l'etudiant : ");
    scanf("%99s", prenom);
    printf("Entrez le code de l'UV : ");
    scanf("%9s", codeUV);

    // Appel de la fonction inscrire
    abr = inscrire(abr, nom, prenom, codeUV);
    printf("Etudiant inscrit avec succes.\n");

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
                void afficherInscriptionsUV(T_Arbre abr, char *code);

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
