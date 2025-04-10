#include <stdio.h>

int input();
void quersumme(int number, int puffer);
int rueckwerts(int number, int puffer);

int main()
{

    int number = 0, puffer = 0;                                     //Initalisierung der Variablen

    printf("Gib eine Zahl ein: ");
    number = input();                                               //Aufruf der Eingabefunktion, und Rückgabe der Ganzzahl

    printf("--------Quersumme: ");
    quersumme(number, puffer);                                      //Aufruf der Berechnungsfunktion

    printf("--------umgedreht: ");
    rueckwerts(number, puffer);                                     //Aufruf der Umdrehfunktion

    return 0;
}


 
int input()
{

    int inputnum = 0;                   
                                                                    // Es wird eine Ganze Zahl eingelesen
    scanf("%d", &inputnum);                                         // und als return Wert an die main zurückgegeben           

    return inputnum;
}

void quersumme(int number, int puffer)
{

    int quersum = puffer;                   

    quersum = quersum + (number % 10);                              // Die eingelesene Ganzzahl wird mittels Call bei Value an die Funktion übergeben
    number = number / 10;                                           // dann berechne ich die Summe aller Ziffern indem ich die letzte Ziffer der Ganzzahl
                                                                    // durch (number % 10) erhalte und diese dann plus meine summe nehme. Das numer/10 lässt die letzte Ziffer 
    if (number > 0)                                                 // wegfallen. Diese Rechnung wiederhole ich durch das Aufrufen der Funktion (Rekursion) bis die Ganzzahl
    {                                                               // 0 wird, dann printe ich die Summe aus.
        quersumme(number, quersum);
    }
    else
    {
        printf("%d\n", quersum);
    }
}

int rueckwerts(int number, int puffer)
{

    int letztezahl = puffer;
                                                                    // Zum umdrehen der Ziffern verwende ich den Selben ansatz, durch (number % 10)
    letztezahl = (number % 10);                                     // erhalte ich die letzte Ziffer der Ganzzahl und speichere sie kurzfristig ab.
    number = number / 10;                                           // ISt die Ganzzahl größer als null oder die gerade gespeicherte Ziffer kleiner 10 und nicht 0
                                                                    // wird die Ziffer ausgegeben, sobald das passiert ist ruft die Funktion sich selber auf (Rekusrion)
    if (number > 0 || letztezahl < 10 && letztezahl != 0)           // dies passiert so lange bis die Ganzzahl null wird und das Programm endet.
    {
        printf("%d", letztezahl);
    }
    else
    {
        return 0;
    }

    return rueckwerts(number, letztezahl);
}