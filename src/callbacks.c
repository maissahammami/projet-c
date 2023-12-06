#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "UserMgmnt.h"


void
on_buttonLogin_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
  GtkWidget *cin;
  GtkWidget *pwd;
  GtkWidget *msg;
  GtkWidget *affiche;
  GtkWidget *treeview;
  char uid[30];
  char pass[30];
  int test;
  cin = lookup_widget(objet_graphique, "entryUser") ;
  pwd = lookup_widget(objet_graphique, "entryPwd") ;
  strcpy(uid,gtk_entry_get_text(GTK_ENTRY(cin)));
  strcpy(pass,gtk_entry_get_text(GTK_ENTRY(pwd)));
  if(login(uid,pass)==1){
  affiche = create_listUser ();
  gtk_widget_show (affiche);
  treeview=lookup_widget(affiche, "treeviewUsers") ;
  showUsers(treeview);
  } else {
  affiche = create_loginUser ();
  gtk_widget_show (affiche);
  }
}


void
on_buttonReturn_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonAddUser_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
user u;

GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *cin;
GtkWidget *pwd;
GtkWidget *rolecb;
GtkWidget *DN;
guint day, month, year;

nom = lookup_widget(objet_graphique, "entryNom") ;
prenom = lookup_widget(objet_graphique, "entryPrenom") ;
cin = lookup_widget(objet_graphique, "entryCIN") ;
pwd = lookup_widget(objet_graphique, "entryPwd") ;
DN = lookup_widget(objet_graphique, "calendarDNUser") ;
rolecb = lookup_widget(objet_graphique, "comboboxRole") ;

strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(u.CIN,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(u.pwd,gtk_entry_get_text(GTK_ENTRY(pwd)));
gtk_calendar_get_date(DN,&year,&month,&day);
sprintf(u.DateNaissance,"%d/%d/%d", day,month,year);
strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(rolecb)));
addUser(u);
}


void
on_buttonReturnUpdate_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonUpdateUser_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
user u;

GtkWidget *nom;
GtkWidget *prenom;
GtkWidget *cin;
GtkWidget *pwd;
GtkWidget *rolecb;
GtkWidget *DN;
guint day, month, year;

nom = lookup_widget(objet_graphique, "entryNom") ;
prenom = lookup_widget(objet_graphique, "entryPrenom") ;
cin = lookup_widget(objet_graphique, "entryCIN") ;
pwd = lookup_widget(objet_graphique, "entryPwd") ;
DN = lookup_widget(objet_graphique, "calendarDNUser") ;
rolecb = lookup_widget(objet_graphique, "comboboxRole") ;

strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(u.CIN,gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(u.pwd,gtk_entry_get_text(GTK_ENTRY(pwd)));
gtk_calendar_get_date(DN,&year,&month,&day);
sprintf(u.DateNaissance,"%d/%d/%d", day,month,year);
strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(rolecb)));
updateUser(u);
}
void
on_treeviewUsers_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
user u;
GtkTreeIter iter;
gchar* cin;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter ,path))
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter, 2, &cin,-1);
strcpy(u.CIN,cin);
delUser(u);
showUsers(treeview);
}

}

void
on_statsBtn_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data)
{
  user u;
  GtkWidget *rolecb;
  GtkWidget *affiche;
  GtkWidget *treeview;
  rolecb = lookup_widget(objet_graphique, "comboboxRole") ;
  strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(rolecb)));
  affiche = create_listUser ();
  gtk_widget_show (affiche);
  treeview=lookup_widget(affiche, "treeviewUsers") ;
  findUserByRole(treeview,u);
}

void
on_goToaddUserBtn_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *addUser;
  addUser = create_ajouterUser ();
  gtk_widget_show (addUser);
}

void
on_comboboxRole_changed                (GtkComboBox     *combobox,
                                        gpointer         user_data)
{
}

