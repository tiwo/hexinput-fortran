c     ******************************************************
c     * hextest - Testet die C-Subroutine hexin, indem es  *
c     *           eine zweistellige Hexadezimalzahl ein-   *
c     *           liest (alle Zeichen außer den            *
c     *           Hexa dezimalziffern werden dabei         *
c     *           ignoriert) und ihren Wert ausgibt.       *
c     *                                                    *
c     * Das Compilieren müsste mit                         *
c     *                                                    *
c     *      g77 -o hextest.exe hexin.c hextest.f          *
c     *                                                    *
c     *  gelingen, oder mit dem zweischrittigen            *
c     *                                                    *
c     *      g77 -c hexin.c                                *
c     *      g77 -o hextest.exe hexin.o hextest.f          *
c     ******************************************************
        PROGRAM hextest
        IMPLICIT NONE
        INTEGER :: eof, c
c 
        CALL hexin(eof, c)
c      
        IF (eof == 1) THEN
            PRINT *, 'Bin ans Dateiende gestoßen!'
        ELSE
            PRINT *, 'Das eingelesene kodierte Byte hat den Wert', c
        ENDIF
c
        END
c     ******************************************************
