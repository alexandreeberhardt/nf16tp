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
    T_Transaction* nouveauLT;
    nouveauLT = creerTransaction(idEtu, montant, descr);
    //laissé exprès pour la lisibilité mais pas utile
    if (listeTransaction!=NULL){
        nouveauLT->suivant=listeTransaction;
    }
    return nouveauLT;
}



/* ********************************
 * 2.	Ajout d'un bloc en tête de la BlockChain :
 ******************************** */
BlockChain ajouterBlock(BlockChain bc){ // ici on a un pointeur vers le premier element de la liste des blocks = bc
    BlockChain chaine_de_blocs = malloc(sizeof(T_Block));
    T_Block nouveaubloc;
    char *dateJ="20231014";
    if (bc == NULL){
        //strcpy(chaine_de_blocs->dateBloc,dateJ);
        //chaine_de_blocs->dateBloc = dateJ; //attention dateJ devra être modifiable pour le bien du test
        chaine_de_blocs = creerBloc(0, dateJ);
        chaine_de_blocs->suivant = NULL;
    } else {
        chaine_de_blocs->idBloc = 1 + bc->idBloc;
        chaine_de_blocs = creerBloc(chaine_de_blocs->idBloc, dateJ);
        chaine_de_blocs->suivant = bc;
    }
    //on a besoin de la date
    //pour déclanger un ajout de bloc, il faut vérifier que c'est une date diff du bloc precedent

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
    T_Transaction *listeTransaction = NULL;
    listeTransaction = bc->listeTransactions;
    listeTransaction = ajouterTransaction(idEtu,montant,descr,bc->listeTransactions);
    while(listeTransaction!=NULL){
        printf("\nid de nouv = %d\n",listeTransaction->idEtu);
        printf("montant de nouv = %f\n",listeTransaction->montant);
        printf("descrip de nouv = %s\n",listeTransaction->description);
        listeTransaction = listeTransaction->suivant;
    }
    BlockChain listeB=NULL;
    listeB = ajouterBlock(bc);
    while(listeB!=NULL){
        printf("\nid de nouv Liste bloc = %d\n",listeB->idBloc);
        printf("descrip de nouv liste bloc = %s\n",listeB->dateBloc);
        listeB = listeB->suivant;
    }
    //ici pas besoin de créer un bloc car on ajoute la transaction dans le premier bloc et pas dans un nouveau

    return bc;
}

/* ********************************
 * 6.	Paiement d'un repas :
 ******************************** */
int payer(int idEtu, float montant, char *descr, BlockChain bc){
    if (soldeEtudiant(idEtu, bc)>montant){
        ajouterTransaction(idEtu,montant,descr,bc);//->listeTransactions);
        return 1;
    }
    return 0;
}


/* ********************************
 * 7.	Historique d’un étudiant :
 ******************************** */
void consulter(int idEtu, BlockChain bc){
    float solde = soldeEtudiant(idEtu,bc);
    int i=0;
    {
    T_Transaction *t;
        while (bc &&i<5){
            t=bc->listeTransactions;
            while (t && i<5){
                if (t->idEtu==idEtu){
                    printf("transaction n°%d : le %s, %s, %lf€",i,bc->dateBloc,t->description,t->montant);
                    i++;
                }
                t=t->suivant;
            }
        bc=bc->suivant;
        }
    }
    return 0;
}


/* ********************************
 * 8.	Transfert de EATCoins entre deux étudiants :
 ******************************** */
int transfert(int idSource, int idDestination, float montant, char *descr, BlockChain bc){
    if (soldeEtudiant(idSource, bc)>montant){
        payer(idSource, montant, *descr, bc);
        crediter(idDestination, montant, *descr, bc);
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
