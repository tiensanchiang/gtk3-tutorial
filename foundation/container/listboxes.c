#include<gtk/gtk.h>

static void list_row_selected(GtkListBox *list_box, GtkListBoxRow *list_box_row, gpointer user_data){
  gint index = gtk_list_box_row_get_index(list_box_row);
  g_message("selected row at %d.", index);
}

static void activate(GtkApplication *app, gpointer user_data){
  GtkWindow* window;
  GtkListBox* list_box;
  window = (GtkWindow*)gtk_application_window_new(app);
  gtk_window_set_title(window, "List Box");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  gtk_widget_set_size_request(GTK_WIDGET(window), 200, 400);

  list_box = (GtkListBox*)gtk_list_box_new();
  g_signal_connect(G_OBJECT(list_box), "row-selected", G_CALLBACK(list_row_selected), NULL);
  gint i=0;

  for(i=0;i<10;i++){
    GtkLabel *label;
    GtkEntry *entry;
    GtkBox * hbox;
    hbox = (GtkBox*) gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
    entry = (GtkEntry*) gtk_entry_new();
    label = (GtkLabel*)gtk_label_new("Label>>>");

    gtk_box_pack_start(hbox, GTK_WIDGET(label), FALSE, FALSE, 5);
    gtk_box_pack_start(hbox, GTK_WIDGET(entry), TRUE, TRUE, 5);
    
    gtk_list_box_prepend(list_box, GTK_WIDGET(hbox));
  }

  gtk_container_add(GTK_CONTAINER(window), GTK_WIDGET(list_box));
  gtk_widget_show_all(GTK_WIDGET(window));

}

int main(int argc, char* argv[]){
  GtkApplication * app;
  gint status;

  app = gtk_application_new("org.gtk3.listbox", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app),argc,argv);

  g_object_unref(app);

  return status;
}
  
  
