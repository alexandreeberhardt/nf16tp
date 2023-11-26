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
    printf("\n000000000\n");
    T_Element*pred=malloc(sizeof(T_Element));
    T_Element*la_liste=malloc(sizeof(T_Element));
    if(pred==NULL && la_liste==NULL)return NULL;
    la_liste = liste;
    if (liste==NULL){
        printf("\nLa liste est vide\n");
        pred=0;
        return 0;
    }else {
        printf("\n11111111\n");
        while(la_liste!=NULL && la_liste->code_uv!=code)
        {
            pred=la_liste;
            printf("\n%s JJJJJ\n",la_liste->code_uv);
            la_liste=la_liste->suivant;
            printf("\nMMMMMMMM\n");

        }
        printf("PFFF\n");
    }



    printf("\n%sAAAA\n",liste->code_uv);
    return liste;
}

T_Element*pred(T_Element *liste, char*code)
{
    printf("\n PPPPP\n");
    T_Element*y=malloc(sizeof(T_Element));
    if(y==NULL)return 0;

    if (liste->code_uv==code)
    {
        printf("\n QQQQQ\n");
        return NULL;
    }else{
        y=liste;
        printf("\n DDDDD\n");
        while(y->suivant!=NULL && y->suivant->code_uv!=code)
        {
            printf("\n SSSSSS\n");
            y=y->suivant;
        }
        return y;
    }
}

T_Element *ajouterInscription(T_Element *liste, char* code){
    printf("\nLLLLLLLLLLL");
	T_Element* nouveauE = malloc(sizeof(T_Element));
	T_Element* newInscription = malloc(sizeof(T_Element));
	T_Element* tmp = malloc(sizeof(T_Element));
	T_Element* tmp2 = malloc(sizeof(T_Element));
	T_Element* teteL = malloc(sizeof(T_Element));
	if (tmp2==NULL && tmp==NULL && nouveauE==NULL && teteL==NULL && newInscription==NULL) return 0;
	teteL = liste;
	tmp2 = rechercherInscription(liste, code);
	printf("%s\n",tmp2->code_uv);
	nouveauE=liste;
	if (tmp2->code_uv==code && nouveauE!=NULL)//permet de verifier que le code n'est pas deja dans la liste
    {
        printf("L'UV est deja ajoutee dans la liste des UV suivies pour cet etudiant.\n");

    }else
    {
        if (strcmp(nouveauE->code_uv,code)>0)//a place en debut de liste par ordre alphabetique
        {
            printf("\n 1 tete de liste %s\n",teteL->code_uv);
            printf("\nZZZZZ\n");
            tmp=nouveauE->suivant;
            nouveauE->code_uv=code;
            nouveauE->suivant=tmp;
            teteL=nouveauE;
            printf("\n 2 tete de liste %s\n",teteL->code_uv);
        }else
        {
            printf("\nRRRR\n");
            while(strcmp(nouveauE->code_uv,code)<0 && nouveauE==0)
            {
                nouveauE=nouveauE->suivant;
            }
            printf("\n nouveau E%s\n",nouveauE->code_uv);
            tmp=nouveauE;
            printf("\n tmp  %s\n",tmp->code_uv);
            newInscription->code_uv=code;
            printf("\n EEEE  %s\n",newInscription->code_uv);
            //nouveauE->code_uv=code;
            //printf("\n EEEE  %s\n",nouveauE->code_uv);

            if(tmp->suivant==NULL)//a placer en fin de liste
            {
                printf("\n UUUU\n");
                tmp->suivant=newInscription;
                printf("\n tmp suivant  %s\n",tmp->suivant->code_uv);
                newInscription->suivant=NULL;
            }else{
                printf("\n YYYYY\n");
                tmp2 = tmp->suivant;
                tmp->suivant=newInscription;
                newInscription->suivant=tmp2;
            }

        }
    }
    printf("FINNN %s ",liste->code_uv);
    printf("FINNN %s ",liste->suivant->code_uv);
    return liste;

}


T_Arbre rechercherNoeud(T_Arbre abr, char *nom, char *prenom)
{
    int cmp, cmp2;
    T_Arbre N=malloc(sizeof(T_Arbre));
    if(N==NULL)return 0;

    N=abr;
    while(N!=NULL && N->nom==nom && N->prenom==prenom)
    {
        cmp = strcmp(N->nom, nom);
        cmp2 = strcmp(N->prenom, prenom);
        if((cmp > 0) || (cmp == 0 && cmp2>0))
        {
            N = N->filsDroit;
        }else if((cmp < 0) || (cmp == 0 && cmp2<0))
        {
            N = N->filsGauche;
        }
    }
            return N;
}

T_Arbre creerNoeud(char *nom, char *prenom, char *code)
{
    T_Noeud*nouvN=malloc(sizeof(T_Noeud));
    if (nouvN==NULL)return 0;
    nouvN->nom=nom;
    nouvN->prenom=prenom;
    nouvN->listeInscriptions=creerInscription(code);
    nouvN->filsGauche=NULL;
    nouvN->filsDroit=NULL;
    return nouvN;
}// creer cette fct  utiliser dans T_Arbre inscrire


T_Arbre inscrire(T_Arbre abr, char *nom, char *prenom, char *code){
	int cmp, cmp2;
	T_Arbre etudiant = malloc(sizeof(T_Arbre));
	T_Arbre pere = malloc(sizeof(T_Arbre));
	T_Arbre nouveauE = malloc(sizeof(T_Arbre));
	T_Element* nouveauI = malloc(sizeof(T_Element));
	if (nouveauE==NULL || etudiant==NULL || nouveauI==NULL || pere==NULL) return NULL;
	etudiant =rechercherNoeud(abr, nom, prenom);
	if (etudiant!=NULL)//l'etudiant existe, on lui ajoute l'inscription
    {
        nouveauI = ajouterInscription(etudiant->listeInscriptions, code);
        etudiant->listeInscriptions = nouveauI;
    }else{//il faut creer l'etudiant
        while(etudiant!=NULL)
        {
            pere = etudiant;
            cmp = strcmp(etudiant->nom, nom);
            cmp2 = strcmp(etudiant->prenom, prenom);
            if((cmp > 0) || (cmp == 0 && cmp2>0))
            {
                etudiant = etudiant->filsDroit;
            }else if((cmp < 0) || (cmp == 0 && cmp2<0))
            {
                etudiant = etudiant->filsGauche;
            }
        }
        if (pere==NULL)//arbre vide
        {
            nouveauE = creerNoeud(nom, prenom, code);
            nouveauI = ajouterInscription(nouveauE->listeInscriptions, code);
            nouveauE->listeInscriptions = nouveauI;
            abr = nouveauE;
        }else if((cmp > 0) || (cmp == 0 && cmp2>0))
            {
                nouveauE = creerNoeud(nom, prenom, code);
                nouveauI = ajouterInscription(nouveauE->listeInscriptions, code);
                nouveauE->listeInscriptions = nouveauI;
                etudiant->filsDroit= nouveauE;
            }else if((cmp < 0) || (cmp == 0 && cmp2<0))
            {
                nouveauE = creerNoeud(nom, prenom, code);
                nouveauI = ajouterInscription(nouveauE->listeInscriptions, code);
                nouveauE->listeInscriptions = nouveauI;
                etudiant->filsGauche = nouveauE;
            }
    }
    return abr;
}


void afficherInscriptions(T_Arbre abr) {
    if (abr == NULL) {
 // si null on ne revoie rien
        return NULL;
    }

// appel recursif sur l'arbre gauche
    return afficherInscriptions(abr->filsGauche);

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
    return afficherInscriptions(abr->filsDroit);
}
void afficherInscriptionsUV(T_Arbre abr, char *code) {
    if (abr == NULL) {
        // Si l'arbre est vide, il n'y a rien à afficher.
        return;
    }

    // Appel récursif sur le sous-arbre gauche.
    afficherInscriptionsUV(abr->filsGauche, code);

    // Vérifier si l'étudiant est inscrit à l'UV spécifiée.
    T_Element *currentElement = abr->listeInscriptions;
    while (currentElement != NULL) {
        if (strcmp(currentElement->code_uv, code) == 0) {
            // Si l'étudiant est inscrit à cette UV, on peut faire l'affichage
            printf("%s %s est inscrit à l'UV %s\n", abr->nom, abr->prenom, code);
            break; // Pas besoin de vérifier les autres UVs vu qu'elles ne doivent être présentes qu'une seule fois chacunes
        }
        currentElement = currentElement->suivant;
    }

    // Appel récursif sur le sous-arbre droit.
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
