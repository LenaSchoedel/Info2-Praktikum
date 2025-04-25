#include <stdio.h>
#include <stdlib.h>

int input();
void umwandlung(unsigned int zahl, unsigned int rest[], unsigned int *p_i);
void ouput(unsigned int rest[], unsigned int *p_i);

int main()
{

    unsigned int zahl, i = 0;                 //ich initalisiere unsigned integer Werte damit ich später bei den minus Werten keine Probleme bekomme, die werden dann von größ möglich einzulesenden Wert abgezogen -1 = 0,-2 = 1
    unsigned int rest[100];

    zahl = input();                                                                 // Aufruf der Eingabefunktion

    umwandlung(zahl, rest, &i);                                                     // Aufruf der Umrechnungfunktion

    ouput(rest, &i);                                                                // Aufruf der Ausgabefunktion

    return 0;
}

int input()
{

    int eingabeZahl;

    printf("Gib eine Dezimalzahl ein: ");
    scanf("%u", &eingabeZahl);

    return eingabeZahl;
}

void umwandlung(unsigned int zahl, unsigned int rest[], unsigned int *p_i)
{

    if (zahl > 0)
    {

        rest[*p_i] = zahl % 2;                                                       // Die Eingelesene Zahl wird an die Funktion übergeben, und durch % 2
        zahl = zahl / 2;                                                             // erhalte ich den Rest also entweder eine 0 oder 1, diese wird im Array Rest gespeichert
        (*p_i)++;                                                                    // das i für die hochzählung habe ich in der main initalisiert, da sonst beim wieder
                                                                                     // der Funktion das i wieder bei 0 starten würde, daher *p_i. Dann nehme ich die
        umwandlung(zahl, rest, p_i);                                                 // eingelesen Zahl durch 2 um das letzt gespeicherte Bit zu entfernen. Dannach wird
    }                                                                                // die Funktion neu aufgerufen, solange bis die eingelesene Zahl null ist.
}

void ouput(unsigned int rest[], unsigned int *p_i)
{
                                                                                     // Jetzt lese ich das Array von hinten nach vorne aus, damit die letzte Ziffer
    if (*p_i > 0)                                                                    // Als erstes Steht, hier ist wichtg das das i vor der printen kleiner wird.
    {                                                                                // im letzten Array kein wert steht. 

        (*p_i)--;
        printf("%d", rest[*p_i]);
        ouput(rest, p_i);
    }
}