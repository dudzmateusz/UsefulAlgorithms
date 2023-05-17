#include <iostream>
#include <string>

int PossibleMoves(std::string position) {
    int possibleMoves = 0;
    int row = position[1] - '0';
    int col = position[0] - 'a' + 1;
    int rowMovesAvailable[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int colMovesAvailable[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++) {
        int newRow = row + rowMovesAvailable[i];
        int newCol = col + colMovesAvailable[i];

        if (newRow >= 1 && newRow <= 8 && newCol >= 1 && newCol <= 8) {
            possibleMoves++;
        }
    }
    return possibleMoves;
}

int main() {
    std::string knightPosition;
    std::cout << "Wprowadz pozycje skoczka: ";
    std::cin >> knightPosition;
    int moves = PossibleMoves(knightPosition);
    std::cout << "Ilosc mozliwych ruchow: " << moves << std::endl;

    return 0;
}
