#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fiche.h"
static int gender;
static int genre;
int choix[4]={0,0,0,0};
int choice[4]={0,0,0,0};
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

