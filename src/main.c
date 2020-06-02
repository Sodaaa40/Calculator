#include <gtk/gtk.h>
#include "func.h"

gchar text[100];
gchar otv[20];
int f = 0;
GtkWidget *okno;

int main(int a, char *h[]) {
	gtk_init(&a, &h);

	GtkWidget *one, *two, *three, *four, *five, 
    *six, *seven, *eight, *nine, *zero;
	GtkWidget *point, *leftBracket, *rightBracket, *divide, *multiply,
    *plus, *minus, *result, *delete, *sqrt, *pow;

    zero = gtk_button_new_with_label("0");
	g_signal_connect(G_OBJECT(zero), "clicked",
			 G_CALLBACK(zero_clicked), "0");
	one = gtk_button_new_with_label("1");  
	g_signal_connect(G_OBJECT(one), "clicked",
			 G_CALLBACK(one_clicked), "1");
	two = gtk_button_new_with_label("2");
	g_signal_connect(G_OBJECT(two), "clicked",
			 G_CALLBACK(two_clicked), "2");
	three = gtk_button_new_with_label("3");
	g_signal_connect(G_OBJECT(three), "clicked",
			 G_CALLBACK(three_clicked), "3");
	four = gtk_button_new_with_label("4");
	g_signal_connect(G_OBJECT(four), "clicked",
			 G_CALLBACK(four_clicked), "4");
	five = gtk_button_new_with_label("5");
	g_signal_connect(G_OBJECT(five), "clicked",
			 G_CALLBACK(five_clicked), "5");
	six = gtk_button_new_with_label("6");
	g_signal_connect(G_OBJECT(six), "clicked",
			 G_CALLBACK(six_clicked), "6");
	seven = gtk_button_new_with_label("7");
	g_signal_connect(G_OBJECT(seven), "clicked",
			 G_CALLBACK(seven_clicked), "7");
	eight = gtk_button_new_with_label("8");
	g_signal_connect(G_OBJECT(eight), "clicked",
			 G_CALLBACK(eight_clicked), "8");
    nine = gtk_button_new_with_label("9");
	g_signal_connect(G_OBJECT(nine), "clicked",
			 G_CALLBACK(nine_clicked), "9");
	plus = gtk_button_new_with_label("+");
	g_signal_connect(G_OBJECT(plus), "clicked",
			 G_CALLBACK(plus_clicked), "+");
    minus = gtk_button_new_with_label("-");
	g_signal_connect(G_OBJECT(minus), "clicked",
			 G_CALLBACK(minus_clicked), "-");
	divide = gtk_button_new_with_label("/");
	g_signal_connect(G_OBJECT(divide), "clicked",
			 G_CALLBACK(divide_clicked), "/");
	multiply = gtk_button_new_with_label("*");
	g_signal_connect(G_OBJECT(multiply), "clicked",
			 G_CALLBACK(multiply_clicked), "*");
    sqrt = gtk_button_new_with_label("sqrt");
	g_signal_connect(G_OBJECT(sqrt), "clicked",
			 G_CALLBACK(sqrt_clicked), "^(0.5)");
	pow = gtk_button_new_with_label("^");
	g_signal_connect(G_OBJECT(pow), "clicked",
			 G_CALLBACK(pow_clicked), "^");
	leftBracket = gtk_button_new_with_label("(");
	g_signal_connect(G_OBJECT(leftBracket), "clicked",
			 G_CALLBACK(leftBracket_clicked), "(");
	rightBracket = gtk_button_new_with_label(")");
	g_signal_connect(G_OBJECT(rightBracket), "clicked",
			 G_CALLBACK(rightBracket_clicked), ")");
	point = gtk_button_new_with_label(".");
	g_signal_connect(G_OBJECT(point), "clicked",
			 G_CALLBACK(point_clicked), ".");
	delete = gtk_button_new_with_label("C");
	g_signal_connect(G_OBJECT(delete), "clicked",
			 G_CALLBACK(delete_clicked), "C");
	result = gtk_button_new_with_label("=");
	g_signal_connect(G_OBJECT(result), "clicked",
			 G_CALLBACK(result_clicked), "=");
	GtkWidget *window;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Калькулятор");
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 450);

	okno = gtk_entry_new();

	GtkWidget *table;
	table = gtk_table_new(4, 6, FALSE);
	gtk_table_attach_defaults(GTK_TABLE(table), okno, 0, 3, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(table), delete, 3, 4, 0,1);
    int x = 0;
    int y = 1;
    GtkWidget *mas[20] = {seven, eight, nine, plus, four, five, six, minus, one, two, three, divide, sqrt, zero, pow, multiply, leftBracket, rightBracket, point, result};    
    for(int i = 0; i < 20; i++) {
        if(x > 3) {
            x = 0;
            y++;
        }
        gtk_table_attach_defaults(GTK_TABLE(table), mas[i], x, x+1, y, y+1);
        x++;                   
    }
	gtk_container_add(GTK_CONTAINER(window), table);
	gtk_widget_show_all(window);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();

	return 0;
}
