/*
    spicoli piersilvio
    esercitazione 3
*/
#include <stdio.h>
#include <ctype.h>
#define LETTERE 26

void ContaOccorrenze(int contatori[]);
void IstogrammaVerticale(int contatori[]);
char Minuscola(char lettera);

int main()
{
  int contatori[LETTERE];

  printf("Inserisci un testo terminato dal carattere #\n");
  ContaOccorrenze(contatori);
  IstogrammaVerticale(contatori);

  return 0;
}


void ContaOccorrenze(int contatori[])
{
   char ch;
   int i;

   for (i = 0; i < LETTERE; i++)
   {contatori[i] = 0; }

   while ((ch = getchar()) != '.')
   {
      ch = Minuscola(ch);
      if (ch >= 'a' && ch <= 'z')
         contatori[ch - 'a']++;
   }
}

void IstogrammaVerticale(int contatori[])
{
   int i, top;

   printf ("\n");

   /* cerca il massimo valore tra i contatori (quello da cui partire) */
   top = 0;

   for (i = 0; i < LETTERE; i++)
   {
      if (contatori [i] > top)
         top = contatori [i];
   }
   /* stampa gli asterischi per i dati che hanno contatore
      maggiore o uguale a top, portando top dal valore corrente a zero */
   while (top > 0)
   {
      for (i = 0; i < LETTERE; i++)
      {
         if (contatori [i] >= top)
            printf ("*");
         else
            printf (" ");
      }

      /* passa alla riga successiva */
      top -= 1;
      printf ("\n");
   }

   /* stampa le lettere */
   for (i = 0; i < LETTERE; i++)
   {
      printf ("%c", i + 'a');
   }
   printf ("\n");
}


char Minuscola(char lettera)
{
   if (lettera >= 'A' && lettera <= 'Z')
      return lettera - 'A' + 'a';
   else
      return lettera;
}
