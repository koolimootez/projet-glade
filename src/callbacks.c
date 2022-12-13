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
#include "search_criteria.h"
#include "password.h"

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

	// Get addresse
	char addresse [100];
	entry_get_value(interface, "adresse_entry", addresse);

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
    User user_to_add;
    strcpy(user_to_add.identifiant , identifiant);
    strcpy(user_to_add.nom , nom);
    strcpy(user_to_add.prenom , prenom);
    strcpy(user_to_add.date_de_naissance , date_de_naissance);
    strcpy(user_to_add.lieu_de_naissance , lieu_de_naissance);
    strcpy(user_to_add.genre , genre);
    strcpy(user_to_add.statut_social , statut_social);
    strcpy(user_to_add.addresse , addresse);
    strcpy(user_to_add.code_postal , code_postal);
    strcpy(user_to_add.gouvernorat , gouvernorat);
    strcpy(user_to_add.email , email);
    strcpy(user_to_add.mot_de_passe , mot_de_passe);
    strcpy(user_to_add.bureau_de_vote , "");
    strcpy(user_to_add.role , "electeur");
    strcpy(user_to_add.profession , "");
    strcpy(user_to_add.liste_electorale , "");

	char * message = sinscrire(user_to_add);

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

	// attendre 2 secondes
    sleep(2);

	// redirection vers la page d'accueil apres 2 secondes d'attente
	if(strcmp(message,  "Connexion avec succès !") == 0 ){
	  GtkWidget * connexion_fenetre;
      GtkWidget * accueil_fenetre;
      connexion_fenetre = lookup_widget(interface, "connexion");
      gtk_widget_hide (connexion_fenetre);
      accueil_fenetre = create_accueil ();
      gtk_widget_show (accueil_fenetre);
	}
		
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
    char * message = reinitialiser_mot_de_passe(identifiant,
                                                date_de_naissance,
                                                nouveau_mot_de_passe,
                                                confirmer_nouveau_mot_de_passe);

    // display message dans le label
	label_set_value(interface, "message_label", message);
}


void on_mes_informations_sauvgarder_button_clicked
                                        (GtkWidget *interface,
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

    	// Get addresse
    	char addresse [100];
    	entry_get_value(interface, "adresse_entry", addresse);

    	// Get code postal
    	char code_postal [100];
    	entry_get_value(interface, "code_postal_entry", code_postal);

    	// Get gouvernorat
    	char gouvernorat [100];
    	combo_box_get_value(interface, "gouvernorat_entry", gouvernorat);

        // Get bureau de vote
        char bureau_de_vote [100];
        combo_box_get_value(interface, "bureau_de_vote_entry", bureau_de_vote);

    	//get email
    	char email [100];
        entry_get_value(interface, "email_entry", email);


        //get message
        Search_criteria criterias [1];
        strcpy(criterias[0].key , "identifiant");
        strcpy(criterias[0].value , identifiant);


        User old_user = chercher(criterias);
        User new_user;
        strcpy(new_user.identifiant , old_user.identifiant);
        strcpy(new_user.nom , nom);
        strcpy(new_user.prenom , prenom);
        strcpy(new_user.date_de_naissance , date_de_naissance);
        strcpy(new_user.lieu_de_naissance , lieu_de_naissance);
        strcpy(new_user.genre , genre);
        strcpy(new_user.statut_social , statut_social);
        strcpy(new_user.addresse , addresse);
        strcpy(new_user.code_postal , code_postal);
        strcpy(new_user.gouvernorat , gouvernorat);
        strcpy(new_user.email , email);
        strcpy(new_user.mot_de_passe , old_user.mot_de_passe);
        strcpy(new_user.bureau_de_vote , bureau_de_vote);
        strcpy(new_user.role , old_user.role);
        strcpy(new_user.profession , old_user.profession);
        strcpy(new_user.liste_electorale ,  old_user.liste_electorale);

        char * message = modifier(identifiant, new_user);
       // display message dans le label
        label_set_value(interface, "message_label", message);

}


void
on_ajout_utilisateur_sauvegarder_button_clicked
                                        (GtkWidget *interface,
                                        gpointer   user_data)
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
    	combo_box_get_value(interface, "statut_social_entry", statut_social);

    	// Get addresse
    	char addresse [100];
    	entry_get_value(interface, "adresse_entry", addresse);

    	// Get code postal
    	char code_postal [100];
    	entry_get_value(interface, "code_postal_entry", code_postal);

    	// Get gouvernorat
    	char gouvernorat [100];
    	combo_box_get_value(interface, "gouvernorat_entry", gouvernorat);

        // Get role
        char role [100];
        combo_box_get_value(interface, "role_entry", role);

        // Get bureau de vote
        char bureau_de_vote [100];
        combo_box_get_value(interface, "bureau_de_vote_entry", bureau_de_vote);

    	//get email
    	char email [100];
        entry_get_value(interface, "email_entry", email);

        //get profession
    	char profession [100];
        entry_get_value(interface, "profession_entry", profession);

        // Get bureau de vote
        char liste_electorale [100];
        combo_box_get_value(interface, "liste_electorale_entry", liste_electorale);

        // Get password
       char mot_de_passe[12];
        generate_password(mot_de_passe);

        // Get message
        User user_to_add ;
        strcpy(user_to_add.identifiant , identifiant);
        strcpy(user_to_add.nom , nom);
        strcpy(user_to_add.prenom , prenom);
        strcpy(user_to_add.date_de_naissance , date_de_naissance);
        strcpy(user_to_add.lieu_de_naissance , lieu_de_naissance);
        strcpy(user_to_add.genre , genre);
        strcpy(user_to_add.statut_social , statut_social);
        strcpy(user_to_add.addresse , addresse);
        strcpy(user_to_add.code_postal , code_postal);
        strcpy(user_to_add.gouvernorat , gouvernorat);
        strcpy(user_to_add.email , email);
        strcpy(user_to_add.mot_de_passe , mot_de_passe);
        strcpy(user_to_add.bureau_de_vote, bureau_de_vote);
        strcpy(user_to_add.role , role);
        strcpy(user_to_add.profession , profession);
        strcpy(user_to_add.liste_electorale , liste_electorale);

        char * message = ajouter(user_to_add, "users.txt");

        label_set_value(interface, "message_label", message);


}


void
on_modifier_utilisateur_sauvegarder_button_clicked  (GtkWidget *interface,
                                                     gpointer   user_data)
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
        combo_box_get_value(interface, "statut_social_entry", statut_social);

        // Get addresse
        char addresse [100];
        entry_get_value(interface, "adresse_entry", addresse);

        // Get code postal
        char code_postal [100];
        entry_get_value(interface, "code_postal_entry", code_postal);

        // Get gouvernorat
        char gouvernorat [100];
        combo_box_get_value(interface, "gouvernorat_entry", gouvernorat);

        // Get role
        char role [100];
        combo_box_get_value(interface, "role_entry", role);

        // Get bureau de vote
        char bureau_de_vote [100];
        combo_box_get_value(interface, "bureau_de_vote_entry", bureau_de_vote);

        //get email
        char email [100];
        entry_get_value(interface, "email_entry", email);

        //get profession
        char profession [100];
        entry_get_value(interface, "profession_entry", profession);

        // Get bureau de vote
        char liste_electorale [100];
        combo_box_get_value(interface, "liste_electorale_entry", liste_electorale);

        // Get message
        Search_criteria criterias [1];
        strcpy(criterias[0].key , "identifiant");
        strcpy(criterias[0].value , identifiant);
        User old_user = chercher(criterias);
        User new_user ;
        strcpy(new_user.identifiant , identifiant);
        strcpy(new_user.nom , nom);
        strcpy(new_user.prenom , prenom);
        strcpy(new_user.date_de_naissance , date_de_naissance);
        strcpy(new_user.lieu_de_naissance , lieu_de_naissance);
        strcpy(new_user.genre , genre);
        strcpy(new_user.statut_social , statut_social);
        strcpy(new_user.addresse , addresse);
        strcpy(new_user.code_postal , code_postal);
        strcpy(new_user.gouvernorat , gouvernorat);
        strcpy(new_user.email , email);
        strcpy(new_user.mot_de_passe , old_user.mot_de_passe);
        strcpy(new_user.bureau_de_vote, bureau_de_vote);
        strcpy(new_user.role , role);
        strcpy(new_user.profession , profession);
        strcpy(new_user.liste_electorale , liste_electorale);

        char * message = modifier(identifiant, new_user);

        label_set_value(interface, "message_label", message);
}

void
on_annuler_supprimer_utilisateur_button_clicked   (GtkWidget *interface,
                                                   gpointer   user_data)
{
          GtkWidget * gestion_utilisateur_fenetre;
          GtkWidget * supprimer_utilisateur_fenetre;
          supprimer_utilisateur_fenetre = lookup_widget(interface, "supprimer_utilisateur");
          gtk_widget_hide (supprimer_utilisateur_fenetre);
          gestion_utilisateur_fenetre = create_gestion_utilisateur();
          gtk_widget_show (gestion_utilisateur_fenetre);
}

void
on_confirmer_supprimer_utilisateur_button_clicked    (GtkWidget *interface,
                                                      gpointer   user_data)
{
          // Get identifiant
          char identifiant [100];
          entry_get_value(interface, "identifiant_entry", identifiant);

          // Get message
          char * message = supprimer(identifiant);

          label_set_value(interface, "message_label", message);

}

void
on_inscription_button_connexion_fenetre_clicked
                                        (GtkWidget *interface,
                                        gpointer         user_data)
{
  GtkWidget * connexion_fenetre;
  GtkWidget * inscription_fenetre;
  connexion_fenetre = lookup_widget(interface, "connexion");
  gtk_widget_hide (connexion_fenetre);
  inscription_fenetre = create_inscription ();
  gtk_widget_show (inscription_fenetre);
}

void
on_mot_de_passe_oublie_button_connexion_fenetre_clicked
                                        (GtkWidget *interface,
                                        gpointer         user_data)
{
  GtkWidget * connexion_fenetre;
  GtkWidget * mot_de_passe_oublie_fenetre;
  connexion_fenetre = lookup_widget(interface, "connexion");
  gtk_widget_hide (connexion_fenetre);
  mot_de_passe_oublie_fenetre = create_mot_de_passe_oublie ();
  gtk_widget_show (mot_de_passe_oublie_fenetre);
}

void
on_connexion_button_inscription_fenetre_clicked
                                        (GtkWidget *interface,
                                        gpointer         user_data)
{
  GtkWidget * connexion_fenetre;
  GtkWidget * inscription_fenetre;
  inscription_fenetre = lookup_widget(interface, "inscription");
  gtk_widget_hide (inscription_fenetre);
  connexion_fenetre = create_connexion ();
  gtk_widget_show (connexion_fenetre);
}

void
on_connexion_button_mot_de_passe_oublie_clicked
                                        (GtkWidget *interface,
                                        gpointer         user_data)
{
  GtkWidget * connexion_fenetre;
  GtkWidget * mot_de_passe_oublie_fenetre;
  mot_de_passe_oublie_fenetre = lookup_widget(interface, "mot_de_passe_oublie");
  gtk_widget_hide (mot_de_passe_oublie_fenetre);
  connexion_fenetre = create_connexion ();
  gtk_widget_show (connexion_fenetre);
}

void
on_se_deconnecter_button_accueil_fenetre_clicked
                                        (GtkWidget *interface,
                                        gpointer         user_data)
{
  GtkWidget * connexion_fenetre;
  GtkWidget * accueil_fenetre;
  accueil_fenetre = lookup_widget(interface, "accueil");
  gtk_widget_hide (accueil_fenetre);
  connexion_fenetre = create_connexion ();
  gtk_widget_show (connexion_fenetre);

}


void
on_gestion_utilisateur_button_accueil_fenetre_clicked
                                        (GtkWidget * interface,
                                        gpointer         user_data)
{
  GtkWidget * gestion_utilisateur_fenetre;
  GtkWidget * accueil_fenetre;
  accueil_fenetre = lookup_widget(interface, "accueil");
  gtk_widget_hide (accueil_fenetre);
  gestion_utilisateur_fenetre = create_gestion_utilisateur();
  gtk_widget_show (gestion_utilisateur_fenetre);
}


void
on_accueil_button_gestion_utilisateur_fenetre_clicked
                                        (GtkWidget * interface,
                                         gpointer         user_data)
{
      GtkWidget * gestion_utilisateur_fenetre;
      GtkWidget * accueil_fenetre;
      gestion_utilisateur_fenetre = lookup_widget(interface, "gestion_utilisateur");
      gtk_widget_hide (gestion_utilisateur_fenetre);
      accueil_fenetre = create_accueil ();
      gtk_widget_show (accueil_fenetre);
}


void
on_modifier_utilisateur_button_gestion_des_utilisateurs_fenetre_clicked
                                        (GtkWidget * interface,
                                         gpointer         user_data)
{
      GtkWidget * gestion_utilisateur_fenetre;
      GtkWidget * modification_utilisateur_fenetre;
      gestion_utilisateur_fenetre = lookup_widget(interface, "gestion_utilisateur");
      gtk_widget_hide (gestion_utilisateur_fenetre);
      modification_utilisateur_fenetre = create_modification_utlisateur ();
      gtk_widget_show (modification_utilisateur_fenetre);
}


void
on_supprimer_utilisateur_button_gestion_utilisateur_fenetre_clicked
                                        (GtkWidget * interface,
                                         gpointer         user_data)
{
      GtkWidget * gestion_utilisateur_fenetre;
      GtkWidget * supprimer_utilisateur_fenetre;
      gestion_utilisateur_fenetre = lookup_widget(interface, "gestion_utilisateur");
      gtk_widget_hide (gestion_utilisateur_fenetre);
      supprimer_utilisateur_fenetre = create_supprimer_utilisateur ();
      gtk_widget_show (supprimer_utilisateur_fenetre);
}


void
on_ajout_utilisateur_button_gestion_des_utilisateurs_fenetre_clicked
                                        (GtkWidget * interface,
                                         gpointer         user_data)
{
        GtkWidget * gestion_utilisateur_fenetre;
        GtkWidget * ajout_utilisateur_fenetre;
        gestion_utilisateur_fenetre = lookup_widget(interface, "gestion_utilisateur");
        gtk_widget_hide (gestion_utilisateur_fenetre);
        ajout_utilisateur_fenetre = create_ajout_utilisateur ();
        gtk_widget_show (ajout_utilisateur_fenetre);
}


void
on_gestion_utilisateur_button_ajout_utilisateur_fenetre_clicked
                                        (GtkWidget * interface,
                                         gpointer         user_data)
{
      GtkWidget * gestion_utilisateur_fenetre;
      GtkWidget * ajout_utilisateur_fenetre;
      ajout_utilisateur_fenetre = lookup_widget(interface, "ajout_utilisateur");
      gtk_widget_hide (ajout_utilisateur_fenetre);
      gestion_utilisateur_fenetre = create_gestion_utilisateur ();
      gtk_widget_show (gestion_utilisateur_fenetre);
}


void
on_gestion_utilsateur_button_modifier_utilisateur_fenetre_clicked
                                        (GtkWidget * interface,
                                         gpointer         user_data)
{
      GtkWidget * gestion_utilisateur_fenetre;
      GtkWidget * modification_utilisateur_fenetre;
      modification_utilisateur_fenetre = lookup_widget(interface, "modification_utlisateur");
      gtk_widget_hide (modification_utilisateur_fenetre);
      gestion_utilisateur_fenetre = create_gestion_utilisateur ();
      gtk_widget_show (gestion_utilisateur_fenetre);
}


void
on_gestion_utilisateur_button_supprimer_utilisateur_fenetre_clicked
                                        (GtkWidget * interface,
                                         gpointer         user_data)
{
      GtkWidget * gestion_utilisateur_fenetre;
      GtkWidget * supprimer_utilisateur_fenetre;
      supprimer_utilisateur_fenetre = lookup_widget(interface, "supprimer_utilisateur");
      gtk_widget_hide (supprimer_utilisateur_fenetre);
      gestion_utilisateur_fenetre = create_gestion_utilisateur ();
      gtk_widget_show (gestion_utilisateur_fenetre);
}

