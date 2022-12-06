#ifdef HAVE_CONFIG_H
#  include <config.h>
#  include <string.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "user.h"
#include "widget.h"


void
on_sincrire_button_clicked             (GtkWidget *interface,
                                        gpointer         user_data)
{
	
	// Get identifiant 
	char identifiant [100];
	entry_get_value(interface, "identifiant_entry", identifiant);
	
	// Get nom 
	char nom [100];
	entry_get_value(interface, "nom_entry", nom);

	// Get prenom 
	char prenom [100];
	entry_get_value(interface, "prenom_entry", prenom);

	
	// Get date de naissance 
	char date_de_naissance_jour [100];
	spin_button_get_value(interface, "date_de_naissance_jour_button", date_de_naissance_jour);
	
	char date_de_naissance_mois [100];
	spin_button_get_value(interface, "date_de_naissance_mois_button", date_de_naissance_mois);

	char date_de_naissance_annee [100];
	spin_button_get_value(interface, "date_de_naissance_annee_button", date_de_naissance_annee);

	char  date_de_naissance [100];
	
	strcpy(date_de_naissance, date_de_naissance_jour);
	strcat(date_de_naissance,"/");
	strcat(date_de_naissance,date_de_naissance_mois);
	strcat(date_de_naissance,"/");
	strcat(date_de_naissance,date_de_naissance_annee);

	// Get lieu de naissance 
	char lieu_de_naissance [100];
	entry_get_value(interface, "lieu_de_naissance_entry", lieu_de_naissance);

	// Get genre 
	int  genre_radio_button_value = radio_button_get_value(interface, "genre_homme_button");
	char genre [100];

	if(genre_radio_button_value == 1)
	{
	strcpy(genre,"homme");
	}else
	{
	strcpy(genre,"femme");
	}

	// Get statut social 
	char statut_social [100];
	entry_get_value(interface, "statut_social_entry", statut_social);

	// Get adresse
	char adresse [100];
	entry_get_value(interface, "adresse_entry", adresse);

	// Get code postal 
	char code_postal [100];
	entry_get_value(interface, "code_postal_entry", code_postal);

	// Get gouvernorat
	char gouvernorat [100];
	combo_box_get_value(interface, "gouvernorat_entry", gouvernorat);

	// Get email
	char email [100];
	entry_get_value(interface, "email_entry", email);

	// Get Mot de passe 
	char mot_de_passe [100];
	entry_get_value(interface, "mot_de_passe_entry", mot_de_passe);

	// Get confirmer mot de passe 
	char confirmer_mot_de_passe [100];
	entry_get_value(interface, "confirmer_mot_de_passe_entry", confirmer_mot_de_passe);
	
	// Get message 

	char * message = sinscrire(identifiant,
				nom,
				prenom,
				date_de_naissance,
				lieu_de_naissance,
				genre,
				statut_social,
				adresse,
				code_postal,
				gouvernorat,
				email,
				mot_de_passe,
				confirmer_mot_de_passe);

	label_set_value(interface, "message_label", message);
		
}

void
on_se_connecter_button_clicked         (GtkWidget *interface, 
					gpointer         user_data)
{

	// Get identifiant 
	char identifiant [100];
	entry_get_value(interface, "identifiant_entry", identifiant);

	// Get Mot de passe 
	char mot_de_passe [100];
	entry_get_value(interface, "mot_de_passe_entry", mot_de_passe);
   	
	// Get message
	char * message = se_connecter (identifiant, mot_de_passe);

	label_set_value(interface, "message_label", message);
		
}
void
on_reinitialiser_mot_de_passe_button_clicked (GtkWidget *interface,
                                                gpointer         user_data)
{
    // Get identifiant
    char identifiant [100];
    entry_get_value(interface, "identifiant_entry", identifiant);

    // get date de naissance
    char date_de_naissance_jour [100];
	spin_button_get_value(interface, "date_naissance_jour_button", date_de_naissance_jour);

	char date_de_naissance_mois [100];
	spin_button_get_value(interface, "date_naissance_mois_button", date_de_naissance_mois);

	char date_de_naissance_annee [100];
	spin_button_get_value(interface, "date_naissance_annee_button", date_de_naissance_annee);

	char  date_de_naissance [100];
	strcpy(date_de_naissance, date_de_naissance_jour);
	strcat(date_de_naissance,"/");
	strcat(date_de_naissance,date_de_naissance_mois);
	strcat(date_de_naissance,"/");
	strcat(date_de_naissance,date_de_naissance_annee);

    // get nouveau mot de passe
    char nouveau_mot_de_passe [100];
    entry_get_value(interface, "nouveau_mot_de_passe_entry", nouveau_mot_de_passe);

  // get confirmer nouveau mot de passe
    char confirmer_nouveau_mot_de_passe [100];
    entry_get_value(interface, "confirmer_nouveau_mot_de_passe_entry", confirmer_nouveau_mot_de_passe);

    // get message
    char * message = reinitialiser_mot_de_passe(identifiant, date_de_naissance, nouveau_mot_de_passe, confirmer_nouveau_mot_de_passe);

    // display message dans le label
	label_set_value(interface, "message_label", message);
}

