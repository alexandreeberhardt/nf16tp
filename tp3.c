#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "tp3.h"
//Nous définissions la date ici, le programme de base aurait été cherché la date de l'ordinateur
char *dateJ="20231024";


/* ********************************
 * Création et initialisation Bloc
 ******************************** */
T_Block *creerBloc(int id, char* date){
    T_Block *nouveauBloc = malloc(sizeof(T_Block));
    if (nouveauBloc != NULL) {
        //Permet de vérifier que l'allocation mémoire s'est bien passée
        nouveauBloc->dateBloc = malloc(strlen(date) + 1);
        strcpy(nouveauBloc->dateBloc,date);
        nouveauBloc->idBloc = id;
        nouveauBloc->listeTransactions = NULL;
        nouveauBloc->suivant = NULL;
    }

    return nouveauBloc;
}

/* **************************************
 * Création et initialisation Transaction
 ************************************** */
T_Transaction *creerTransaction(int id, float montant, char *descr) {
    T_Transaction *nouvelleTransaction = malloc(sizeof(T_Transaction));
    if (nouvelleTransaction != NULL) {
        // l'allocation mémoire s'est bien passée
        nouvelleTransaction->description = malloc(strlen(descr) + 1);
        strcpy(nouvelleTransaction->description,descr);
        nouvelleTransaction->idEtu = id;
        nouvelleTransaction->montant = montant;
        nouvelleTransaction->suivant = NULL;
    }

    return nouvelleTransaction;
}


/* ********************************
 * 1.	Ajout d'une transaction en tête d'une liste de transactions :
 ******************************** */
T_Transaction *ajouterTransaction(int idEtu, float montant, char *descr, T_Transaction *listeTransaction) {
    T_Transaction* nouveauLT;
    nouveauLT = creerTransaction(idEtu, montant, descr);
    //laissé exprès pour la lisibilité
    if (listeTransaction!=NULL){
        nouveauLT->suivant=listeTransaction;
    }
    return nouveauLT;
}



/* ********************************
 * 2.	Ajout d'un bloc en tête de la BlockChain :
 ******************************** */
BlockChain ajouterBlock(BlockChain bc){ //ici on a un pointeur vers le 1er element de la liste
    BlockChain chaine_de_blocs = malloc(sizeof(T_Block));
    T_Block nouveaubloc;
        if (bc == NULL){
            chaine_de_blocs = creerBloc(0, dateJ);
            chaine_de_blocs->suivant = NULL;
        } else {
            chaine_de_blocs->idBloc = 1 + bc->idBloc;
            chaine_de_blocs = creerBloc(chaine_de_blocs->idBloc, dateJ);
            chaine_de_blocs->suivant = bc;
        }
    return chaine_de_blocs;
}

/* ********************************
 * 3.	Calcul de la somme des EATCoin crédités et dépensés par un étudiant sur une journée :
 ******************************** */
float totalTransactionEtudiantBlock(int idEtu, T_Block b){
    float total=0;
    T_Transaction *t;
    t=b.listeTransactions;
    while (t){
        if (t->idEtu==idEtu){
        total+=t->montant;
        }
        t=t->suivant;
    }
    return total;
}



/* ********************************
 * 4.	Calcul du solde total d'un étudiant:
 ******************************** */
float soldeEtudiant(int idEtu, BlockChain bc){
    float solde=0;
    while (bc){
        solde+=totalTransactionEtudiantBlock(idEtu, *bc);
        bc=bc->suivant;
        }
    return solde;
}


/* ********************************
 * 5.	Rechargement du compte d’un étudiant :
 ******************************** */
void crediter(int idEtu, float montant, char*descr, BlockChain bc){
    //ici pas besoin de créer un bloc car on ajoute la transaction dans le premier bloc et pas dans un nouveau
    if (bc!=NULL){
        T_Transaction *listeTransaction = NULL;
        listeTransaction = ajouterTransaction(idEtu,montant,descr,bc->listeTransactions);
        //ici on utilise le premier bloc de la liste pour ajouter la transaction car on concidère que c'est celle du jour
        bc->listeTransactions=listeTransaction;

    }
}

/* ********************************
 * 6.	Paiement d'un repas :
 ******************************** */
int payer(int idEtu, float montant, char *descr, BlockChain bc){
    montant=fabs(montant);
    if (soldeEtudiant(idEtu, bc)>montant){//double vérification du solde mais permet d'utiliser la fonction autrement que dans le choix 6 si on le souhaitait
        montant=montant*(-1.);//permet de rentrer le bon signe pour le montant et ainsi calculer le bon solde
        bc->listeTransactions = ajouterTransaction(idEtu,montant,descr,bc->listeTransactions);
        return 1;
    }
    return 0;
}


/* ********************************
 * 7.	Historique d’un étudiant :
 ******************************** */
void consulter(int idEtu, BlockChain bc){
    float solde = soldeEtudiant(idEtu,bc);
    int i=1;
    {
    T_Transaction *t;
        while (bc &&i<=5){
            t=bc->listeTransactions;
            while (t && i<=5){
                if (t->idEtu==idEtu){
                    printf("\ndate de la transaction n %d = %s\n",i,bc->dateBloc);
                    printf("montant de la transaction n %d = %f\n",i, t->montant);
                    printf("descrip de la transaction n %d = %s\n",i, t->description);
                    i++;
                }
                t=t->suivant;
            }
        bc=bc->suivant;
        }
        if (i<5){
            printf("Il n'y a pas d'autres transactions pour cet etudiant.");
        }
    }
}


/* ********************************
 * 8.	Transfert de EATCoins entre deux étudiants :
 ******************************** */
int transfert(int idSource, int idDestination, float montant, char *descr, BlockChain bc){
    if (soldeEtudiant(idSource, bc)>montant){
        payer(idSource, montant, descr, bc);
        crediter(idDestination, montant, descr, bc);
        return 1;
    }
    return 0;
}



/* *********************
 * Fonctions utilitaires
 ********************* */
// Vider le buffer (utile quand on utlise des getchar() )
void viderBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

//libérer l'espace mémoire
void libererEspace(BlockChain bc_de_base){
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
                printf("Les transactions sont supprimees.\n"); //on peut faire apparaitre ce print pour vérifier
                free(listeT2);
            }
            //Libérer le bloc
            bcbis = bc_de_base;
            bc_de_base = bc_de_base->suivant;
            free(bcbis);
            printf("Le bloc est supprime.\n"); //on peut faire apparaitre ce print pour vérifier
        }
}
