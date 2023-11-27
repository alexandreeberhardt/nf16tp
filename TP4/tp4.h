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
T_Arbre inscrire(T_Arbre abr, char *nomx, char *prenomx, char *codex);
void afficherInscriptions(T_Arbre abr);
void afficherInscriptionsUV(T_Arbre abr, char *code);
char* strupr_(char* s);
void viderBuffer();
T_Arbre lireFichier(T_Arbre abr, char *nomFichier);
T_Element*pred(T_Element *liste, char*code);
T_Element *rechercherInscription(T_Element *liste, char* code);
T_Element * creerInscription(char* code);
T_Arbre rechercherNoeud(T_Arbre abr, char *nom, char *prenom);
T_Arbre creerNoeud(char *nom, char *prenom, char *code);
void SupprimerTout(T_Arbre abr);
void libererListeInscriptions(T_Element* liste);
