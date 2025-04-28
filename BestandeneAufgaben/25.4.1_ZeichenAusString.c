#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TEXTGROESSE 1001                                                        // Maximale Textlänge inkl. Nullterminator ('\0')

// Funktionsdeklarationen
void input(char *textinhalt, char *p_loescheZeichen);                           // Funktion zum Einlesen des Texts und Zeichens
void streicheZeichen(char *textinhalt, char *p_loescheZeichen);                 // Funktion zum Entfernen des Zeichens aus dem Text

int main()
{
    char text[TEXTGROESSE], *textinhalt = text;                                 // hier wird ein Array text initalisiert und ein char-Zeiger der auf das Array text zeigt                             
    char loescheZeichen;                                                        // Zeichen, das später gelöscht werden soll

    input(text, &loescheZeichen);                                               // Funktionsaufruf 1
    streicheZeichen(text, &loescheZeichen);                                     // Funktionsaufruf 2

    return 0;
}

//-------Funktion zum Einlesen des Texts und Zeichens-----------------
void input(char *textinhalt, char *p_loescheZeichen)
{
    printf("Geben Sie eine Zeichenkette (max. 1000 Zeichen) ein:\n");
    fgets(textinhalt, TEXTGROESSE, stdin);                                      // fgets liest einen text ein, inkl. Leerzeichen, und speichert in durch char pointer in Array text                                

    textinhalt[strcspn(textinhalt, "\n")] = '\0';                               // fgets liest enter als newline ein, und ist erstmal teil des strings, da wir das nicht wollen überschreibt der Befehl \n mit \0 und signalisiert damit das Stringende         
    printf("\n");

    printf("Geben Sie das zu loeschende Zeichen ein: ");
    scanf(" %c", p_loescheZeichen);                                              // einlesen des zu löschenden Zeichen

    printf("\n");
    printf("....... Die neue Zeichenkette ist:\n");
}

//--------Funktion zum Entfernen des Zeichens aus dem Text---------
void streicheZeichen(char *textinhalt, char *p_loescheZeichen)
{
    for (int i = 0; textinhalt[i] != '\0'; i++){                                 // Schleife über jedes Zeichen im String, bis zum Nullterminator
        if (tolower(textinhalt[i]) != tolower(*p_loescheZeichen)){               // Wenn der Buchstabe nicht der zu löschende Buchstabe ist dann printe aus, hierbei werden Klein/Großbuchstaben nicht beachtet             
            printf("%c", textinhalt[i]);
        }
    }
}