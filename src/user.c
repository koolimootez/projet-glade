#include <stdio.h>
#include <string.h>

#include "user.h"
#include "search_criteria.h"

void getFieldValue(User u , char key [], char user_value []){
            if(strcmp(key, "identifiant") == 0){
                strcpy(user_value, u.identifiant);
            }
            if(strcmp(key, "nom") == 0){
                strcpy(user_value, u.nom);

            }
            if(strcmp(key, "prenom") == 0){
                strcpy(user_value, u.prenom);
            }
            if(strcmp(key, "date_de_naissance") == 0){
                strcpy(user_value, u.date_de_naissance);
            }
            if(strcmp(key, "lieu_de_naissance") == 0){
                strcpy(user_value, u.lieu_de_naissance);
            }
            if(strcmp(key, "genre") == 0){
                strcpy(user_value, u.genre);
            }
            if(strcmp(key, "statut_social") == 0){
                strcpy(user_value, u.statut_social);
            }
            if(strcmp(key, "addresse") == 0){
                strcpy(user_value, u.addresse);
            }
            if(strcmp(key, "code_postal") == 0){
                strcpy(user_value, u.code_postal);
            }
            if(strcmp(key, "gouvernorat") == 0){
                strcpy(user_value, u.gouvernorat);
            }
            if(strcmp(key, "email") == 0){
               strcpy(user_value, u.email);
            }
            if(strcmp(key, "mot_de_passe") == 0){
                strcpy(user_value, u.mot_de_passe);
            }
            if(strcmp(key, "bureau_de_vote") == 0){
                strcpy(user_value, u.bureau_de_vote);
            }
            if(strcmp(key, "role") == 0){
                strcpy(user_value, u.role);
            }
            if(strcmp(key, "profession") == 0){
                strcpy(user_value, u.profession);
            }
            if(strcmp(key, "liste_electorale") == 0){
                strcpy(user_value, u.liste_electorale);
            }
}
char *  ajouter(User user_to_add, char file_name[]){
    // on veut chercher si un utilisateur existe avec le meme identifiant de user_to_add
    Search_criteria criterias [1];
    strcpy(criterias[0].key, "identifiant");
    strcpy(criterias[0].value, user_to_add.identifiant);

    User searched_user = chercher(criterias);
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
        fprintf(file,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s \n",
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
    if(file !=NULL)
    {

        while(fscanf(file, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
                         iterated_user.identifiant,  iterated_user.nom,  iterated_user.prenom,
                         iterated_user.date_de_naissance,  iterated_user.lieu_de_naissance,
                         iterated_user.genre,  iterated_user.statut_social,
                         iterated_user.addresse,  iterated_user.code_postal,
                         iterated_user.gouvernorat,  iterated_user.email,
                         iterated_user.mot_de_passe, iterated_user.bureau_de_vote,
                         iterated_user.role, iterated_user.profession, iterated_user.liste_electorale)!= EOF)
            {
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
        remove("users.txt");
        rename("users_aux.txt", "users.txt");
        return "L'utilisateur a été modifié avec succès ! ";
    }

}

User chercher(Search_criteria criterias []){
    // parcours du fichiers users.txt
    User u;
    int trouver = 0;
    FILE *file = fopen("users.txt", "r");
    if(file != NULL )
    {
        while(trouver == 0 &&
            fscanf(file,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s",
                          u.identifiant,  u.nom,  u.prenom,  u.date_de_naissance,
                          u.lieu_de_naissance,  u.genre,  u.statut_social,
                          u.addresse,  u.code_postal,  u.gouvernorat,  u.email,
                           u.mot_de_passe, u.bureau_de_vote, u.role, u.profession, u.liste_electorale)  != EOF)
        {
            // verfier si la ligne courrante correspondant à l'identifiant et à la date de naissance donnée
            int i = 0;
            int do_match = 1;
            int total_length = sizeof criterias / sizeof *criterias;;

            while(do_match == 1 && i < total_length)
            {
                    Search_criteria criteria = criterias[i];
                    char userValue [20];
                    getFieldValue(u, criteria.key, userValue);
                    if(strcmp(criteria.value , userValue) != 0)
                    {
                    do_match = 0;
                    }
                   else
                   {
                        i++;
                   }
            }
            if(do_match == 1)
            {
                trouver = 1;
            }
        }
        fclose(file);
    }
    // si l'utilisateur existe => retourner l'utilisateur trouvé
    if(trouver == 1 ) {
        return u;
    }else
       {
        // si l'utilisateur n'existe pas => retourner un user ayant un identifiant vallant à -1
        strcpy(u.identifiant, "-1");
        return u;
       }
}

char *  sinscrire(User u){
    ajouter(u, "users.txt");
    return "Inscription avec succès !";
 }


char * se_connecter(char identifiant [], char mot_de_passe [])
{
    Search_criteria criterias [2];
    strcpy(criterias[0].key , "identifiant");
    strcpy(criterias[0].value , identifiant);

    strcpy(criterias[1].key , "mot_de_passe");
    strcpy(criterias[1].value , mot_de_passe);

	User u = chercher(criterias);

	if(strcpy(u.identifiant, "_1") == 0)
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
        Search_criteria criterias [2];
        strcpy(criterias[0].key , "identifiant");
        strcpy(criterias[0].value , identifiant);

        strcpy(criterias[1].key , "date_de_naissance");
        strcpy(criterias[1].value , date_de_naissance);

        User old_user = chercher(criterias);
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