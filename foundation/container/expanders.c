#include<gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data){
  GtkWidget *window,*expander,*label;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Expanders");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  gtk_widget_set_size_request(window, 200, 100);

  expander = gtk_expander_new_with_mnemonic("_Click me for more!");
  label = gtk_label_new("Hide me or show me,\nthat is your choice.");

  gtk_container_add(GTK_CONTAINER(expander), label);
  gtk_expander_set_expanded(GTK_EXPANDER(expander), TRUE);
  gtk_container_add(GTK_CONTAINER(window), expander);

  gtk_widget_show_all(window);
  
}

int main(int argc, char* argv[]){

  GtkApplication* app;
  int status;
  
  app = gtk_application_new("org.gtk3.foundation.expanders",
			    G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
  
  status = g_application_run(G_APPLICATION(app),argc,argv);
  g_object_unref(app);

  return status;
}
