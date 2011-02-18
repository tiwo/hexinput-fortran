/*
 *  hexin.c - zum Einlesen von Hexadezimalzahlen
 * 
 *  C-Subroutine zum Aufruf aus Fortran.
 *
 *  Aus Fortran kann die Subroutine wie folgt eingebunden werden:
 *
 *      PROGRAM hextest
 *      INTEGER :: eof, c
 *
 *      CALL hexin(eof, c)
 *      
 *      IF (eof == 1) THEN
 *          PRINT *, 'Bin ans Dateiende gestoßen!'
 *      ELSE
 *          PRINT *, 'Das eingelesene kodierte Byte hat den Wert', c
 *      ENDIF
 *
 *      END
 *
 * 
 * Das Compilieren müsste mit
 * 
 *      g77 -o hextest.exe hexin.c hextest.f
 *
 *  gelingen, oder mit dem zweischrittigen
 *
 *      g77 -c hexin.c                             (erstellt hexin.o)
 *      g77 -o hextest.exe hexin.o hextest.f    (fügt alles zusammen)
 */

#include <stdio.h>

/* Prototypen: */
int get_hex_digit(void);
void hexin_(int *, int *);
const int hexval[256];

/* hexin_ - liest eine zweistellige Hexadezimalzahl von der
 *          Standardeingabe. Falls vor der zweiten Ziffer das Dateiende
 *          erreicht wird, setzt es *eof=1. Ansonsten ist *eof=0 und
 *          *c enthält den Wert der gelesenen Zahl (0-255).  */
void hexin_(int * eof, int * c)
{
        int digit1, digit2;
        
        digit1 = get_hex_digit();
        digit2 = get_hex_digit();

        if ((digit1 == EOF) || (digit2 == EOF)) {
                *eof = 1;
        } else {
                *eof = 0;
                *c = digit1 * 16 + digit2;
        }
}


/* get_hex_digit - liest eine Hexadezimalziffer (0-9, A-F, a-f) von der
 *                 Standardeingabe, wobei es alle anderen Zeichen
 *                 ignoriert. Bei Dateiende liefert es den speziellen Wert
 *                 EOF aus stdio.h, ansonsten den Wert der gelesenen
 *                 Ziffer (0-15).  */
int get_hex_digit(void)
{
        int c = -9;

        while (c == -9) {
                c = getchar();
                if (c != EOF) c = hexval[c];
        }
        return c;
}


/* hexval - ordnet jedem Zeichen seinen Hexadezimalwert zu oder -9, falls
 *          es keine Hexadezimalziffer ist.  */
const int hexval[256] = {
        -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9,
        -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9,
        -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9,
         0,  1,  2,  3,  4,  5,  6,  7,  8,  9, -9, -9, -9, -9, -9, -9,
        -9, 10, 11, 12, 13, 14, 15, -9, -9, -9, -9, -9, -9, -9, -9, -9,
        -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9,
        -9, 10, 11, 12, 13, 14, 15, -9, -9, -9, -9, -9, -9, -9, -9, -9,
        -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9,
        -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9,
        -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9,
        -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9,
        -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9,
        -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9,
        -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9,
        -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9,
        -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9, -9
};

