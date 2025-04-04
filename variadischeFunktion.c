#include <stdio.h>
#include <stdarg.h>

int input();
int numbers(int zahl, ...);

int main()
{
   int maximum = 0;

   input();

   maximum = numbers(12, 17, 3, 6, 24, 8, -1);
   printf("Das Maximum der Zahlen 12, 17, 3, 6, 24, 8 ist: %d\n", maximum);

   maximum = numbers(105, 77, 3, 54, -1);
   printf("Das Maximum der Zahlen 105, 77, 3, 54 ist: %d\n", maximum);

   maximum = numbers(300, 400, 10, 20, 30, 300, 1, 0, 80, -1);
   printf("Das Maximum der Zahlen 300, 400, 10, 20, 30, 300, 1, 0, 80 ist: %d\n", maximum);

   return 0;
}

int input()
{

   printf("Testprogramm fuer Funktion vielmax()\n"
          "====================================\n"
          "\n");
   return 0;
}

int numbers(int zahl, ...)
{

   int vergleich, maxzahl = 0;

   va_list liste;
   va_start(liste, zahl);

   while ((vergleich = va_arg(liste, int)) != -1)
   {

      if (vergleich > maxzahl)
      {
         maxzahl = vergleich;
      }
   }
   va_end(liste);

   return maxzahl;
}