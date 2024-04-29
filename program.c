#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include<gtk/gtk.h>
#include<glib.h>
                             
void list_files(GtkWidget* button, gpointer user_data);
void change_permissions(GtkWidget* button, gpointer user_data);
void create_file(GtkWidget* button, gpointer user_data);
void delete_file(GtkWidget* button, gpointer user_data);
void create_directory(GtkWidget* button, gpointer user_data);
void delete_directory(GtkWidget* button, gpointer user_data);
void create_symbolic_link(GtkWidget* button, gpointer user_data);
void save_text(GtkWidget* widget, gpointer user_data);
void save_text2(GtkWidget* widget, gpointer user_data);
void on_window_destroy(GtkWidget* widget, gpointer user_data);

void list_files(GtkWidget* button, gpointer user_data) {
    const gchar *text=gtk_entry_get_text(GTK_ENTRY(user_data));
    char Command[]="ls -la ";
 strcat(Command,text);
system(Command);

}

void change_permissions(GtkWidget* button, gpointer user_data){
    // Create the main window
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Change permission");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Connect the main window's destroy event to the callback function
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);

    // Create a vertical box container
    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Create an entry field for the directory path
    GtkWidget* permission = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), permission, FALSE, FALSE, 0);
    gpointer data[2]={user_data,permission};
    button =gtk_button_new_with_label("Confirm");
    g_signal_connect(button,"clicked",G_CALLBACK(save_text),data);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);

        // Show all the widgets
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();
}

void create_file(GtkWidget* button, gpointer user_data) {
GtkWidget *entry=GTK_WIDGET(user_data);
    const gchar *text=gtk_entry_get_text(GTK_ENTRY(entry));
    char Command[]= "touch ";
    strcat(Command,text);
    system(Command);
}

void delete_file(GtkWidget* button, gpointer user_data) {
 GtkWidget *entry=GTK_WIDGET(user_data);
    const gchar *text=gtk_entry_get_text(GTK_ENTRY(entry));
    char Command[]="rm ";
    strcat(Command,text);
    system(Command);
}

void create_directory(GtkWidget* button, gpointer user_data) {
 GtkWidget *entry=GTK_WIDGET(user_data);
    const gchar *text=gtk_entry_get_text(GTK_ENTRY(entry));
    char Command[]="mkdir ";
    strcat(Command,text);
    system(Command);
}

void delete_directory(GtkWidget* button, gpointer user_data) {
 GtkWidget *entry=GTK_WIDGET(user_data);
    const gchar *text=gtk_entry_get_text(GTK_ENTRY(entry));
    char Command[]="rm -r ";
    strcat(Command,text);
    system(Command);
}

void create_symbolic_link(GtkWidget* button, gpointer user_data) {
    // Create the main window
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Create symbolic link");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Connect the main window's destroy event to the callback function
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);

    // Create a vertical box container
    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Create an entry field for the directory path
    GtkWidget* symbolic_link = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), symbolic_link, FALSE, FALSE, 0);
    gpointer data[2]={user_data,symbolic_link};
    button =gtk_button_new_with_label("Confirm");
    g_signal_connect(button,"clicked",G_CALLBACK(save_text2),data);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);

        // Show all the widgets
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();
}
void on_window_destroy(GtkWidget* widget, gpointer user_data) {
    gtk_main_quit();
}
void save_text(GtkWidget* widget, gpointer user_data){
  gpointer* data = (gpointer*)user_data;
    const gchar *text=gtk_entry_get_text(GTK_ENTRY(data[0]));
    const gchar *pr =gtk_entry_get_text(GTK_ENTRY(data[1]));
    char Command[]="chmod ";//777 744

   strcat(Command,pr);
   strcat(Command," ");
   strcat(Command,text);
   system(Command);
}
void save_text2(GtkWidget* widget, gpointer user_data){
  gpointer* data = (gpointer*)user_data;
    const gchar *source_path=gtk_entry_get_text(GTK_ENTRY(data[0]));
    const gchar *symbolic_link=gtk_entry_get_text(GTK_ENTRY(data[1]));
     char Command[]="ln -s ";
       
   strcat(Command,source_path);
   strcat(Command," ");
   strcat(Command,symbolic_link);
   system(Command);
}
   
int main(int argc, char* argv[]) {
    // Initialize GTK	
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "File Manager");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Connect the main window's destroy event to the callback function
    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);

    // Create a vertical box container
    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Create an entry field for the directory path
    GtkWidget* path_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), path_entry, FALSE, FALSE, 0);

    //  list button
    GtkWidget* list_button = gtk_button_new_with_label("List");
    g_signal_connect(list_button, "clicked", G_CALLBACK(list_files),path_entry);
    gtk_box_pack_start(GTK_BOX(vbox), list_button, FALSE, FALSE, 0);

    //  change permissions button
    GtkWidget* permissions_button = gtk_button_new_with_label("Change Permissions");
    g_signal_connect(permissions_button, "clicked", G_CALLBACK(change_permissions), path_entry);
    gtk_box_pack_start(GTK_BOX(vbox), permissions_button, FALSE, FALSE, 0);

    //  create file button
    GtkWidget* create_file_button = gtk_button_new_with_label("Create file");
    g_signal_connect(create_file_button, "clicked", G_CALLBACK(create_file), path_entry);
    gtk_box_pack_start(GTK_BOX(vbox), create_file_button, FALSE, FALSE, 0);
    
    //  delete file button
    GtkWidget* delete_file_button = gtk_button_new_with_label("Delete file");
    g_signal_connect(delete_file_button, "clicked", G_CALLBACK(delete_file), path_entry);
    gtk_box_pack_start(GTK_BOX(vbox), delete_file_button, FALSE, FALSE, 0);
    
   // Create directory button
    GtkWidget* create_directory_button = gtk_button_new_with_label("Create directory ");
    g_signal_connect(create_directory_button, "clicked", G_CALLBACK(create_directory), path_entry);
    gtk_box_pack_start(GTK_BOX(vbox), create_directory_button, FALSE, FALSE, 0);
    
     // Delete directory button
    GtkWidget* delete_directory_button = gtk_button_new_with_label("Delete directory ");
    g_signal_connect(delete_directory_button, "clicked", G_CALLBACK(delete_directory), path_entry);
    gtk_box_pack_start(GTK_BOX(vbox), delete_directory_button, FALSE, FALSE, 0);
    
    //  create symbolic link button
    GtkWidget* symbolic_link_button = gtk_button_new_with_label("Create Symbolic Link");
    g_signal_connect(symbolic_link_button, "clicked", G_CALLBACK(create_symbolic_link), path_entry);
    gtk_box_pack_start(GTK_BOX(vbox), symbolic_link_button, FALSE, FALSE, 0);

    // Show all the widgets
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();
}
