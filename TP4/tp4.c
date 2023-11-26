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


T_Element *rechercherInscription(T_Element *liste, char* code){
    T_Element*pred=malloc(sizeof(T_Element));
    if(pred==NULL)return NULL;
    if (liste==NULL){
        pred=0;
    }else {
        while(liste->code_uv!=code || liste!=NULL)
        {
            pred=liste;
            liste=liste->suivant;
        }
    }
    return liste;
}

T_Element*pred(T_Element *liste, char*code)
{
    T_Element*y=malloc(sizeof(T_Element));
    if(y==NULL)return 0;
    if (code==liste->code_uv)
    {
        return NULL;
    }else{
        y=liste;
        while(y->suivant->code_uv!=code)
        {
            y=y->suivant;
        }
        return y;
    }
}

T_Element *ajouterInscription(T_Element *liste, char* code){
	T_Element* nouveauE = malloc(sizeof(T_Element));
	T_Element* tmp = malloc(sizeof(T_Element));
	T_Element* recherche = malloc(sizeof(T_Element));
	if (recherche==NULL || tmp==NULL || nouveauE==NULL) return 0;
	recherche = rechercherInscription(liste, code);
	nouveauE=liste;
	if (recherche!=NULL && nouveauE!=NULL)//permet de verifier que le code n'est pas deja dans la liste
    {
        printf("L'UV est deja ajoutee dans la liste des UV suivies pour cet etudiant.\n");
        return 0;
    }else
    {   if (strcmp(nouveauE->code_uv,code)<0)//a place en debut de liste par ordre alphabetique
        {
            tmp=nouveauE->suivant;
            nouveauE->code_uv=code;
            nouveauE->suivant=tmp;
            liste=nouveauE;
        }else
        {

            while(strcmp(nouveauE->code_uv,code)>0 || nouveauE==0)
            {
                nouveauE=nouveauE->suivant;
            }
            nouveauE->code_uv=code;
            recherche = pred(liste, code);
            if (recherche->suivant!=0)//a placer au milieu de la liste
            {
                tmp=recherche->suivant;
                recherche->suivant=nouveauE;
                nouveauE->suivant=tmp;
            }else if(recherche->suivant==0)//a placer en fin de liste
            {
                recherche->suivant=nouveauE;
                nouveauE->suivant=NULL;
            }
        }
    }
    return liste;

}

T_Arbre rechercherNoeud(T_Arbre abr, char *nom, char *prenom)
{
    int cmp, cmp2;
    T_Noeud*N=malloc(sizeof(T_Noeud));
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


/////////////////////////////////////////
T_Arbre inscrire(T_Arbre abr, char *nom, char *prenom, char *code){
	T_Arbre etudiant = malloc(sizeof(T_Arbre));
	T_Arbre nouveauE = malloc(sizeof(T_Arbre));
	T_Element* nouveauI = malloc(sizeof(T_Element));
	if (nouveauE==NULL || etudiant==NULL || nouveauI==NULL) return NULL;
	etudiant =rechercherNoeud(abr, nom, prenom);
	if (etudiant!=NULL)//l'etudiant existe, on lui ajoute l'inscription
    {
        nouveauI = ajouterInscription(etudiant->listeInscriptions, code);
    }else{//il faut creer l'etudiant

    }

    nouveauE = creerNoeud(nom, prenom, code);
	if (abr->nom==NULL&&abr->prenom==NULL){
		abr->nom=nom;
		abr->prenom=prenom;
		abr->listeInscriptions = ajouterInscription(abr->listeInscriptions, code);
	}
	else if (abr->nom==nom&&abr->prenom==prenom){
		abr->listeInscriptions = ajouterInscription( abr->listeInscriptions, code);
	}
		else if (strcmp(strcat(strcat(abr->nom," "),abr->prenom),strcat(strcat(nom," "),prenom))>0){// le noeud est plus grand
			if (abr->filsGauche==NULL){
				T_Arbre nouveau = malloc(sizeof(T_Arbre));
				nouveau->nom = nom;
				nouveau->prenom = prenom;
				nouveau->listeInscriptions = ajouterInscription(nouveau->listeInscriptions, code);
				nouveau->filsGauche=NULL;
				nouveau->filsDroit=NULL;
			}
			else {
				inscrire(abr->filsGauche, nom, prenom, code);
			}
		}
				else {
				if (abr->filsDroit==NULL){
					T_Arbre nouveau = malloc(sizeof(T_Arbre));
					nouveau->nom = nom;
					nouveau->prenom = prenom;
					nouveau->listeInscriptions = ajouterInscription(nouveau->listeInscriptions, code);
					nouveau->filsGauche=NULL;
					nouveau->filsDroit=NULL;
				}
				else {
					inscrire(abr->filsDroit, nom, prenom, code);
				}
			}
    return abr;
}
/////////////////////////////////////////


void afficherInscriptions(T_Arbre abr){
	if (abr->nom!=NULL&&abr->prenom!=NULL){
		if (abr->filsGauche){
			afficherInscriptions(abr->filsGauche);
		}
		else {
			printf(", ");
			}
		printf("%s %s :",abr->nom,abr->prenom);
		printf("%s ",abr->listeInscriptions->code_uv);
		T_Element* ptr = abr->listeInscriptions;
		while (ptr->suivant!=NULL){
			printf("%s ",ptr->code_uv);
			ptr=ptr->suivant;
		}
		printf("\n");
		if (abr->filsDroit){
			printf(", ");
			afficherInscriptions(abr->filsDroit);
		}

	}

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

void supprimerListe(T_Element *c){
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
}

// Vider le buffer (utile quand on utlise des getchar() )
void viderBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}
