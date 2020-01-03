#include <stdio.h>

#include "./game.h"
#include "./logic.h"

void click_on_cell(game_t *game, int row, int column)
{
    int index = row * N + column;

    if (game->state == IDLE)
    {
        if (game->done_board[index] == CLOSED)
        {
            game->pick = index;
            game->state = FIRST_PICK;
            game->done_board[index] = OPEN;
        }
    }
    else if (game->state == FIRST_PICK)
    {
        // Second click wasn't on the same cell
        if (game->pick != index)
        {
            // Second cell was closed
            if (game->done_board[index] == CLOSED)
            {
                // Last and current cells content match! (pair found)
                if (game->corr_board[index] == game->corr_board[game->pick])
                {
                    game->done_board[index] = OPEN;
                    game->state = IDLE;
                } else {
                    game->done_board[index] = CLOSED;
                    game->done_board[game->pick] = CLOSED;
                    game->pick = 9999;
                    game->state = IDLE;
                }
            }
        }
    }
}