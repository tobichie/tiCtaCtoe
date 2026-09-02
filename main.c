#include <stdio.h>

// tic tac toes
// create an empty char array that is 3 x 3 (9)
// |0|1|2|
// |3|4|5|
// |6|7|8|
// get position of all X (if x is playing)
// get position of all empty blocks to see which are available
// if 0 1 2 or 345 or 678 or 036 or 147 or 258 or 246 or 048

struct Player {
    char symbol;

};

struct Move {
    int index;
    struct Player *player;
};

void showBord(char *_tictoes) {
    printf(
        "|%c|%c|%c|\n|%c|%c|%c|\n|%c|%c|%c|\n",
        _tictoes[0], _tictoes[1], _tictoes[2], _tictoes[3], _tictoes[4], _tictoes[5], _tictoes[6], _tictoes[7], _tictoes[8]
        ); // the first 3 tiles then the next row etc
    printf("-------------------------------------\n");
    printf(
        "|0|1|2|\n|3|4|5|\n|6|7|8|\n"
        ); // the first 3 tiles then the next row etc

}

struct Move getMove(int choice, struct Player *player) {

    scanf_s("%d", &choice);
    struct Move move = {
        .index = choice,
        .player = player
    };
    return move;
}

int checkValidMove(const int *tictoes, struct Move *move) {
    // see if the index of the move is empty
    if (tictoes[move->index] == 0) {
        return 1;
    }
    return 0;
}

int checkVictory(const char *_tictoes) {
    // check if a game winning move was made

    if ((_tictoes[0] == _tictoes[1] && _tictoes[1] == _tictoes[2] && _tictoes[0] != ' ')) {
        if (_tictoes[0] == 'X') {
            printf("X wins");
        }
        else {
            printf("O wins");
        }
        return 1;
    }
    if ((_tictoes[3] == _tictoes[4] && _tictoes[4] == _tictoes[5] && _tictoes[3] != ' ')) {
        if (_tictoes[3] == 'X') {
            printf("X wins");
        }
        else {
            printf("O wins");
        }
        return 1;
    }
    if ((_tictoes[6] == _tictoes[7] && _tictoes[7] == _tictoes[8] && _tictoes[6] != ' ')) {
        if (_tictoes[6] == 'X') {
            printf("X wins");
        }
        else {
            printf("O wins");
        }
        return 1;
    }
    // if 0 1 2 or 345 or 678 or 036 or 147 or 258 or 246 or 048

    if ((_tictoes[0] == _tictoes[3] && _tictoes[3] == _tictoes[6] && _tictoes[0] != ' ')) {
        if (_tictoes[0] == 'X') {
            printf("X wins");
        }
        else {
            printf("O wins");
        }
        return 1;
    }
    if ((_tictoes[1] == _tictoes[4] && _tictoes[4] == _tictoes[7] && _tictoes[1] != ' ')) {
        if (_tictoes[1] == 'X') {
            printf("X wins");
        }
        else {
            printf("O wins");
        }
        return 1;
    }
    if ((_tictoes[2] == _tictoes[5] && _tictoes[5] == _tictoes[8] && _tictoes[2] != ' ')) {
        if (_tictoes[2] == 'X') {
            printf("X wins");
        }
        else {
            printf("O wins");
        }
        return 1;
    }
    if ((_tictoes[2] == _tictoes[4] && _tictoes[4] == _tictoes[6] && _tictoes[2] != ' ')) {
        if (_tictoes[2] == 'X') {
            printf("X wins");
        }
        else {
            printf("O wins");
        }
        return 1;
    }
    if ((_tictoes[0] == _tictoes[4] && _tictoes[4] == _tictoes[8] && _tictoes[0] != ' ')) {
        if (_tictoes[0] == 'X') {
            printf("X wins");
        }
        else {
            printf("O wins");
        }
        return 1;
    }

    return 0;

}

void placeChoice(char *_tictoes, int *tictoes, struct Move *move) {
    if (checkValidMove(tictoes, move) == 1) {
        // place the moves symbol where the choice is
        _tictoes[move->index] = move->player->symbol;
        // next place a 1 in the int array at the moves index so checkValidMove returns a 0
        tictoes[move->index] = 1;
    }

}

int gameLoop() {
    // define arrays
    printf("You lose your turn if you click the same tile as the opponent.\n");
    int tictoes[9] = {0};
    char _tictoes[9] = {' ', ' ', ' ',
                        ' ', ' ', ' ',
                        ' ', ' ', ' '};


    int choice1 = 0;
    int choice2 = 0;
    // get both players and their symbol
    //
    struct Player player1 = {
        .symbol = 'X'
    };
    struct Player player2 = {
        .symbol = 'O'
    };
    // while checkVictory == 0
    while (checkVictory(_tictoes) == 0) {
        showBord(_tictoes);
        printf("Player one choose: \n");
        struct Move move1 = getMove(choice1, &player1);
        placeChoice(_tictoes, tictoes, &move1);
        if (checkVictory(_tictoes) == 1) {
            break;
        }

        printf("Player two choose position: \n");
        struct Move move2 = getMove(choice2, &player2);
        placeChoice(_tictoes, tictoes, &move2);
    }


}



int main() {
    gameLoop();
    return 0;
}
