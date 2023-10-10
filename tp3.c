#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"


//remarque pour la date : convertir en entier la chaine de char et ajouter par exemple +3 ou autre, puis revenir en char
// on peut aussi utiliser directement la date où se positionner


/* ********************************
 * Création et initialisation Bloc
 ******************************** */
T_Block *creerBloc(int id, char* date){
    T_Block *nouveauBloc = malloc(sizeof(T_Block));
    if (nouveauBloc != NULL) {
        // l'allocation mémoire s'est bien passée
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
        nouvelleTransaction->description = malloc(strlen(descr) + 1); // Important : malloc permet d'avoir l'espace mémoire dédié pour notre champ de structure
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
    T_Transaction* nouveau;
    nouveau = creerTransaction(int idEtu, float montant, char *descr);
    //laissé exprès pour la lisibilité mais pas utile
    if (listeTransaction!=NULL){
        nouveau->suivant=listeTransaction;
    }
    return nouveau;
}



/* ********************************
 * 2.	Ajout d'un bloc en tête de la BlockChain :
 ******************************** */
BlockChain ajouterBlock(BlockChain bc){ // ici on a un pointeur vers le premier element de la liste des blocks = bc
    BlockChain chaine_de_blocs;
    if (bc == NULL){
        chaine_de_blocs->idBloc = 0;//premier bloc
        chaine_de_blocs->dateBloc = dateJ; //attention dateJ devra être modifiable pour le bien du test
        chaine_de_blocs = creerBloc(chaine_de_blocs->idBloc, chaine_de_blocs->dateBloc);
        bc->suivant = NULL;
    } else {
        chaine_de_blocs->idBloc = 1 + bc->idBloc;
        chaine_de_blocs = creerBloc(chaine_de_blocs->idBloc, chaine_de_blocs->dateBloc);
        chaine_de_blocs->suivant = bc->idBloc;
    }
    //on a besoin de la date
    //pour déclanger un ajout de bloc, il faut vérifier que c'est une date diff du bloc precedent

    return chaine_de_blocs;
}

/* ********************************
 * 3.	Calcul de la somme des EATCoin crédités et dépensés par un étudiant sur une journée :
 ******************************** */
float totalTransactionEtudiantBlock(int idEtu, T_Block b){
    // TODO
    return 0;
}


/* ********************************
 * 4.	Calcul du solde total d'un étudiant:
 ******************************** */
float soldeEtudiant(int idEtu, BlockChain bc){
    // TODO
    return 0;
}


/* ********************************
 * 5.	Rechargement du compte d’un étudiant :
 ******************************** */
void crediter(int idEtu, float montant, char *descr, BlockChain bc){
    // TODO

}


/* ********************************
 * 6.	Paiement d'un repas :
 ******************************** */
int payer(int idEtu, float montant, char *descr, BlockChain bc){
    // TODO
    return 1;
}


/* ********************************
 * 7.	Historique d’un étudiant :
 ******************************** */
void consulter(int idEtu, BlockChain bc){
    // TODO

}


/* ********************************
 * 8.	Transfert de EATCoins entre deux étudiants :
 ******************************** */
int transfert(int idSource, int idDestination, float montant, char *descr, BlockChain bc){
    // TODO
    return 1;
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
