#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp4.h"


T_Element *ajouterInscription(T_Element *liste, char* code){
    if (strcmp(liste->code_uv,code)==0){;}//l'UV est d�j� ajout�e
    else if (strcmp(liste->code_uv,code)>0){
        T_Element* nouveau;//malloc
        nouveau->code_uv=code;
        nouveau->suivant=liste;
        liste=nouveau;
    }
        else if (liste->suivant==NULL&&strcmp(liste->code_uv,code)<0){ // double verification pas n�cessaire mais on s�curise
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

Car_Fichier(char* filename){ // affiche le caract�re lu du fichier
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
    //se s�pare par les "; " et les "\n"
    //1ere chose : lire la premiere ligne
    if (*filename!="\n"){

        //ici faire appel � une fonction qui extrait les nom prenom et de la ligne !
        //puis suivre du fait d'inscrire l'�tudiant

        if (*filemane != ";"){
            if (*filename != " "){
                Nom = Car_Fichier //plutot utiliser tant que/ while
            }

        }
    }//fin du fichier  = \0
    //Parcourir le fichier texte jusqu'� la ligne suivante

    //Faire appel � l'inscription d'un �tudiant � une UV : conf choix 1 du main


    return racine_abr;
}
