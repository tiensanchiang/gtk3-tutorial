#include<gtk/gtk.h>
#include<stdlib.h>

static gboolean button_pressed(GtkWidget*, GdkEventButton*, GtkLabel*);

static void activate(GtkApplication* app, gpointer user_data){

  GtkWidget *window, *eventbox, *label;

  window = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window), "Event Boxes");
  gtk_container_set_border_width(GTK_CONTAINER(window), 10);
  gtk_widget_set_size_request(GTK_WIDGET(window), 200, 50);

  eventbox = gtk_event_box_new();
  label = gtk_label_new("Double-Click Me!");

  gtk_event_box_set_above_child(GTK_EVENT_BOX(eventbox), FALSE);
  g_signal_connect(G_OBJECT(eventbox), "button-press-event",
		   G_CALLBACK(button_pressed), label);

  gtk_container_add(GTK_CONTAINER(eventbox), label);
  gtk_container_add(GTK_CONTAINER(window), eventbox);

  gtk_widget_set_events(eventbox, GDK_BUTTON_PRESS_MASK);
  gtk_widget_realize(eventbox);
  gdk_window_set_cursor(gtk_widget_get_window(GTK_WIDGET(eventbox)), gdk_cursor_new(GDK_HAND1));
  
  gtk_widget_show_all(window);
}


int main(int argc, char* argv[]){

  GtkApplication *app;
  gint status;

  app = gtk_application_new("org.gtk3.foundation.eventboxes", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(G_OBJECT(app), "activate", G_CALLBACK(activate), NULL);

  status = g_application_run(G_APPLICATION(app), argc, argv);

  g_object_unref(app);

  return status;
}
  
static gboolean button_pressed(GtkWidget *eventbox, GdkEventButton *event, GtkLabel *label){
  if(event -> type == GDK_2BUTTON_PRESS){
    const gchar *text = gtk_label_get_text(label);

    if( text[0] == 'D' ){
      gtk_label_set_text(label, "I Was Double-Clicked!");
    }else{
      gtk_label_set_text(label, "Double-Click Me Again!");
    }

 
  }
  return FALSE;
}
