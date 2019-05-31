#include<gtk/gtk.h>
#include<stdlib.h>

static void activate(GtkApplication *app, gpointer user_data){
  GtkWidget *window, *fixed;
  GtkWidget *button1, *button2;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Fixed");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  fixed = gtk_fixed_new();
  button1 = gtk_button_new_with_label("Pixel by pixel ...");
  button2 = gtk_button_new_with_label("you choose my fate");

  g_signal_connect_swapped(G_OBJECT(button1), "clicked",
			   G_CALLBACK(gtk_widget_destroy),
			   window);
  g_signal_connect_swapped(G_OBJECT(button2), "clicked",
			   G_CALLBACK(gtk_widget_destroy),
			   window);

  gtk_fixed_put(GTK_FIXED(fixed), button1, 0, 0);
  gtk_fixed_put(GTK_FIXED(fixed), button2, 20, 30);
  
  gtk_container_add(GTK_CONTAINER(window), fixed);

  gtk_widget_show_all(GTK_WIDGET(window));
}

int main(int argc, char* argv[]){
  GtkApplication *app;
  int status;

  app = gtk_application_new("org.gtk3.foundation", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
