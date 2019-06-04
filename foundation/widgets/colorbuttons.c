#include<gtk/gtk.h>

static void color_changed(GtkColorButton*, GtkWidget*);

static void activate(GtkApplication* app, gpointer user_data){
  GtkWidget *window, *button, *label, *hbox;
  GdkColor color;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Color Buttons");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  gdk_color_parse("#003366", &color);
  button = gtk_color_button_new_with_color(&color);
  gtk_color_button_set_title(GTK_COLOR_BUTTON(button), "Select a Color");

  label = gtk_label_new("Look at my color");
  gtk_widget_modify_fg(label, GTK_STATE_NORMAL, &color);

  g_signal_connect(G_OBJECT(button), "color_set", G_CALLBACK(color_changed), label);

  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  gtk_box_pack_start(GTK_BOX(hbox), button, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 5);

  gtk_container_add(GTK_CONTAINER(window), hbox);
  gtk_widget_show_all(window);
}

int main(int argc, char* argv[]){
  GtkApplication * app;
  gint status;

  app = gtk_application_new("org.gtk3.colorbutton", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}

static void color_changed(GtkColorButton *button, GtkWidget *label){
  GdkColor color;
  gtk_color_button_get_color(button, &color);
  
  gtk_widget_modify_fg(label,GTK_STATE_NORMAL, &color);
}

