#include<gtk/gtk.h>
#include<stdlib.h>

static void destroy(GtkWidget * widget, gpointer user_data){
  gtk_main_quit();
}

int main(int argc, char* argv[]){
  GtkWidget *window, *pane;
  GtkWidget *button1,*button2;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy),NULL);
  gtk_window_set_title(GTK_WINDOW(window),"Panes");

  gtk_container_set_border_width(GTK_CONTAINER(window), 25);
  gtk_widget_set_size_request(GTK_WIDGET(window), 225, 150);

  pane = gtk_paned_new(GTK_ORIENTATION_HORIZONTAL);
  button1 = gtk_button_new_with_label("Resize");
  button2 = gtk_button_new_with_label("Me!");

  gtk_paned_add1(GTK_PANED(pane), button1);
  gtk_paned_add2(GTK_PANED(pane), button2);

  g_signal_connect_swapped(G_OBJECT(button1), "clicked",
			   G_CALLBACK(gtk_widget_destroy), window);
  g_signal_connect_swapped(G_OBJECT(button2), "clicked",
			   G_CALLBACK(gtk_widget_destroy), window);

  gtk_container_add(GTK_CONTAINER(window), pane);
  gtk_widget_show_all(window);

  gtk_main();

  return EXIT_SUCCESS;
}

			  
