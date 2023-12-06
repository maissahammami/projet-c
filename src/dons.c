#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"dons.h"
#include <gtk/gtk.h>

enum
{ 
	EID,
	EIDETABLISSEMENT,
	ECIN,
	EJOUR,
	EMOIS,
	EANNEE,
	ETYPE,
	COLUMNS,
};

//Ajouter


void ajouter_don(don b,char *dons){
FILE * f;
f=fopen(dons,"a");

  fprintf(f,"%s %s %s %d %s %d %s \n ",b.id,b.cin,b.idetablissement,b.jour,b.mois,b.annee,b.type);
  fclose(f);
}


//Afficher

void afficher_don(GtkWidget *liste){
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;
	GtkListStore *store;
	char id[30];
	char idetablissement[10];
	char cin[10];
	char jour[10];
	char mois[30];
	char annee[30];
	char type[30];
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",ECIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("idetablissement", renderer, "text",EIDETABLISSEMENT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
	

	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING);
	f=fopen("don.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("don.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s   \n",id,cin,idetablissement,jour,mois,annee,type)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EID, id,ECIN, cin, EIDETABLISSEMENT,idetablissement, EJOUR, jour, EMOIS, mois ,EANNEE ,annee,  ETYPE, type,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
}

//Modifier

void modifier_don(char id[],don b1,char *dons)
{
don b;
  FILE* f=fopen(dons, "r");
  FILE* f2=fopen("donmod.txt", "w");
  
  if((f!=NULL) ||( f2!=NULL))
 {
while(fscanf(f,"%s %s %s %d %s %d %s \n ",b.id,b.cin,b.idetablissement,&b.jour,b.mois,&b.annee,b.type)!=EOF)
{
if(strcmp(b.id,b1.id)==0)
  fprintf(f2,"%s %s %s %d %s %d %s \n ",b1.id,b1.cin,b1.idetablissement,b1.jour,b1.mois,b1.annee,b1.type);
else
 fprintf(f2,"%s %s %s %d %s %d %s \n ",b.id,b.cin,b.idetablissement,b.jour,b.mois,b.annee,b.type);
}
   fclose(f);
   fclose(f2);
remove(dons);
rename("donmod.txt",dons);
 }
}

//supprimer

void supprimer_don(char cin[],char *dons)
{
don b;     
FILE * f=fopen(dons,"r");
FILE * f2=fopen("donsupp.txt","w");

while (fscanf(f,"%s %s %s %d %s %d %s \n  ",b.id,b.cin,b.idetablissement,&b.jour,b.mois,&b.annee,b.type)!=EOF)
{

if(strcmp(b.cin,cin)!=0)

  fprintf(f2,"%s %s %s %d %s %d %s \n  ",b.id,b.cin,b.idetablissement,b.jour,b.mois,b.annee,b.type);
}
  fclose(f);

  fclose(f2);

remove(dons);
rename("donsupp.txt",dons);

 
}
//fonction remplir tab
int remplirtabRech (don tab[],int nb)
{
    char id[20];
    char idetablissement[20];
    int jour;
    int  annee;
    char cin[20];
    char mois[20];
    char type[30]; 
  
    FILE* fichier ;
    int i;

    fichier = fopen("don.txt", "a+");

        while (fscanf(fichier,"%s %s %s %d %s %d %s \n ",id,cin,idetablissement,&jour,mois,&annee,type)!=EOF)
        {
            
            strcpy(tab[i].id,id);
            strcpy(tab[i].idetablissement,idetablissement);
	    tab[i].jour=jour;
            strcpy(tab[i].mois,mois);
	    tab[i].annee=annee;
	    strcpy(tab[i].cin,cin);
	    strcpy(tab[i].type,type);
	    	
            nb++;
	    i++;    
        }
        fclose(fichier);
	return(nb);
}
//rechercher 

int rechercher_don(char id[])
{
don tab[100];
int nb;
int ce,i;
FILE*f;
ce=0;
nb=remplirtabRech (tab,nb);
for (i=0;i<nb;i++)
	{if ((strcmp(id,tab[i].id)==0) ||(strcmp(id,tab[i].idetablissement)==0) || (strcmp(id,tab[i].cin)==0))
		{
		ce=1;
		f=fopen("rechdon.txt", "w+");
		if("f!=NULL")			
	{fprintf(f,"%s %s %s %d %s %d %s \n ",tab[i].id,tab[i].cin,tab[i].idetablissement,tab[i].jour,tab[i].mois,tab[i].annee,tab[i].type);}
		fclose(f);		
		}
	
	}
return(ce);		
}

//AFF RECH
void afficher_rechercher_don(GtkWidget *liste)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;
	GtkListStore *store;
	char id[30];
	char idetablissement[10];
	char cin[10];
	char jour[10];
	char mois[30];
	char annee[30];
	char type[30];
	
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model (liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin", renderer, "text",ECIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("idetablissement", renderer, "text",EIDETABLISSEMENT,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",EJOUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",EMOIS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",EANNEE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("type", renderer, "text",ETYPE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

	

	}
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING);
	f=fopen("rechdon.txt","r");
	if(f==NULL)
	{
		return;
	}
	else
	{
		f= fopen("rechdon.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s  \n",id,cin,idetablissement,jour,mois,annee,type)!=EOF)
		{
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store,&iter, EID, id, ECIN, cin, EIDETABLISSEMENT,idetablissement, EJOUR, jour, EMOIS,  mois,EANNEE ,annee,  ETYPE,type ,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref (store);
	}
	
}
        

        

