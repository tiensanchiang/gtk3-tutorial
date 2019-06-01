#include<gtk/gtk.h>

static void activate(GtkApplication* app, gpointer user_data){

  GtkWidget *window, *button;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Stock Items");
  gtk_container_set_border_width(GTK_CONTAINER(window), 15);
  gtk_widget_set_size_request(window, 200, 100);

  button = gtk_button_new_from_icon_name("window-close",GTK_ICON_SIZE_BUTTON);
  gtk_button_set_always_show_image(GTK_BUTTON(button), TRUE);
  gtk_button_set_label(GTK_BUTTON(button), "Close");
  g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(gtk_widget_destroy), window);

  gtk_container_add(GTK_CONTAINER(window), button);
  gtk_widget_show_all(window);

}

int main(int argc, char* argv[]){
  GtkApplication *app;
  gint status;

  app = gtk_application_new("org.gtk3.stock", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}
  
