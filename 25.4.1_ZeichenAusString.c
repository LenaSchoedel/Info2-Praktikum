#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TEXTGROESSE 1001

void input(char *textinhalt, char *p_loescheZeichen);
void streicheZeichen(char *textinhalt, char *p_loescheZeichen);

int main()
{

    char text[TEXTGROESSE], *textinhalt = text;                                     
    char loescheZeichen;

    input(text, &loescheZeichen);

    streicheZeichen(text, &loescheZeichen);

    return 0;
}

void input(char *textinhalt, char *p_loescheZeichen)
{

    printf("Geben Sie eine Zeichenkette (max. 1000 Zeichen) ein:\n");
    fgets(textinhalt, TEXTGROESSE, stdin);                                          

    textinhalt[strcspn(textinhalt, "\n")] = '\0';                                   
    printf("\n");

    printf("Geben Sie das zu loeschende Zeichen ein: ");
    scanf("%c", p_loescheZeichen);

    printf("\n");
    printf("....... Die neue Zeichenkette ist:\n");
}

void streicheZeichen(char *textinhalt, char *p_loescheZeichen)
{

    for (int i = 0; textinhalt[i] != '\0'; i++)
    {

        if (tolower(textinhalt[i]) != tolower(*p_loescheZeichen))                  
        {
            printf("%c", textinhalt[i]);
        }
    }
}