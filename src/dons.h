#include <gtk/gtk.h>

typedef struct
{ 
    char id[20];
    char cin[20];
    char idetablissement[20];
    int  jour;
    char mois[20];
    int  annee;
    char type[30];
}don;

void ajouter_don(don b,char *dons);
void afficher_don(GtkWidget *liste);
void modifier_don(char id[],don b1,char *dons);
void supprimer_don(char cin[],char *dons);
int rechercher_don(char id[]);
void afficher_rechercher_don(GtkWidget *liste);
int remplirtabRech (don tab[],int nb) ;
