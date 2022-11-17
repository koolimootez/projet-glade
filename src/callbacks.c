#ifdef HAVE_CONFIG_H
#  include <config.h>
#  include <string.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "user.h"


void
on_sincrire_button_clicked             (GtkWidget *objet_graphique,
                                        gpointer         user_data)
{
	GtkWidget * identifiant_entry ;
	char identifiant_value [20];
	identifiant_entry = lookup_widget(objet_graphique, "identifiant_entry") ;
	strcpy(identifiant_value,gtk_entry_get_text(GTK_ENTRY(identifiant_entry)));


	GtkWidget * nom_entry ;
	char nom_value [20];
	nom_entry = lookup_widget(objet_graphique, "nom_entry") ;
	strcpy(nom_value,gtk_entry_get_text(GTK_ENTRY(nom_entry)));



	GtkWidget * prenom_entry ;
	char prenom_value [20];
	prenom_entry = lookup_widget(objet_graphique, "prenom_entry") ;	
	strcpy(prenom_value,gtk_entry_get_text(GTK_ENTRY(prenom_entry)));


	GtkWidget * date_de_naissance_jour_button ;
	int date_de_naissance_jour_value;
	date_de_naissance_jour_button = lookup_widget(objet_graphique, "date_de_naissance_jour_button") ;
	date_de_naissance_jour_value = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(date_de_naissance_jour_button));
	char date_de_naissance_jour_string [20];
	sprintf( date_de_naissance_jour_string, "%d", date_de_naissance_jour_value);


	GtkWidget * date_de_naissance_mois_button ;
	int date_de_naissance_mois_value ;
	date_de_naissance_mois_button = lookup_widget(objet_graphique, "date_de_naissance_mois_button") ;
	date_de_naissance_mois_value = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(date_de_naissance_mois_button));
	char date_de_naissance_mois_string [20];
	sprintf( date_de_naissance_mois_string, "%d", date_de_naissance_mois_value);


	GtkWidget * date_de_naissance_annee_button ;
	int date_de_naissance_annee_value ;
	date_de_naissance_annee_button = lookup_widget(objet_graphique, "date_de_naissance_annee_button") ;
	date_de_naissance_annee_value = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(date_de_naissance_annee_button));
	char date_de_naissance_annee_string [20];
	sprintf( date_de_naissance_annee_string, "%d", date_de_naissance_annee_value);


	char date_de_naissance_value [20];
	strcpy(date_de_naissance_value,date_de_naissance_jour_string);
	strcat(date_de_naissance_value,"/");
	strcat(date_de_naissance_value,date_de_naissance_mois_string);
	strcat(date_de_naissance_value,"/");
	strcat(date_de_naissance_value,date_de_naissance_annee_string);

	GtkWidget * lieu_de_naissance_entry ;
	char lieu_de_naissance_value [20];
	lieu_de_naissance_entry = lookup_widget(objet_graphique, "lieu_de_naissance_entry") ;
	strcpy(lieu_de_naissance_value,gtk_entry_get_text(GTK_ENTRY(lieu_de_naissance_entry)));


	GtkWidget * genre_homme_button ;
	int genre_homme_value;
	genre_homme_button = lookup_widget(objet_graphique, "genre_homme_button") ;
	genre_homme_value=gtk_toggle_button_get_active(GTK_RADIO_BUTTON(genre_homme_button));

	
	char genre_value [2];
	if(genre_homme_value == 1)
	{
	strcpy(genre_value,"H");
	}else
	{
	strcpy(genre_value,"F");
	}
	

	GtkWidget * statut_social_entry ;
	char statut_social_value [20];
	statut_social_entry = lookup_widget(objet_graphique, "statut_social_entry") ;
	strcpy(statut_social_value,gtk_entry_get_text(GTK_ENTRY(statut_social_entry)));
	


	GtkWidget * adresse_entry ;
	char adresse_value [20];
	adresse_entry = lookup_widget(objet_graphique, "adresse_entry") ;
	strcpy(adresse_value, gtk_entry_get_text(GTK_ENTRY(adresse_entry)));


	GtkWidget * code_postal_entry ;
	char code_postal_value [20];
	code_postal_entry = lookup_widget(objet_graphique, "code_postal_entry") ;
	strcpy(code_postal_value,gtk_entry_get_text(GTK_ENTRY(code_postal_entry)));



	GtkWidget * gouvernorat_entry ;
	char gouvernorat_value [20];
	gouvernorat_entry = lookup_widget(objet_graphique, "gouvernorat_entry") ;
	strcpy(gouvernorat_value,gtk_combo_box_get_active_text(GTK_COMBO_BOX(gouvernorat_entry)));



	GtkWidget * email_entry ;
	char email_value [20];
	email_entry = lookup_widget(objet_graphique, "email_entry") ;
	strcpy(email_value,gtk_entry_get_text(GTK_ENTRY(email_entry)));



	GtkWidget * mot_de_passe_entry ;
	char mot_de_passe_value [20];
	mot_de_passe_entry = lookup_widget(objet_graphique, "mot_de_passe_entry") ;
	strcpy(mot_de_passe_value,gtk_entry_get_text(GTK_ENTRY(mot_de_passe_entry)));



	GtkWidget * confirmer_mot_de_passe_entry ;
	char confirmer_mot_de_passe_value [20];
	confirmer_mot_de_passe_entry = lookup_widget(objet_graphique, "confirmer_mot_de_passe_entry") ;	
	strcpy(confirmer_mot_de_passe_value,gtk_entry_get_text(GTK_ENTRY(confirmer_mot_de_passe_entry)));



	GtkWidget * message_label ;
	char * message_value;
	message_label = lookup_widget(objet_graphique, "message_label") ;
	message_value = sinscrire(identifiant_value, 
				nom_value,
				prenom_value,
				date_de_naissance_value,
				lieu_de_naissance_value,
				genre_value,
				statut_social_value,
				adresse_value,
				code_postal_value,
				gouvernorat_value,
				email_value,
				mot_de_passe_value,
				confirmer_mot_de_passe_value);  

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

