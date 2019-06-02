#include<gtk/gtk.h>

static void check_toggled(GtkToggleButton*, GtkWidget*);

static void activate(GtkApplication* app, gpointer user_data){
  GtkWidget *window, *vbox;
  GtkWidget *check1, *check2, *close;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Check Boxex");
  gtk_container_set_border_width(GTK_CONTAINER(window), 25);
  gtk_widget_set_size_request(window, 200, 400);

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  check1 = gtk_check_button_new_with_label("I'm the main option");
  check2 = gtk_check_button_new_with_label("I rely on the other guy");
  close = gtk_button_new_from_icon_name("window-close", GTK_ICON_SIZE_BUTTON);
  gtk_button_set_always_show_image(GTK_BUTTON(close), TRUE);
  gtk_button_set_label(GTK_BUTTON(close), "Close");

  gtk_widget_set_sensitive(check2, FALSE);
  
  g_signal_connect(G_OBJECT(check1), "toggled", G_CALLBACK(check_toggled), check2);
  //  g_signal_connect(G_OBJECT(check2), "toggled", G_CALLBACK(check_toggled), check1);
  g_signal_connect_swapped(G_OBJECT(close), "clicked", G_CALLBACK(gtk_widget_destroy), window);

  gtk_box_pack_start(GTK_BOX(vbox), check1, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), check2, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), close, FALSE, FALSE, 5);

  gtk_container_add(GTK_CONTAINER(window), vbox);

  gtk_widget_show_all(window);

}

static void check_toggled(GtkToggleButton* toggle, GtkWidget* other){
  if(gtk_toggle_button_get_active(toggle))
    gtk_widget_set_sensitive(other, TRUE);
  else
    gtk_widget_set_sensitive(other, FALSE);
}

int main(int argc, char* argv[]){
  GtkApplication *app;
  gint status;

  app = gtk_application_new("org.gtk3.checkbox", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}

  

  
