#include <gtk/gtk.h>


void
on_buttonLogin1_clicked                 (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonReturn_clicked                (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonAddUser_clicked               (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonReturnUpdate_clicked          (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_buttonUpdateUser_clicked            (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_treeviewUsers_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_statsBtn_clicked                    (GtkButton       *objet_graphique,
                                        gpointer         user_data);

void
on_goToaddUserBtn_clicked              (GtkButton       *button,
                                        gpointer         user_data);
////////////////////////////////////////////////////////////////////////
void
on_retourner_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_rechercher_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser1_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_male_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_female_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_male_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_female_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_male1_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_female1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_drogue_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_tattoo_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_anemie_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_piercing_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_drogue1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_piercing1_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_anemie1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_tattoo1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_male_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_female_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_male1_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_female1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeviewgestion_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_modifier_redirect_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercher_redirect_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_statistiques_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_redirect_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_redirect_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser_gestion_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_retourner_redirect_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_gestion_donneur_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewaffiche_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeviewrdv_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_chercherrdv_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficherrdv_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_valider_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewajout_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_actualiserajout_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewmodif_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_actualisermodif_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview5_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_actualisersupp_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewsupp_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retournerajout_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_retournermodif_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_retournersupp_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_retourner_recherche_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser_recherche_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_statistiquesredirect_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_retourner_acceuil_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_retournerstat_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewrecherche_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);
////////////////////////////////////////////////////////////////////////
void
on_treeview11_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button2_afffiche_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_wndaj_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_wndmod_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_wndsupp_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_wndrech_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_OM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_BM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_BP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_ABM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_AM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_ABP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_AP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button1_retaj_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_OP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_confaj_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button1_confaj_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton2_BM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_OM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_BP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_OP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_AM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_ABM_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_AP_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_ABP_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button2_retmod_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton2_confmod_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button2_confmod_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2_rechfiche_row_activated   (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_rechfiche_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_rechret_clicked              (GtkButton       *button,
                                        gpointer         user_data);
////////////////////////////////////////////////////////////////////////
void
on_buttgestionets_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttgestionutilisateur_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter1_clicked(GtkButton       *button, gpointer user_data);

void
on_supprimer3_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficher_clicked(GtkWidget *objet, gpointer user_data);

void
on_treeview12_row_activated             (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ok1_clicked                         (GtkButton       *button,
                                        gpointer         user_data);

void
on_ok2_clicked                         (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer2_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview3,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview4_row_activated             (GtkTreeView     *treeview7,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_ok_clicked                          (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview5_row_activated             (GtkTreeView     *treeview5,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_afficher8_clicked                 (GtkWidget *objet, gpointer user_data);

void
on_modifier1_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_capacite_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_region_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);





void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_login_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouterg_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifierg_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_back1_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button18_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_back2_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_back3_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_back4_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_back5_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_back6_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_back7_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercher1_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_rechercher2_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

