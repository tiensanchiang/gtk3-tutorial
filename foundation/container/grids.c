#include<gtk/gtk.h>
#include<stdlib.h>

static void destroy(GtkWidget * widget, gpointer user_data){
  gtk_main_quit();
}

int main(int argc, char* argv[]){

  GtkWidget *window, *grid;
  GtkWidget *header, *name_label, *name_entry;

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Grids");
  gtk_widget_set_size_request(GTK_WIDGET(window), 150, 100);
  gtk_container_set_border_width(GTK_CONTAINER(window), 25);

  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);

  grid = gtk_grid_new();
  header = gtk_label_new("Enter the follow information...");
  name_label = gtk_label_new("Name:");
  name_entry = gtk_entry_new();

  gtk_grid_set_row_spacing(GTK_GRID(grid), 5);
  gtk_grid_set_column_spacing(GTK_GRID(grid), 5);
  
  gtk_grid_attach(GTK_GRID(grid), header, 0,0,2,1);
  gtk_grid_attach(GTK_GRID(grid), name_label, 0, 1, 1, 1);
  gtk_grid_attach(GTK_GRID(grid), name_entry, 1, 1, 1, 1);

  gtk_container_add(GTK_CONTAINER(window), grid);

  gtk_widget_show_all(window);

  gtk_main();

  return EXIT_SUCCESS;
}
