#include <gtk/gtk.h>

//static void showAdmin (GtkWidget *widget, gpointer data){
//    g_print ("Hello World\n");
//}

static void activate (GtkApplication *app, gpointer user_data){
    GtkWidget *window;
    GtkWidget *button;

    /*Create a window with a title and a default size*/
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "GNOME Button");
    gtk_window_set_default_size (GTK_WINDOW (window), 250, 50);

    gtk_widget_show_all (window);
}

int main (int argc, char *argv[]){
    GtkBuilder *builder;
    GtkWidget *windowApp;
    GtkWidget *window;
    GObject *button;
    GError *error = NULL;

    gtk_init (&argc, &argv);

    /* Construct a GtkBuilder instance and load our UI description */
    builder = gtk_builder_new ();
    if (gtk_builder_add_from_file (builder, "../builder/admin.glade", &error) == 0)
    {
        g_printerr ("Error loading file: %s\n", error->message);
        g_clear_error (&error);
        return 1;
    }

    /* Connect signal handlers to the constructed widgets. */
    window = GTK_WIDGET(gtk_builder_get_object (builder, "admin_window"));
    g_signal_connect (window, "destroy", G_CALLBACK (gtk_main_quit), NULL);

//    button = gtk_builder_get_object (builder, "admin_user");
//    g_signal_connect (button, "clicked", G_CALLBACK (showAdmin), NULL);
//
//    button = gtk_builder_get_object (builder, "button2");
//    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
//
//    button = gtk_builder_get_object (builder, "quit");
//    g_signal_connect (button, "clicked", G_CALLBACK (gtk_main_quit), NULL);
    g_object_unref(builder);
    gtk_widget_show(window);
    gtk_main ();

    return 0;
}