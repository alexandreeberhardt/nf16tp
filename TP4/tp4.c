#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp4.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp4.h"



T_Element *ajouterInscription(T_Element *liste, char* code){
	if (liste->code_uv==NULL){
		liste->code_uv=code;
		liste->suivant=NULL;
		}
	else if (strcmp(liste->code_uv,code) == 0){;} //l'UV est déjà ajoutée	
		
		else if (strcmp(liste->code_uv,code)>0){
				T_Element* nouveau = malloc(sizeof(T_Element));
				nouveau->code_uv = code;
				nouveau->suivant = liste;
				liste = nouveau;
		 	}
			
			else if (liste->suivant==NULL&&strcmp(liste->code_uv,code)<0){ // double verification pas nécessaire mais on sécurise
				T_Element* nouveau = malloc(sizeof(T_Element));
				nouveau->code_uv = code;
				nouveau->suivant = NULL;
				liste->suivant = nouveau;
			}
			
				else {
					ajouterInscription(liste->suivant,code); //T_Element nimp =
				}
				
		return liste;		
}


T_Arbre inscrire(T_Arbre abr, char *nom, char *prenom, char *code){
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
		
}

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




T_Element *ajouterInscription(T_Element *liste, char* code){
    if (strcmp(liste->code_uv,code)==0){;}//l'UV est déjà ajoutée
    else if (strcmp(liste->code_uv,code)>0){
        T_Element* nouveau;//malloc
        nouveau->code_uv=code;
        nouveau->suivant=liste;
        liste=nouveau;
    }
        else if (liste->suivant==NULL&&strcmp(liste->code_uv,code)<0){ // double verification pas nécessaire mais on sécurise
            T_Element* nouveau;//malloc
            nouveau->code_uv=code;
            nouveau->suivant=NULL;
            liste->suivant=nouveau;
        }
            else {
                ajouterInscription(liste->suivant,code);
            }
    return liste;
}

Car_Fichier(char* filename){ // affiche le caractère lu du fichier
    char chaine_fichier;
    if (filename==";"||filename==" "||filename=="\n"){
        return 0;
    }
    else {
        /*return chaine_fichier = {'filename', 'Car_Fichier(filename->suivant)'};*/
    }
}

void strupr_(char* s){//permet de mettre en maj
    while(*s != '\0'){
        if(*s >= 'a' && *s <= 'z'){
            *s += 'A' - 'a';
        }
        ++s;
    }
}

T_Arbre chargerFichier(T_Arbre abr, char *filename){
    T_Arbre racine_abr=malloc(sizeof(T_Arbre));
    racine_abr=abr;
    char*NOM;
    char*PRENOM;
    char*CODE_UV;
    while(*filename!="\n"){
        while(*filename !=";"){
            NOM=+*filemane;
        }
    }
    //se sépare par les "; " et les "\n"
    //1ere chose : lire la premiere ligne
    if (*filename!="\n"){

        //ici faire appel à une fonction qui extrait les nom prenom et de la ligne !
        //puis suivre du fait d'inscrire l'étudiant

        if (*filemane != ";"){
            if (*filename != " "){
                Nom = Car_Fichier //plutot utiliser tant que/ while
            }

        }
    }//fin du fichier  = \0
    //Parcourir le fichier texte jusqu'à la ligne suivante

    //Faire appel à l'inscription d'un étudiant à une UV : conf choix 1 du main


    return racine_abr;
}
