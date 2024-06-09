#include "headers.h"

void activate (GtkApplication *app, void *data);

int main (int argc, char *argv[])
{
    GtkApplication *app;
    int status;

    app = gtk_application_new ("connect.contact", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    
    status = g_application_run (GAPPLICATION (app), argc, argv);

    g_object_unref (app);
    return status;
}

void activate (GtkApplication *app, void *data)
{
    GtkWindow *mainwindow;
    mainwindow = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (mainwindow), "Connect");
    gtk_window_set_default_size (GTK_WINDOW (mainwindow), 400, 400);

    gtk_window_present (GTK_WINDOW (mainwindow));
}