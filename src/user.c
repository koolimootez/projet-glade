#include <stdio.h>
#include <string.h>

#include "user.h"

char *  sinscrire(char identifiant [],
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
		char confirmer_mot_de_passe []){

  	 FILE *f = fopen("users.txt", "a");
    if(f != NULL)
    {
    fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s \n", identifiant, nom, prenom, date_de_naissance, lieu_de_naissance, genre, statut_social, addresse, code_postal, gouvernorat, email, mot_de_passe);
    fclose(f);
    return "Inscription avec succès !";
    } else {
        return "Echec d'inscription !";
    }

 }


char * se_connecter(char identifiant [], char mot_de_passe [])
{
	User u;
	char * message;
	int trouver=0;
	FILE *f= fopen("users.txt", "r");
	if(f != NULL )
	{

		while(trouver == 0 &&
	fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s",  u.identifiant,  u.nom,  u.prenom,  u.date_de_naissance,  u.lieu_de_naissance,  u.genre,  u.statut_social,  u.addresse,  u.code_postal,  u.gouvernorat,  u.email,   u.mot_de_passe)!= EOF)
			{
				if(strcmp(identifiant,   u.identifiant) == 0 && strcmp(mot_de_passe,   u.mot_de_passe) == 0 )
				{
				trouver = 1;
				}
			}
		fclose(f);
	}
	if(trouver== 0)
	{
	return "Identifiant(s) incorrect(s) !";
	}
	else
	{
	return "Connexion avec succès !";
	}

}
User chercher(char identifiant [],
              char date_de_naissance []){
    // parcours du fichiers users.txt
    User u;
    int trouver = 0;
    FILE *file = fopen("users.txt", "r");
    if(file != NULL )
    {
        while(trouver == 0 &&
            fscanf(file,"%s %s %s %s %s %s %s %s %s %s %s %s",
                          u.identifiant,  u.nom,  u.prenom,  u.date_de_naissance,  u.lieu_de_naissance,  u.genre,  u.statut_social,
                          u.addresse,  u.code_postal,  u.gouvernorat,  u.email,   u.mot_de_passe)  != EOF)
        {
            // verfier si la ligne courrante correspondant à l'identifiant et à la date de naissance donnés
            if(strcmp(  u.identifiant, identifiant) == 0 &&
                strcmp(  u.date_de_naissance, date_de_naissance) == 0) {
                trouver = 1;
                }
        }
        fclose(file);
    }
    // si l'utilisateur existe => retourner l'utilisateur trouvé
    if(trouver == 1 ) {
        return u;
    }else{
        // si l'utilisateur n'existe pas => retourner un user ayant un identifiant vallant à -1
        strcpy(u.identifiant, "-1");
        return u;
    }
}

char * modifier(char identifiant [],
                User nouveau_user){
    User u;
    FILE * file = fopen("users.txt", "r");
    FILE * aux_file = fopen("users_aux.txt", "w");
    if(file !=NULL && 
        aux_file !=NULL)
    {
    
        while(fscanf(file, "%s %s %s %s %s %s %s %s %s %s %s %s",
                         u.identifiant,  u.nom,  u.prenom,  u.date_de_naissance,  u.lieu_de_naissance,  u.genre,  u.statut_social,
                         u.addresse,  u.code_postal,  u.gouvernorat,  u.email,   u.mot_de_passe)!= EOF)
            {
                if( strcmp(u.identifiant, identifiant) != 0)
                {
                     fprintf(aux_file,"%s %s %s %s %s %s %s %s %s %s %s %s \n",
                                        u.identifiant,  u.nom,  u.prenom,  u.date_de_naissance,  u.lieu_de_naissance,  u.genre,  u.statut_social,
                                        u.addresse,  u.code_postal,  u.gouvernorat,  u.email,   u.mot_de_passe);
                }
                else
                {
                     fprintf(aux_file,"%s %s %s %s %s %s %s %s %s %s %s %s \n",
                                            nouveau_user.identifiant,  nouveau_user.nom,  nouveau_user.prenom,  nouveau_user.date_de_naissance,
                                          nouveau_user.lieu_de_naissance,  nouveau_user.genre,  nouveau_user.statut_social,  nouveau_user.addresse,
                                          nouveau_user.code_postal,  nouveau_user.gouvernorat,  nouveau_user.email, nouveau_user.mot_de_passe);
                }

            }
        fclose(file);
        fclose(aux_file);
        remove("users.txt");
        rename("users_aux.txt", "users.txt");
        return "L'utilisateur a été modifié avec succès ! ";
    }

}

char *	reinitialiser_mot_de_passe(char identifiant [],
                                    char date_de_naissance [],
                                    char mot_de_passe [],
                                    char confirmer_mot_de_passe []){
    // chercher un utilsateur correspondant à l'identifiant et à la date de naissance saisies
    User old_user = chercher(identifiant, date_de_naissance);
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