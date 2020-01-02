#include <stdio.h>

#include "./game.h"
#include "./logic.h"

void click_on_cell(game_t *game, int row, int column)
{
    int index = row * N + column;

    if (game->state == IDLE)
    {
        game->state = FIRST_PICK;
    }
    printf("%d\n", index);
}