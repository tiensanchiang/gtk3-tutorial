#include<gtk/gtk.h>
#include<stdlib.h>
#include<glib/gprintf.h>

#define PAGE_NUM 4

static void activate(GtkApplication* app, gpointer user_data);
static void page_button_clicked(GtkWidget* widget, GtkNotebook* notebook);

int main(int argc, char* argv[]){
  GtkApplication* app;
  gint status;

  app = gtk_application_new("com.gtk3", G_APPLICATION_FLAGS_NONE);

  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);

  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}

static void activate(GtkApplication* app, gpointer user_data){

  GtkWidget *window;
  GtkWidget *hbox, *vbox,*notebook;
  GtkWidget *next_button, *close_button;
  gint i;
  
  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Exercise 2-1");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  gtk_widget_set_size_request(window, 500, 500);

  notebook = gtk_notebook_new();

  for(i = 0; i < PAGE_NUM; i++){
    GtkWidget* button, *label;

    //char *title;
    //    title = malloc(sizeof(char) * 6);
    //    g_sprintf(title, "Page%d", i);

    char title[6]={0};
    g_sprintf(title, "Page%d", i);
    
    button = gtk_button_new_with_label("Next");
    label = gtk_label_new(title);
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), button, label);
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(page_button_clicked), notebook);
    
  }

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  gtk_box_pack_start(GTK_BOX(vbox), notebook, TRUE, TRUE, 5);
    
  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);
  next_button = gtk_button_new_with_label("Next");
  close_button = gtk_button_new_with_label("Close");
  gtk_box_pack_start(GTK_BOX(hbox), next_button, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), close_button, FALSE, FALSE, 5);

  g_signal_connect(G_OBJECT(next_button), "clicked", G_CALLBACK(page_button_clicked), notebook);
  g_signal_connect_swapped(G_OBJECT(close_button), "clicked", G_CALLBACK(gtk_widget_destroy), window);
  gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 5);
  
  
  gtk_container_add(GTK_CONTAINER(window), vbox);

  gtk_widget_show_all(window);
}

static void page_button_clicked(GtkWidget* widget, GtkNotebook *notebook){

  gint next;
  gint current;
  current = gtk_notebook_get_current_page(notebook);
  next = (current + 1) % PAGE_NUM;

  gtk_notebook_set_current_page(notebook, next);
    
  g_message("Button clicked: %d", current);
}  
  
