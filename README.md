# DFS
Na wejściu dane są dodatnie liczby całkowite w ≤ 100 (szerokość), h ≤ 100
(wysokość) i k ≤ 100 (ograniczenie liczby zmian kierunku). Nastepnie podanych jest
h wierszy po w znaków, gdzie znak ’.’ określa pusty obszar, a znak ’#’ obszar
niedostępny. Dokładnie dwa puste obszary są również oznaczone przez ’A’ i ’B’; są
to obszar początkowy i końcowy.
Napisz program który sprawdza czy można dojść od A do B zmieniając kierunek
chodzenia co najwyżej k razy. Kierunki są cztery: lewo, prawo, góra, dół. Na
początku nie mamy wybranego żadnego kierunku, więc wybranie go na początku
liczy się już jako pierwsza jego zmiana.
• Przykład 1:
4 4 3
A...
##..
...#
...B
Odpowiedź: TAK.
• Przykład 2:
4 4 3
A.#B
#.#.
....
..#.
Odpowiedź: NIE (ale dla k = 4 byłoby TAK).
