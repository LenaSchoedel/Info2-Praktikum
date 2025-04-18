//
// Created by Nur Ahmed on 04.04.25.
//
/**********************************************************************\
* Kurzbeschreibung: Uebung: 22.4.1;
*
* Datum:       Autor:      Grund der Aenderung:
* 04.04.2025   Nur Ahmed       Neuerstellung
\**********************************************************************/


#include <stdio.h>
#include <stdarg.h>


//vielmax


int vielmax(int zahl1,...)
{
    va_list arg_zeiger;// definiert einen Zeiger auf die weiteren Argumente
    int max, zahl;

    max = zahl1;
    va_start(arg_zeiger, zahl1); //initialisiert den Argument-Zeiger mit dem ersten fixen Argument (zahl1)

    // Schleife durch alle weiteren übergebenen int-Werte, bis eine 0 erreicht wird
    while ((zahl=va_arg(arg_zeiger, int)) != 0)
    max = zahl > max? zahl: max;// prüft, ob aktuelle Zahl größer ist als bisheriges Maximum
    va_end(arg_zeiger); //beendet die Verarbeitung der Argumentliste

    return(max);
}
//main

int main(void)
{
    int max;

    printf("Testprogramm fuer Funktion vielmax()\n");
    printf("====================================\n\n");

    max = vielmax(12, 17, 3, 6, 24, 8, 0);
    printf("Das Maximum der Zahlen 12, 17, 3, 6, 24, 8 ist: %d", max);

    // Aufruf der Funktion mit mehreren Zahlen, letztes Argument ist 0 (Ende der Liste)
    max = vielmax(105, 77, 3, 54, 0);
    printf("\nDas Maximum der Zahlen 105, 77, 3, 54 ist: %d\n", max);

    return(0);
}
