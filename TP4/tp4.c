#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp4.h"

T_Element * creerInscription(char* code)//Initialise une inscription  une UV
{
    T_Element*nouvIns=malloc(sizeof(T_Element));
    if (nouvIns==NULL)return 0;
    nouvIns->code_uv=code;
    nouvIns->suivant=NULL;
    return nouvIns;
}


T_Element * rechercherInscription(T_Element *liste, char* code){
    //printf("\n000000000\n");
    T_Element*pred=malloc(sizeof(T_Element));
    T_Element*la_liste=malloc(sizeof(T_Element));
    if(pred==NULL && la_liste==NULL)return NULL;
    la_liste = liste;
    if (liste==NULL){
        printf("\nLa liste est vide\n");
        pred=0;
        return 0;
    }else {
        //printf("\n11111111\n");
        while(la_liste!=NULL && strcmp(la_liste->code_uv,code))
        {
            pred=la_liste;
            //printf("\n%s JJJJJ\n",la_liste->code_uv);
            la_liste=la_liste->suivant;
            //printf("\nMMMMMMMM\n");

        }
        //printf("PFFF\n");
    }



    //printf("\n%sAAAA\n",liste->code_uv);
    return liste;
}

T_Element*pred(T_Element *liste, char*code){
    //printf("\n PPPPP\n");
    T_Element*y=malloc(sizeof(T_Element));
    if(y==NULL)return 0;

    if (liste->code_uv==code)
    {
        //printf("\n QQQQQ\n");
        return NULL;
    }else{
        y=liste;
        //printf("\n DDDDD\n");
        while(y->suivant!=NULL && y->suivant->code_uv!=code)
        {
            //printf("\n SSSSSS\n");
            y=y->suivant;
        }
        return y;
    }
}

T_Element *ajouterInscription(T_Element *liste, char* code) {
    // Créer le nouvel élément
    T_Element *nouveau = malloc(sizeof(T_Element));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        return liste;
    }
    nouveau->code_uv = strdup(code); // Dupliquer le code
    nouveau->suivant = NULL;

    // Si la liste est vide, insérer le nouvel élément en tête
    if (liste == NULL) {
        return nouveau;
    }

    // Sinon, parcourir la liste jusqu'à la fin et insérer le nouvel élément
    T_Element *temp = liste;
    while (temp->suivant != NULL) {
        temp = temp->suivant;
    }
    temp->suivant = nouveau;

    return liste;
}

T_Arbre rechercherNoeud(T_Arbre abr, char *nom, char *prenom){
    int cmp, cmp2;
    T_Arbre N=malloc(sizeof(T_Arbre));
    if(N==NULL)return 0;

    N=abr;
    while(N!=NULL && strcmp(N->nom,nom)!=0 && strcmp(N->prenom, prenom))
    {

        cmp = strcmp(N->nom, nom);
        cmp2 = strcmp(N->prenom, prenom);
        if((cmp > 0) || (cmp == 0 && cmp2>0))
        {
            //printf("\n 111111\n");
            N = N->filsDroit;
        }else if((cmp < 0)|| (cmp == 0 && cmp2<0))
        {
            //printf("\n 22222\n");
            N = N->filsGauche;
        }
        //printf("\n 333333\n");
    }

        //printf("\n 444444\n");
    return N;
}

T_Arbre creerNoeud(char *nom, char *prenom, char *code){
    T_Noeud*nouvN=malloc(sizeof(T_Noeud));
    if (nouvN==NULL)return 0;
    nouvN->nom=nom;
    nouvN->prenom=prenom;
    nouvN->listeInscriptions=creerInscription(code);
    nouvN->filsGauche=NULL;
    nouvN->filsDroit=NULL;
    return nouvN;
}// creer cette fct  utiliser dans T_Arbre inscrire

T_Arbre inscrire(T_Arbre abr, char *nom, char *prenom, char *code) {
    // Rechercher l'emplacement où insérer le nouveau nœud
    if (abr == NULL) {
        // Si l'emplacement est vide, créer un nouveau nœud avec des copies des chaînes
        return creerNoeud(strdup(nom), strdup(prenom), strdup(code));
    } else {
        // Comparaison pour décider où aller (gauche ou droite dans l'arbre)
        int comp = strcmp(nom, abr->nom);
        if (comp < 0) {
            // Insérer à gauche
            abr->filsGauche = inscrire(abr->filsGauche, nom, prenom, code);
        } else if (comp > 0) {
            // Insérer à droite
            abr->filsDroit = inscrire(abr->filsDroit, nom, prenom, code);
        } else {
            // Même nom, vérifier le prénom
            int compPrenom = strcmp(prenom, abr->prenom);
            if (compPrenom == 0) {
                // Même nom et prénom, ajouter l'UV à la liste des inscriptions
                abr->listeInscriptions = ajouterInscription(abr->listeInscriptions, code);
            } else if (compPrenom < 0) {
                abr->filsGauche = inscrire(abr->filsGauche, nom, prenom, code);
            } else {
                abr->filsDroit = inscrire(abr->filsDroit, nom, prenom, code);
            }
        }
        return abr;
    }
}

void afficherInscriptions(T_Arbre abr) {
    if (abr == NULL) {
 // si null on ne revoie rien
        return;
    }

// appel recursif sur l'arbre gauche
    afficherInscriptions(abr->filsGauche);

//affichage normal
    printf(" %s %s: ", abr->nom, abr->prenom);
    T_Element *currentElement = abr->listeInscriptions;
    if (currentElement == NULL) {
        printf("pas d'inscription.\n"); // ce n'est pas suppos arriver
    } else {
        while (currentElement != NULL) {
            printf("%s ", currentElement->code_uv);
            currentElement = currentElement->suivant;
        }
        printf("\n");
    }

// appel  rcursif sur l'arbre droit
    afficherInscriptions(abr->filsDroit);
}

void afficherInscriptionsUV(T_Arbre abr, char *code) {
    if (abr == NULL) {
        // Si l'arbre est vide, il n'y a rien  afficher.
        return;
    }

    // Appel rcursif sur le sous-arbre gauche.
    afficherInscriptionsUV(abr->filsGauche, code);

    // Vrifier si l'tudiant est inscrit  l'UV spcifie.
    T_Element *currentElement = abr->listeInscriptions;
    while (currentElement != NULL) {
        if (strcmp(currentElement->code_uv, code) == 0) {
            // Si l'tudiant est inscrit  cette UV, on peut faire l'affichage
            printf("%s %s est inscrit  l'UV %s\n", abr->nom, abr->prenom, code);
            break; // Pas besoin de vrifier les autres UVs vu qu'elles ne doivent tre prsentes qu'une seule fois chacunes
        }
        currentElement = currentElement->suivant;
    }

    // Appel rcursif sur le sous-arbre droit.
    afficherInscriptionsUV(abr->filsDroit, code);
}

void lireFichier(T_Arbre abr, char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    char ligne[100];
    char *nom, *prenom, *code_uv;

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(1);
    }

    while (fgets(ligne, sizeof(ligne), fichier)) {
        nom = strtok(ligne, ";");
        prenom = strtok(NULL, ";");
        code_uv = strtok(NULL, "\n");

        if (nom && prenom && code_uv) {
            abr = inscrire(abr, nom, prenom, code_uv);
        }
    }

    fclose(fichier);
}


/*Car_Fichier(char* filename){ // affiche le caractre lu du fichier
    char chaine_fichier;
    if (filename==";"||filename==" "||filename=="\n"){
        return 0;
    }
    else {
        *//*return chaine_fichier = {'filename', 'Car_Fichier(filename->suivant)'};
    }
}*/

void strupr_(char* s){//permet de mettre en maj
    while(*s != '\0'){
        if(*s >= 'a' && *s <= 'z'){
            *s += 'A' - 'a';
        }
        ++s;
    }
}

/*T_Arbre chargerFichier(T_Arbre abr, char *filename){
    T_Arbre racine_abr=malloc(sizeof(T_Arbre));
    racine_abr=abr;
    char*NOM;
    char*PRENOM;
    char*CODE_UV;
    while(filename!="\n"){
        while(filename !=";"){
            NOM=+filemane;
        }
    }
    //se spare par les "; " et les "\n"
    //1ere chose : lire la premiere ligne
    if (*filename!="\n"){

        //ici faire appel  une fonction qui extrait les nom prenom et de la ligne !
        //puis suivre du fait d'inscrire l'tudiant

        if (*filemane != ";"){
            if (*filename != " "){
                Nom = Car_Fichier //plutot utiliser tant que/ while
            }

        }
    }//fin du fichier  = \0
    //Parcourir le fichier texte jusqu' la ligne suivante

    //Faire appel  l'inscription d'un tudiant  une UV : conf choix 1 du main


    return racine_abr;
}*/

/*void afficherInscriptionsUV(T_Arbre abr,char*code)
{

}*/

/*void supprimerListe(T_Element *c){
    T_Element *tmp = c;
    while(tmp){
        c = c->suivant;
        free(tmp);
        tmp = c;
    }
}

void freeNoeud(T_Noeud *p){
    free(p->nom);
    free(p->prenom);
    supprimerListe(p->listeInscriptions);
    free(p);
}

void supprimer_Noeud(T_Arbre* abr, char* nom, char* prenom){
    T_Noeud **p = rechercherNoeud(abr, nom, prenom); //p points to [the case pointing the node to delete]
    T_Noeud *tmp = *p; //tmp points to [the node to delete]
    if(!*p){
        printf("Etudiant introuve.\n");
        return;
    }
    else if(!(*p)->filsGauche && !(*p)->filsDroit){ //00
        // printf("00");
        *p = 0;
    }
    else if(!(*p)->filsGauche){ //01
        // printf("01");
        *p = (*p)->filsDroit;
    }
    else if(!(*p)->filsDroit){ //10
        // printf("10");
        *p = (*p)->filsGauche;
    }
    // 11
    else if(!tmp->filsGauche->filsDroit){
        tmp->filsGauche->filsDroit = tmp->filsDroit;
        *p = tmp->filsGauche;
    }
    else{
        T_Noeud **p2 = &tmp->filsGauche; //p2 points to [the case pointing the node to replace]
        while((*p2)->filsDroit) p2 = &(*p2)->filsDroit;
        *p = *p2;
        *p2 = (*p2)->filsGauche;
        (*p2)->filsGauche = tmp->filsGauche;
        (*p2)->filsDroit = tmp->filsDroit;
    }
    freeNoeud(tmp);
    printf("Etudiant supprime.\n");
    return;
}

T_Arbre supprimerInscription(T_Arbre abr, char*nom, char*prenom, char*code)
{
    T_Element * inscrip=malloc(sizeof(T_Element));
    if (inscrip==NULL) return 0;
    T_Element * tmpi=malloc(sizeof(T_Element));
    if (tmpi==NULL) return 0;
    T_Noeud *etudiant=malloc(sizeof(T_Noeud));
    etudiant=rechercherNoeud(abr, nom, prenom);
    inscrip=rechercherInscription(etudiant,code);
    tmpi = pred(etudiant,code);
    if (inscrip==NULL)
    {
        printf("Il n'y a pas d'inscription a cette UV pour cet etudiant.\n");
        return 0;
    }else{
        if (tmpi==NULL && inscrip->suivant==NULL)
        {
            printf("C'est la seule inscription de l'Etudiant.\n");
            supprimerNoeud(abr, nom);
        }else //la liste d'uv ne sera pas nulle apres la suppression de l'inscription
        {
            if(tmpi==NULL)
            {
                etudiant=inscrip->suivant;
                free(inscrip);
            }else
            {
                tmpi->suivant=inscrip->suivant;
                free(inscrip);
            }
        }
    }
    return abr;
}*/

// Vider le buffer (utile quand on utlise des getchar() )
void viderBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}
