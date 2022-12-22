#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

typedef struct 
{
char identifiant [50];
char nom [50];
char prenom [50];
char date_de_naissance [50];
char lieu_de_naissance [50];
char genre [50];
char statut_social [50];
char addresse [50];
char code_postal [50];
char gouvernorat [50];
char email [50];
char mot_de_passe [50];
char bureau_de_vote [50];
char role [550];
char profession [50];
char liste_electorale [50];
}User;

char * ajouter (User nouveau_user, char file_name[]);

char * modifier(char * identifiant, User nouveau_user);

User chercherParIdentifiant(char identifiant [], char file_name[]);

User chercherParIdentifiantEtMotDePasse(char identifiant [], char mot_de_passe [], char file_name[]);

User chercherParIdentifiantEtDateDeNaissance(char identifiant [], char date_de_naissance [], char file_name[]);

char * se_connecter(char identifiant [], char mot_de_passe []);

char * sinscrire(User u);

char *	reinitialiser_mot_de_passe(char identifiant [],
                                    char date_de_naissance [],
                                    char mot_de_passe [],
                                    char confirmer_mot_de_passe []);

char * supprimer(char identifiant []);


#endif
