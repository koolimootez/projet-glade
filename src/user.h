#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#include "search_criteria.h"

typedef struct 
{
char identifiant [20];
char nom [20];
char prenom [20];
char date_de_naissance [20];
char lieu_de_naissance [20];
char genre [20];
char statut_social [50];
char addresse [50];
char code_postal [20];
char gouvernorat [50];
char email [50];
char mot_de_passe [20];
char bureau_de_vote [20];
char role [20];
char profession [20];
char liste_electorale [20];
}User;

char * ajouter (User nouveau_user, char file_name[]);

char * modifier(char * identifiant, User nouveau_user);

User chercher(Search_criteria criterias []);

char * se_connecter(char identifiant [], char mot_de_passe []);

char * sinscrire(User u);

char *	reinitialiser_mot_de_passe(char identifiant [],
                                    char date_de_naissance [],
                                    char mot_de_passe [],
                                    char confirmer_mot_de_passe []);

void getFieldValue(User u , char key [], char user_value []);

char * supprimer(char identifiant []);


#endif
