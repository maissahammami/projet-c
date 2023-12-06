#ifndef ETS_H_INCLUDED
#define ETS_H_INCLUDED
#include <gtk/gtk.h>

typedef struct {
    char id[20];
    char name[50];
    char capacity[20];
    char region[20];
} EST;

int addEstablishment(EST est, const char *filename);
int modifyEstablishment(const char *id, EST modifiedEST, const char *filename);
int removeEstablishment(const char *id, const char *filename);
EST findEstablishment(const char *id, const char *filename);
int ETSParRegion(char nomFichier[], char reg[]);
void ETSTrierCapacite(char nomFichier[]);
void afficherEtablissements(GtkWidget *liste);
void afficherEtablissementsapressupp(GtkWidget *liste);
void regcap(int capacite,int region, char msg[]);


#endif // ETS_H_INCLUDED
