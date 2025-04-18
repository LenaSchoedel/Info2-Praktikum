#include <stdio.h>

int input();
void quersumme(int number, int puffer);
int rueckwerts(int number, int puffer);

int main()
{

    int number = 0, puffer = 0;

    printf("Gib eine Zahl ein: ");
    number = input();

    printf("--------Quersumme: ");
    quersumme(number, puffer);

    printf("--------umgedreht: ");
    rueckwerts(number, puffer);

    return 0;
}

int input()
{

    int inputnum = 0;

    scanf("%d", &inputnum);

    return inputnum;
}

void quersumme(int number, int puffer)
{

    int quersum = puffer;

    quersum = quersum + (number % 10);
    number = number / 10;

    if (number > 0)
    {
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

    letztezahl = (number % 10);
    number = number / 10;

    if (number > 0 || letztezahl < 10 && letztezahl != 0)
    {
        printf("%d", letztezahl);
    }
    else
    {
        return 0;
    }

    return rueckwerts(number, letztezahl);
}