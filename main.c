#include <stdio.h>
#include <stdlib.h>
#include "tp3.h"
#include "tp3.C"

int main(){

    BlockChain ma_chaine_de_blocs = NULL;

    // ============= MENU UTILISATEUR ============= */
    char choix = '0';
    while (choix != '8') {
        printf("\n======================================");
        printf("\n1. Afficher la liste des blocs de la BlockChain");
        printf("\n2. Afficher toutes les transactions d'un bloc");
        printf("\n3. Afficher toutes les transactions du jour pour un etudiant");
        printf("\n4. Afficher l'historique pour un etudiant");
        printf("\n5. Crediter un compte");
        printf("\n6. Payer un repas");
        printf("\n7. Transferer des EATCoins entre deux etudiants");
        printf("\n8. Quitter");
        printf("\n======================================");
        printf("\n   Votre choix ? ");

        choix = getchar();

        switch (choix) {
            case '1' :
                break;

            case '2' :
                break;

            case '3' :
                break;

            case '4' :
                break;

            case '5' :
                break;

            case '6' :
                break;

            case '7' :
               break;

            case '8' :
                printf("\n======== PROGRAMME TERMINE ========\n");
                break;

            default :
                printf("\n\nERREUR : votre choix n'est valide ! ");
        }
        printf("\n\n\n");
        viderBuffer(); // supprimer de l'entrée standard le retour charriot et les éventuels caractères supplémentaires tapés par l'utilisateur
    }

    return 0;
}
