#include "calc.h"
#include "input.h"
#include <gtk/gtk.h>
#include <string.h>

double Calc(char* str, int launch, int end);
int input(char** str, int* length);
extern int f;
extern int length;
extern gchar text[100];
extern gchar otv[20];
extern GtkWidget* okno;
int input(char** str, int* length);

void zero_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void one_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void two_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void three_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void four_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void five_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void six_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void seven_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void eight_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void nine_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void plus_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void minus_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void multiply_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void divide_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void pow_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void sqrt_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void leftBracket_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void rightBracket_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void point_clicked(GtkWidget* widget, gpointer data)
{
    strcat(text, (gchar*)data);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void delete_clicked(GtkWidget* widget, gpointer data)
{
    memset(text, 0, 100);
    gtk_entry_set_text(GTK_ENTRY(okno), text);
}
void result_clicked(GtkWidget* widget, gpointer data)
{
    char* s = &text[0];
    if (input(&s, &length))
        return;
    sprintf(otv, "%lf", Calc(text, 0, length - 1));
    printf("%s\n", text);
    memset(text, 0, 100);
    gtk_entry_set_text(GTK_ENTRY(okno), otv);
    length = 0;
}
