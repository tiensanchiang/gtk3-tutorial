#include<gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data){
  GtkWidget *window, *vbox, *hbox;
  GtkWidget *question, *label, *pass;
  gchar* str;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Entries");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  str = g_strconcat("What is the password for ", g_get_user_name(), "?", NULL);
  question = gtk_label_new(str);
  label = gtk_label_new("Password");
  pass = gtk_entry_new();

  gtk_entry_set_visibility(GTK_ENTRY(pass), FALSE);
  gtk_entry_set_invisible_char(GTK_ENTRY(pass), '*');
  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

  gtk_box_pack_start(GTK_BOX(vbox), question, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 0);

  gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), pass, FALSE, TRUE, 0);

  gtk_container_add(GTK_CONTAINER(window), vbox);

  gtk_widget_show_all(window);

}

int main(int argc, char* argv[]){
  GtkApplication *app;
  gint status;

  app = gtk_application_new("org.gtk3.entry", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}

  
