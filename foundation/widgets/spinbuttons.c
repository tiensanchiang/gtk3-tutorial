#include<gtk/gtk.h>

static void activate(GtkApplication* app, gpointer user_data){
  GtkWidget *window, *vbox;
  GtkWidget *spin_int, *spin_float;
  GtkAdjustment *integer, *float_pt;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Spin  Buttons");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

  integer = GTK_ADJUSTMENT(gtk_adjustment_new(5.0, 0.0, 10.0, 1.0, 2.0, 2.0));
  float_pt = GTK_ADJUSTMENT(gtk_adjustment_new(0.5, 0.0, 1.0, 0.1, 0.5, 0.5));

  spin_int = gtk_spin_button_new(integer, 1.0, 0);
  spin_float = gtk_spin_button_new(float_pt, 0.1, 1);

  gtk_box_pack_start(GTK_BOX(vbox), spin_int, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), spin_float, FALSE, FALSE, 5);

  gtk_container_add(GTK_CONTAINER(window), vbox);

  gtk_widget_show_all(window);
}

int main(int argc, char* argv[]){
  GtkApplication *app;
  gint status;

  app = gtk_application_new("org.gtk3.spin.button", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}
		       
  
