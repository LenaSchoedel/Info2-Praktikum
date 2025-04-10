
//
// Created by Nur Ahmed on 04.04.25.
//
#include <stdio.h>
#include <stdlib.h> // Für rand(), srand(), Speicherfunktionen
#include <time.h> // Für time() – Initialisierung des Zufallsgenerators

int generiere_neue_folge(int len, int folge[]);
/*--------------------------------------------------------------- main -----*/


// Hauptfunktion des Programms.
// 1. Eingabe der Folgelänge
// 2. Erzeugung einer zufälligen 0/1-Folge
// 3. Ausgabe der Folge
// 4. Iterative Reduktion durch paarweisen Vergleich
// 5. Ausgabe jeder Zwischenschrittfolge


int main(void)
{
    int folge[1001]; // Array für 0/1-Folge. Index von 1 bis 1000
    int a, laenge;

    // Eingabeaufforderung
    do
    {
        printf("Länge der 0/1-Folge (max. 1000): ");
        scanf("%d", &laenge);
    }

    while (laenge<0 || laenge>1000); // Bereichsabfrage

    srand(time(NULL));// Initialisierung des Zufallszahlengenerators (aktuell)

// Generieren der Zufallsfolge – jedes Element ist entweder 0 oder 1
    for (a=1; a<=laenge; a++)
        folge[a] = rand()%2;
// Ausgabe der generierten Anfangsfolge in einer Zeile
    for (a=1; a<=laenge; a++)
        printf("%d", folge[a]);
    printf("\n");


    // Solange die Folge mehr als ein Bit enthält, wird sie reduziert
    while (laenge > 1) {
        laenge = generiere_neue_folge(laenge, folge);// Rückgabewert ist die neue, verkürzte Länge


// Ausgabe der neuen Folge nach dem Reduktionsschritt
        for (a=1; a<=laenge; a++)
            printf("%d", folge[a]);
        printf("\n");
    }
    return(0);
}
/*----------------------------------------------- generiere_neue_folge -----*/

// Diese Funktion reduziert eine Folge nach folgendem Regelwerk:
//
// - Zwei gleiche aufeinanderfolgende Ziffern (00 oder 11) → ergeben 0
// - Zwei unterschiedliche aufeinanderfolgende Ziffern (01 oder 10) → ergeben 1
//
// Die neue Folge wird **in-place** (also im selben Array) ab Index 1 gespeichert.
// Falls die Eingabefolge eine ungerade Länge hatte, bleibt das letzte Bit am Ende erhalten.
//


int generiere_neue_folge(int laenge, int folge[])
{
    int i, j;
    // Vergleich zweier aufeinanderfolgender Bits:
    // Wenn sie gleich sind → !(1) = 0
    // Wenn sie unterschiedlich sind → !(0) = 1
    for (i=1,j=1; i<laenge; i+=2,j++)
        folge[j] = !(folge[i] == folge[i+1]);

    // ein einzelnes Element bleibt übrig
    // wird unverändert übernommen
    if (i == laenge)
        folge[j] = folge[laenge];
    else
        j--; // Wenn nichts übernommen wurde, muss j wieder reduziert werden
    return(j);
}


