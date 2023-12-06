#include<stdio.h>
#include<gtk/gtk.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
int jours;
int mois;
int an;
}Date;

typedef struct {
char id[20];
char medecin[50];
int salle;
char ets[50];
int crenau;
int etat;
Date dat;
} RDV;

typedef struct {
char id[20];
char nom[50];
char prenom[50];
char groupe[20];
char ets[20];
int jour;
int mois;
int annee;
char sexe[20];
char maladie_freq[100];
char risk[50];
}FicheDonneur;

void afficher(GtkWidget *liste);
int ajouter(FicheDonneur D, int gender,int choix[]);
int modifier_fiche(FicheDonneur D,char iden[20],int genre,int choice[]);
int supprimer(char identifiant [20]);
void chercher(char identifiant[20],GtkWidget *liste);
void vider(GtkWidget *liste);
//int listeRDV(char ETS[], int jour, int mois, int annee);
int nbETS();
float moyRDV (int jour, int mois, int annee,FILE *f);
int liste_rdv(char ETS[],int j, int m, int a);
void afficher_rdv(GtkWidget *liste);




