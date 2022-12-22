#include <stdio.h>
#include <string.h>

#include "user.h"

char *  ajouter(User user_to_add, char file_name[]){
    // on veut chercher si un utilisateur existe avec le meme identifiant de user_to_add
    User searched_user = chercherParIdentifiant(user_to_add.identifiant, file_name);
    // si un utilsateur avec le meme identifiant existe => message : L'utilisateur existe déja
    if (strcmp(searched_user.identifiant,"-1") != 0)
    {
    return "utilisateur existe déja !";
    }
    // sinon on ajoute l'utilisateur = message : L'utilisateur a été ajouté avec succès
    else
    {
         FILE *file = fopen(file_name, "a");
        if(file != NULL)
            {
        fprintf(file,"%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;\n",
                    user_to_add.identifiant, user_to_add.nom, user_to_add.prenom, user_to_add.date_de_naissance,
                    user_to_add.lieu_de_naissance, user_to_add.genre, user_to_add.statut_social, user_to_add.addresse,
                    user_to_add.code_postal, user_to_add.gouvernorat, user_to_add.email, user_to_add.mot_de_passe,
                    user_to_add.bureau_de_vote, user_to_add.role, user_to_add.profession, user_to_add.liste_electorale);
        fclose(file);
        return "L'utilisateur a été ajouté avec succès !";
            }
    }

 }

char * modifier(char identifiant [],
                User nouveau_user){

            User iterated_user;
            FILE * file = fopen("users.txt", "r");
            char line [1000];
            if(file !=NULL)
                {
                    while(fgets(line, 1000, file) != NULL)
                        {
                               char * p = strtok(line, ";");
                                sprintf(iterated_user.identifiant, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.nom, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.prenom, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.date_de_naissance, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.lieu_de_naissance, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.genre, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.statut_social, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.addresse, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.code_postal, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.gouvernorat, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.email, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.mot_de_passe, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.bureau_de_vote, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.role, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.profession, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.liste_electorale, "%s", p);
                               if( strcmp(iterated_user.identifiant, identifiant) != 0)
                                {
                                     ajouter(iterated_user, "users_aux.txt");
                                }
                                else
                                {
                                      ajouter(nouveau_user, "users_aux.txt");
                                }
                        }
                    fclose(file);
            }
             remove("users.txt");
             rename("users_aux.txt", "users.txt");
            return "L'utilisateur a été modifié avec succès ! ";

}

User chercherParIdentifiant(char identifiant [], char file_name[]){
    // parcours du fichier users.txt
    User u;
    int trouver = 0;
    char line [1000];
    FILE *file = fopen(file_name, "r");
    if(file != NULL )
    {
         while(trouver == 0 && fgets(line, 1000, file) != NULL)
            {
               char * p = strtok(line, ";");
                sprintf(u.identifiant, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.nom, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.prenom, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.date_de_naissance, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.lieu_de_naissance, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.genre, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.statut_social, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.addresse, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.code_postal, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.gouvernorat, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.email, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.mot_de_passe, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.bureau_de_vote, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.role, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.profession, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.liste_electorale, "%s", p);
                 if(strcmp(u.identifiant , identifiant) == 0)
                  {
                      trouver = 1;
                  }
            }
            fclose(file);
    }

    // si l'utilisateur existe => retourner l'utilisateur trouvé
    if(trouver == 1 ) {
        return u;
    }
    else {
        // si l'utilisateur n'existe pas => retourner un user ayant un identifiant vallant à -1
        strcpy(u.identifiant, "-1");
        return u;
    }
 }

User chercherParIdentifiantEtMotDePasse(char identifiant [], char mot_de_passe [], char file_name[]){
    // parcours du fichier users.txt
    User u;
    int trouver = 0;
    char line [1000];
    FILE *file = fopen(file_name, "r");
    if(file != NULL )
    {
         while(trouver == 0 && fgets(line, 1000, file) != NULL)
            {
               char * p = strtok(line, ";");
                sprintf(u.identifiant, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.nom, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.prenom, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.date_de_naissance, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.lieu_de_naissance, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.genre, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.statut_social, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.addresse, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.code_postal, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.gouvernorat, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.email, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.mot_de_passe, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.bureau_de_vote, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.role, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.profession, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.liste_electorale, "%s", p);
                 if(strcmp(u.identifiant , identifiant) == 0 && strcmp(u.mot_de_passe , mot_de_passe) == 0 )
                  {
                      trouver = 1;
                  }
            }
        fclose(file);
    }
    // si l'utilisateur existe => retourner l'utilisateur trouvé
    if(trouver == 1 ) {
        return u;
    }
    else {
        // si l'utilisateur n'existe pas => retourner un user ayant un identifiant vallant à -1
        strcpy(u.identifiant, "-1");
        return u;
    }
 }

User chercherParIdentifiantEtDateDeNaissance(char identifiant [], char date_de_naissance [], char file_name[]){
    // parcours du fichier users.txt
    User u;
    int trouver = 0;
    char line [1000];
    FILE *file = fopen(file_name, "r");
    if(file != NULL )
    {
         while(trouver == 0 && fgets(line, 1000, file) != NULL)
            {
               char * p = strtok(line, ";");
                sprintf(u.identifiant, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.nom, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.prenom, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.date_de_naissance, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.lieu_de_naissance, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.genre, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.statut_social, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.addresse, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.code_postal, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.gouvernorat, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.email, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.mot_de_passe, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.bureau_de_vote, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.role, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.profession, "%s", p);
                p=strtok(NULL, ";");
                sprintf(u.liste_electorale, "%s", p);
                 if(strcmp(u.identifiant , identifiant) == 0 && strcmp(u.date_de_naissance , date_de_naissance) == 0 )
                  {
                      trouver = 1;
                  }
            }
        fclose(file);
    }
    // si l'utilisateur existe => retourner l'utilisateur trouvé
    if(trouver == 1 ) {
        return u;
    }
    else {
        // si l'utilisateur n'existe pas => retourner un user ayant un identifiant vallant à -1
        strcpy(u.identifiant, "-1");
        return u;
    }
 }

char *  sinscrire(User u){
    char * message = ajouter(u, "users.txt");
    if(strcmp(message, "L'utilisateur a été ajouté avec succès !") == 0){
         return "Inscription avec succès !";
    }
    return message;
 }


char * se_connecter(char identifiant [], char mot_de_passe [])
{
    User u = chercherParIdentifiantEtMotDePasse(identifiant, mot_de_passe, "users.txt");

	if(strcmp(u.identifiant, "-1") == 0)
	{
	return "Identifiant(s) incorrect(s) !";
	}
	else
	{
	return "Connexion avec succès !";
	}

}


char *	reinitialiser_mot_de_passe(char identifiant [],
                                    char date_de_naissance [],
                                    char mot_de_passe [],
                                    char confirmer_mot_de_passe []){
    // chercher un utilsateur correspondant à l'identifiant et à la date de naissance saisies
    User old_user = chercherParIdentifiantEtDateDeNaissance(identifiant, date_de_naissance, "users.txt");
    // si utilisateur existe => alors modifier l'ancien mot de passe par le nouveau et on retourne un message de succès
    if(strcmp(old_user.identifiant, "-1") != 0){
        // modifier l'ancien mot de passe par le nouveau
        User new_user = old_user;
        strcpy(new_user.mot_de_passe, mot_de_passe) ;
        modifier(old_user.identifiant, new_user);
        // on retourne un message de succès
        return "La réinitialisation du mot de passe \n a été effectué avec succès !";
    }
    else{
        // si l'utlisateur n'existe pas => on retourne un message d'erreur
        return "Aucun utlisateur ne correspond pas \n aux identifiant et date de naissance saisies !";
    }


}

char * supprimer (char identifiant [])
{
    // chercher un utilisateur dont l'identifiant est celui saisie dans l'interface
    User user_to_delete = chercherParIdentifiant(identifiant, "users.txt");
    if(strcmp(user_to_delete.identifiant, "-1") == 0){
           return "Aucun utilisateur ne correspond pas à l'identifiant saisie !";
      }else{
            User iterated_user;
            FILE * file = fopen("users.txt", "r");
            char line [1000];
            if(file !=NULL)
                {
                    while(fgets(line, 1000, file) != NULL)
                        {
                               char * p = strtok(line, ";");
                                sprintf(iterated_user.identifiant, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.nom, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.prenom, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.date_de_naissance, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.lieu_de_naissance, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.genre, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.statut_social, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.addresse, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.code_postal, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.gouvernorat, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.email, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.mot_de_passe, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.bureau_de_vote, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.role, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.profession, "%s", p);
                                p=strtok(NULL, ";");
                                sprintf(iterated_user.liste_electorale, "%s", p);
                               if( strcmp(iterated_user.identifiant, identifiant) != 0)
                                {
                                     ajouter(iterated_user, "users_aux.txt");
                                }
                        }
                    fclose(file);
            }
             remove("users.txt");
             rename("users_aux.txt", "users.txt");
           return "Suppression avec succès !";
     }

}