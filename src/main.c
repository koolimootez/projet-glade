/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *connexion;

  GtkWidget *inscription;

  GtkWidget *mot_de_passe_oublie;
  
  GtkWidget *Mes_informations_;
  GtkWidget *accueil;
  GtkWidget *gestion_des_elections_;
  GtkWidget *ajout_election_;
  GtkWidget *modif_election_;
  GtkWidget *supprimer_election_;
  GtkWidget *Gestion_utilisateur_;
  GtkWidget *ajout_utilisateur;
  GtkWidget *modification_utlisateur_;
  GtkWidget *supprimer_utilisateur_;
  GtkWidget *Gestion_observateur_;
  GtkWidget *ajouter_observateur_;
  GtkWidget *modifier_observateur_;
  GtkWidget *supprimer_observateur_;
  GtkWidget *Gestion_electeur_;
  GtkWidget *Ajout__electeur;
  GtkWidget *modifier___electeur;
  GtkWidget *supprimer_electeur_;
  GtkWidget *gestion_des_listes_electorales_;
  GtkWidget *Ajout__liste_electorale_;
  GtkWidget *modifier___liste_electorale_;
  GtkWidget *supprimer_liste_electorale_;
  GtkWidget *Gestion_bureau_de_vote;
  GtkWidget *ajouter_bureau_de_vote_;
  GtkWidget *modifier__bureau_de_vote_;
  GtkWidget *supprimer_bureau_de_vote_;
  GtkWidget *Gestion_agent_de_bureau_de_vote;
  GtkWidget *ajouter_agent_de_bureau_de_vote_;
  GtkWidget *modifier_agent_de_bureau_de_vote_;
  GtkWidget *supprimer_agent_de_bureau_de_vote_;
  GtkWidget *gestion__reclamation_;
  GtkWidget *ajout_reclamation_;
  GtkWidget *modif_reclamation_;
  GtkWidget *supprimer_reclamation_;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  
    //connexion = create_connexion ();
    //gtk_widget_show (connexion);

     //inscription = create_inscription ();
     //gtk_widget_show (inscription);

    //mot_de_passe_oublie = create_mot_de_passe_oubli__ ();
    //gtk_widget_show (mot_de_passe_oublie);

    // Mes_informations_ = create_Mes_informations_ ();
    // gtk_widget_show (Mes_informations_);

    ajout_utilisateur = create_ajout_utilisateur ();
    gtk_widget_show (ajout_utilisateur);

    //modification_utlisateur_ = create_modification_utlisateur_ ();
    //gtk_widget_show (modification_utlisateur_);
    // supprimer_utilisateur_ = create_supprimer_utilisateur_ ();
    // gtk_widget_show (supprimer_utilisateur_);

  /*


  accueil = create_accueil ();
  gtk_widget_show (accueil);
  gestion_des_elections_ = create_gestion_des_elections_ ();
  gtk_widget_show (gestion_des_elections_);
  ajout_election_ = create_ajout_election_ ();
  gtk_widget_show (ajout_election_);
  modif_election_ = create_modif_election_ ();
  gtk_widget_show (modif_election_);
  supprimer_election_ = create_supprimer_election_ ();
  gtk_widget_show (supprimer_election_);
  Gestion_utilisateur_ = create_Gestion_utilisateur_ ();
  gtk_widget_show (Gestion_utilisateur_);

  Gestion_observateur_ = create_Gestion_observateur_ ();
  gtk_widget_show (Gestion_observateur_);
  ajouter_observateur_ = create_ajouter_observateur_ ();
  gtk_widget_show (ajouter_observateur_);
  modifier_observateur_ = create_modifier_observateur_ ();
  gtk_widget_show (modifier_observateur_);
  supprimer_observateur_ = create_supprimer_observateur_ ();
  gtk_widget_show (supprimer_observateur_);
  Gestion_electeur_ = create_Gestion_electeur_ ();
  gtk_widget_show (Gestion_electeur_);
  Ajout__electeur = create_Ajout__electeur ();
  gtk_widget_show (Ajout__electeur);
  modifier___electeur = create_modifier___electeur ();
  gtk_widget_show (modifier___electeur);
  supprimer_electeur_ = create_supprimer_electeur_ ();
  gtk_widget_show (supprimer_electeur_);
  gestion_des_listes_electorales_ = create_gestion_des_listes_electorales_ ();
  gtk_widget_show (gestion_des_listes_electorales_);
  Ajout__liste_electorale_ = create_Ajout__liste_electorale_ ();
  gtk_widget_show (Ajout__liste_electorale_);
  modifier___liste_electorale_ = create_modifier___liste_electorale_ ();
  gtk_widget_show (modifier___liste_electorale_);
  supprimer_liste_electorale_ = create_supprimer_liste_electorale_ ();
  gtk_widget_show (supprimer_liste_electorale_);
  Gestion_bureau_de_vote = create_Gestion_bureau_de_vote ();
  gtk_widget_show (Gestion_bureau_de_vote);
  ajouter_bureau_de_vote_ = create_ajouter_bureau_de_vote_ ();
  gtk_widget_show (ajouter_bureau_de_vote_);
  modifier__bureau_de_vote_ = create_modifier__bureau_de_vote_ ();
  gtk_widget_show (modifier__bureau_de_vote_);
  supprimer_bureau_de_vote_ = create_supprimer_bureau_de_vote_ ();
  gtk_widget_show (supprimer_bureau_de_vote_);
  Gestion_agent_de_bureau_de_vote = create_Gestion_agent_de_bureau_de_vote ();
  gtk_widget_show (Gestion_agent_de_bureau_de_vote);
  ajouter_agent_de_bureau_de_vote_ = create_ajouter_agent_de_bureau_de_vote_ ();
  gtk_widget_show (ajouter_agent_de_bureau_de_vote_);
  modifier_agent_de_bureau_de_vote_ = create_modifier_agent_de_bureau_de_vote_ ();
  gtk_widget_show (modifier_agent_de_bureau_de_vote_);
  supprimer_agent_de_bureau_de_vote_ = create_supprimer_agent_de_bureau_de_vote_ ();
  gtk_widget_show (supprimer_agent_de_bureau_de_vote_);
  gestion__reclamation_ = create_gestion__reclamation_ ();
  gtk_widget_show (gestion__reclamation_);
  ajout_reclamation_ = create_ajout_reclamation_ ();
  gtk_widget_show (ajout_reclamation_);
  modif_reclamation_ = create_modif_reclamation_ ();
  gtk_widget_show (modif_reclamation_);
  supprimer_reclamation_ = create_supprimer_reclamation_ ();
  gtk_widget_show (supprimer_reclamation_);
  
	*/

  gtk_main ();
  return 0;
}

