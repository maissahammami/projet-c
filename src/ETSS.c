#include "ETS.h"
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
enum
{
   EID,
   ENAME,
   ECAPACITY,
   EREGION,
   COLUMNS,
   
 
};
enum
{
   EIDI,
   ENAMEI,
   ECAPACITYI,
   EREGIONI,
   COLUMNSI,
   
 
};

//Ajouter une personne

int addEstablishment(EST est, const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file != NULL) {
        fprintf(file, "%s %s %s %s\n", est.id, est.name, est.capacity, est.region);
        fclose(file);
        return 1;
    } else {
        return 0;
    }
}

int modifyEstablishment(const char *id, EST modifiedEST, const char *filename) {
    EST currentEST;
    int found = 0;

    FILE *f = fopen("ETSS.txt", "r");
    FILE *f2 = fopen("islem.txt", "w");

    if (f == NULL || f2 == NULL) {
        return 0;
    } else {
        while (fscanf(f, "%s %s %s %s", currentEST.id, currentEST.name, currentEST.capacity, currentEST.region) != EOF) {
            if (strcmp(currentEST.id, id) != 0){
                fprintf(f2, "%s %s %s %s\n", currentEST.id, currentEST.name, currentEST.capacity, currentEST.region);
            } else {
                fprintf(f2, "%s %s %s %s\n", modifiedEST.id, modifiedEST.name, modifiedEST.capacity, modifiedEST.region);
                found = 1;
            }
        }

        fclose(f);
        fclose(f2);

        remove("ETSS.txt");
        rename("islem.txt","ETSS.txt" );

        return found;
    }
}

int removeEstablishment(const char *id, const char *filename) {
    EST currentEST;
    int found = 0;

    FILE *f = fopen("ETSS.txt", "r");
    FILE *f2 = fopen("islem.txt", "w");

    if (f == NULL || f2 == NULL) {
        return 0;
    } else {
        while (fscanf(f, "%s %s %s %s", currentEST.id, currentEST.name, currentEST.capacity, currentEST.region) != EOF) {
            if (strcmp(currentEST.id, id) != 0)  {
                fprintf(f2, "%s %s %s %s\n", currentEST.id, currentEST.name, currentEST.capacity, currentEST.region);
            } else {
                found = 1;
            }
        }

        fclose(f);
        fclose(f2);

        remove("ETSS.txt");
        rename("islem.txt", "ETSS.txt");

        return found;
    }
}

EST findEstablishment(const char *id, const char *filename) {
    EST currentEST;
    int tr = 0;
    FILE *f = fopen("ETSS.txt", "r");

    if (f != NULL) {
        while (fscanf(f, "%s %s %s %s", currentEST.id, currentEST.name, currentEST.capacity, currentEST.region) != EOF && tr == 0) {
            if (strcmp(currentEST.id, id) == 0) {
                tr = 1;
            }
        }
    }

    if (tr == 0) {
        strcpy(currentEST.id, "-1");
    }

    fclose(f);
    return currentEST;

}
int ETSParRegion(char nomFichier[], char reg[]) {
    FILE *f = fopen(nomFichier, "r");
    int count = 0;

    if (f != NULL) {
        EST currentEST;

        while (fscanf(f, "%s %s %s %s", currentEST.id, currentEST.name, currentEST.capacity, currentEST.region) != EOF) {
            if (strcmp(currentEST.region, reg) == 0) {
                printf("Établissement trouvé : ID=%s, Nom=%s, Capacité=%s, Région=%s\n", currentEST.id, currentEST.name, currentEST.capacity, currentEST.region);
                count++;
            }
        }

        fclose(f);
    }

    return count;
}

void ETSTrierCapacite(char nomFichier[]) {
    FILE *f = fopen("ETSS.txt", "r");
    
    if (f != NULL) {
        EST establishments[100];  // Supposons que le fichier contient au plus 100 établissements
        int count = 0;

        // Lire les établissements dans le tableau
        while (fscanf(f, "%s %s %s %s", establishments[count].id, establishments[count].name, establishments[count].capacity, establishments[count].region) != EOF) {
            count++;
        }

        fclose(f);

        // Trier les établissements par capacité (tri par insertion)
        for (int i = 1; i < count; i++) {
            EST key = establishments[i];
            int j = i - 1;

            while (j >= 0 && establishments[j].capacity > key.capacity) {
                establishments[j + 1] = establishments[j];
                j = j - 1;
            }

            establishments[j + 1] = key;
        }

        // Afficher les établissements triés
        printf("Établissements triés par capacité :\n");
        for (int i = 0; i < count; i++) {
            printf("ID=%s, Nom=%s, Capacité=%s, Région=%s\n", establishments[i].id, establishments[i].name, establishments[i].capacity, establishments[i].region);
        }
    }
}



// Fonction d'affichage des établissements dans le TreeView
void afficherEtablissementsapressupp(GtkWidget *liste) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

    char id[20];
    char name[50];
    char capacity[20];
    char region[20];
    store=NULL;
    FILE *f;

   store=gtk_tree_view_get_model(liste);


    if(store==NULL)
    {
     

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("id" , renderer, "text",EID, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    column=gtk_tree_view_column_new_with_attributes("name" , renderer, "text",ENAME, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
column=gtk_tree_view_column_new_with_attributes("region" , renderer, "text",EREGION, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    column=gtk_tree_view_column_new_with_attributes("capacity" , renderer, "text",ECAPACITY, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
    }
   store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
   
    

   
   f= fopen("ETSS.txt", "r");
   if(f==NULL)
   {
      return;
   }
   else
   {
        f=fopen("ETSS.txt", "a+");
        //EST currentEST;
        while (fscanf(f, "%s %s %s %s", id, name, capacity, region) == 4) {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, EID, id, ENAME, name, ECAPACITY, capacity, EREGION, region, -1);
        }
        fclose(f);
        // Associer le modèle au TreeView
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));

    // Libérer le modèle
    g_object_unref(store);
    }

    
}
void regcap(int capacite,int region, char msg[]){
if(capacite==0)
strcpy(msg,"capacite");
if(region==1)
strcpy(msg,"region");

}
void afficherEtablissements(GtkWidget *liste) {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;

    char id[20];
    char name[50];
    char capacity[20];
    char region[20];
    store=NULL;
    FILE *f;

   store=gtk_tree_view_get_model(liste);


    if(store==NULL)
    {
     

    renderer=gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("id" , renderer, "text",EIDI, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    column=gtk_tree_view_column_new_with_attributes("name" , renderer, "text",ENAMEI, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
column=gtk_tree_view_column_new_with_attributes("region" , renderer, "text",EREGIONI, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    column=gtk_tree_view_column_new_with_attributes("capacity" , renderer, "text",ECAPACITYI, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
    }
   store = gtk_list_store_new(COLUMNSI, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
   
    

   
   f= fopen("ETSS.txt", "r");
   if(f==NULL)
   {
      return;
   }
   else
   {
        f=fopen("ETSS.txt", "a+");
        //EST currentEST;
        while (fscanf(f, "%s %s %s %s", id, name, capacity, region) == 4) {
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, EIDI, id, ENAMEI, name, ECAPACITYI, capacity, EREGIONI, region, -1);
        }
        fclose(f);
        // Associer le modèle au TreeView
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));

    // Libérer le modèle
    g_object_unref(store);
    }

    
}
