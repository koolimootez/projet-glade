#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

#include "support.h"
#include "widget.h"

void entry_get_value(GtkWidget * interface,
			char entry_name [],
			char * value){

	GtkWidget * entry = lookup_widget(interface, entry_name) ;

	char value_as_const_char[100];
	strcpy(value,gtk_entry_get_text(GTK_ENTRY(entry)));
	value = value_as_const_char;


}


void spin_button_get_value(GtkWidget * interface,
			char spin_button_name [],
			char * value){

	GtkWidget * spin_button = lookup_widget(interface, spin_button_name) ;
	int spin_button_value = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_button));
	sprintf(value, "%d", spin_button_value);
}

int radio_button_get_value(GtkWidget * interface,
			char radio_button_name []){

	GtkWidget * radio_button = lookup_widget(interface, radio_button_name) ;
	return  gtk_toggle_button_get_active(GTK_RADIO_BUTTON(radio_button));
	
}

void combo_box_get_value(GtkWidget * interface,
			char combo_box_name [],
			char * value){
	
	GtkWidget * combo_box = lookup_widget(interface, combo_box_name);
	char value_as_const_char [100];
	strcpy(value_as_const_char,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo_box)));
	value = value_as_const_char;

}

void label_set_value(	GtkWidget * interface,
			char label_name [],
			char * value){
	GtkWidget * label = lookup_widget(interface, label_name);
	gtk_label_set_text(GTK_LABEL(label), value);

}
