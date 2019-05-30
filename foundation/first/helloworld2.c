#include<gtk/gtk.h>

static void destroy(GtkWidget*, gpointer);
static gboolean delete_event(GtkWidget*, GdkEvent*, gpointer);


int main(int argc, char* argv[]){

  GtkWidget *window, *label;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Hello World Extended");
  gtk_window_set_default_size(GTK_WINDOW(window), 300, 300); 
  gtk_container_set_border_width(GTK_CONTAINER(window), 10); 

  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
  g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);

  label = gtk_label_new("Hello World 测试");
  gtk_label_set_selectable(GTK_LABEL(label), TRUE);
  gtk_widget_set_sensitive(label, FALSE);

  gtk_container_add(GTK_CONTAINER(window), label);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;

}

static void destroy(GtkWidget *window, gpointer user_data){
  gtk_main_quit();
}

static gboolean delete_event(GtkWidget *window, GdkEvent * event, gpointer user_data){
  return FALSE;
}
