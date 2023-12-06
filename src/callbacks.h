#include <gtk/gtk.h>


void
on_buttonLogin_clicked                 (GtkButton       *objet_graphique,
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


void
on_comboboxRole_changed                (GtkComboBox     *combobox,
                                        gpointer         user_data);
