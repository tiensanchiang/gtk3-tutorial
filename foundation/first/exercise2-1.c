#include<gtk/gtk.h>

static void destroy(GtkWidget*, gpointer user_data);
static void key_pressed(GtkWidget*, GdkEvent *, gpointer user_data);

int main(int argc, char* argv[]){

  GtkWidget *window, *label;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "San Qiang");
  gtk_widget_set_size_request(window, 300, 100);
  gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);

  
  label = gtk_label_new("Tian");
  gtk_label_set_selectable(GTK_LABEL(label), TRUE);
  g_signal_connect(G_OBJECT(window), "key-press-event", G_CALLBACK(key_pressed), label);
  
  gtk_container_add(GTK_CONTAINER(window), label);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}


static void destroy(GtkWidget* widget, gpointer user_data){
  gtk_main_quit();

}

static void key_pressed(GtkWidget * widget, GdkEvent * event, gpointer user_data){
  const gchar* label = gtk_label_get_text(GTK_LABEL(user_data));
  const gchar* title = gtk_window_get_title(GTK_WINDOW(widget));

  gtk_label_set_text(GTK_LABEL(user_data), title);
  gtk_window_set_title(GTK_WINDOW(widget), label);

}
