#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

void entry_get_value(GtkWidget * interface,
			char entry_name [],
			char * value);


void spin_button_get_value(GtkWidget * interface,
			char spin_button_name [],
			char * value);

int radio_button_get_value(GtkWidget * interface,
			char radio_button_name []);

void combo_box_get_value(GtkWidget *interface,
			char combo_box_name [],
			char * value);

void label_set_value(GtkWidget *interface,
			char label_name [],
			char * value);


#endif
