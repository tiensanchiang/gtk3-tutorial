#include<gtk/gtk.h>

static void activate(GtkApplication* app, gpointer user_data){
  GtkWidget *window, *vbox;
  GtkWidget *scale_int, *scale_float;
  GtkAdjustment *scale_int_adj, *scale_float_adj;
  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Scales");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  gtk_widget_set_size_request(window, 300, 200);

  scale_int_adj = gtk_adjustment_new(0.0, 1, 10.0, 1, 0.0, 0.0);
  scale_float_adj = gtk_adjustment_new(0.0, 0.0, 1.0, 0.1, 0.0, 0.0);

  scale_int = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, scale_int_adj);
  scale_float = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, scale_float_adj);

  gtk_scale_set_digits(GTK_SCALE(scale_int), 0);

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  gtk_box_pack_start(GTK_BOX(vbox), scale_int, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), scale_float, FALSE, FALSE, 0);

  gtk_container_add(GTK_CONTAINER(window), vbox);

  gtk_widget_show_all(window);

}

int main(int argc, char* argv[]){
  GtkApplication *app;
  gint status;

  app = gtk_application_new("org.gtk3.scales", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}

  
