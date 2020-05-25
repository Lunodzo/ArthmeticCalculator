#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//GLOBAL VARIABLES
static GtkWidget *label;
static GtkBuilder *builder;
static GtkWidget *number1;
static GtkWidget *number2;

//ADDITION FUNCTION
void on_add_clicked(GtkButton *button, gpointer   user_data){
    float num1 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number1))); //ATOI (String to integer)
    float num2 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number2)));

    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%.2f", num1+num2);
    gtk_label_set_text(GTK_LABEL(label), buffer);
}

//SUBSTRACTION FUNCTION
void on_minus_clicked(GtkButton *button, gpointer   user_data){
    float num1 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number1))); //ATOI (String to integer)
    float num2 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number2)));

    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%.2f", num2-num1);
    gtk_label_set_text(GTK_LABEL(label), buffer);
}

//MULTIPLICATION FUNCTION
void on_multiply_clicked(GtkButton *button, gpointer   user_data){
    float num1 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number1))); //ATOI (String to integer)
    float num2 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number2)));

    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%.2f", num2*num1);
    gtk_label_set_text(GTK_LABEL(label), buffer);
}

//DIVISION FUNCTION
void on_division_clicked(GtkButton *button, gpointer   user_data){
    float num1 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number1))); //ATOI (String to float)
    float num2 = atoi((char *)gtk_entry_get_text(GTK_ENTRY(number2)));

    char buffer[32];
    if (num1==0)
    {
        gtk_label_set_text(GTK_LABEL(label), "ARE YOU KIDDING ME!");
    }else{
        float output = num2/num1;
        snprintf(buffer, sizeof(buffer), "%.2f", output);
        gtk_label_set_text(GTK_LABEL(label), buffer);
    }
}

//A FUNCTION TO CLEAR TEXTS
void on_clear_clicked(){
    gtk_entry_set_text(GTK_ENTRY(number1), "");
    gtk_entry_set_text(GTK_ENTRY(number2), "");
    gtk_label_set_text(GTK_LABEL(label), "");
}

//UNDO OPERATIONS (NOT WORKING)
void on_undo_clicked(){
    gtk_entry_set_text(GTK_ENTRY(number1), "");
    gtk_entry_set_text(GTK_ENTRY(number2), "");
    gtk_label_set_text(GTK_LABEL(label), "");
}

//CLOSING WINDOW FUNCTION
void on_main_windo_destroy(){
    gtk_main_quit();
}

//MAIN FUNCTION
int main(int argc, char *argv[])
{
    GError *err = NULL; //Checking for errors
    GtkWidget *window;
    gtk_init(&argc, &argv);

    builder = gtk_builder_new();
    if(0 == gtk_builder_add_from_file (builder, "SimpleArthmetic.glade", &err))
        {
            /* Print out the error. You can use GLib's message logging */
            fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
            /* Your error handling code goes here */
        }

    gtk_builder_connect_signals(builder, NULL);
    window = GTK_WIDGET(gtk_builder_get_object(builder, "main_window"));
    //CONFIRM THE window OBJECT
    if (NULL == window){
        /* Print out the error. You can use GLib's message logging  */
        fprintf(stderr, "Unable to file object with id \"main_window\" \n");
    }

    label = GTK_WIDGET(gtk_builder_get_object(builder, "label"));
    number1 = GTK_WIDGET(gtk_builder_get_object(builder, "input1"));
    number2 = GTK_WIDGET(gtk_builder_get_object(builder, "input2"));

    g_object_unref(builder);
    gtk_widget_show(window);
    gtk_main();
    return 0;
}