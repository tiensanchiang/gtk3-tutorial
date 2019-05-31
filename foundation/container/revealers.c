#include<gtk/gtk.h>
static void do_reveal(GtkWidget *widget, GtkRevealer* revealer){
  GtkWidget* child;
  child = gtk_label_new("I'm revealed......");

  gtk_container_add(GTK_CONTAINER(revealer), child);
  gtk_revealer_set_reveal_child(revealer, TRUE);
}

static void activate(GtkApplication *app, gpointer user_data){
  GtkWidget *window, *revealer, *button, *hbox;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Revealer");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  gtk_widget_set_size_request(window, 300, 200);

  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

  button = gtk_button_new_with_label("Reveal");
  gtk_box_pack_start(GTK_BOX(hbox), button, FALSE, FALSE, 5);

  revealer = gtk_revealer_new();
  gtk_revealer_set_transition_duration(GTK_REVEALER(revealer), 3000);
  gtk_revealer_set_transition_type(GTK_REVEALER(revealer), GTK_REVEALER_TRANSITION_TYPE_SLIDE_LEFT);
  //  gtk_container_add(GTK_CONTAINER(revealer), child);
  //  gtk_revealer_set_reveal_child(GTK_REVEALER(revealer), TRUE);
  g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(do_reveal), revealer);

  gtk_box_pack_start(GTK_BOX(hbox), revealer, TRUE, TRUE, 5);
  
  gtk_container_add(GTK_CONTAINER(window), hbox);

  gtk_widget_show_all(window);
  
}
int main(int argc, char* argv[]){
  GtkApplication *app;
  gint status;

  app = gtk_application_new("org.gtk3.demo", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}
