## Plik availableMovesForKnightInChees

```css
Biorąc pod uwagę pozycję skoczka(konia) na standardowej szachownicy,
funkcję znajduje liczbę możliwych ruchów jakie może wykonać.
Dane wejściowe:
• position – string oznaczający kwadrat, na którym znajduje się skoczka np.”A1”.
Wyjście:
Liczba możliwych ruchów jakie może wykonać skoczek z przekazanej pozycji position.
Przykład:
• PossibleMoves(”a1”) => 2
```

## Plik findLargestWaterBodySize

```plaintext
Mapa terenu zapisana jest na siatce dwuwymiarowej w bardzo prosty sposób:
• 0 – oznacza ląd
• 1 – oznacza wodę
Dwa pola w mapie sąsiadują ze sobą tylko jeśli do siebie przylegają w pionie lub
poziomie (czyli nie po skosie).
Napisz funkcję, która przyjmuje taką siatkę dwuwymiarową, a zwraca rozmiar
największego zbiornika wodnego (czyli pól wody sąsiadujących ze sobą).
Dane wejściowe:
Siatka przedstawiająca teren
Wyjście:
Rozmiar największego zbiornika wodnego
Przykład:
00000001
00011101
10011000
11010000
10011100
00000011
zwróci 9
```