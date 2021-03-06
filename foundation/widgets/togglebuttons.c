#include<gtk/gtk.h>

static void button_toggled(GtkToggleButton* button, GtkWidget*);

static void activate(GtkApplication* app, gpointer user_data){
  GtkWidget *window;
  GtkWidget *vbox;
  GtkWidget *toggle1, *toggle2;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Toggle Buttons");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  gtk_widget_set_size_request(GTK_WIDGET(window), 200,200);

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  toggle1 = gtk_toggle_button_new_with_label("_Deactivate the other one!");
  toggle2 = gtk_toggle_button_new_with_label("_No! Deactivate that one!");

  g_signal_connect(G_OBJECT(toggle1), "toggled", G_CALLBACK(button_toggled), toggle2);
  g_signal_connect(G_OBJECT(toggle2), "toggled", G_CALLBACK(button_toggled), toggle1);

  gtk_container_add(GTK_CONTAINER(vbox), toggle1);
  gtk_container_add(GTK_CONTAINER(vbox), toggle2);

  gtk_container_add(GTK_CONTAINER(window), vbox);

  gtk_widget_show_all(window);

}

static void button_toggled(GtkToggleButton *toggle, GtkWidget* other_toggle){
  if(gtk_toggle_button_get_active(toggle))
    gtk_widget_set_sensitive(other_toggle,FALSE);
  else
    gtk_widget_set_sensitive(other_toggle,TRUE);
}

int main(int argc, char* argv[]){
  GtkApplication* app;
  gint status;

  app = gtk_application_new("org.gtk3.widgets.toggle", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}
