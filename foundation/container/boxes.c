#include<gtk/gtk.h>
#include<stdlib.h>
#define NUM_NAMES 4

const gchar* names [] = {"Andrew", "Joe", "Samantha", "Jonathan"};

static void destroy(GtkWidget* widget, gpointer user_data){
  gtk_main_quit();
}

static void button_clicked(GtkWidget* widget,  gpointer user_data){
  if(GTK_IS_BOX(user_data))
    g_message("user_data is box");
  if(user_data == NULL)
    g_message("user_data is null");
  
  gtk_box_reorder_child(user_data, widget, 0);
}

int main(int argc, char * argv[]){

  gint i;
  GtkWidget *window, *vbox;

  if(argc <=1 ){
    g_message("Usage: ./boxes start|end");
    exit(1);
  }

  gboolean start;
  if(g_strcmp0(argv[1], "start") == 0){
    start = TRUE;
  }else if(g_strcmp0(argv[1], "end") ==0){
    start = FALSE;
  }else{
    g_message("Usage: ./boxes start|end");
    exit(1);
  }

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Boxes");
  gtk_container_set_border_width(GTK_CONTAINER(window), 25);
  gtk_widget_set_size_request(GTK_WIDGET(window), 200, -1);

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

  for(i = 0; i< NUM_NAMES; i++){
    GtkWidget *button = gtk_button_new_with_label(names[i]);
    /*    gtk_box_pack_start_defaults(GTK_BOX(vbox), button);*/
    if(start){
      gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 5);
    }else{
      gtk_box_pack_end(GTK_BOX(vbox), button, FALSE, FALSE, 5);
    }

    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(button_clicked), vbox);
  }

  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy), NULL);
  
  gtk_container_add(GTK_CONTAINER(window), vbox);
  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}

