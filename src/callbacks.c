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
on_sincrire_button_clicked             (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	
	// Get identifiant 
	char identifiant [100];
	entry_get_value(objet_graphique, "identifiant_entry", identifiant);
	
	// Get nom 
	char nom [100];
	entry_get_value(objet_graphique, "nom_entry", nom);

	// Get prenom 
	char prenom [100];
	entry_get_value(objet_graphique, "prenom_entry", prenom);

	
	// Get date de naissance 
	char date_de_naissance_jour [100];
	spin_button_get_value(objet_graphique, "date_de_naissance_jour_button", date_de_naissance_jour);
	
	char date_de_naissance_mois [100];
	spin_button_get_value(objet_graphique, "date_de_naissance_mois_button", date_de_naissance_mois);

	char date_de_naissance_annee [100];
	spin_button_get_value(objet_graphique, "date_de_naissance_annee_button", date_de_naissance_annee);

	char  date_de_naissance [100];
	
	strcpy(date_de_naissance, date_de_naissance_jour);
	strcat(date_de_naissance,"/");
	strcat(date_de_naissance,date_de_naissance_mois);
	strcat(date_de_naissance,"/");
	strcat(date_de_naissance,date_de_naissance_annee);

	// Get lieu de naissance 
	char lieu_de_naissance [100];
	entry_get_value(objet_graphique, "lieu_de_naissance_entry", lieu_de_naissance);

	// Get genre 
	int  genre_radio_button_value = radio_button_get_value(objet_graphique, "genre_homme_button");
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
	entry_get_value(objet_graphique, "statut_social_entry", statut_social);

	// Get adresse
	char adresse [100];
	entry_get_value(objet_graphique, "adresse_entry", adresse);

	// Get code postal 
	char code_postal [100];
	entry_get_value(objet_graphique, "code_postal_entry", code_postal);

	// Get gouvernorat
	char gouvernorat [100];
	combo_box_get_value(objet_graphique, "gouvernorat_entry", gouvernorat);

	// Get email
	char email [100];
	entry_get_value(objet_graphique, "email_entry", email);

	// Get Mot de passe 
	char mot_de_passe [100];
	entry_get_value(objet_graphique, "mot_de_passe_entry", mot_de_passe);

	// Get confirmer mot de passe 
	char confirmer_mot_de_passe [100];
	entry_get_value(objet_graphique, "confirmer_mot_de_passe_entry", confirmer_mot_de_passe);
	
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

	label_set_value(objet_graphique, "message_label", message);
		
}

void
on_se_connecter_button_clicked         (GtkWidget *objet_graphique, 
					gpointer         user_data)
{

	GtkWidget * identifiant_entry ;
	char identifiant_value [20];
	identifiant_entry = lookup_widget(objet_graphique, "identifiant_entry") ;
	strcpy(identifiant_value,gtk_entry_get_text(GTK_ENTRY(identifiant_entry)));



	GtkWidget * mot_de_passe_entry ;
	char mot_de_passe_value [20];
	mot_de_passe_entry = lookup_widget(objet_graphique, "mot_de_passe_entry") ;
	strcpy(mot_de_passe_value,gtk_entry_get_text(GTK_ENTRY(mot_de_passe_entry)));



	GtkWidget * message_label ;
	char * message_value;
	message_label = lookup_widget(objet_graphique, "message_label") ;
	message_value = se_connecter(identifiant_value, mot_de_passe_value);  

	gtk_label_set_text(GTK_LABEL(message_label), message_value);

   	

}


void
on_reinitialiser_mot_de_passe_button_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_sauvegarder_button_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}




