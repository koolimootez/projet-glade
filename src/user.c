#include <stdio.h>
#include <string.h>

#include "user.h"

char * se_connecter(char identifiant [], char mot_de_passe [])
{
	User u;
	char * message;
	int trouver=0;
	FILE *f= fopen("users.txt", "r");
	if(f != NULL )
	{

		while(trouver == 0 && 
	fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s",u.identifiant,u.nom,u.prenom,u.date_de_naissance,u.lieu_de_naissance,u.genre,u.statut_social,u.addresse,u.code_postal,u.gouvernorat,u.email, u.mot_de_passe, u.confirmer_mot_de_passe)!= EOF)
			{
				if(strcmp(identifiant, u.identifiant) == 0 && strcmp(mot_de_passe, u.mot_de_passe) == 0 )
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
		char confirmer_mot_de_passe []){

	 FILE *f = fopen("users.txt", "a");
	    if(f != NULL)
	    {
		fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s %s %s \n", identifiant, nom, prenom, date_de_naissance, lieu_de_naissance, genre, statut_social, addresse, code_postal, gouvernorat, email, mot_de_passe, confirmer_mot_de_passe);
		fclose(f);
		return "Inscription avec succès !";
	    } else {
	return "Echec d'inscription !";
	}


}
