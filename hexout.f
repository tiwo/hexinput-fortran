c   ********************************************************
c   *   hexout(n) - gibt die Zahl n in zwei Hexadezimal-   *
c   *               ziffern aus und begrenzt dabei die     *
c   *               Zeilenlänge auf 72 Zeichen.            *
c   ********************************************************
c
      SUBROUTINE hexout(n)
      IMPLICIT NONE
      INTEGER :: n
      INTEGER :: zeilpos = 1
      SAVE zeilpos
c
c     Die Hexadezimalziffern sind:
      CHARACTER*1 :: hexzif(0:15)
      DATA hexzif/'0', '1', '2', '3', '4', '5', '6', '7',
     *            '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'/
c
c     Sicherstellen, dass 0 <= n <= 255:
      IF ((n .LT. 0) .OR. (n .GT. 255)) THEN
          WRITE (*, *), 'hexout: Fehler: ', n, ' unzulässig'
          CALL exit(1)
      ENDIF
c
c     Ausgabe der beiden Hexadeziamlziffern von n:
      WRITE (*, '(a,$)') hexzif(n / 16)
      WRITE (*, '(a,$)') hexzif(mod(n, 16))
c
c     Position in der Zeile mitzählen:
      zeilpos = zeilpos + 2
c
c     Nach 72 Zeichen eine neue Zeile beginnen:
      IF (zeilpos .GE. 72) THEN
          PRINT *
          zeilpos = 0
      ENDIF
c
      END
c   ********************************************************
c
c
c
c   ********************************************************
c   * test - Testet die Subroutine hexout, indem es alle   *
c   *        Zahlen von 0 bis 255 ausgibt                  *
c   ********************************************************
      PROGRAM test
      IMPLICIT NONE
      INTEGER i
      DO i = 0, 255
          CALL hexout(i)
      END DO
      WRITE (*, *)
      END
c   ********************************************************
