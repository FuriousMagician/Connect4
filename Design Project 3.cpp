#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void Introduction();
void PrintBoard(char[6][7]);
bool GameOver(char[6][7]);
void Victory(char, int);

int main() {
    Introduction();

    const int Row = 6;
    const int Column = 7;
    char Board[Row][Column];

    int P1_Tally = 0, P2_Tally = 0;
    int input, TallyCount;

    // Initialize board
    for (int a = 0; a < Row; a++) {
        for (int b = 0; b < Column; b++) {
            Board[a][b] = ' ';
        }
    }

    PrintBoard(Board);
    bool turn = false;

    while (true) {
        char PlayerMove = turn ? 'O' : 'X';
        cout << "Player #" << (turn ? 2 : 1) << "'s Turn (" << PlayerMove << "): Enter Your Move (1-7): ";
        cin >> input;

        // Input validation
        while (input < 1 || input > 7 || Board[0][input - 1] != ' ') {
            cout << "Invalid input. Try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> input;
        }

        int t = Row - 1;
        while (t >= 0 && Board[t][input - 1] != ' ') {
            t--;
        }
        Board[t][input - 1] = PlayerMove;

        if (PlayerMove == 'X') P1_Tally++;
        else P2_Tally++;

        system("cls");
        PrintBoard(Board);

        if (GameOver(Board)) {
            TallyCount = (PlayerMove == 'X') ? P1_Tally : P2_Tally;
            Victory(PlayerMove, TallyCount);
            break;
        }

        turn = !turn;
    }

    return 0;
}

void Introduction() {
    cout << "Welcome to Connect4.\n\n";
    cout << "The goal is to be the first player to place\n";
    cout << "four checkers in a row, horizontal, vertical,\n";
    cout << "or diagonal.\n\n";
}

void PrintBoard(char Board[6][7]) {
    const int Row = 6, Column = 7;
    string Top = "  1   2   3   4   5   6   7";
    string Separator = "+---+---+---+---+---+---+---+";

    cout << Top << endl;
    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Column; j++) {
            cout << "| " << Board[i][j] << " ";
        }
        cout << "|" << endl << Separator << endl;
    }
}

bool GameOver(char Board[6][7]) {
    const int Row = 6, Column = 7;

    for (int i = 0; i < Row; i++) {
        for (int j = 0; j < Column; j++) {
            char current = Board[i][j];
            if (current == ' ') continue;

            // Horizontal
            if (j <= Column - 4 &&
                current == Board[i][j + 1] &&
                current == Board[i][j + 2] &&
                current == Board[i][j + 3]) return true;

            // Vertical
            if (i <= Row - 4 &&
                current == Board[i + 1][j] &&
                current == Board[i + 2][j] &&
                current == Board[i + 3][j]) return true;

            // Diagonal down-right
            if (i <= Row - 4 && j <= Column - 4 &&
                current == Board[i + 1][j + 1] &&
                current == Board[i + 2][j + 2] &&
                current == Board[i + 3][j + 3]) return true;

            // Diagonal down-left
            if (i <= Row - 4 && j >= 3 &&
                current == Board[i + 1][j - 1] &&
                current == Board[i + 2][j - 2] &&
                current == Board[i + 3][j - 3]) return true;
        }
    }

    return false;
}

void Victory(char Shape, int Tally) {
    cout << "\nPlayer " << (Shape == 'X' ? "1" : "2") << " wins!\n";
    cout << "Tally Count: " << Tally << endl;
    system("pause");
}