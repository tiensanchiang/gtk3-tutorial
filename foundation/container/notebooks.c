#include<gtk/gtk.h>
#include<stdlib.h>

static void switch_page(GtkWidget* , gpointer);

static void activate(GtkApplication* app, gpointer user_data){

  GtkWidget *window, *notebook;
  GtkWidget *label1, *label2, *child1, *child2;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Notbook");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  gtk_widget_set_size_request(window, 250, 100);

  notebook = gtk_notebook_new();
  label1 = gtk_label_new("Label1");
  label2 = gtk_label_new("Label2");
  child1 = gtk_button_new_with_label("Go to page2 to find the answer.");
  child2 = gtk_button_new_with_label("Go to page1 to find the answer.");

  g_signal_connect(G_OBJECT(child1), "clicked", G_CALLBACK(switch_page), notebook);
  g_signal_connect(G_OBJECT(child2), "clicked", G_CALLBACK(switch_page), notebook);

  gtk_notebook_append_page(GTK_NOTEBOOK(notebook), child1, label1);
  gtk_notebook_append_page(GTK_NOTEBOOK(notebook), child2, label2);

  gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook), GTK_POS_BOTTOM);

  gtk_container_add(GTK_CONTAINER(window), notebook);

  gtk_widget_show_all(window);
  
}

int main(int argc, char* argv[]){
  GtkApplication *app;
  gint status;

  app = gtk_application_new("org.gtk3.foundation.hotebook",G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;

}


static void switch_page(GtkWidget *widget, gpointer user_data){
  gint page = gtk_notebook_get_current_page(GTK_NOTEBOOK(user_data));
  if(page == 0){
    gtk_notebook_set_current_page(GTK_NOTEBOOK(user_data), 1);
  }else{
    gtk_notebook_set_current_page(GTK_NOTEBOOK(user_data), 0);
  }
}
