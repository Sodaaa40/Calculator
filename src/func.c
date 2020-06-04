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

void button_clicked(GtkWidget* widget, gpointer data)
{
    char* dat = data;
    if (dat[0] == '=') {
        char* s = &text[0];
        if (input(&s, &length))
            return;
        sprintf(otv, "%lf", Calc(text, 0, length - 1));
        printf("%s\n", text);
        memset(text, 0, 100);
        gtk_entry_set_text(GTK_ENTRY(okno), otv);
        length = 0;
    } else if (dat[0] == 'C') {
        memset(text, 0, 100);
        gtk_entry_set_text(GTK_ENTRY(okno), text);
    } else {
        strcat(text, (gchar*)data);
        gtk_entry_set_text(GTK_ENTRY(okno), text);
    }
}

