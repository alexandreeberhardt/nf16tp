#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tp3.c"

int main(){

    BlockChain ma_chaine_de_blocs = NULL;
    BlockChain premier_bloc = NULL;
    BlockChain listeB = NULL;



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
                    if(ma_chaine_de_blocs==NULL){ //vérifier que la chaine n'est pas vide
                        printf("Il n'y a pas de blocs dans la chaine de blocs.\n");
                    } else {
                        premier_bloc = ma_chaine_de_blocs;
                    }
                    while(ma_chaine_de_blocs!=NULL){
                        printf("\nid du bloc = %d\n",ma_chaine_de_blocs->idBloc);
                        printf("descrip du bloc = %s\n",ma_chaine_de_blocs->dateBloc);
                        ma_chaine_de_blocs = ma_chaine_de_blocs->suivant;
                    }
                    //remet le pointeur au premier élément de la liste
                    ma_chaine_de_blocs = premier_bloc;
                }
                break;

            case '2' :
                {
                	if(ma_chaine_de_blocs==NULL){ //vérifier que la chaine n'est pas vide
                        printf("Il n'y a pas de blocs dans la chaine de blocs, il n'y a donc aucun bloc a afficher.\n");
                    } else {
                        
		                int idbloc;
		                premier_bloc = ma_chaine_de_blocs;
		                printf("entrez le numero du bloc a afficher : ");
		                scanf("%d",&idbloc);
		                while (idbloc>=ma_chaine_de_blocs->idBloc+1){
		                    printf("\nL'identifiant de bloc indique n'existe pas. Veuillez en saisir un autre :\n");
		                    scanf("%d",&idbloc);
		                }
		                do{
		                    //On va pouvoir afficher les transactions du bloc existant
		                    if (ma_chaine_de_blocs->idBloc==idbloc){
		                        T_Transaction *t;
		                        t=ma_chaine_de_blocs->listeTransactions;
		                        if (t!=NULL){
		                            int i=1;
		                            while (t!=NULL){
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
		                    ma_chaine_de_blocs = ma_chaine_de_blocs->suivant;//permet de parcourir la liste si jamais il y a eu des mauvaises allocations des identifiants de bloc
		                }while (ma_chaine_de_blocs!=NULL);//si pas de mauvaise allocation d'identifiant, alors le do while est inutile
		                ma_chaine_de_blocs = premier_bloc;//remet le pointeur au début
		            }
                }
                break;


            case '3' : //on considère que le bloc en premier dans la liste est le bloc du jour
                {	
                	if(ma_chaine_de_blocs==NULL){ //vérifier que la chaine n'est pas vide
                        printf("Il n'y a pas de blocs dans la chaine de blocs, il n'y a donc aucune transaction a afficher.\n");
                    } else {
                    int idetu;
                    premier_bloc = ma_chaine_de_blocs;
                    printf("entrez l'id de l'etudiant a afficher : \n");
                    scanf("%d",&idetu);
                    printf("Votre demande concerne idetu = %d\n",idetu);
                    if(ma_chaine_de_blocs!=NULL){
                        T_Transaction *t;
                        t=ma_chaine_de_blocs->listeTransactions;
                        if (t!=NULL){
                            int i=1;
                            int nb_T=0;
                            while (t!=NULL){
                                    if (idetu==t->idEtu){
                                        nb_T++;
                                        printf("\nidentifiant de l'etudiant n %d= %d\n",nb_T,t->idEtu);
                                        printf("montant de la transaction n %d = %f\n",nb_T, t->montant);
                                        printf("descrip de la transaction n %d = %s\n",nb_T, t->description);
                                    }
                                    t = t->suivant;
                                    i++;
                            }
                            if (nb_T==0){
                                printf("Il n'y a pas de transaction aujourd'hui pour l'etudiant a l'identifiant n %d.\n",idetu);
                            }
                        }else{
                            printf("Il n'y a pas de transaction.\n");
                        }
                    }
                }
                }
                break;

            case '4' :
                {
                	if(ma_chaine_de_blocs==NULL){ //vérifier que la chaine n'est pas vide
                        printf("Il n'y a pas de blocs dans la chaine de blocs, l'historique est donc vide pour tous les etudiants.\n");
                    } else {
		                int idetu;
		                float solde=0;
		                printf("entrez l'id de l'etudiant dont on souhaite afficher les 5 dernieres transactions : \n");
		                scanf("%d",&idetu);
		                solde = soldeEtudiant(idetu, ma_chaine_de_blocs);
		                printf("Le solde de l'etudiant est de : %.2f\n\n",solde);
		                consulter(idetu, ma_chaine_de_blocs);
		            }
                }
                break;

            case '5' :
                {
                	if (ma_chaine_de_blocs==NULL){
                	    ma_chaine_de_blocs = ajouterBlock(ma_chaine_de_blocs);
                	    }//permet de créer le premier bloc du jour et ici de la liste
                    int idetu;
                    float montant;
                    char * desc;

                    printf("Entrez l'id de l'etudiant a crediter : \n");
                    scanf("%d",&idetu);
                    printf("Vous avez choisi : idetu=%d\n",idetu);

                    viderBuffer();
                    printf("\n");
                    printf("Entrez le montant a crediter : ");
                    scanf("%f",&montant);
                    printf("Vous demandez de crediter un montant=%f",montant);
                    printf("\n");

                    viderBuffer();
                    desc = (char *)malloc(100* sizeof(char));
                    if (desc != NULL){
                        printf("Entrez la description en moins de 100 caracteres :\n");
                        fgets(desc, 100, stdin);
                        size_t length = strcspn(desc, "\n");
                        if (length < strlen(desc)) {
                            desc[length] = '\0';
                        }
                        printf("Vous avez saisi la description suivante = %s\n", desc);
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
                    if (ma_chaine_de_blocs==NULL){
                	    ma_chaine_de_blocs = ajouterBlock(ma_chaine_de_blocs);
                	    }//permet de créer le premier bloc du jour et ici de la liste
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
                	if (ma_chaine_de_blocs==NULL){
                	    ma_chaine_de_blocs = ajouterBlock(ma_chaine_de_blocs);
                	    }//permet de créer le premier bloc du jour et ici de la liste
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
                	if (ma_chaine_de_blocs==NULL){
                	    ma_chaine_de_blocs = ajouterBlock(ma_chaine_de_blocs);
                	    }//permet de créer le premier bloc du jour et ici de la liste
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
                            dateJ=nJ;//permet de saisir en char*
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

            case '9' : //vider la mémoire : on aurait pu faire une fonction mais ici pas d'interet particulier
                {
                	if (ma_chaine_de_blocs!=NULL){
		                libererEspace(ma_chaine_de_blocs);
		                printf("Tous les blocs sont supprimes.\n");
		                printf("\n======== PROGRAMME TERMINE ========\n");
		            }
		            else {
		            printf("Il n'y a aucun bloc a supprimer.\n");
		                printf("\n======== PROGRAMME TERMINE ========\n");
		            }
		            
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
