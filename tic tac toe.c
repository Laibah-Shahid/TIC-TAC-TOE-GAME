#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BOARD_SIZE 3

int numGenerator() {
    return rand() % 3;
}

void lines(char board[BOARD_SIZE][BOARD_SIZE]) {

    system("cls");
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    fflush(stdin);
    char temp;
    printf("\nPress key to continue...");
    scanf("%c", &temp);
}

int check(char move, char index[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < 3; i++) {
        if (index[i][0] == move && index[i][1] == move && index[i][2] == move ) {
            if (move == 'X') {
                return 1;
            } else if (move == 'O') {
                return 2;
            }
        }
    }

    // Check for vertical wins
    for (int i = 0; i < 3; i++) {
        if (index[0][i] == move && index[1][i] == move && index[2][i] == move) {
            if (move == 'X') {
                return 1;
            } else if (move == 'O') {
                return 2;
            }
        }
    }

    // Check for diagonal wins
    if (index[0][0] == move && index[1][1] == move && index[2][2] == move ) {
        if (move == 'X') {
            return 1;

        } else if (move == 'O') {
            return 2;

        }
    }
    if (index[0][2] == move && index[1][1] == move && index[2][0] == move ) {
        if (move == 'X') {
            return 1;

        } else if (move == 'O') {
            return 2;

        }
    }
    return 0;
}

void playerMove(int move, int row, int col, char game[BOARD_SIZE][BOARD_SIZE]) {
    while (1) {
        printf("Enter the row and column of the cell that you chose: ");
        scanf("%d %d", &row, &col);
        if (game[row - 1][col - 1] == ' ') {
            game[row - 1][col - 1] = move;
            lines(game);
            break;
        } else {
            printf("Space already filled!\n");
            continue;
        }
    }
}

void compMove(int move, int row, int col, char game[BOARD_SIZE][BOARD_SIZE]) {
    while (1) {
        row = numGenerator();
        col = numGenerator();
        if (game[row][col] == ' ') {
            game[row][col] = move;
            lines(game);
            break;
        } else {
            continue;
        }
    }
}

int main() {
    char game[3][3], choice, playerOne[100], playerTwo[100];
    int row, col, y = 1;

    srand(time(0));

    while (y != 0) {
        system("cls");
        memset(game, ' ', sizeof(game)); //initialise board with blank spaces.
        fflush(stdin);
        printf("Welcome,please select one of the following options:\na-One player\tb-Multiplayer\n");
        scanf("%c", &choice);
        fflush(stdin);

        if (choice == 'a') {
            printf("Enter player name: ");
            gets(playerOne);
            fflush(stdin);

            for (int i = 1; i <= 9; i++) {

                char move = (i % 2 == 0) ? 'O' : 'X';

                if (i % 2 != 0) {
                    playerMove(move, row, col, game);
                } else {
                    compMove(move, row, col, game);
                }

                if (i > 3) {
                    int res = check(move, game);
                    if (res == 1) {
                        printf("\n%s wins!\n", playerOne);
                        break;
                    }
                    if (res == 2) {
                        printf("Computer wins!\n");
                        break;
                    }
                    if (i == 9) {
                        printf("It's a Tie.\n");
                    }
                }
            }
        }

        if (choice == 'b') {
            printf("Enter player one's name:");
            gets(playerOne);

            printf("Enter player two's name:");
            gets(playerTwo);

            for (int i = 1; i <= 9; i++) {
                char move = (i % 2 == 0) ? 'O' : 'X';

                if (move == 'X') {
                    printf("%s's turn\n", playerOne);
                    playerMove(move, row, col, game);
                }
                if (move == 'O') {
                    printf("%s's turn\n", playerTwo);
                    playerMove(move, row, col, game);
                }
                if (i > 3) {
                    int res = check(move, game);
                    if (res == 1) {
                        printf("\n%s wins!\n", playerOne);
                        break;
                    }
                    if (res == 2) {
                        printf("%s wins!\n", playerTwo);
                        break;
                    }
                    if (i == 9) {
                        printf("It's a Tie\n.");
                    }
                }
            }
        }

        printf("Would you like to replay?\nEnter 1 for Yes and 0 for No.");
        scanf("%d", &y);

    }

}


