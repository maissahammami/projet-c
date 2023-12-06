#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"UserMgmnt.h"
#include<gtk/gtk.h>

enum
{ 
	ENOM,
	EPRENOM,
	ECIN,
	EDATENAISSANCE,
        EROLE,
	COLUMNS,
};

//////////////////////////////////
void addUser(user u){
FILE *f;
f = fopen("users.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s\n",u.nom,u.prenom,u.CIN,u.DateNaissance,u.pwd,u.role);
fclose(f);
}
}

/////////////////////////////////
void showUsers(GtkWidget *liste){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char nom[30];
char prenom[30];
char CIN[12];
char DateNaissance[25];
char pwd[30];
char role[30];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
g_object_set(renderer, "editable", TRUE, NULL);
column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
g_object_set(renderer, "editable", TRUE, NULL);
column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text",EPRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",ECIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);  

renderer = gtk_cell_renderer_text_new();
g_object_set(renderer, "editable", TRUE, NULL);
column = gtk_tree_view_column_new_with_attributes("Date Naissance", renderer, "text",EDATENAISSANCE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
g_object_set(renderer, "editable", TRUE, NULL);
column = gtk_tree_view_column_new_with_attributes("Role", renderer, "text",EROLE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
}

store=gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,  G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("users.txt","r");
if(f==NULL)
{
return;
}
else
{
f= fopen("users.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s \n",nom,prenom,CIN,DateNaissance,pwd,role)!=EOF)
{
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter, ENOM, nom, EPRENOM,prenom, 	ECIN,CIN,EDATENAISSANCE,DateNaissance,EROLE,role, -1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}

/////////////////////////////////
void delUser(user u){
user u2;
FILE *f,*g;
f=fopen("users.txt","r");
g=fopen("usersTemp.txt","w");
if( f==NULL  || g==NULL )
return;
else
{
while (fscanf(f,"%s %s %s %s %s %s \n", u2.nom,u2.prenom,u2.CIN,u2.DateNaissance,u2.pwd,u2.role)!=EOF)
{
if (strcmp(u.CIN,u2.CIN)!=0)
{
fprintf(g,"%s %s %s %s %s %s \n", u2.nom,u2.prenom,u2.CIN,u2.DateNaissance,u2.pwd,u2.role);
}
printf(u2.CIN);
}
fclose(f);
fclose(g);
remove("users.txt");
rename("usersTemp.txt","users.txt");
}
}

/////////////////////////////////
void updateUser(user u){
user u2;
FILE *f,*g;
f=fopen("users.txt","r");
g=fopen("usersTemp.txt","w");
if( f==NULL  || g==NULL )
return;
else
{
while (fscanf(f,"%s %s %s %s %s %s \n",u2.nom,u2.prenom,u2.CIN,u2.DateNaissance,u2.pwd,u2.role)!=EOF)
{
if (strcmp(u.CIN,u2.CIN)!=0)
fprintf(g,"%s %s %s %s %s %s \n",u2.nom,u2.prenom,u2.CIN,u2.DateNaissance,u2.pwd,u2.role);
else fprintf(g,"%s %s %s %s %s %s \n",u.nom,u.prenom,u2.CIN,u.DateNaissance,u2.pwd,u.role);
}
fclose(f);
fclose(g);
remove("users.txt");
rename("usersTemp.txt","users.txt");
}
}

////////////////////////////////
void findUserByRole(GtkWidget *liste, user u){
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char nom[30];
char prenom[30];
char CIN[12];
char DateNaissance[25];
char pwd[30];
char role[30];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text",EPRENOM,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column); 

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("CIN", renderer, "text",ECIN,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);  

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Date Naissance", renderer, "text",EDATENAISSANCE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Role", renderer, "text",EROLE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
}

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING,  G_TYPE_STRING);
f=fopen("users.txt","r");
if(f==NULL)
{
return;
}
else
{
f= fopen("users.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s \n",nom,prenom,CIN,DateNaissance,pwd,role)!=EOF)
{
if(strcmp(role,u.role)==0){
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter, ENOM, nom, EPRENOM,prenom, 	ECIN,CIN,EDATENAISSANCE,DateNaissance,EROLE,role, -1);
}
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}
}
//////////////////////////////////////
int login(char cin[],char pass[]){
char nom[30];
char prenom[30];
char CIN1[12];
char DateNaissance[25];
char pwd[30];
char role[30];
int trouve =0;
FILE *f;
f=fopen("users.txt","r");
if (f!=NULL)
{
while (fscanf(f,"%s %s %s %s %s %s \n",nom,prenom,CIN1,DateNaissance,pwd,role)!=EOF)
{
if((strcmp(cin,CIN1)==0)&&(strcmp(pass,pwd)==0))
if ((strcmp(role,"Administrateur")==0))
trouve=1;
else if ((strcmp(role,"Infirmiers")==0))
trouve=4;
else if ((strcmp(role,"Medecin")==0))
trouve=5;
}
fclose(f);
}
return trouve;
}
