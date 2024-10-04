#include <stdio.h>
#include <stdlib.h>
int i,j;
void print(char elements[3][3]);
void entry(int num, char choice, char elements[3][3]);
int checkWin(char elements[3][3]);
int checkFull(char elements[3][3]);
void clearScreen();

int main() {
    char elements[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; 
    char choice;
    int num;
    int turn = 1; // 1 for X's turn, 0 for O's turn

    printf("       TIC TAC TOE GAME  Are you ready !!!!!!!!!!!!!!\n");
    print(elements);

    while (1) {
 // Clear the screen before printing the updated board
        if (turn) {
            printf("Player X, choose a position: ");
        } else {
            printf("Player O, choose a position: ");
        }
        scanf("%d", &num);
		clearScreen();
        if (num < 1 || num > 9) {
            printf("Invalid input. Please enter a number between 1 and 9.\n");
            continue;
        }

        choice = (turn) ? 'X' : 'O';
        entry(num, choice, elements);
        print(elements);

        if (checkWin(elements)) {
            printf("Player %c wins!\n", choice);
            break;
        }

        if (checkFull(elements)) {
            printf("The game is a draw!\n");
            break;
        }

        turn = !turn; // Switch turns
    }

    return 0;
}

void print(char elements[3][3]) {
    printf("\n-------------\n");
    for ( i = 0; i < 3; i++) {
        printf("|");
        for ( j = 0; j < 3; j++) {
            printf(" %c |", elements[i][j]);
        }
        printf("\n-------------\n");
    }
}

void entry(int num, char choice, char elements[3][3]) {
    int row = (num - 1) / 3;
    int col = (num - 1) % 3;

    if (elements[row][col] == 'X' || elements[row][col] == 'O') {
        printf("This position is already taken. Try again.\n");
        return;
    }

    elements[row][col] = choice;
}

int checkWin(char elements[3][3]) {
    // Check rows and columns
    for (i = 0; i < 3; i++) {
        if (elements[i][0] == elements[i][1] && elements[i][1] == elements[i][2]) return 1;
        if (elements[0][i] == elements[1][i] && elements[1][i] == elements[2][i]) return 1;
    }

    // Check diagonals
    if (elements[0][0] == elements[1][1] && elements[1][1] == elements[2][2]) return 1;
    if (elements[0][2] == elements[1][1] && elements[1][1] == elements[2][0]) return 1;

    return 0;
}

int checkFull(char elements[3][3]) {
    for ( i = 0; i < 3; i++) {
        for ( j = 0; j < 3; j++) {
            if (elements[i][j] != 'X' && elements[i][j] != 'O') return 0;
        }
    }
    return 1;
}

void clearScreen() {
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Unix-based systems
    #endif
}

