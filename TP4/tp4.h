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


void afficherInscriptionsUV(T_Arbre abr, char *code);
T_Element *ajouterInscription(T_Element *liste, char* code);
T_Arbre inscrire(T_Arbre abr, char *nom, char *prenom, char *code);
void afficherInscriptions(T_Arbre abr);
void strupr_(char* s);
void viderBuffer();

