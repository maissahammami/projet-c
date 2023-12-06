#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "UserMgmnt.h"
#include "fiche.h"
#include "dons.h"
#include "ETS.h"

static int gender;
static int genre;
int choix[4]={0,0,0,0};
int choice[4]={0,0,0,0};

int x,y,l;
int z,k,m;


void
on_buttonLogin1_clicked                 (GtkButton       *objet_graphique,
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
  affiche = create_HOMEadmin ();
  gtk_widget_show (affiche);
  }
  else if(login(uid,pass)==4){
  affiche= create_fenetre_acceuil ();
  gtk_widget_show (affiche);
  }
  else if(login(uid,pass)==5){
  affiche = create_window_gestionfiche ();
  gtk_widget_show (affiche);
  }
  else {
  affiche = create_loginUser ();
  gtk_widget_show (affiche);
  }
/*
  GtkWidget *cin;
  GtkWidget *pwd;
  GtkWidget *affiche;
  GtkWidget *treeview;
  char uid[30];
  char pass[30];
  cin = lookup_widget(objet_graphique, "entryUser") ;
  pwd = lookup_widget(objet_graphique, "entryPwd") ;
  strcpy(uid,gtk_entry_get_text(GTK_ENTRY(cin)));
  strcpy(pass,gtk_entry_get_text(GTK_ENTRY(pwd)));
  printf("test: %s",cin);
  test=login(uid,pass);
  printf("test: %d",test);
  if(login(uid,pass)==1){
  affiche = create_HOMEadmin ();
  gtk_widget_show (affiche);
  }
  else if(login(uid,pass)==4){
  affiche= create_fenetre_acceuil ();
  gtk_widget_show (affiche);
  }
  else if(login(uid,pass)==5){
  affiche = create_window_gestionfiche ();
  gtk_widget_show (affiche);
  }
  else {
  affiche = create_loginUser ();
  gtk_widget_show (affiche);
  }
*/
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
////////////////////////////////////////////////
void
on_treeview1_row_activated             (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
GtkWidget *treeview2;
gchar* id;
//FicheDonneur D;
GtkTreeModel *model=gtk_tree_view_get_model(treeview1);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id, -1);
supprimer(id);
//treeview2=lookup_widget(treeview1,"treeview1");
//afficher(treeview2);
}
}

void
on_retourner_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
int res;
FicheDonneur D;
GtkWidget *fenetre_ajouter;
GtkWidget *objet = GTK_WIDGET(button);
GtkWidget *input1, *input2, *input3, *input4, *input5,*jour,*mois,*annee,*combomal,*ajout_succ;
fenetre_ajouter=lookup_widget(objet,"fenetre_ajouter");
ajout_succ= lookup_widget(objet, "ajout_succ");
gtk_label_set_text(ajout_succ, "");

input1=lookup_widget(objet,"id");
input2=lookup_widget(objet,"nom");
input3=lookup_widget(objet,"prenom");
input4=lookup_widget(objet,"groupe");
input5=lookup_widget(objet,"ets");
strcpy(D.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(D.nom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(D.prenom,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(D.groupe,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(D.ets,gtk_entry_get_text(GTK_ENTRY(input5)));
jour=lookup_widget(objet,"jour");
mois=lookup_widget(objet,"mois");
annee=lookup_widget(objet,"annee");
combomal=lookup_widget(objet,"combomal");
D.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
D.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
D.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(D.maladie_freq,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combomal)));
g_print("%d\n",gender);
//ajouter(D,gender,choix);
//printf("ajout success\n");
res=ajouter(D,gender,choix);
if (res==1)
{
gtk_label_set_text(ajout_succ, "Ajout avec succés!!!!");
}
else
{
gtk_label_set_text(ajout_succ, "Attention! Erreur!");
}
}



void
on_supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  int res;
  GtkWidget *identifiant1,*supp_succ;
    GtkWidget *fenetre_supprimer;
    GtkWidget *objet = GTK_WIDGET(button);
    FicheDonneur D;
    char id1[20];
    fenetre_supprimer=lookup_widget(objet,"fenetre_supprimer");
    identifiant1=lookup_widget(button, "identifiant1");
    strcpy(id1, gtk_entry_get_text(GTK_ENTRY(identifiant1)));
    supp_succ= lookup_widget(objet, "supp_succ");
    gtk_label_set_text(supp_succ, "");
    printf("id: %s \n",id1);
    //printf("supprimer success\n");
    res=supprimer(id1);
     if (res==1)
{
gtk_label_set_text(supp_succ, "Suppression avec succés!!!!");
}
else
{
gtk_label_set_text(supp_succ, "Attention! Identifiant inexistant !");
}
}


void on_modifier_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{ 
  int res;
  char a[20];
    GtkWidget *identifiant1;
    GtkWidget *fenetre_modifier;

    GtkWidget *objet = GTK_WIDGET(button);
    FicheDonneur D;
    char id1[20];
    fenetre_modifier=lookup_widget(objet,"fenetre_modifier");
    identifiant1=lookup_widget(button, "identifiant1");
    strcpy(id1, gtk_entry_get_text(GTK_ENTRY(identifiant1)));

    FicheDonneur nouv;

    GtkWidget *id, *nom, *prenom, *groupe, *ets,*jour1,*mois1,*annee1,*combomal1,*modif_succ;
    modif_succ= lookup_widget(objet, "modif_succ");
    gtk_label_set_text(modif_succ, "");
    id=lookup_widget(objet,"id");
    nom=lookup_widget(objet,"nom");
    prenom=lookup_widget(objet,"prenom");
    groupe=lookup_widget(objet,"groupe");
    ets=lookup_widget(objet,"ets");
    jour1=lookup_widget(objet,"jour1");
    mois1=lookup_widget(objet,"mois1");
   annee1=lookup_widget(objet,"annee1");
   combomal1=lookup_widget(objet,"combomal1");


    strcpy(nouv.id, gtk_entry_get_text(GTK_ENTRY(id)));
    strcpy(nouv.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
    strcpy(nouv.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
    strcpy(nouv.groupe, gtk_entry_get_text(GTK_ENTRY(groupe)));
    strcpy(nouv.ets, gtk_entry_get_text(GTK_ENTRY(ets)));
    nouv.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
    nouv.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
    nouv.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));
    //sprintf(gender, "%d" ,a);
    //strcpy(nouv.sexe,a);

    
   strcpy(nouv.maladie_freq, gtk_combo_box_get_active_text(GTK_COMBO_BOX(combomal1)));
   g_print("%d\n",gender);
  
   printf("id: %s \n",id1);
   //printf("modifier success\n");
    res=modifier_fiche(nouv,id1,genre,choice);
   if (res==1)
{
gtk_label_set_text(modif_succ, "Modification avec succés!!!!");
}
else
{
gtk_label_set_text(modif_succ, "Attention! Identifiant inexistnat !");
}
}



void
on_rechercher_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
FicheDonneur D;
char id1[20];
GtkWidget *identifiant1;
identifiant1=lookup_widget(button,"identifiant1");
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(identifiant1)));
GtkWidget *treeviewrecherche;
treeviewrecherche=lookup_widget(button,"treeviewrecherche");
if (treeviewrecherche == NULL) {
        g_print("Error: Widget 'treeview' not found.\n");
        return;
    }
chercher(id1,treeviewrecherche);
}





//lookupwidget(button widget_name)
//widgethide
//widgetdestroy
//widgetcreate
//widgetshow




void
on_actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;
GtkWidget *treeview1;
w1=lookup_widget(button,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
gtk_widget_hide (w1);
treeview1=lookup_widget(fenetre_afficher,"treeview1");
afficher(treeview1);
}












void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *id,*nom,*prenom,*groupe,*medpres;
//FicheDonneur D;
GtkTreeModel *model=gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id,1,&nom,2,&prenom,3,&groupe,4,&medpres, -1);
supprimer(id);
GtkWidget *treeview3;
treeview3=lookup_widget(treeview,"treeview");
afficher(treeview3);
//treeview2=lookup_widget(treeview1,"treeview1");
//afficher(treeview2);
}
}


//void
//on_actualiser_clicked                  (GtkButton       *button,
                                       // gpointer         user_data)
//{
//GtkWidget *fenetre_afficher,*w1;
//GtkWidget *treeview;
//w1=lookup_widget(button,"fenetre_afficher");
//fenetre_afficher=create_fenetre_afficher();
//gtk_widget_show(fenetre_afficher);
//gtk_widget_hide (w1);
//treeview1=lookup_widget(fenetre_afficher,"treeview");
//vider(treeview);
//afficher(treeview);
//}


void
on_actualiser1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
//GtkWidget *fenetre_rechercher,*w1;
GtkWidget *treeview2;
//w1=lookup_widget(button,"fenetre_rechercher");
//fenetre_rechercher=create_fenetre_rechercher();
//gtk_widget_show(fenetre_rechercher);
//gtk_widget_hide (w1);
treeview2=lookup_widget(button,"treeview2");
//vider(treeview);
afficher(treeview2);
}


void
on_male_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
gender=0;
}


void
on_female_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
gender=1;
}




void
on_male1_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
genre=0;
}


void
on_female1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
genre=1;
}


void
on_drogue_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choix[0]=1;
}


void
on_tattoo_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choix[1]=1;
}


void
on_anemie_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choix[2]=1;
}


void
on_piercing_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choix[3]=1;
}


void
on_drogue1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choice[0]=1;
}


void
on_piercing1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choice[3]=1;
}


void
on_anemie1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choice[2]=1;
}


void
on_tattoo1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
choice[1]=1;
}







void
on_treeviewgestion_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_modifier_redirect_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *bureau;
bureau=lookup_widget(button,"fenetre_gestion");
gtk_widget_destroy(bureau);
GtkWidget *modifier;
modifier = create_fenetre_modifier();
 gtk_widget_show (modifier);
}


void
on_chercher_redirect_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *bureau;
bureau=lookup_widget(button,"fenetre_gestion");
gtk_widget_destroy(bureau);
GtkWidget *rechercher;
rechercher = create_fenetre_rechercher();
 gtk_widget_show (rechercher);
}


void
on_statistiques_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_supprimer_redirect_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *bureau;
bureau=lookup_widget(button,"fenetre_gestion");
gtk_widget_destroy(bureau);
GtkWidget *supprimer;
supprimer = create_fenetre_supprimer();
 gtk_widget_show (supprimer);
}


void
on_ajouter_redirect_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *bureau;
bureau=lookup_widget(button,"fenetre_gestion");
gtk_widget_destroy(bureau);
GtkWidget *ajouter ;
ajouter = create_fenetre_ajouter();
  gtk_widget_show (ajouter);
}


void
on_actualiser_gestion_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_gestion,*w1;
GtkWidget *treeviewaffiche;
w1=lookup_widget(button,"fenetre_gestion");
fenetre_gestion=create_fenetre_gestion();
gtk_widget_show(fenetre_gestion);
gtk_widget_hide (w1);
treeviewaffiche=lookup_widget(fenetre_gestion,"treeviewaffiche");
afficher(treeviewaffiche);
}


void
on_retourner_redirect_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *bureau;
 GtkWidget *fenetre_acceuil;
 bureau=lookup_widget(button,"fenetre_gestion");
 fenetre_acceuil=lookup_widget(button,"fenetre_acceuil");
 gtk_widget_hide(bureau);
 fenetre_acceuil=create_fenetre_acceuil();
 gtk_widget_show(fenetre_acceuil);
}


void
on_gestion_donneur_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *bureau;
 GtkWidget *fenetre_gestion;
 bureau=lookup_widget(button,"fenetre_acceuil");
 fenetre_gestion=lookup_widget(button,"fenetre_gestion");
 gtk_widget_hide(bureau);
 fenetre_gestion=create_fenetre_gestion();
 gtk_widget_show(fenetre_gestion);
}


void
on_treeviewaffiche_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *EIDENTIFIANT[20];
gchar *ENOM[50];
gchar *EPRENOM[50];
gchar *EGROUPE[20];
gchar *EETS[20];
gint *EJOUR;
gint *EMOIS;
gint *EANNEE;
gchar *ESEXE[20];
gchar *EMALD[100];
gchar *ERISK[50];

FicheDonneur D;

GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* fenetre_modifier,*windowgestionfiche,*tre, *nomp,*prep,*cinp,*jrdv,*mrdv,*ardv,*typep;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&EIDENTIFIANT,1,&ENOM,2,&EPRENOM,3,&EGROUPE,4,&EETS,5,&EJOUR,6,&EMOIS,7,&EANNEE,8,&ESEXE,9,&EMALD,10,&ERISK,-1);

//windowmodifier=create_window_modfiche();
//windowgestionfiche=create_window_gestionfiche();
//gtk_widget_hide(windowgestionfiche);
//gtk_widget_show(windowmodifier);

//nomp=lookup_widget(windowmodifier,"entry2_id");
//gtk_entry_set_text(GTK_ENTRY(nomp),id);

//prep=lookup_widget(windowmodifier,"entry2_cin");
//gtk_entry_set_text(GTK_ENTRY(prep),idetablissement);

//cinp=lookup_widget(windowmodifier,"entry2_idetablissement");
//gtk_entry_set_text(GTK_ENTRY(cinp),cin);

//jrdv=lookup_widget(windowmodifier,"spinbutton2_jour");
//gtk_entry_set_text(GTK_ENTRY(jrdv),jour);
//mrdv=lookup_widget(windowmodifier,"comboboxentry2_mois");
//gtk_entry_set_text(GTK_ENTRY(mrdv),mois);

//ardv=lookup_widget(windowmodifier,"spinbutton2_annee");
//gtk_entry_set_text(GTK_ENTRY(ardv),annee);
}
afficher(treeview);
strcpy(D.id,EIDENTIFIANT);
supprimer(D.id);
}


void
on_treeviewrdv_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_chercherrdv_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
/*int res;
char j[10], m[10], a[10];
GtkWidget *fenetre_statistiques;
GtkWidget *entryjour,*entrymois,*entryan;
GtkWidget *treeviewrdv;
GtkWidget *objet = GTK_WIDGET(button);

entryjour=lookup_widget(objet,"entryjour");
entrymois=lookup_widget(objet,"entrymois");
entryan=lookup_widget(objet,"entryan");

strcpy(j,gtk_entry_get_text(GTK_ENTRY(entryjour)));
strcpy(m,gtk_entry_get_text(GTK_ENTRY(entrymois)));
strcpy(a,gtk_entry_get_text(GTK_ENTRY(entryan)));

// Convert strings to integers
int jour = atoi(j);
int mois = atoi(m);
int annee = atoi(a);

res=liste_rdv(jour,mois,annee);
if(res==1)
afficher_rdv(treeviewrdv);*/

}


void
on_afficherrdv_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
int res;
char j[10], m[10], a[10], e[50];
GtkWidget *fenetre_statistiques;
GtkWidget *entryjour,*entrymois,*entryan,*etablis;
GtkWidget *treeviewrdv;
GtkWidget *objet = GTK_WIDGET(button);

etablis=lookup_widget(objet,"etablis");
entryjour=lookup_widget(objet,"entryjour");
entrymois=lookup_widget(objet,"entrymois");
entryan=lookup_widget(objet,"entryan");

strcpy(j,gtk_entry_get_text(GTK_ENTRY(entryjour)));
strcpy(m,gtk_entry_get_text(GTK_ENTRY(entrymois)));
strcpy(a,gtk_entry_get_text(GTK_ENTRY(entryan)));
strcpy(e,gtk_entry_get_text(GTK_ENTRY(etablis)));

// Convert strings to integers
int jour = atoi(j);
int mois = atoi(m);
int annee = atoi(a);

res=liste_rdv(e,jour,mois,annee);
if(res==1)
{
GtkWidget *fenetre_statistiques,*w1;
GtkWidget *treeviewrdv;
w1=lookup_widget(button,"fenetre_statistiques");
fenetre_statistiques=create_fenetre_statistiques();
gtk_widget_show(fenetre_statistiques);
gtk_widget_hide (w1);
treeviewrdv=lookup_widget(fenetre_statistiques,"treeviewrdv");
afficher_rdv(treeviewrdv);
}
}


void
on_valider_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

  int res1;
    float res2;
    char j[10], m[10], a[10];

    GtkWidget *fenetre_statistiques;
    GtkWidget *entryjour, *entrymois, *entryan;
    GtkWidget *nbrets, *moy;
    GtkWidget *objet = GTK_WIDGET(button);

    fenetre_statistiques = lookup_widget(objet, "fenetre_statistiques");
    entryjour = lookup_widget(objet, "entryjour");
    entrymois = lookup_widget(objet, "entrymois");
    entryan = lookup_widget(objet, "entryan");
    nbrets = lookup_widget(objet, "nbrets");
    moy = lookup_widget(objet, "moy");

    gtk_label_set_text(nbrets, "");
    gtk_label_set_text(moy, "");

    strcpy(j, gtk_entry_get_text(GTK_ENTRY(entryjour)));
    strcpy(m, gtk_entry_get_text(GTK_ENTRY(entrymois)));
    strcpy(a, gtk_entry_get_text(GTK_ENTRY(entryan)));

    // Convert strings to integers
    int jour = atoi(j);
    int mois = atoi(m);
    int annee = atoi(a);

   FILE *f1 = fopen("fiche.txt", "r");
if (f1 == NULL) {
    printf("Error opening fiche.txt");
    return;
}

    res1 = nbETS();
    res2 = moyRDV(jour, mois, annee, f1);
printf("res1: %d\n", res1);
printf("res2: %.2f\n", res2);

    fclose(f1);

    if (res1 == 0) {
        gtk_label_set_text(nbrets, "Pas encore d'établissements choisis");
        gtk_label_set_text(moy, "Pas de RDVs pour ce jour-là");
    } else {
        char res1_str[10];
        snprintf(res1_str, sizeof(res1_str), "%d", res1);
        gtk_label_set_text(nbrets, res1_str);

        if (res1 > 0) {
            char res2_str[20]; // Adjust the size based on the expected length of res2
            snprintf(res2_str, sizeof(res2_str), "%.2f", res2);
            gtk_label_set_text(moy, res2_str);
        } else {
            gtk_label_set_text(moy, "Pas de RDVs pour ce jour-là");
        }
    }
}


void
on_treeviewajout_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_actualiserajout_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajouter,*w1;
GtkWidget *treeviewajout;
w1=lookup_widget(button,"fenetre_ajout");
fenetre_ajouter=create_fenetre_ajouter();
gtk_widget_show(fenetre_ajouter);
gtk_widget_hide (w1);
treeviewajout=lookup_widget(fenetre_ajouter,"treeviewajout");
afficher(treeviewajout);
}


void
on_treeviewmodif_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_actualisermodif_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modifier,*w1;
GtkWidget *treeviewmodif;
w1=lookup_widget(button,"fenetre_modifier");
fenetre_modifier=create_fenetre_modifier();
gtk_widget_show(fenetre_modifier);
gtk_widget_hide (w1);
treeviewmodif=lookup_widget(fenetre_modifier,"treeviewmodif");
afficher(treeviewmodif);
}


//void
//on_treeview5_row_activated             (GtkTreeView     *treeview,
 //                                       GtkTreePath     *path,
//                                        GtkTreeViewColumn *column,
//                                        gpointer         user_data)
//{

//}


void
on_actualisersupp_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_supprimer,*w1;
GtkWidget *treeviewsupp;
w1=lookup_widget(button,"fenetre_supprimer");
fenetre_supprimer=create_fenetre_supprimer();
gtk_widget_show(fenetre_supprimer);
gtk_widget_hide (w1);
treeviewsupp=lookup_widget(fenetre_supprimer,"treeviewsupp");
afficher(treeviewsupp);
}


void
on_treeviewsupp_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_retournerajout_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *bureau;
 GtkWidget *gestion;
 bureau=lookup_widget(button,"fenetre_ajouter");
 gestion=lookup_widget(button,"fenetre_gestion");
 gtk_widget_hide(bureau);
 gestion=create_fenetre_gestion();
 gtk_widget_show(gestion);
}


void
on_retournermodif_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *bureau;
 GtkWidget *gestion;
 bureau=lookup_widget(button,"fenetre_modifier");
 gestion=lookup_widget(button,"fenetre_gestion");
 gtk_widget_hide(bureau);
 gestion=create_fenetre_gestion();
 gtk_widget_show(gestion);
}


void
on_retournersupp_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *bureau;
 GtkWidget *gestion;
 bureau=lookup_widget(button,"fenetre_supprimer");
 gestion=lookup_widget(button,"fenetre_gestion");
 gtk_widget_hide(bureau);
 gestion=create_fenetre_gestion();
 gtk_widget_show(gestion);
}


void
on_retourner_recherche_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *bureau;
 GtkWidget *gestion;
 bureau=lookup_widget(button,"fenetre_rechercher");
 gestion=lookup_widget(button,"fenetre_gestion");
 gtk_widget_hide(bureau);
 gestion=create_fenetre_gestion();
 gtk_widget_show(gestion);
}


void
on_actualiser_recherche_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
char id1[20];
GtkWidget *identifiant1;
identifiant1=lookup_widget(button,"identifiant1");
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(identifiant1)));
GtkWidget *fenetre_rechercher,*w1;
GtkWidget *treeviewrecherche;
w1=lookup_widget(button,"fenetre_rechercher");
fenetre_rechercher=create_fenetre_rechercher();
gtk_widget_show(fenetre_rechercher);
gtk_widget_hide (w1);
treeviewrecherche=lookup_widget(fenetre_rechercher,"treeviewrecherche");
chercher(id1,treeviewrecherche);
}


void
on_statistiquesredirect_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *bureau;
bureau=lookup_widget(button,"fenetre_gestion");
gtk_widget_destroy(bureau);
GtkWidget *stat ;
stat = create_fenetre_statistiques();
  gtk_widget_show (stat);
}


void
on_retourner_acceuil_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *bureau;
 GtkWidget *acceuil;
 bureau=lookup_widget(button,"fenetre_gestion");
 acceuil=lookup_widget(button,"fenetre_acceuil");
 gtk_widget_hide(bureau);
 acceuil=create_fenetre_acceuil();
 gtk_widget_show(acceuil);
}


void
on_retournerstat_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *bureau;
 GtkWidget *gestion;
 bureau=lookup_widget(button,"fenetre_statistiques");
 gestion=lookup_widget(button,"fenetre_gestion");
 gtk_widget_hide(bureau);
 gestion=create_fenetre_gestion();
 gtk_widget_show(gestion);
}


void
on_treeviewrecherche_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}
////////////////////////////////////////////////
void
on_treeview11_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* idetablissement;
gchar* cin;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* type;

don b;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* windowmodifier,*windowgestionfiche,*tre, *nomp,*prep,*cinp,*jrdv,*mrdv,*ardv,*typep;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&idetablissement,2,&cin,3,&jour,4,&mois,5,&annee,6,&type,-1);

windowmodifier=create_window_modfiche();
windowgestionfiche=create_window_gestionfiche();
gtk_widget_hide(windowgestionfiche);
gtk_widget_show(windowmodifier);

nomp=lookup_widget(windowmodifier,"entry2_id");
gtk_entry_set_text(GTK_ENTRY(nomp),id);

prep=lookup_widget(windowmodifier,"entry2_cin");
gtk_entry_set_text(GTK_ENTRY(prep),idetablissement);

cinp=lookup_widget(windowmodifier,"entry2_idetablissement");
gtk_entry_set_text(GTK_ENTRY(cinp),cin);

jrdv=lookup_widget(windowmodifier,"spinbutton2_jour");
gtk_entry_set_text(GTK_ENTRY(jrdv),jour);
mrdv=lookup_widget(windowmodifier,"comboboxentry2_mois");
gtk_entry_set_text(GTK_ENTRY(mrdv),mois);

ardv=lookup_widget(windowmodifier,"spinbutton2_annee");
gtk_entry_set_text(GTK_ENTRY(ardv),annee);
}
}


void
on_button1_wndmod_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier, *windowgestionfiche;
windowgestionfiche=lookup_widget(button,"window_gesionfiche");
gtk_widget_destroy(windowgestionfiche);
windowmodifier=create_window_modfiche ();
gtk_widget_show (windowmodifier);
}


void
on_button2_afffiche_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree,*windowgestionfiche;
windowgestionfiche=lookup_widget(button,"window_gestionfiche");
gtk_widget_destroy(windowgestionfiche);
windowgestionfiche=create_window_gestionfiche();
tree=lookup_widget(windowgestionfiche,"treeview1_afffiche");

afficher_don(tree);

gtk_widget_hide(windowgestionfiche);
gtk_widget_show(windowgestionfiche);
}


void
on_button1_wndaj_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter, *windowgestionfiche;
windowgestionfiche=lookup_widget(button,"window_gestionfiche");
gtk_widget_destroy(windowgestionfiche);
windowajouter=create_window_ajfiche ();
gtk_widget_show (windowajouter);
}





void
on_button1_wndsupp_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
char noom[20];
GtkWidget *windowgestionfiche,*tree, *nmm,*output;
nmm = lookup_widget(button,"entry2_suppfich");
strcpy(noom,gtk_entry_get_text(GTK_ENTRY(nmm)));
supprimer_don(noom,"don.txt");
windowgestionfiche=lookup_widget(button,"window_gestionfiche");
tree=lookup_widget(windowgestionfiche,"treeview1_affiche");
afficher_don(tree);
output=lookup_widget(button,"label2_suppfiche");
gtk_label_set_text(GTK_LABEL(output), "Suppression avec Succès");
gtk_widget_hide(windowgestionfiche);
gtk_widget_show(windowgestionfiche);
}


void
on_button1_wndrech_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *window_rechfiche, *windowgestionfiche;
windowgestionfiche=lookup_widget(button,"window_gestionfiche");
gtk_widget_destroy(windowgestionfiche);
window_rechfiche=create_window_rechfiche ();
gtk_widget_show (window_rechfiche);
}


void
on_radiobutton1_OM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=8;}
}


void
on_radiobutton1_BM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=6;}
}


void
on_radiobutton1_BP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=5;}
}


void
on_radiobutton1_ABM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=4;}
}


void
on_radiobutton1_AM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}


void
on_radiobutton1_ABP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=3;}
}


void
on_radiobutton1_AP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void
on_button1_retaj_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajouter, *windowgestionfiche;
windowajouter=lookup_widget(button,"window_ajfiche");
gtk_widget_destroy(windowajouter);
windowgestionfiche=create_window_gestionfiche ();
gtk_widget_show (windowgestionfiche);
}


void
on_radiobutton1_OP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=7;}
}


void
on_checkbutton1_confaj_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;}
}


void
on_button1_confaj_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
don b;
GtkWidget *windowajout,*nm,*pre,*cinn,*jr,*moi,*anne,*typ,*combobox1, *output, *output1;
windowajout=create_window_ajfiche();
nm= lookup_widget(button,"entry1_id");
pre= lookup_widget(button,"entry1_idetablissement");
cinn = lookup_widget(button,"entry1_cin");
jr = lookup_widget(button,"spinbutton1_jour");
anne = lookup_widget(button,"spinbutton1_anne");

combobox1=lookup_widget(button,"comboboxentry1_mois");

strcpy(b.id,gtk_entry_get_text(GTK_ENTRY(nm)));
strcpy(b.idetablissement,gtk_entry_get_text(GTK_ENTRY(pre)));
strcpy(b.cin,gtk_entry_get_text(GTK_ENTRY(cinn)));



b.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jr));
b.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (anne));



if(x==1)
{strcpy(b.type,"A+");}
else if(x==2)
{strcpy(b.type,"A-");}
else if(x==3)
{strcpy(b.type,"AB+");}
else if(x==4)
{strcpy(b.type,"AB-");}
else if(x==5)
{strcpy(b.type,"B+");}
else if(x==6)
{strcpy(b.type,"B-");}
else if(x==7)
{strcpy(b.type,"O+");}
else if(x==8)
{strcpy(b.type,"O-");}


if ((strcmp(b.id,"")==0) || (strcmp(b.idetablissement,"")==0) ||(strcmp(b.cin,"")==0) ) {
output1=lookup_widget(button,"label1_nnajtfiche");
gtk_label_set_text(GTK_LABEL(output1), "Données manquantes. \n Veuillez remplir tout les champs!");
output=lookup_widget(button,"label1_ajtfichesucc");
gtk_label_set_text(GTK_LABEL(output), "");
}
if (combobox1 != NULL) {
        gchar *selected_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1));

        if (selected_text != NULL) {
            // Affiche le genre sélectionné dans la console (debug)
            g_print("Genre sélectionné : %s\n", selected_text);

            // Copie le genre sélectionné dans la structure c
            strcpy(b.mois, selected_text);

            g_free(selected_text);
        } else {
            // Aucune option sélectionnée dans la combobox
            // Faites quelque chose en conséquence
           l=0;
        }


if(y==1){
ajouter_don(b,"don.txt");

output1=lookup_widget(button,"label1_nnajfiche");
gtk_label_set_text(GTK_LABEL(output1), "");
output=lookup_widget(button,"label1_ajfichesucc");
gtk_label_set_text(GTK_LABEL(output), "Ajout avec Succès");
}
z=0;
k=0;
}
}




void
on_radiobutton2_BM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=6;}
}


void
on_radiobutton2_OM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=8;}
}


void
on_radiobutton2_BP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=5;}
}


void
on_radiobutton2_OP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=7;}
}


void
on_radiobutton2_AM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=2;}
}


void
on_radiobutton2_ABM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=4;}
}


void
on_radiobutton2_AP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=1;}
}


void
on_radiobutton2_ABP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=3;}
}


void
on_button2_retmod_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowmodifier, *windowgestionfiche;
windowmodifier=lookup_widget(button,"window_modfiche");
gtk_widget_destroy(windowmodifier);
windowgestionfiche=create_window_gestionfiche ();
gtk_widget_show (windowgestionfiche);
}


void
on_checkbutton2_confmod_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{k=1;}
}


void
on_button2_confmod_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
don b1;
GtkWidget *windowmodifier,*nm1,*pre1,*cinn1,*jr1,*moi1,*anne1,*typ1,*combobox2,*output2;
windowmodifier=create_window_modfiche();
nm1= lookup_widget(button,"entry2_id");
pre1= lookup_widget(button,"entry2_idetablissement");
jr1 = lookup_widget(button,"spinbutton2_jour");
cinn1= lookup_widget(button,"entry2_cin");
anne1 = lookup_widget(button,"spinbutton2_ardv");

combobox2=lookup_widget(button,"comboboxentry2_mois");

strcpy(b1.id,gtk_entry_get_text(GTK_ENTRY(nm1)));
strcpy(b1.idetablissement,gtk_entry_get_text(GTK_ENTRY(pre1)));
strcpy(b1.cin,gtk_entry_get_text(GTK_ENTRY(cinn1)));
b1.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (jr1));
b1.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (moi1));

if (combobox2 != NULL) {
        gchar *selected_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2));

        if (selected_text != NULL) {
            // Affiche le genre sélectionné dans la console (debug)
            g_print("Genre sélectionné : %s\n", selected_text);

            // Copie le genre sélectionné dans la structure c
            strcpy(b1.mois, selected_text);

            g_free(selected_text);
        } else {
            // Aucune option sélectionnée dans la combobox
            // Faites quelque chose en conséquence
           m=0;
        }


if(z==1)
{strcpy(b1.type,"A+");}
else if(z==2)
{strcpy(b1.type,"A-");}
else if(z==3)
{strcpy(b1.type,"AB+");}
else if(z==4)
{strcpy(b1.type,"AB-");}
else if(z==5)
{strcpy(b1.type,"B+");}
else if(z==6)
{strcpy(b1.type,"B-");}
else if(z==7)
{strcpy(b1.type,"O+");}
else if(z==8)
{strcpy(b1.type,"O-");}




if(k==1){
modifier_don(b1.id,b1,"don.txt");
output2=lookup_widget(button,"label3_modsuufiche");
gtk_label_set_text(GTK_LABEL(output2), "Modification avec Succès");

}
z=0;
m=0;
k=0;
}
}


void
on_treeview2_rechfiche_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_rechfiche_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
char id[20];
int c; 
GtkWidget *nm,*tree,*windowrech,*output;
windowrech=lookup_widget(button,"window_rechfiche");
nm = lookup_widget(button,"entry_rechfiche");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(nm)));
c=rechercher_don(id);
if (c==0)
{
	output=lookup_widget(button,"label4_rechintrou");
	gtk_label_set_text(GTK_LABEL(output), "fiche INTROUVABLE");
}
if (c==1)
{	
tree=lookup_widget(windowrech,"treeview4_recherche");
afficher_rechercher_don(tree);
}
}


void
on_button_rechret_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowrechercher, *windowgestionfiche;
windowrechercher=lookup_widget(button,"window_rechfiche");
gtk_widget_destroy(windowrechercher);
windowgestionfiche=create_window_gestionfiche ();
gtk_widget_show (windowgestionfiche);

}
///////////////////////////////////////////////////////////////
void on_ajouter1_clicked(GtkButton       *button, gpointer user_data)
{

    char id[20];
    char name[50];
    char capacity[20];
    char region[20];
GtkWidget *input1, *input2, *input3, *input4; 
//GtkWidget *ajouterislem;
//ajouterislem=lookup_widget(GTK_WIDGET(button), "ajouterislem");
input1=lookup_widget(GTK_WIDGET(button), "id");
input2=lookup_widget(GTK_WIDGET(button), "name");
input3=lookup_widget(GTK_WIDGET(button), "region");
input4=lookup_widget(GTK_WIDGET(button), "capacity"); 

strcpy(id, gtk_entry_get_text(GTK_ENTRY(input1)));
 if (!GTK_IS_ENTRY(input1) || !GTK_IS_ENTRY(input2) || !GTK_IS_ENTRY(input3) || !GTK_IS_ENTRY(input4)) {
        g_print("Erreur : Tous les widgets ne sont pas du type GtkEntry.\n");
        return;
    }
strcpy(name, gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(region, gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(capacity, gtk_entry_get_text(GTK_ENTRY(input4)));
FILE *f = fopen("ETSS.txt", "a");
    if (f != NULL) {
        fprintf(f, "%s %s %s %s\n",id, name, region, capacity);
        fclose(f);
        }
}
void on_afficher_clicked(GtkWidget *objet, gpointer user_data)
{
					
 GtkWidget *ajouterislem;
 GtkWidget *afficherislem;
 GtkWidget *treeview3;
ajouterislem=lookup_widget(objet, "ajouterislem");
gtk_widget_destroy(ajouterislem);
afficherislem=lookup_widget(objet, "afficherislem");
afficherislem=create_afficherislem();
gtk_widget_show(afficherislem);
treeview3=lookup_widget(afficherislem, "treeview3");
afficherEtablissements(treeview3);
}


void
on_treeview3_row_activated			(GtkTreeView		*treeview3,
						 GtkTreePath		*path,
						 GtkTreeViewColumn	*column,
						 gpointer		user_data)
{
EST est;
GtkTreeIter iter;
gchar* id;
gchar* name;
gchar* region ;
gchar* capacity ;

GtkTreeModel *model = gtk_tree_view_get_model(treeview3);
if (gtk_tree_model_get_iter (model, &iter, path)) {
}
//obtention des valeurs de la ligne selectionnée
gtk_tree_model_get (GTK_TREE_MODEL (model), &iter, 0, &id, 1, &name, 2,&region, 3,&capacity,-1);
 // copie des valeurs dans la variable p de type personne pour le passer à la fonction de suppression 

strcpy(est.id,id);
strcpy(est.name, name);
strcpy(est.region, region);
strcpy(est.capacity, capacity);

// mise à jour de l'affichage de la treeview
afficherEtablissements(treeview3);

}





void
on_buttgestionets_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *HOMEadmin;
 GtkWidget *gestiondesetsislem;
HOMEadmin=lookup_widget(button, "HOMEadmin");
gtk_widget_destroy(HOMEadmin);
gestiondesetsislem=lookup_widget(button, "gestiondesetsislem");
gestiondesetsislem=create_gestiondesetsislem();
gtk_widget_show(gestiondesetsislem);
}


void
on_buttgestionutilisateur_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *affiche;
  GtkWidget *treeview;
  affiche = create_listUser ();
  gtk_widget_show (affiche);
  treeview=lookup_widget(affiche, "treeviewUsers") ;
  showUsers(treeview);
}


void
on_supprimer3_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestiondesetsislem;
 GtkWidget *Supprimerislem;
gestiondesetsislem=lookup_widget(button, "gestiondesetsislem");
gtk_widget_destroy(gestiondesetsislem);
Supprimerislem=lookup_widget(button, "Supprimerislem");
Supprimerislem=create_Supprimerislem();
gtk_widget_show(Supprimerislem);
}





void
on_treeview12_row_activated             (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
EST est;
GtkTreeIter iter;
gchar* id;
gchar* name;
gchar* region ;
gchar* capacity ;

GtkTreeModel *model = gtk_tree_view_get_model(treeview1);
if (gtk_tree_model_get_iter (model, &iter, path)) {
}
//obtention des valeurs de la ligne selectionnée
gtk_tree_model_get (GTK_TREE_MODEL (model), &iter, 0, &id, 1, &name, 2,&region, 3,&capacity,-1);
 // copie des valeurs dans la variable p de type personne pour le passer à la fonction de suppression 

strcpy(est.id,id);
strcpy(est.name, name);
strcpy(est.region, region);
strcpy(est.capacity, capacity);

// mise à jour de l'affichage de la treeview
afficherEtablissements(treeview1);

}


void
on_ok1_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_ok2_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_supprimer2_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
        EST currentEST;  
	char id[20];
	GtkWidget  *identifiant1 ;
        GtkWidget  *sortie;

	identifiant1= lookup_widget(button,"suppid");
                   sortie = lookup_widget(button,"label42");
	strcpy(currentEST.id,gtk_entry_get_text(GTK_ENTRY(identifiant1)));
         removeEstablishment(currentEST.id, "ETSS.txt");
         if( removeEstablishment(currentEST.id, "ETSS.txt") == 0){
gtk_label_set_text(GTK_LABEL(sortie),"Identifiant n`est pas trouve");

}
     
	 
          
	
}



void
on_treeview4_row_activated             (GtkTreeView     *treeview7,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
EST est;
GtkTreeIter iter;
gchar* id;
gchar* name;
gchar* region ;
gchar* capacity ;

GtkTreeModel *model = gtk_tree_view_get_model(treeview7);
if (gtk_tree_model_get_iter (model, &iter, path)) {
}
//obtention des valeurs de la ligne selectionnée
gtk_tree_model_get (GTK_TREE_MODEL (model), &iter, 0, &id, 1, &name, 2,&region, 3,&capacity,-1);
 // copie des valeurs dans la variable p de type personne pour le passer à la fonction de suppression 

strcpy(est.id,id);
strcpy(est.name, name);
strcpy(est.region, region);
strcpy(est.capacity, capacity);

// mise à jour de l'affichage de la treeview
afficherEtablissements(treeview7);

}


void
on_ok_clicked                          (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *input1, *input2;
 GtkWidget *treeview7;
 GtkWidget *regcaptreeislem;
 GtkWidget *togglebutton1, *togglebutton2;
 GtkWidget *capacity;
 
  //char region[50] ;
   int capacite, region;
   EST currentEST;
  int mode;
  char msg[100];
  int i;
    //mode = (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton1))) ? 1 : 2;
    input1 = lookup_widget(GTK_WIDGET(button), "comboboxentry2");
    input2 = lookup_widget(GTK_WIDGET(button), "spinbutton1");
    //togglebutton1 = lookup_widget(GTK_WIDGET(button), "radiobutton4");
    //togglebutton2 = lookup_widget(GTK_WIDGET(button), "radiobutton3");
    regcap( capacite,region, msg);
    if (capacite==0)
{
gtk_toggle_button_set_active (GTK_RADIO_BUTTON (togglebutton1), TRUE); 
capacity = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
    ETSTrierCapacite("ETSS.txt");

}

else if (region==1)
{
gtk_toggle_button_set_active (GTK_RADIO_BUTTON (togglebutton2), TRUE);
 strcpy(region, gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));
ETSParRegion("ETSS.txt", region) ;
regcap( capacite,region, msg);
}
    treeview7=lookup_widget(regcaptreeislem, "treeview7");

    regcaptreeislem=lookup_widget(button, "regcaptreeislem");
    regcaptreeislem=create_regcaptreeislem();
    gtk_widget_show(regcaptreeislem);
afficherEtablissements(treeview7);
}
 // Assurez-vous que le fichier d'en-tête est inclus

//GtkWidget *create_Afficherislem(void) {
    // Implémentation de la fonction
   // GtkWidget *widget = gtk_button_new_with_label("Afficher");
    // Ajoutez le code nécessaire pour initialiser le widget comme vous le souhaitez
   // return widget;
//}


void
on_treeview5_row_activated             (GtkTreeView     *treeview5,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
EST est;
GtkTreeIter iter;
gchar* id;
gchar* name;
gchar* region ;
gchar* capacity ;

GtkTreeModel *model = gtk_tree_view_get_model(treeview5);
if (gtk_tree_model_get_iter (model, &iter, path)) {
}
//obtention des valeurs de la ligne selectionnée
gtk_tree_model_get (GTK_TREE_MODEL (model), &iter, 0, &id, 1, &name, 2,&region, 3,&capacity,-1);
 // copie des valeurs dans la variable p de type personne pour le passer à la fonction de suppression 

strcpy(est.id,id);
strcpy(est.name, name);
strcpy(est.region, region);
strcpy(est.capacity, capacity);

// mise à jour de l'affichage de la treeview
afficherEtablissementsapressupp(treeview5);


}


void
on_afficher8_clicked                   (GtkWidget *objet, gpointer user_data)
{
        GtkWidget *Supprimerislem;
        GtkWidget *affichesuppressionislem;
        GtkWidget *treeview5;
Supprimerislem=lookup_widget(objet, "Supprimerislem");
gtk_widget_destroy(Supprimerislem);
affichesuppressionislem=lookup_widget(objet, "affichesuppressionislem");
affichesuppressionislem=create_affichesuppressionislem();
gtk_widget_show(affichesuppressionislem);
treeview5=lookup_widget(objet,"treeview5");
void afficherEtablissementsapressupp(treeview5);
}


void
on_modifier1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{ 
	char id[20];
        GtkWidget *Modifierislem;
        GtkWidget *sortie;
        EST currentEST;
        EST modifiedEST;
        //int tr=0;
GtkWidget *input1, *input2, *input3, *input4; 
//GtkWidget *ajouterislem;
//ajouterislem=lookup_widget(GTK_WIDGET(button), "ajouterislem");
input1=lookup_widget(GTK_WIDGET(button), "entry5");
input2=lookup_widget(GTK_WIDGET(button), "entry11");
input3=lookup_widget(GTK_WIDGET(button), "entry12");
input4=lookup_widget(GTK_WIDGET(button), "entry13"); 
sortie=lookup_widget(GTK_WIDGET(button), "label41"); 
strcpy(currentEST.id,gtk_entry_get_text(GTK_ENTRY(input1)));
findEstablishment(currentEST.id, "ETSS.txt");
if(strcmp(currentEST.id,id) == 0){

gtk_label_set_text(GTK_LABEL(sortie),"Identifiant n`est pas trouve");
}
strcpy(modifiedEST.id, gtk_entry_get_text(GTK_ENTRY(input1)));
 if (!GTK_IS_ENTRY(input1) || !GTK_IS_ENTRY(input2) || !GTK_IS_ENTRY(input3) || !GTK_IS_ENTRY(input4)) {
        g_print("Erreur : Tous les widgets ne sont pas du type GtkEntry.\n");
        return;
    }
strcpy(modifiedEST.name, gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(modifiedEST.region, gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(modifiedEST.capacity, gtk_entry_get_text(GTK_ENTRY(input4)));
modifyEstablishment(currentEST.id,  modifiedEST, "ETSS.txt");
	
}



void
on_capacite_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
int capacite;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  capacite=0;
}


void
on_region_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 int region;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  region=1;
}







void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *affichesuppressionislem,*w1;
GtkWidget *treeview5;
w1=lookup_widget(button,"affichesuppressionislem");
affichesuppressionislem=create_affichesuppressionislem();
gtk_widget_show(affichesuppressionislem);
gtk_widget_hide (w1);
treeview5=lookup_widget(affichesuppressionislem,"treeview5");
afficherEtablissements(treeview5);
}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifierislem,*w1;
GtkWidget *treeview1;
w1=lookup_widget(button,"Modifierislem");
Modifierislem=create_Modifierislem();
gtk_widget_show(Modifierislem);
gtk_widget_hide (w1);
treeview1=lookup_widget(Modifierislem,"treeview1");
afficherEtablissements(treeview1);
}


void
on_login_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
//typedef struct {
        GtkWidget *entry_nom;
        GtkWidget *entry_id;
        GtkWidget *loginislemadmin;
        GtkWidget *HOMEadmin;
        GtkWidget *sortie;
   // } AppWidgets;

   // AppWidgets *widgets = (AppWidgets *)user_data;
    char nom[50];
    char id[50];
    const char *expected_nom = "islem";  // Change this to your expected value
    const char *expected_id = "1234";    // Change this to your expected value
             entry_nom =lookup_widget(GTK_WIDGET(button), "entry14");
             entry_id= lookup_widget(GTK_WIDGET(button), "entry15");
   strcpy(nom, gtk_entry_get_text(GTK_ENTRY(entry_nom)));
strcpy(id, gtk_entry_get_text(GTK_ENTRY(entry_id)));
    //const char *entered_nom = gtk_entry_get_text(GTK_ENTRY(entry14));
    //const char *entered_id = gtk_entry_get_text(GTK_ENTRY(entry15));
    sortie = lookup_widget(button,"label45");
    if ((strcmp(nom, expected_nom) == 0) && (strcmp(id, expected_id) == 0)) {
        // Successful login, show the main window
        loginislemadmin=lookup_widget(button, "loginislemadmin");
gtk_widget_destroy(loginislemadmin);
HOMEadmin=lookup_widget(button, "HOMEadmin");
HOMEadmin=create_HOMEadmin();
gtk_widget_show(HOMEadmin);
        //gtk_widget_show_all(widgets->window_main);
    } else {
        // Display an error message
        gtk_label_set_text(GTK_LABEL(sortie), "Invalid credentials");
    }
}


void
on_ajouterg_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestiondesetsislem;
 GtkWidget *ajouterislem;
gestiondesetsislem=lookup_widget(button, "gestiondesetsislem");
gtk_widget_destroy(gestiondesetsislem);
ajouterislem=lookup_widget(button, "ajouterislem");
ajouterislem=create_ajouterislem();
gtk_widget_show(ajouterislem);
}


void
on_modifierg_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestiondesetsislem;
 GtkWidget *Modifierislem;
gestiondesetsislem=lookup_widget(button, "gestiondesetsislem");
gtk_widget_destroy(gestiondesetsislem);
Modifierislem=lookup_widget(button, "Modifierislem");
Modifierislem=create_Modifierislem();
gtk_widget_show(Modifierislem);
}


void
on_back1_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestiondesetsislem;
 GtkWidget *HOMEadmin;
gestiondesetsislem=lookup_widget(button, "gestiondesetsislem");
gtk_widget_destroy(gestiondesetsislem);
HOMEadmin=lookup_widget(button, "HOMEadmin");
HOMEadmin=create_HOMEadmin();
gtk_widget_show(HOMEadmin);
}


void
on_button18_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *gestiondesetsislem;
 GtkWidget *regcaptreeislem;
gestiondesetsislem=lookup_widget(button, "gestiondesetsislem");
gtk_widget_destroy(gestiondesetsislem);
regcaptreeislem=lookup_widget(button, "regcaptreeislem");
regcaptreeislem=create_regcaptreeislem();
gtk_widget_show(regcaptreeislem);
}


void
on_back2_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajouterislem;
 GtkWidget *gestiondesetsislem;
ajouterislem=lookup_widget(button, "ajouterislem");
gtk_widget_destroy(ajouterislem);
gestiondesetsislem=lookup_widget(button, "gestiondesetsislem");
gestiondesetsislem=create_gestiondesetsislem();
gtk_widget_show(gestiondesetsislem);
}


void
on_back3_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifierislem;
 GtkWidget *gestiondesetsislem;
Modifierislem=lookup_widget(button, "Modifierislem");
gtk_widget_destroy(Modifierislem);
gestiondesetsislem=lookup_widget(button, "gestiondesetsislem");
gestiondesetsislem=create_gestiondesetsislem();
gtk_widget_show(gestiondesetsislem);
}


void
on_back4_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Supprimerislem;
 GtkWidget *gestiondesetsislem;
Supprimerislem=lookup_widget(button, "Supprimerislem");
gtk_widget_destroy(Supprimerislem);
gestiondesetsislem=lookup_widget(button, "gestiondesetsislem");
gestiondesetsislem=create_gestiondesetsislem();
gtk_widget_show(gestiondesetsislem);
}


void
on_back5_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *regcaptreeislem;
 GtkWidget *gestiondesetsislem;
regcaptreeislem=lookup_widget(button, "regcaptreeislem");
gtk_widget_destroy(regcaptreeislem);
gestiondesetsislem=lookup_widget(button, "gestiondesetsislem");
gestiondesetsislem=create_gestiondesetsislem();
gtk_widget_show(gestiondesetsislem);
}


void
on_back6_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *affichesuppressionislem;
 GtkWidget *Supprimerislem;
affichesuppressionislem=lookup_widget(button, "affichesuppressionislem");
gtk_widget_destroy(affichesuppressionislem);
Supprimerislem=lookup_widget(button, "Supprimerislem");
Supprimerislem=create_Supprimerislem();
gtk_widget_show(Supprimerislem);
}


void
on_back7_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *afficherislem;
 GtkWidget *ajouterislem;
afficherislem=lookup_widget(button, "afficherislem");
gtk_widget_destroy(afficherislem);
ajouterislem=lookup_widget(button, "ajouterislem");
ajouterislem=create_ajouterislem();
gtk_widget_show(ajouterislem);
}


void
on_chercher1_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
char id[20];
        GtkWidget *Modifierislem;
        GtkWidget *sortie;
        EST currentEST;
        //EST modifiedEST;
        //int tr=0;
GtkWidget *input1; 
//GtkWidget *ajouterislem;
//ajouterislem=lookup_widget(GTK_WIDGET(button), "ajouterislem");
input1=lookup_widget(GTK_WIDGET(button), "entry5"); 
sortie=lookup_widget(GTK_WIDGET(button), "label41"); 
strcpy(currentEST.id,gtk_entry_get_text(GTK_ENTRY(input1)));

if(strcmp(currentEST.id,id) == 0){

gtk_label_set_text(GTK_LABEL(sortie),"Identifiant n`est pas trouve");
}
else 
findEstablishment(currentEST.id, "ETSS.txt");

	
}



