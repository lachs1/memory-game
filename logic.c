#include <stdio.h>

#include "./game.h"
#include "./logic.h"

void click_on_cell(game_t *game, int row, int column)
{
    int index = row * N + column;

    if (game->state == IDLE)
    {
        game->pick = game->board[index];
        game->state = FIRST_PICK;
    }
    else if (game->state == FIRST_PICK)
    {
        // Found pair!
        if (game->board[index] == game->pick)
        {
        }
        game->pick = 0;
        game->state = IDLE;
    }
    printf("%d\n", index);
}