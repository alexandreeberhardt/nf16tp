#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Element {
char* code_uv;
struct Element* suivant;
}T_Element;


typedef struct Noeud {
char* nom;
char* prenom;
T_Element* listeInscriptions;
struct Noeud* filsGauche;
struct Noeud* filsDroit;
}T_Noeud;


typedef T_Noeud* T_Arbre;

void afficherInscriptions(T_Arbre abr);
void afficherInscriptionsUV(T_Arbre abr, char *code);
