#ifndef GAME_H
#define GAME_H

#define N 2
#define WINDOW_WIDTH 640.0
#define WINDOW_HEIGHT 480.0
#define CELL_WIDTH (WINDOW_WIDTH / N)
#define CELL_HEIGHT (WINDOW_HEIGHT / N)

typedef enum {
    A,
    B
} cards;

typedef enum {
    IDLE,
    FIRST_PICK,
    SECOND_PICK,
    END,
    QUIT
} game_states;

// rename
typedef struct {
    int board[N * N];
    int pick;
    int done_indexes[5];
    int state;
} game_t;

#endif