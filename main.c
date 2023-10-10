#include <stdio.h>
#include <stdlib.h>
#include "tp3.c"

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
        printf("\n");
        switch (choix) {
            case '1' :

                while (ma_chaine_de_blocs){
                    printf("n° du bloc : %d \n",ma_chaine_de_blocs->idBloc);
                }
                break;

            case '2' :
                {

                int idbloc;
                printf("entrez le numero du bloc a afficher : ");
                scanf("%d",&idbloc);
                while (ma_chaine_de_blocs){
                    if (ma_chaine_de_blocs->idBloc==idbloc){
                        int i=0;
                        T_Transaction *t;
                        t=ma_chaine_de_blocs->listeTransactions;
                        while (t){
                            printf("transaction n°%d : le %s, %s, %lf€ \n",i,ma_chaine_de_blocs->dateBloc,t->description,t->montant);
                            i++;
                            t=t->suivant;
                        }
                    }
                }
                break;
                }

            case '3' :
                {

                int idetu;
                int i;
                printf("entrez l'id de l'etudiant a afficher : ");
                scanf("%d",&idetu);
                float solde = soldeEtudiant(idetu,ma_chaine_de_blocs);
                T_Transaction *t;
                t=ma_chaine_de_blocs->listeTransactions;
                while (t){
                    if (t->idEtu==idetu){
                        printf("transaction n°%d : le %s, %s, %lf€ \n",i,ma_chaine_de_blocs->dateBloc,t->description,t->montant);
                        i++;
                    }
                    t=t->suivant;
                }
                break;
                }
            case '4' :
                {

                int idetu;
                printf("entrez l'id de l'etudiant a afficher : ");
                scanf("%d",&idetu);
                consulter(idetu, ma_chaine_de_blocs);
                break;
                }
            case '5' :
                {
                int idetu;
                float montant;
                char desc[100];
                printf("entrez l'id de l'etudiant a crediter : ");
                scanf("%d",&idetu);
                printf("\n");
                printf("entrez le montant a crediter : ");
                scanf("%lf",&montant);
                printf("\n");
                printf("entre la description : ");
                fgets(desc, sizeof(desc), stdin);
                printf("\n");
                crediter(idetu, montant, desc, ma_chaine_de_blocs);

                break;
                }

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
