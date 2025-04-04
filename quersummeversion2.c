//
// Created by Nur Ahmed on 04.04.25.
//
/**********************************************************************\
* Kurzbeschreibung: Uebung: 22.5.4;
*
* Datum:       Autor:      Grund der Aenderung:
* 04.04.2025   Nur Ahmed       Neuerstellung
\**********************************************************************/



#include <stdio.h>



//quersum

int quersum(int zahl)
{
    if (zahl == 0)
        return 0;  // Abbruchbedingung: Wenn die Zahl 0 ist, ist die Quersumme auch 0
    return( (zahl%10) + quersum (zahl/10) ); // letzte Ziffer + Quersumme vom Rest
}


//umdrehen
void umdrehen(int zahl)
{
    if(zahl == 0)  //Wenn die Zahl 0 ist, wird nichts mehr ausgegeben
        return;
    printf("%d", zahl%10); // letzte Ziffer der Zahl aus (z.B. bei 123 -> 3)
    umdrehen(zahl/10); // Zahl ohne letzte Ziffer (z. B. 123 -> 12)
}



int main(void)
{
    int zahl;

    printf("Quersumme und Rueckwaertsausgabe einer Zahl\n"
           "===========================================\n\n");

    printf("Gib eine Zahl ein: ");
    scanf("%d", &zahl);

    printf(" ----Quersumme: %d\n", quersum(zahl));

    printf(" ----umgedreht: ");
    umdrehen(zahl);
    printf("\n");

    return(0);
}
