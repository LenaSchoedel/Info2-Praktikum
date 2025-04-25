#include <stdio.h>

int wahl();
int vonDatumzuTagesnummer();
int vonTagesnummerzuDatum();

int main()
{

    int wahlEingabe, nummer;

    while (1)
    {

        wahlEingabe = wahl();

        if (wahlEingabe == 1)
        {
            nummer = vonDatumzuTagesnummer();
            printf("Die Tagesnummer ist: %d\n", nummer);
            printf("\n");
        }

        if (wahlEingabe == 2)
        {
            vonTagesnummerzuDatum();
        }

        if (wahlEingabe == 0)
        {
            return 0;
        }
    }
}

int wahl()
{
    int eingabe;

    printf("Was wollen Sie tun:\n"
           "Bei Eingabe 0 wird das Programm beendet.\n"
           "Bei Eingabe 1 wird die Tagesnummer zu einen eingegbenen Datum ermittelt.\n"
           "Bei Eingabe 2 wird das Datum zu einer eingegebenen Tagesnummer ermittelt.\n"
           "Deine Wahl: ");

    scanf("%d", &eingabe);

    return (eingabe);
}

int vonDatumzuTagesnummer()
{

    int monatTage[][13] = {

        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},  // normales Jahr
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}}; // schaltjahr

    int tag, monat, jahr, tagesnummer = 0;

    printf("Bitte gib dein Datum ein: ");

    scanf("%d.%d.%d", &tag, &monat, &jahr);

    if ((jahr % 4 == 0 && jahr % 100 != 0) || (jahr % 400 == 0))
    {

        for (int i = 1; i < monat; i++)
        {

            tagesnummer += monatTage[1][i];
        }
    }
    else
    {

        for (int i = 1; i < monat; i++)
        {

            tagesnummer += monatTage[0][i];
        }
    }

    tagesnummer += tag;

    return tagesnummer;
}

int vonTagesnummerzuDatum()
{
    int tagesnummer = 0, jahr = 0, tag = 0, monat = 0;
    int monatTage[][13] = {

        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

    printf("Bitte gib die Tagesnummer und das Jahr ein: ");

    scanf("%d,%d", &tagesnummer, &jahr);
    

    while((tagesnummer > 365 || tagesnummer <= 0) || (jahr <= 0)){

        printf("Falsche Eingabe.\n"
               "Bitte gib die Tagesnummer und das Jahr ein: ");
            tagesnummer = 0;
            jahr = 0;

        scanf("%d,%d", &tagesnummer, &jahr);
    }

    if ((jahr % 4 == 0 && jahr % 100 != 0) || (jahr % 400 == 0))
    {

        while (tagesnummer > 0)
        {

            tag = tagesnummer;
            tagesnummer -= monatTage[1][monat];
            monat++;
        }
    }
    else
    {
        while (tagesnummer > 0)
        {

            monat++;
            tag = tagesnummer;
            tagesnummer -= monatTage[0][monat];
        }
    }

    printf("Das Datum ist: %d.%d.%d\n", tag, monat, jahr);

    return 0;
}