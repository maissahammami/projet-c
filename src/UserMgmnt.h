#include<gtk/gtk.h>

typedef struct 
{
char nom[30];
char prenom[30];
char CIN[12];
char DateNaissance[25];
char pwd[30];
char role[30];
}user;

void addUser(user);
void showUsers(GtkWidget *liste);
void delUser(user);
void updateUser(user);
void findUserByRole(GtkWidget *liste,user u);
int login(char cin[],char pass[]);
