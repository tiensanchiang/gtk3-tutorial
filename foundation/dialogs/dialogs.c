#include<gtk/gtk.h>

static void button_clicked(GtkButton* button, GtkWindow *window);

static void activate(GtkApplication *, gpointer user_data);

int main(int argc, char* argv[]){
  GtkApplication *app;
  gint status;

  app = gtk_application_new("org.gtk3.dialogs", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}

static void activate(GtkApplication * app, gpointer user_data){

  GtkWidget *window, *button;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Dialogs");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);

  button = gtk_button_new_with_mnemonic("_Click Me");

  g_signal_connect(G_OBJECT(button), "clicked",
		   G_CALLBACK(button_clicked),
		   window);

  gtk_container_add(GTK_CONTAINER(window), button);
  gtk_widget_show_all(window);
}

static void button_clicked(GtkButton *button, GtkWindow *window){
  GtkWidget *dialog, *label, *image, *hbox;
  GtkWidget *content;
  dialog = gtk_dialog_new_with_buttons("Information", window,
				       GTK_DIALOG_MODAL,
				       "_OK", GTK_RESPONSE_OK,
				       NULL);
  label = gtk_label_new("The button was clicked");
  image = gtk_image_new_from_icon_name("window-close",GTK_ICON_SIZE_DIALOG);

  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  gtk_container_set_border_width(GTK_CONTAINER(hbox), 10);
  gtk_box_pack_start(GTK_BOX(hbox), image,FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);

  content = gtk_dialog_get_content_area(GTK_DIALOG(dialog));

  gtk_container_add(GTK_CONTAINER(content), hbox);

  g_signal_connect_swapped(dialog, "response", G_CALLBACK(gtk_widget_destroy), dialog);
  gtk_widget_show_all(dialog);

  
}

  
