#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp3.h"





/* ********************************
 * Cr�ation et initialisation Bloc
 ******************************** */
T_Block *creerBloc(int id, char* date){
    T_Block *nouveauBloc = malloc(sizeof(T_Block));
    if (nouveauBloc != NULL) {
        // l'allocation m�moire s'est bien pass�e
        nouveauBloc->dateBloc = malloc(strlen(date) + 1);
        strcpy(nouveauBloc->dateBloc,date);
        nouveauBloc->idBloc = id;
        nouveauBloc->listeTransactions = NULL;
        nouveauBloc->suivant = NULL;
    }

    return nouveauBloc;
}

/* **************************************
 * Cr�ation et initialisation Transaction
 ************************************** */
T_Transaction *creerTransaction(int id, float montant, char *descr) {
    T_Transaction *nouvelleTransaction = malloc(sizeof(T_Transaction));
    if (nouvelleTransaction != NULL) {
        // l'allocation m�moire s'est bien pass�e
        nouvelleTransaction->description = malloc(strlen(descr) + 1); // Important : malloc permet d'avoir l'espace m�moire d�di� pour notre champ de structure
        strcpy(nouvelleTransaction->description,descr);
        nouvelleTransaction->idEtu = id;
        nouvelleTransaction->montant = montant;
        nouvelleTransaction->suivant = NULL;
    }

    return nouvelleTransaction;
}


/* ********************************
 * 1.	Ajout d'une transaction en t�te d'une liste de transactions :
 ******************************** */
T_Transaction *ajouterTransaction(int idEtu, float montant, char *descr, T_Transaction *listeTransaction) {
    // TODO
    return NULL;
}



/* ********************************
 * 2.	Ajout d'un bloc en t�te de la BlockChain :
 ******************************** */
BlockChain ajouterBlock(BlockChain bc){
    // TODO
    return NULL;
}


/* ********************************
 * 3.	Calcul de la somme des EATCoin cr�dit�s et d�pens�s par un �tudiant sur une journ�e :
 ******************************** */
float totalTransactionEtudiantBlock(int idEtu, T_Block b){
    // TODO
    return 0;
}


/* ********************************
 * 4.	Calcul du solde total d'un �tudiant:
 ******************************** */
float soldeEtudiant(int idEtu, BlockChain bc){
    // TODO
    return 0;
}


/* ********************************
 * 5.	Rechargement du compte d�un �tudiant :
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
 * 7.	Historique d�un �tudiant :
 ******************************** */
void consulter(int idEtu, BlockChain bc){
    // TODO

}


/* ********************************
 * 8.	Transfert de EATCoins entre deux �tudiants :
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
