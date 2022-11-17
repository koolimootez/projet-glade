#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

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
char confirmer_mot_de_passe [20];
}User;


char * se_connecter(char identifiant [], char mot_de_passe []);

char * sinscrire(char identifiant [], 
		char nom [],
		char prenom [],
		char date_de_naissance [],
		char lieu_de_naissance [],
		char genre [],
		char statut_social [],
		char addresse [],
		char code_postal [],
		char gouvernorat [],
		char email [],
		char mot_de_passe [],
		char confirmer_mot_de_passe []); 

#endif
