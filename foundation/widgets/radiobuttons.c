#include<gtk/gtk.h>

static void activate(GtkApplication* app, gpointer user_data){
  GtkWidget *window, *vbox;
  GtkWidget *radio1, *radio2,  *radio3, *radio4;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Radio buttons");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  radio1 = gtk_radio_button_new_with_label(NULL, "I want to be clicked");
  radio2 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(radio1), "Click me instead!");
  radio3 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(radio2), "No! Click me!");

  radio4 = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(radio3), "No! click me instead");

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  gtk_box_pack_start(GTK_BOX(vbox), radio1, FALSE, FALSE ,0);
  gtk_box_pack_start(GTK_BOX(vbox), radio2, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), radio3, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), radio4, FALSE, FALSE, 0);

  gtk_container_add(GTK_CONTAINER(window), vbox);

  gtk_widget_show_all(window);

}

int main(int argc, char* argv[]){
  GtkApplication *app;
  gint status;


  app = gtk_application_new("org.gtk3.radiobutton", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}

							   
