#include <stdio.h>
#include <stdlib.h>
#include "tp3.c"

int main(){

    BlockChain ma_chaine_de_blocs = NULL;
    /*char chaine[10];
    printf("chaine ?\n");
    fgets(chaine, 10, stdin);
    printf("chaine = %s", chaine);*/

    //test de creerTransaction
    int id = 15;
    float montant = 12.675;
    char*descr= "Midi";
    /*T_Transaction *nouvelleT = NULL;
    nouvelleT = creerTransaction(id, montant, descr);
    printf("id de nouvelle T = %d\n",nouvelleT->idEtu);
    printf("montant de nouvelle T = %f\n",nouvelleT->montant);
    printf("descrip de nouvelle T = %s\n",nouvelleT->description);*/

    //test d'ajouterTransaction (ici 2)
    T_Transaction *listeTransaction = NULL;
    listeTransaction = ajouterTransaction(id,montant,descr,listeTransaction);
    id = 20;
    montant = 40;
    descr= "Soir";
    listeTransaction = ajouterTransaction(id,montant,descr,listeTransaction); // ajoute une seconde transaction
    while(listeTransaction!=NULL){
        printf("\nid de nouv = %d\n",listeTransaction->idEtu);
        printf("montant de nouv = %f\n",listeTransaction->montant);
        printf("descrip de nouv = %s\n",listeTransaction->description);
        listeTransaction = listeTransaction->suivant;
    }

    //test creerbloc
    int ide = 1;
    char*date = "20231014";
    T_Block * nouveauB = NULL;
    nouveauB = creerBloc(ide, date);
    while(nouveauB!=NULL){
        printf("\nid de nouv B = %d\n",nouveauB->idBloc);
        printf("descrip de nouv B = %s\n",nouveauB->dateBloc);
        nouveauB = nouveauB->suivant;
    }

    //test ajouterBloc
    /*BlockChain listeB=NULL;
    listeB = ajouterBlock(listeB);
    listeB->listeTransactions = listeTransaction;

    /*ide = 2;
    date = "20231014";
    nouveauB = creerBloc(ide, date);
    listeB = ajouterBlock(listeB);
    ide = 3;
    date = "20231015";
    nouveauB = creerBloc(ide, date);
    listeB = ajouterBlock(listeB);*/
    /*while(listeB!=NULL){
        printf("\nid de liste 1= %d\n",listeB->idBloc);
        printf("descrip de liste 1= %s\n",listeB->dateBloc);
        listeB = listeB->suivant;
    }*/

    id = 1;
    montant = 1;
    descr= "Matin";
    T_Transaction *listeT2 = NULL;
    listeT2 = ajouterTransaction(id,montant,descr,listeT2);
    id = 2;
    montant = 2;
    descr= "Matin";
    listeT2 = ajouterTransaction(id,montant,descr,listeT2); // ajoute une seconde transaction
    while(listeT2!=NULL){
        printf("\nid de liste T2 = %d\n",listeT2->idEtu);
        printf("montant de liste T2 = %f\n",listeT2->montant);
        printf("descrip de liste T2 = %s\n",listeT2->description);
        listeT2 = listeT2->suivant;
    }

    BlockChain listeB=NULL;

    listeB = ajouterBlock(listeB);

    while(listeB!=NULL){
        printf("\nid de nouv Liste bloc = %d\n",listeB->idBloc);
        printf("descrip de nouv liste bloc = %s\n",listeB->dateBloc);
        listeB = listeB->suivant;
    }
    listeB = ajouterBlock(listeB);
    listeB = ajouterBlock(listeB);
    listeB = ajouterBlock(listeB);
    while(listeB!=NULL){
        printf("\nid de nouv Liste bloc = %d\n",listeB->idBloc);
        printf("descrip de nouv liste bloc = %s\n",listeB->dateBloc);
        listeB = listeB->suivant;
    }


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

                if(ma_chaine_de_blocs!=NULL){
                    do {
                        printf("n° du bloc : %d \n",ma_chaine_de_blocs->idBloc);
                    }while(ma_chaine_de_blocs!=NULL);
                }else {
                    printf("Il n'y a pas de blocs dans la chaine de blocs.\n");
                }
                break;

            case '2' :
                {

                int idbloc;
                printf("entrez le numero du bloc a afficher : ");
                scanf("%d",&idbloc);
                while (ma_chaine_de_blocs!=NULL){
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
                while (t!=NULL){
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
                char chaine[100];
                char * desc;

                printf("entrez l'id de l'etudiant a crediter : ");
                scanf("%d",&idetu);
                printf("idetu=%d",idetu);

                viderBuffer();
                printf("\n");
                printf("entrez le montant a crediter : ");
                scanf("%f",&montant);
                printf("montant=%f",montant);
                printf("\n");

                viderBuffer();
                printf("entrez la description en moins de 100 caracteres :");
                fgets(chaine, 100, stdin);
                printf("chaine = %s\n", chaine);
                printf("idetu = %d, montant = %f, descrip = %s ", idetu, montant, chaine);
                desc = (char *)malloc(strlen(chaine) * sizeof(char));
                *desc = chaine;
                crediter(idetu, montant, desc, ma_chaine_de_blocs);


                break;
                }

            case '6' :
                break;

            case '7' :
               break;

            case '8' :
                printf("\n======== PROGRAMME TERMINE ========\n");
                //vider la memoire avec les free
                break;

            default :
                printf("\n\nERREUR : votre choix n'est valide ! ");
        }
        printf("\n\n\n");
        viderBuffer(); // supprimer de l'entrée standard le retour charriot et les éventuels caractères supplémentaires tapés par l'utilisateur
    }

    return 0;
}
