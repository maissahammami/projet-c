#include"fiche.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>
enum 
{
EIDENTIFIANT,
ENOM,
EPRENOM,
EGROUPE,
EETS,
EJOUR,
EMOIS,
EANNEE,
ESEXE,
EMALD,
ERISK,
COLUMNS
};


void afficher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
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
store=NULL;
FILE *f;
FicheDonneur D;
store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
if(store==NULL)
{

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Groupe",renderer,"text",EGROUPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Ets",renderer,"text",EETS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Maladie",renderer,"text",EMALD,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Risques",renderer,"text",ERISK,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("fiche.txt","r");
if(f==NULL)
{
return;
}
else 
{
f=fopen("fiche.txt","a+");
while(fscanf(f,"%s  %s  %s  %s  %s  %d  %d  %d  %s  %s  %s\n",id,nom,prenom,groupe,ets,&jour,&mois,&annee,sexe,maladie_freq,risk)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EIDENTIFIANT,id,ENOM,nom,EPRENOM,prenom,EGROUPE,groupe,EETS,ets,EJOUR,jour,EMOIS,mois,EANNEE,annee,ESEXE,sexe,EMALD,maladie_freq,ERISK,risk,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}




int ajouter(FicheDonneur D,int gender,int choix[]) 
{
FILE *f1;
if(gender==0)
strcpy(D.sexe,"male");
if(gender==1)
strcpy(D.sexe,"female");
if(choix[0]==1)
strcpy(D.risk,"drogue");
if(choix[1]==1)
strcpy(D.risk,"tattoo");
if(choix[2]==1)
strcpy(D.risk,"anemie");
if(choix[3]==1)
strcpy(D.risk,"piercing");

f1=fopen("fiche.txt","a+");

if(f1!=NULL) 
{
fprintf(f1,"%s  %s  %s  %s  %s  %d  %d  %d  %s  %s  %s\n",D.id,D.nom,D.prenom,D.groupe,D.ets,D.jour,D.mois,D.annee,D.sexe,D.maladie_freq,D.risk);
fclose(f1);
return 1;
}

}



    
int modifier_fiche(FicheDonneur D1,char iden[20],int genre,int choice[])
{
if(genre==0)
strcpy(D1.sexe,"male");
if(genre==1)
strcpy(D1.sexe,"female");
if(choice[0]==1)
strcpy(D1.risk,"drogue");
if(choice[1]==1)
strcpy(D1.risk,"tattoo");
if(choice[2]==1)
strcpy(D1.risk,"anemie");
if(choice[3]==1)
strcpy(D1.risk,"piercing");
FILE *f1, *temp;
FicheDonneur D;
f1=fopen("fiche.txt","a+");
temp=fopen("temp.txt","a+");
if (f1==NULL)
	return 0;
else
{
	while (fscanf(f1,"%s  %s  %s  %s  %s  %d  %d  %d  %s  %s  %s\n",D.id,D.nom,D.prenom,D.groupe,D.ets,&D.jour,&D.mois,&D.annee,D.sexe,D.maladie_freq,D.risk)!=EOF)
		{
		if (strcmp(D.id,iden)==0)
		{
                        
			fprintf(temp,"%s  %s  %s  %s  %s  %d  %d  %d  %s  %s  %s\n",D1.id,D1.nom,D1.prenom,D1.groupe,D1.ets,D1.jour,D1.mois,D1.annee,D1.sexe,D1.maladie_freq,D1.risk);		
		}
		else
		{
			fprintf(temp,"%s  %s  %s  %s  %s  %d  %d  %d  %s  %s  %s\n",D.id,D.nom,D.prenom,D.groupe,D.ets,D.jour,D.mois,D.annee,D.sexe,D.maladie_freq,D.risk);	
		}
		}
}
fclose(f1);
fclose(temp);
remove("fiche.txt");	
rename("temp.txt","fiche.txt");
return 1;
}






int supprimer(char iden[20])
{
FILE *f1, *temp;
FicheDonneur D;
f1=fopen("fiche.txt","a+");
temp=fopen("temp.txt","a+");
if (f1==NULL)
	return 0;
else
{
	while (fscanf(f1,"%s  %s  %s  %s  %s  %d  %d  %d  %s  %s  %s\n",D.id,D.nom,D.prenom,D.groupe,D.ets,&D.jour,&D.mois,&D.annee,D.sexe,D.maladie_freq,D.risk)!=EOF)
		{
		if (strcmp(D.id,iden)!=0)
		{
                        
			fprintf(temp,"%s  %s  %s  %s  %s  %d  %d  %d  %s  %s  %s\n",D.id,D.nom,D.prenom,D.groupe,D.ets,D.jour,D.mois,D.annee,D.sexe,D.maladie_freq,D.risk);		
		}
		
		}
}
fclose(f1);
fclose(temp);
remove("fiche.txt");	
rename("temp.txt","fiche.txt");
return 1;
}


void chercher(char identifiant[20],GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
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

FicheDonneur D;
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Groupe",renderer,"text",EGROUPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Ets",renderer,"text",EETS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Maladie",renderer,"text",EMALD,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Risques",renderer,"text",ERISK,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

f=fopen("fiche.txt","r");
if(f==NULL)
{
return;
}
else 
{
while(fscanf(f,"%s  %s  %s  %s  %s  %d  %d  %d  %s  %s  %s\n",id,nom,prenom,groupe,ets,&jour,&mois,&annee,sexe,maladie_freq,risk)!=EOF)
{
if(strcmp(id,identifiant)==0)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EIDENTIFIANT,id,ENOM,nom,EPRENOM,prenom,EGROUPE,groupe,EETS,ets,EJOUR,jour,EMOIS,mois,EANNEE,annee,ESEXE,sexe,EMALD,maladie_freq,ERISK,risk,-1);
}
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}


void vider(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

store=NULL;
FILE *f;
store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));

if(store==NULL)
{
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Groupe",renderer,"text",EGROUPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Ets",renderer,"text",EETS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Maladie",renderer,"text",EMALD,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Risques",renderer,"text",ERISK,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
gtk_list_store_append(store,&iter);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
}










/*int listeRDV(char ETS[], int j, int m, int a) {
    //char etablis[20];
    //int j, m, a;
    int nbr = 0;
    FicheDonneur D;

    FILE *f1 = fopen("fiche.txt", "r");
    FILE *f2 = fopen("rdv.txt", "a+");

    if (f1 == NULL || f2 == NULL) {
        return 0;
    } else {
        while (fscanf(f1,"%s  %s  %s  %s  %s  %d  %d  %d  %s  %s  %s\n",D.id,D.nom,D.prenom,D.groupe,D.ets,&D.jour,&D.mois,&D.annee,D.sexe,D.maladie_freq,D.risk)!=EOF)
{
            if (strcmp(ETS,D.ets) == 0 && j==D.jour && m==D.mois && a==D.annee) 
{
                fprintf(f2,"%s  %s  %s  %s  %s  %d  %d  %d  %s  %s  %s\n",D.id,D.nom,D.prenom,D.groupe,D.ets,D.jour,D.mois,D.annee,D.sexe,D.maladie_freq,D.risk);
                nbr++;
            }
        }
    }

    fclose(f1);
    fclose(f2);

    return nbr;
}*/

int liste_rdv(char ETS[],int j, int m, int a) {
    FicheDonneur D;
    int nbr=0;
    // Open "rdv.txt" in write mode, which clears the file
    FILE *f2 = fopen("rdv.txt", "w");

    if (f2 == NULL) {
        return 0;
    }

    FILE *f1 = fopen("fiche.txt", "r");
    if (f1 == NULL) {
        fclose(f2);
        return 0;
    } else {
        while (fscanf(f1, "%s %s %s %s %s %d %d %d %s %s %s\n", D.id, D.nom, D.prenom, D.groupe, D.ets, &D.jour, &D.mois, &D.annee, D.sexe, D.maladie_freq, D.risk) != EOF) {
            if (j == D.jour && m == D.mois && a == D.annee && strcmp(ETS,D.ets) == 0) {
                fprintf(f2, "%s %s %s %s %s %d %d %d %s %s %s\n", D.id, D.nom, D.prenom, D.groupe, D.ets, D.jour, D.mois, D.annee, D.sexe, D.maladie_freq, D.risk);
                nbr++;
            }
        }
        fclose(f1);
        fclose(f2);
    }

    return 1;
}





int nbETS() {
    int lignes = 0;
    FicheDonneur D;

    // Créer un tableau pour stocker les établissements uniques
    char etablissementsUniques[40][40];
    int nombreUnique = 0;

    FILE *f1 = fopen("fiche.txt", "r");
    if (f1 == NULL) {
        return 0;
    } else {
        while (fscanf(f1, "%s %s %s %s %s %d %d %d %s %s %s\n",
                      D.id, D.nom, D.prenom, D.groupe, D.ets,
                      &D.jour, &D.mois, &D.annee, D.sexe, D.maladie_freq, D.risk) != EOF)
        {
            if (nombreUnique == 0) {
                // Si le tableau est vide, ajoutez directement le premier établissement
                nombreUnique++;
                strcpy(etablissementsUniques[0], D.ets);
            } else {
                // Vérifier si l'établissement est unique
                int estUnique = 1;
                for (int i = 0; i < nombreUnique; i++) {
                    if (strcmp(etablissementsUniques[i], D.ets) == 0) {
                        estUnique = 0;
                        break;
                    }
                }

                // Si c'est unique, incrémenter le compteur et ajouter à l'ensemble
                if (estUnique) {
                    nombreUnique++;
                    strcpy(etablissementsUniques[nombreUnique - 1], D.ets);
                }
            }

            lignes++;
        }
        fclose(f1);
    }

    return nombreUnique;
}







float moyRDV(int j, int m, int a, FILE *f1) {
    int nbrdv = 0;
    FicheDonneur D;

    rewind(f1);  // Reset file pointer to the beginning

    while (fscanf(f1, "%s %s %s %s %s %d %d %d %s %s %s\n", D.id, D.nom, D.prenom, D.groupe, D.ets, &D.jour, &D.mois, &D.annee, D.sexe, D.maladie_freq, D.risk) != EOF) {
        printf("Comparing: %d %d %d with Entry: %d %d %d\n", j, m, a, D.jour, D.mois, D.annee);

        if (j == D.jour && m == D.mois && a == D.annee) {
            nbrdv++;
        }
    }

    int totalETS = nbETS();

    if (totalETS == 0) {
        printf("Total ETS is zero.\n");
        return 0;
    }

    printf("Number of RDVs: %d\n", nbrdv);
    printf("Total ETS: %d\n", totalETS);

    return (float)nbrdv / totalETS;
}













void afficher_rdv(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
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
store=NULL;
FILE *f;
FicheDonneur D;
store=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
if(store==NULL)
{

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Id",renderer,"text",EIDENTIFIANT,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EPRENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Groupe",renderer,"text",EGROUPE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);


renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Ets",renderer,"text",EETS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Maladie",renderer,"text",EMALD,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("Risques",renderer,"text",ERISK,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
}

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("rdv.txt","r");
if(f==NULL)
{
return;
}
else 
{
f=fopen("rdv.txt","a+");
while(fscanf(f,"%s  %s  %s  %s  %s  %d  %d  %d  %s  %s  %s\n",id,nom,prenom,groupe,ets,&jour,&mois,&annee,sexe,maladie_freq,risk)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EIDENTIFIANT,id,ENOM,nom,EPRENOM,prenom,EGROUPE,groupe,EETS,ets,EJOUR,jour,EMOIS,mois,EANNEE,annee,ESEXE,sexe,EMALD,maladie_freq,ERISK,risk,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}
