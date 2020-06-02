#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
extern int length;
extern gchar text[100];
extern gchar otv[20];

int symbol(char ch, char* list) //Все доступные символы
{
    int i;
    for (i = 0; list[i] != '\0'; i++) {
        if (ch == list[i])
            return 1;
    }
    return 0;
}

void wronginput()
{
    GtkWidget* dialog;
    GtkWidget* text;
    GtkWidget* area;
    dialog = gtk_dialog_new_with_buttons(
            "Error",
            NULL,
            GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_STOCK_OK,
            GTK_RESPONSE_ACCEPT,
            NULL);
    area = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    text = gtk_label_new("Wrong input");
    gtk_container_add(GTK_CONTAINER(area), text);
    gtk_widget_show(text);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

int input(char** str, int* length)
{
    int i, j, open = 0;
    int indicator = 1;
    char* list = "-+*/()^.1234567890";
    for (i = 0; (*str)[i] != '\0'; i++) {
        if (symbol((*str)[i], list) != 1)
            indicator = 0;
    }
    for (i = 0; (*str)[i] != '\0'; i++) {
        if (symbol((*str)[i], "+*/^")
            && (((i == 0) || ((*str)[i + 1] == '\0') || ((*str)[i - 1] == '(')
                 || ((*str)[i + 1] == ')'))
                || ((i > 0)
                    && ((symbol((*str)[i - 1], "+-*/^"))
                        || (symbol((*str)[i + 1],
                                   "+-*/^")))))) //неверно расставлены знаки
        {
            wronginput();
        }
        if (((*str)[i] == '.')
            && ((i - 1 < 0)
                || (symbol((*str)[i + 1], "-+/*^")
                    || symbol((*str)[i - 1], "+-/*^") || ((*str)[i + 1] == '\0')
                    || ((*str)[i - 1] == '\0')))) //Неверно расположена точка
        {
            wronginput();
        }
        for (i = 0; (*str)[i] != '\0'; i++) {
            if (indicator) {
                *length = *length + 1;
                if ((*str)[i] == '(')
                    open++;
                if ((*str)[i] == ')') {
                    open--;
                    if (open < 0) { //Если закрытых скобок больше открытых
                        wronginput();
                    }
                }
            } else {
                wronginput();
            }
        }
        if (open) { //Если открытых скобок больше закрытых
            wronginput();
        }
        if ((*str)[i] == '.') { //если точка рядом со скобками
            if (symbol((*str)[i + 1], "()") || symbol((*str)[i - 1], "()")) {
                wronginput();
            }
            for (j = i + 1; (*str)[j] != '\0'; j++) {
                if ((*str)[j] == '.') {
                    wronginput();
                }
            }
        }
        if (((*str)[i] == '(') && (i > 0)) { //посторонние знаки у скобок
            if (symbol((*str)[i - 1], "(+-/*^") == 0) {
                wronginput();
            }
            if ((*str)[i + 1] == ')') {
                wronginput();
            }
        }
        if (((*str)[i] == ')') && ((*str)[i + 1] != '\0')) {
            if (symbol((*str)[i + 1], ")+-/*^") == 0) {
                wronginput();
            }
        }
    }
    if ((symbol((*str)[0], "()+-/*^")) && ((*str)[1] == '\0')) {
    }
    return 0;
}
