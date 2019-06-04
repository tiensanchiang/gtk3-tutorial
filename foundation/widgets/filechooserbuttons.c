#include<gtk/gtk.h>

static void folder_changed(GtkFileChooser *, GtkFileChooser*);
static void file_changed(GtkFileChooser*, GtkLabel*);

static void activate(GtkApplication* app, gpointer user_data){
  GtkWidget *window, *chooser1, *chooser2, *label, *vbox;
  GtkFileFilter *filter1, *filter2;
  
  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "File Chooser Buttons");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  label = gtk_label_new("");

  chooser1 = gtk_file_chooser_button_new("Chooser a Folder",
					 GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
  chooser2 = gtk_file_chooser_button_new("Chooser a Folder",
					 GTK_FILE_CHOOSER_ACTION_OPEN);

  g_signal_connect(G_OBJECT(chooser1), "selection_changed", G_CALLBACK(folder_changed), chooser2);
  g_signal_connect(G_OBJECT(chooser2), "selection_changed", G_CALLBACK(file_changed), label);

  gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(chooser1), g_get_home_dir());
  gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(chooser2), g_get_home_dir());

  filter1 = gtk_file_filter_new();
  filter2 = gtk_file_filter_new();

  gtk_file_filter_set_name(filter1, "Image files");
  gtk_file_filter_set_name(filter2, "All files");

  gtk_file_filter_add_pattern(filter1, "*.png");
  gtk_file_filter_add_pattern(filter1, "*.jpg");
  gtk_file_filter_add_pattern(filter1, "*.gif");
  gtk_file_filter_add_pattern(filter2, "*");

  gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(chooser1), filter1);
  gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(chooser2), filter2);

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  gtk_box_pack_start(GTK_BOX(vbox), chooser1, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), chooser2, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), label, FALSE, FALSE, 0);
  
  gtk_container_add(GTK_CONTAINER(window), vbox);
  gtk_widget_show_all(window);
}


static void folder_changed(GtkFileChooser *chooser1, GtkFileChooser *chooser2){
  gchar *folder = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(chooser1));
  gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(chooser2), folder);

}

static void file_changed(GtkFileChooser *chooser, GtkLabel *label){
  gchar* file = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(chooser));
  gtk_label_set_text(label, file);
}

int main(int argc, char* argv[]){
  GtkApplication *app;
  gint status;

  app = gtk_application_new("org.gtk3.filechooserbutton", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}
