#include<gtk/gtk.h>
#include<glib/gstdio.h>

GtkEntry *entry;
GtkFileChooserButton *chooser;
GtkButton *button;

static void file_changed(GtkFileChooser *, GtkLabel *);
static void rename_clicked(GtkButton* , GtkEntry*);
static void activate(GtkApplication *app, gpointer user_data){

  GtkWidget *window, *vbox, *hbox;
  GtkWidget *label;
  

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Exercise 4-1 File Chooser");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  gtk_widget_set_size_request(window, 400, 400);

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

  label = gtk_label_new("");
  chooser = (GtkFileChooserButton*)gtk_file_chooser_button_new("Chooser File", GTK_FILE_CHOOSER_ACTION_OPEN);
  g_signal_connect(G_OBJECT(chooser), "file-set", G_CALLBACK(file_changed), label);

  entry = (GtkEntry*)gtk_entry_new();
  button = gtk_button_new_with_label("Rename");
  gtk_widget_set_sensitive(GTK_WIDGET(entry), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button), FALSE);
  g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(rename_clicked), entry);
  
  gtk_box_pack_start(GTK_BOX(hbox), GTK_WIDGET(entry), TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), GTK_WIDGET(button), FALSE, FALSE, 0);

  gtk_box_pack_start(GTK_BOX(vbox), GTK_WIDGET(chooser), FALSE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 2);
  gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 2);

  gtk_container_add(GTK_CONTAINER(window), vbox);

  gtk_widget_show_all(window);
}

static void file_changed(GtkFileChooser* chooser, GtkLabel *label){
  
  gchar *selected_file = gtk_file_chooser_get_filename(chooser);
  gtk_label_set_text(label, selected_file);

  gtk_widget_set_sensitive(GTK_WIDGET(entry),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(button), TRUE);
  g_free(selected_file);
}

static void rename_clicked(GtkButton *button, GtkEntry* entry){
  gchar* old_file = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(chooser));
  const gchar* new_file = gtk_entry_get_text(entry);
  g_rename(old_file, new_file);

  gtk_widget_set_sensitive(GTK_WIDGET(entry), FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(button), FALSE);

  g_free(old_file);

}

int main(int argc, char* argv[]){
  GtkApplication *app;
  gint status;

  app = gtk_application_new("org.gtk3.exercise4-1", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}
