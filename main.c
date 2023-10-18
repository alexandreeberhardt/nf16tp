#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tp3.c"

int main(){

    BlockChain ma_chaine_de_blocs = NULL;
    BlockChain premier_bloc = NULL;
    BlockChain listeB = NULL;
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
    T_Transaction *premiere_transaction = listeTransaction;
    listeTransaction = ajouterTransaction(id,montant,descr,listeTransaction);
    id = 20;
    montant = 40;
    descr= "Soir";
    listeTransaction = ajouterTransaction(id,montant,descr,listeTransaction);// ajoute une seconde transaction
    premiere_transaction = listeTransaction;
    while(listeTransaction!=NULL){
        printf("\nid de nouv = %d\n",listeTransaction->idEtu);
        printf("montant de nouv = %f\n",listeTransaction->montant);
        printf("descrip de nouv = %s\n",listeTransaction->description);
        listeTransaction = listeTransaction->suivant;
    }
    listeTransaction = premiere_transaction;
    id = 20;
    montant = 30;
    descr= "Soir";
    listeTransaction = ajouterTransaction(id,montant,descr,listeTransaction);
    premiere_transaction = listeTransaction;

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
    /*while(listeT2!=NULL){
        printf("\nid de liste T2 = %d\n",listeT2->idEtu);
        printf("montant de liste T2 = %f\n",listeT2->montant);
        printf("descrip de liste T2 = %s\n",listeT2->description);
        listeT2 = listeT2->suivant;
    }*/

    //BlockChain listeB=NULL;

    ma_chaine_de_blocs = ajouterBlock(ma_chaine_de_blocs);

    while(ma_chaine_de_blocs!=NULL){
        printf("\nid de nouv Liste bloc = %d\n",ma_chaine_de_blocs->idBloc);
        printf("descrip de nouv liste bloc = %s\n",ma_chaine_de_blocs->dateBloc);
        ma_chaine_de_blocs = ma_chaine_de_blocs->suivant;
    }
    ma_chaine_de_blocs = ajouterBlock(ma_chaine_de_blocs);
    ma_chaine_de_blocs->listeTransactions = listeTransaction;
    ma_chaine_de_blocs = ajouterBlock(ma_chaine_de_blocs);

    ma_chaine_de_blocs->listeTransactions = listeT2;
    ma_chaine_de_blocs = ajouterBlock(ma_chaine_de_blocs);
    id = 1;
    montant = 1;
    descr= "Matin";
    T_Transaction *listeT3 = NULL;
    listeT3 = ajouterTransaction(id,montant,descr,listeT3);
    id = 2;
    montant = 2;
    descr= "Matin";
    listeT3 = ajouterTransaction(id,montant,descr,listeT3);
    ma_chaine_de_blocs->listeTransactions = listeT3;
    /*while(ma_chaine_de_blocs!=NULL){
        printf("\nid de nouv Liste bloc = %d\n",ma_chaine_de_blocs->idBloc);
        printf("descrip de nouv liste bloc = %s\n",ma_chaine_de_blocs->dateBloc);
        ma_chaine_de_blocs = ma_chaine_de_blocs->suivant;
    }*/


    // ============= MENU UTILISATEUR ============= */
    printf("\nDate du jour :%s\n",dateJ);
    char choix = '0';
    while (choix != '9') {
        printf("\n======================================");
        printf("\n1. Afficher la liste des blocs de la BlockChain");
        printf("\n2. Afficher toutes les transactions d'un bloc");
        printf("\n3. Afficher toutes les transactions du jour pour un etudiant");
        printf("\n4. Afficher l'historique pour un etudiant");
        printf("\n5. Crediter un compte");
        printf("\n6. Payer un repas");
        printf("\n7. Transferer des EATCoins entre deux etudiants");
        printf("\n8. Changer la date");
        printf("\n9. Quitter");
        printf("\n======================================");
        printf("\n   Votre choix ? ");

        choix = getchar();
        printf("\n");
        switch (choix) {
            case '1' :
                {
                    if(ma_chaine_de_blocs==NULL){
                        printf("Il n'y a pas de blocs dans la chaine de blocs.\n");
                    } else {
                        premier_bloc = ma_chaine_de_blocs;
                    }
                    while(ma_chaine_de_blocs!=NULL){
                        printf("\nid du bloc = %d\n",ma_chaine_de_blocs->idBloc);
                        printf("descrip du bloc = %s\n",ma_chaine_de_blocs->dateBloc);
                        ma_chaine_de_blocs = ma_chaine_de_blocs->suivant;
                    }
                    ma_chaine_de_blocs = premier_bloc;
                }
                break;

            case '2' :
                {
                    int idbloc;
                    premier_bloc = ma_chaine_de_blocs;
                    printf("entrez le numero du bloc a afficher : ");
                    scanf("%d",&idbloc);
                    //printf("idbloc = %d",idbloc);
                    while (idbloc>=ma_chaine_de_blocs->idBloc+1){
                        printf("\nL'identifiant de bloc indique n'existe pas. Veuillez en saisir un autre :\n");
                        scanf("%d",&idbloc);
                    }
                    do{
                        if (ma_chaine_de_blocs->idBloc==idbloc){
                            T_Transaction *t;
                            t=ma_chaine_de_blocs->listeTransactions;
                            if (t!=NULL){
                                int i=1;
                                while (t!=NULL){
                                    //printf("transaction n°%d : le %s, %s, %lf€ \n",i,ma_chaine_de_blocs->dateBloc,t->description,t->montant);
                                    printf("\nidentifiant de la transaction n %d= %d\n",i,t->idEtu);
                                    printf("montant de la transaction n %d = %f\n",i, t->montant);
                                    printf("descrip de la transaction n %d = %s\n",i, t->description);
                                    t = t->suivant;
                                    i++;
                                }
                            }else{
                                printf("Il n'y a pas de transaction.\n");
                            }
                        }
                        ma_chaine_de_blocs = ma_chaine_de_blocs->suivant;
                    }while (ma_chaine_de_blocs!=NULL);//|| ma_chaine_de_blocs->idBloc!=idbloc
                    ma_chaine_de_blocs = premier_bloc;
                }
                break;


            case '3' : //on considère que le bloc en premier dans la liste est le bloc du jour
                {
                    int idetu;
                    premier_bloc = ma_chaine_de_blocs;
                    printf("entrez l'id de l'etudiant a afficher : ");
                    scanf("%d",&idetu);
                    printf("idetu = %d",idetu);
                    if(ma_chaine_de_blocs!=NULL){
                        T_Transaction *t;
                        t=ma_chaine_de_blocs->listeTransactions;
                        if (t!=NULL){
                            int i=1;
                            int nb_T=0;
                            while (t!=NULL){
                                    if (idetu==t->idEtu){
                                        nb_T++;
                                        printf("\nidentifiant de l'etudiant n %d= %d\n",i,t->idEtu);//changer le numero de la transaction pour quelle soit comptée en fonction du nb de transactiond e l'étudiant
                                        printf("montant de la transaction n %d = %f\n",i, t->montant);
                                        printf("descrip de la transaction n %d = %s\n",i, t->description);
                                    }
                                    t = t->suivant;
                                    i++;
                            }
                            if (nb_T==0){
                                printf("Il n'y a pas de transaction pour l'etudiant a l'identifiant n %d.\n",idetu);
                            }
                        }else{
                            printf("Il n'y a pas de transaction.\n");
                        }
                    }
                }
                break;

            case '4' :
                {
                    int idetu;
                    printf("entrez l'id de l'etudiant dont on souhaite afficher les 5 dernieres transactions : ");
                    scanf("%d",&idetu);
                    consulter(idetu, ma_chaine_de_blocs);
                }
                break;

            case '5' :
                {
                    int idetu;
                    float montant;
                    //char chaine[100];
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
                    desc = (char *)malloc(100* sizeof(char));
                    if (desc != NULL){
                        printf("entrez la description en moins de 100 caracteres :");
                        fgets(desc, 100, stdin);
                        size_t length = strcspn(desc, "\n");
                        if (length < strlen(desc)) {
                            desc[length] = '\0';
                        }
                        printf("description = %s\n", desc);
                        printf("\nVotre saisie est : idetu = %d, montant = %f, descrip = %s \n", idetu, montant, desc);
                        crediter(idetu, montant, desc, ma_chaine_de_blocs);
                    }else{
                        printf("Pas d'allocation memoire pour description.\n");
                    }

                    printf("\n\nAppuyez sur entrer pour continuer\n");
                    free(desc);
                }
                break;


            case '6' ://payer un repas, donc il faut débiter un compte
                {
                    //1 : verifier que solde suffisant
                    float montant_repas=0;
                    int idE;
                    float solde=0;
                    char * desc;
                    int i=0;
                    desc = (char *)malloc(100* sizeof(char));
                    viderBuffer();
                    printf("Indiquez l'identifiant de l'etudiant :\n");
                    scanf("%d",&idE);
                    viderBuffer();
                    printf("Indiquez le montant a depenser pour le repas :\n");
                    scanf("%f",&montant_repas);
                    viderBuffer();
                    if (montant_repas<=0){
                        printf("Le montant saisi n'est pas depensable car negatif ou egale a zero. Veuillez en saisir un nouveau.\n");
                        while (montant_repas<=0){
                            printf("Indiquez le montant a depenser pour le repas :\n");
                            scanf("%f",&montant_repas);
                        }
                    }
                    solde = soldeEtudiant(idE, ma_chaine_de_blocs);
                    if (solde<=montant_repas){
                        printf("Le montant est insuffisant pour payer le repas, veuillez crediter le compte avant.\n");
                    }else{
                        if (desc != NULL){
                            printf("Veuillez saisir une description pour votre paiement en moins de 100 caracteres :\n");
                            fgets(desc, 100, stdin);
                            payer(idE,montant_repas,desc,ma_chaine_de_blocs);
                        }
                    }
                    printf("Fin de la transaction. Cliquez sur entrer\n");
                    free(desc);
                }

                break;

            case '7' :
                {
                    int idSource, idDestination;
                    float montant_transf, solde;
                    solde=0;
                    char*desc;
                    desc = (char *)malloc(100* sizeof(char));
                    viderBuffer();
                    printf("Indiquez l'identifiant de l'etudiant devant effectuer le transfert :\n");
                    scanf("%d",&idSource);
                    viderBuffer();
                    printf("Indiquez l'identifiant de l'etudiant recevant le transfert:\n");
                    scanf("%d",&idDestination);
                    viderBuffer();
                    printf("Indiquez le montant du transfert :\n");
                    scanf("%f",&montant_transf);
                    viderBuffer();
                    if (montant_transf<=0){
                        printf("Le montant saisi doit etre positif et superieur a zero. Veuillez en saisir un nouveau.\n");
                        while (montant_transf<=0){
                            printf("Indiquez le montant du transfert :\n");
                            scanf("%f",&montant_transf);
                        }
                    }
                    solde = soldeEtudiant(idSource, ma_chaine_de_blocs);
                    if (solde<=montant_transf){
                        printf("Le montant est insuffisant pour le transfert, veuillez crediter le compte avant.\n");
                    }else{
                        if (desc != NULL){
                            printf("Veuillez saisir une description pour votre transfert en moins de 100 caracteres :\n");
                            fgets(desc, 100, stdin);
                            transfert(idSource, idDestination,montant_transf, desc, ma_chaine_de_blocs);
                        }
                    }
                    printf("Fin de la transaction. Cliquez sur entrer\n");
                    free(desc);
                }
                break;

            case '8' :
                {
                    int nbdateActu=0;
                    int nbdateJ=0;
                    int nbj=0;
                    char nJ[9];
                    char*dateActu;
                    dateActu = (char *)malloc(9* sizeof(char));
                    printf("La date actuelle est :%s\n",dateJ);
                    printf("Selectionner la nouvelle date sous le format AAAAMMJJ :\n");
                    viderBuffer();
                    fgets(dateActu, 9, stdin);
                    viderBuffer();
                    nbdateActu=atoi(dateActu);
                    nbdateJ=atoi(dateJ);//convertit le char* en un entier
                    nbj=nbdateActu-nbdateJ;
                    if (nbj>=0){
                        while(nbj!=0){
                            nbdateJ++;
                            sprintf(nJ, "%d", nbdateJ);//permet de saisir dans le tableau l'entier
                            dateJ=&nJ;//permet de saisir en char*
                            ma_chaine_de_blocs=ajouterBlock(ma_chaine_de_blocs);
                            nbj--;
                        }
                    }else{
                        printf("Erreur : Vous avez saisi une date anterieure a celle actuelle\n");
                    }
                    strcpy(dateJ, dateActu);
                    printf("La nouvelle date est :%s\n",dateJ);
                    printf("Appuyer sur entrer.\n");
                    free(dateActu);
                }
                break;

            case '9' ://vider la mémoire : on aurait pu faire une fonction mais ici pas d'interet particulier
                {
                    BlockChain bc_de_base = ma_chaine_de_blocs;
                    BlockChain bcbis = NULL;
                    T_Transaction *listeT1 = bc_de_base->listeTransactions;
                    T_Transaction *listeT2 = NULL;
                    while (bc_de_base != NULL){
                        //Libérer toutes les listes
                        listeT1 = bc_de_base->listeTransactions;
                        listeT2 = NULL;
                        while (listeT1 != NULL){
                            listeT2 = listeT1;
                            listeT1 = listeT1->suivant;
                            printf("Les transactions sont supprimees.\n");
                            free(listeT2);
                        }
                        //Libérer le bloc
                        bcbis = bc_de_base;
                        bc_de_base = bc_de_base->suivant;
                        free(bcbis);
                        printf("Le bloc est supprime.\n");
                    }
                    printf("Tous les blocs sont supprimes.\n");
                    printf("\n======== PROGRAMME TERMINE ========\n");
                }
                break;

            default :
                {
                printf("\n\nERREUR : votre choix n'est valide ! ");
                }
        }
        printf("\n\n\n");
        viderBuffer(); // supprimer de l'entrée standard le retour charriot et les éventuels caractères supplémentaires tapés par l'utilisateur
    }

    return 0;
}
