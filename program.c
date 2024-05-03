#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include<gtk/gtk.h>
#include<glib.h>
#include<stdbool.h>

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
void show_menu();

void list_files(GtkWidget* button, gpointer user_data) {
    const gchar *text=gtk_entry_get_text(GTK_ENTRY(user_data));
    char Command[]="ls ";
 strcat(Command,text);
 system(Command);
gtk_main();
}

void change_permissions(GtkWidget* button, gpointer user_data){

    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Change permission");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

<<<<<<< HEAD
    // Create a vertical box container
=======

    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);

>>>>>>> 38eb532f8facd63d898f333e55b7db773073e710
    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Create an entry field for the directory path
    GtkWidget* permission = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), permission, FALSE, FALSE, 0);
    gpointer data[2]={user_data,permission};
    button =gtk_button_new_with_label("Confirm");
    g_signal_connect(button,"clicked",G_CALLBACK(save_text),data);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);


    gtk_widget_show_all(window);


    gtk_main();
}

void create_file(GtkWidget* button, gpointer user_data) {
GtkWidget *entry=GTK_WIDGET(user_data);
    const gchar *text=gtk_entry_get_text(GTK_ENTRY(entry));
    char Command[]= "touch ";
    strcat(Command,text);
    system(Command);
    gtk_main();
}

void delete_file(GtkWidget* button, gpointer user_data) {
 GtkWidget *entry=GTK_WIDGET(user_data);
    const gchar *text=gtk_entry_get_text(GTK_ENTRY(entry));
    char Command[]="rm ";
    strcat(Command,text);
    system(Command);
     gtk_main();
}

void create_directory(GtkWidget* button, gpointer user_data) {
 GtkWidget *entry=GTK_WIDGET(user_data);
    const gchar *text=gtk_entry_get_text(GTK_ENTRY(entry));
    char Command[]="mkdir ";
    strcat(Command,text);
    system(Command);
     gtk_main();
}

void delete_directory(GtkWidget* button, gpointer user_data) {
 GtkWidget *entry=GTK_WIDGET(user_data);
    const gchar *text=gtk_entry_get_text(GTK_ENTRY(entry));
    char Command[]="rm -r ";
    strcat(Command,text);
    system(Command);
     gtk_main();
}

void create_symbolic_link(GtkWidget* button, gpointer user_data) {
<<<<<<< HEAD
=======

>>>>>>> 38eb532f8facd63d898f333e55b7db773073e710
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Create symbolic link");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

<<<<<<< HEAD
    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);


=======

    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);


    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

>>>>>>> 38eb532f8facd63d898f333e55b7db773073e710
    GtkWidget* symbolic_link = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), symbolic_link, FALSE, FALSE, 0);

    gpointer data[2]={user_data,symbolic_link};
    button =gtk_button_new_with_label("Confirm");
    g_signal_connect(button,"clicked",G_CALLBACK(save_text2),data);
    gtk_box_pack_start(GTK_BOX(vbox), button, FALSE, FALSE, 0);


    gtk_widget_show_all(window);


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
    gtk_main();
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
    gtk_main();
}
<<<<<<< HEAD

void show_menu(){
    // Create the main window
=======

int main(int argc, char* argv[]) {

    gtk_init(&argc, &argv);

>>>>>>> 38eb532f8facd63d898f333e55b7db773073e710
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Menu");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
<<<<<<< HEAD
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);
=======


    g_signal_connect(window, "destroy", G_CALLBACK(on_window_destroy), NULL);
>>>>>>> 38eb532f8facd63d898f333e55b7db773073e710


    GtkWidget* vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);
<<<<<<< HEAD

    // Create an entry field for the directory path
=======


>>>>>>> 38eb532f8facd63d898f333e55b7db773073e710
    GtkWidget* path_entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(vbox), path_entry, FALSE, FALSE, 0);

    GtkWidget* list_button = gtk_button_new_with_label("List");
    GtkWidget* create_file_button = gtk_button_new_with_label("Create file");
    GtkWidget* delete_file_button = gtk_button_new_with_label("Delete file");
    GtkWidget* create_directory_button = gtk_button_new_with_label("Create directory ");
    GtkWidget* delete_directory_button = gtk_button_new_with_label("Delete directory ");
    GtkWidget* symbolic_link_button = gtk_button_new_with_label("Create Symbolic Link");
    GtkWidget* permissions_button = gtk_button_new_with_label("Change Permissions");


    g_signal_connect(list_button, "clicked", G_CALLBACK(list_files),path_entry);
    g_signal_connect(create_file_button, "clicked", G_CALLBACK(create_file), path_entry);
    g_signal_connect(delete_file_button, "clicked", G_CALLBACK(delete_file), path_entry);
    g_signal_connect(create_directory_button, "clicked", G_CALLBACK(create_directory), path_entry);
    g_signal_connect(delete_directory_button, "clicked", G_CALLBACK(delete_directory), path_entry);
    g_signal_connect(symbolic_link_button, "clicked", G_CALLBACK(create_symbolic_link), path_entry);
    g_signal_connect(permissions_button, "clicked", G_CALLBACK(change_permissions), path_entry);

    gtk_box_pack_start(GTK_BOX(vbox), list_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), create_file_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), delete_file_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), create_directory_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), delete_directory_button, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), symbolic_link_button, FALSE, FALSE, 0);
<<<<<<< HEAD
    gtk_box_pack_start(GTK_BOX(vbox), permissions_button, FALSE, FALSE, 0);

        // Show all the widgets
=======

>>>>>>> 38eb532f8facd63d898f333e55b7db773073e710
    gtk_widget_show_all(window);


    gtk_main();
}

int main(int argc, char* argv[]) {
   gtk_init(&argc, &argv);

   while (1) {
        show_menu();
        gtk_main();
        }
}
