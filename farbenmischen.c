//
// Created by Nur Ahmed on 25.04.25.
//
//
// Created by Nur Ahmed on 12.04.25.
//
#include <stdio.h>      // Für Ein- und Ausgabeoperationen (z.B. printf, fgets)
#include <string.h>     // Für Stringvergleiche (strcmp) und -operationen (strlen)

// Definition eines Arrays mit Grundfarben (Primärfarben)
char *grund_farben[] = { "Grün", "Rot", "Violett" };

// Definition eines Arrays mit möglichen Mischfarben (sowohl Grund- als auch Sekundärfarben)
char *kombi_farben[] = { "Grün", "Gelb", "Blau", "Rot", "Purpur", "Violett" };

// Makrodefinition zur Ermittlung der Anzahl der Grundfarben
#define g_zahl sizeof(grund_farben) / sizeof(grund_farben[0])

// Makrodefinition zur Ermittlung der Anzahl der Kombinationsfarben
#define k_zahl sizeof(kombi_farben) / sizeof(kombi_farben[0])



/*
 * 2D-Tabelle, die das Ergebnis der Mischung zweier Grundfarben enthält.
 * Der Index [i][j] zeigt auf einen Eintrag im kombi_farben-Array.
 * Beispiel: kombi_tabelle[0][1] == 1 → kombi_farben[1] == "Gelb"
 */
int kombi_tabelle[g_zahl][g_zahl] = {
        {0, 1, 2},   // Kombinationen für "Grün"
        {1, 3, 4},   // Kombinationen für "Rot"
        {2, 4, 5}    // Kombinationen für "Violett"
};

// Funktionsprototyp: Liest eine gültige Grundfarbe vom Benutzer ein
int lies_grund_farbe(char *text);

/*--------------------------------------------------------- main ---------*/
int main(void)
{
    int farbe1, farbe2;

    // Erste Farbe vom Benutzer einlesen
    farbe1 = lies_grund_farbe("Erste Grundfarbe");

    // Zweite Farbe vom Benutzer einlesen
    farbe2 = lies_grund_farbe("Zweite Grundfarbe");

    // Ausgabe der entsprechenden Mischfarbe laut Tabelle
    printf("..... Die Mischfarbe ist dann %s\n",
           kombi_farben[kombi_tabelle[farbe1][farbe2]]);

    return(0); // Programm erfolgreich beendet
}

/*--------------------------------------------- lies_grund_farbe ---------*/
/*
 * Funktion liest vom Benutzer eine gültige Grundfarbe ein.
 * Wiederholt die Eingabeaufforderung, bis eine gültige Farbe eingegeben wurde.
 * Gibt den Index der gewählten Farbe im grund_farben-Array zurück.
 */
int lies_grund_farbe(char *text)
{
    int i;
    char farbe[100];  // Eingabepuffer für Benutzereingabe

    while (1) {
        // Eingabeaufforderung mit Liste verfügbarer Farben
        printf("%s (", text);
        for (i = 0; i < g_zahl; i++)
            printf("%s ", grund_farben[i]);
        printf("): ");

        // Einlesen der Benutzereingabe inkl. Zeilenumbruch
        fgets(farbe, 100, stdin);

        // Entfernen des Zeilenumbruchs am Ende der Eingabe
        farbe[strlen(farbe) - 1] = 0;

        // Prüfen, ob Eingabe mit einer bekannten Grundfarbe übereinstimmt
        for (i = 0; i < g_zahl; i++)
            if (!strcmp(farbe, grund_farben[i]))
                break;

        // Falls unbekannt, Fehlermeldung und erneute Eingabeaufforderung
        if (i >= g_zahl)
            printf("..... Unbekannte Grundfarbe %s (Neue Eingabe machen)\n", farbe);
        else
            return(i); // Index der gültigen Grundfarbe zurückgeben
    }
}
