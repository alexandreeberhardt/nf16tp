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
    T_Element*pred=malloc(sizeof(T_Element));
    T_Element*la_liste=malloc(sizeof(T_Element));
    if(pred==NULL && la_liste==NULL)return NULL;
    la_liste = liste;
    if (liste->code_uv==NULL){
        printf("\nLa liste est vide\n");
        pred=0;
        return 0;
    }else {
        while(la_liste!=NULL && strcmp(la_liste->code_uv,code)!=0)
        {
            pred=la_liste;
            la_liste=la_liste->suivant;
        }
    }
    return la_liste;
}

T_Element*pred(T_Element *liste, char*code)
{
    T_Element*y=malloc(sizeof(T_Element));
    if(y==NULL)return 0;

    if (liste->code_uv==code)
    {
        return NULL;
    }else{
        y=liste;
        while(y->suivant!=NULL && strcmp(y->suivant->code_uv,code)!=0)
        {
            y=y->suivant;
        }
        return y;
    }
}

T_Element *ajouterInscription(T_Element *liste, char* code){
	T_Element* nouveauE = malloc(sizeof(T_Element));
	T_Element* newInscription = malloc(sizeof(T_Element));
	T_Element* tmp = malloc(sizeof(T_Element));
	T_Element* tmp2 = malloc(sizeof(T_Element));
	T_Element* teteL = malloc(sizeof(T_Element));
	if (tmp2==NULL && tmp==NULL && nouveauE==NULL && teteL==NULL && newInscription==NULL) return 0;
	teteL = liste;
	tmp2 = rechercherInscription(liste, code);
	nouveauE=liste;
	if (liste!=NULL)
    {
        if (tmp2!=NULL && strcmp(tmp2->code_uv,code)==0){
        //permet de verifier que le code n'est pas deja dans la liste

            printf("L'UV est deja ajoutee dans la liste des UV suivies pour cet etudiant.\n");
        }else{
            if (strcmp(nouveauE->code_uv,code)>0)//a place en debut de liste par ordre alphabetique
            {
                tmp=nouveauE;
                newInscription->code_uv=code;
                newInscription->suivant=tmp;
                liste=newInscription;
            }else{
                while(strcmp(nouveauE->code_uv,code)<0 && nouveauE->suivant!=NULL)
                {
                    tmp=nouveauE;
                    nouveauE=nouveauE->suivant;
                }
                newInscription->code_uv=code;
                if((nouveauE->suivant==NULL)&& (strcmp(nouveauE->code_uv,code)<0))//a placer en fin de liste
                {
                    nouveauE->suivant=newInscription;
                    newInscription->suivant=NULL;
                }else{
                    tmp2 = tmp->suivant;
                    tmp->suivant=newInscription;
                    newInscription->suivant=tmp2;
                }
            }
        }
    }else{//place dans la liste vide
        newInscription->code_uv=code;
        newInscription->suivant=NULL;
        liste=newInscription;
    }
    return liste;
}


T_Arbre rechercherNoeud(T_Arbre abr, char *nom, char *prenom)
{
    int cmp, cmp2;
    T_Arbre N=malloc(sizeof(T_Arbre));
    if(N==NULL)return 0;
    N=abr;
    while((N!=NULL && strcmp(N->nom,nom)!=0) || (N!=NULL && strcmp(N->prenom, prenom)!=0))
    {
        cmp = strcmp(N->nom, nom);
        cmp2 = strcmp(N->prenom, prenom);
        if((cmp > 0)||(cmp == 0 && cmp2>0))
            {
            N = N->filsGauche;
            }else if((cmp < 0)||(cmp == 0 && cmp2<0))
                {
                N = N->filsDroit;
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
}


T_Arbre inscrire(T_Arbre abr, char *nomx, char *prenomx, char *codex){

    char * nom = strdup( nomx );
    char * prenom = strdup( prenomx );
    char * code = strdup( codex );

	int cmp, cmp2;
	T_Arbre etudiant = malloc(sizeof(T_Arbre));
	T_Arbre tmp = malloc(sizeof(T_Arbre));
	T_Arbre pere = malloc(sizeof(T_Arbre));
	T_Arbre nouveauE = malloc(sizeof(T_Arbre));
	T_Element* nouveauI = malloc(sizeof(T_Element));
	if (nouveauE==NULL && etudiant==NULL && nouveauI==NULL && pere==NULL && tmp==NULL) return NULL;
	etudiant =rechercherNoeud(abr, nom, prenom);
	if (etudiant!=NULL)//l'etudiant existe, on lui ajoute l'inscription
    {
        nouveauI = ajouterInscription(etudiant->listeInscriptions, code);
        etudiant->listeInscriptions = nouveauI;
    }else{//il faut creer l'etudiant
        tmp = abr;
        while(tmp !=NULL)
        {
            pere = tmp;
            cmp = strcmp(tmp->nom, nom);
            cmp2 = strcmp(tmp->prenom, prenom);
            if((cmp < 0) || (cmp == 0 && cmp2<0))
            {
                tmp = tmp->filsDroit;
            }else if((cmp > 0) || (cmp == 0 && cmp2>0))
            {
                tmp = tmp->filsGauche;
            }

        }
        if (abr==NULL)//arbre vide
        {
            nouveauE = creerNoeud(nom, prenom, code);
            abr = nouveauE;
        }else
        {
            cmp = strcmp(pere->nom, nom);
            cmp2 = strcmp(pere->prenom, prenom);
            if((cmp < 0) || (cmp == 0 && cmp2<0))
            {
                nouveauE = creerNoeud(nom, prenom, code);
                pere->filsDroit= nouveauE;
            }else if((cmp > 0) || (cmp == 0 && cmp2>0))
            {
                nouveauE = creerNoeud(nom, prenom, code);
                pere->filsGauche = nouveauE;
            }
        }
    }
    return abr;
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


T_Arbre chargerFichier(T_Arbre abr, char *nomFichier) {

    FILE *fichier = fopen(nomFichier, "r");
    char ligne[100];
    char *nom, *prenom, *code_uv;

    if (fichier == NULL) {
        printf("le fichier n'a pas été trouvé");
        return abr;
    }

    while (fgets(ligne, sizeof(ligne), fichier)) {
        nom = strtok(ligne, ";");
        prenom = strtok(NULL, ";");
        code_uv = strtok(NULL, "\n");
        strupr_(nom);
        strupr_(prenom);
        strupr_(code_uv);
        printf("%s %s %s\n",nom,prenom,code_uv);
        if (nom && prenom && code_uv) {
            abr = inscrire(abr, nom, prenom, code_uv);
        }
    }

    fclose(fichier);
    return abr;
}

char* strupr_(char* s){//permet de mettre en maj
    while(*s != '\0'){
        if(*s >= 'a' && *s <= 'z'){
            *s += 'A' - 'a';
        }
        ++s;
    }
    return s;
}

void libererListeInscriptions(T_Element* liste) {
    T_Element *actuel, *suivant;

    actuel = liste;
    while (actuel != NULL) {
        suivant = actuel->suivant;
        free(actuel->code_uv);
        free(actuel);
        actuel = suivant;
    }
}
void SupprimerTout(T_Arbre abr) {
    if (abr == NULL) {
        return;
    }

    SupprimerTout(abr->filsGauche); // Libre la sous-arbre gauche
    SupprimerTout(abr->filsDroit); // Libre la sous-arbre droit

    libererListeInscriptions(abr->listeInscriptions);
    free(abr->nom);
    free(abr->prenom);
    free(abr);
}


T_Element* supprimerElementListe(T_Element* liste, char* code) {
    T_Element *current = liste,
    *prev = NULL;
    while (current != NULL) {
        if (strcmp(current->code_uv, code) == 0) {
            if (prev == NULL) {
                liste = current->suivant;
            } else {
                prev->suivant = current->suivant;
            }
            free(current->code_uv);
            free(current);
            //on libère la mémoire du code puis du noeud supprimé

            return liste;
        }
        prev = current;
        current = current->suivant;
        //sinon on continue le parcours
    }
    printf("L'eleve n'est pas inscrit a %s",code);
    return liste;
}


T_Arbre trouverMinimum(T_Arbre abr) {
    while (abr->filsGauche != NULL)
        abr = abr->filsGauche;
    return abr;
}

T_Arbre supprimerNoeud(T_Arbre abr, char *nom, char *prenom) {
    if (abr == NULL) return NULL;

    // Recherche du nœud à supprimer
    if (strcmp(nom, abr->nom) < 0 || (strcmp(nom, abr->nom) == 0 && strcmp(prenom, abr->prenom) < 0)) {
        abr->filsGauche = supprimerNoeud(abr->filsGauche, nom, prenom);
    } else if (strcmp(nom, abr->nom) > 0 || (strcmp(nom, abr->nom) == 0 && strcmp(prenom, abr->prenom) > 0)) {
        abr->filsDroit = supprimerNoeud(abr->filsDroit, nom, prenom);
    } else {
        // Trouvé le nœud à supprimer
        // Nœud avec un seul fils ou sans fils
        if (abr->filsGauche == NULL) {
            T_Arbre temp = abr->filsDroit;
            free(abr->nom);
            free(abr->prenom);

            free(abr);
            return temp;
        } else if (abr->filsDroit == NULL) {
            T_Arbre temp = abr->filsGauche;
            free(abr->nom);
            free(abr->prenom);
            free(abr);
            return temp;
        }

        // Nœud avec deux fils
        T_Arbre temp = trouverMinimum(abr->filsDroit);
        free(abr->nom);
        free(abr->prenom);
        abr->nom = strdup(temp->nom); // Copie le nom du successeur
        abr->prenom = strdup(temp->prenom);// Copie le prénom du successeur
        abr->listeInscriptions = temp->listeInscriptions;
        abr->filsDroit = supprimerNoeud(abr->filsDroit, temp->nom, temp->prenom);
    }
    return abr;
}


T_Arbre supprimerInscription(T_Arbre abr, char *nom, char *prenom, char *code) {
    T_Arbre node = rechercherNoeud(abr, nom, prenom);
    if (node == NULL) {    printf("%s %s n'est pas dans l'arbre",nom,prenom);

 return abr;} // L'étudiant n'est pas trouvé

    node->listeInscriptions = supprimerElementListe(node->listeInscriptions, code);

    // Si l'étudiant n'a plus d'inscriptions, supprimer le nœud
    if (node->listeInscriptions == NULL) {
        abr = supprimerNoeud(abr, nom, prenom);
    }

    return abr;
}

void viderBuffer() {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}
