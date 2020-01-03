#ifndef GAME_H
#define GAME_H

#define N 4
#define PAIRS N * 2
#define WINDOW_WIDTH 640.0
#define WINDOW_HEIGHT 480.0
#define CELL_WIDTH (WINDOW_WIDTH / N)
#define CELL_HEIGHT (WINDOW_HEIGHT / N)

typedef enum {
    CLOSED,
    OPEN
} card_status;

typedef enum {
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H
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
    int corr_board[N * N];
    int done_board[N * N];
    int pick;
    int done_indexes[5];
    int state;
} game_t;

#endif