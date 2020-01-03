#include <SDL2/SDL.h>

#include "./game.h"
#include "./rendering.h"

const SDL_Color GRID_COLOR = { .r = 255, .g = 255, .b = 255 };

void render_grid(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, GRID_COLOR.r, GRID_COLOR.g, GRID_COLOR.b, 255);

    for (int i = 1; i < N; ++i) {
        SDL_RenderDrawLine(renderer,
                           i * CELL_WIDTH, 0,
                           i * CELL_WIDTH, WINDOW_HEIGHT);
        SDL_RenderDrawLine(renderer,
                           0, i * CELL_HEIGHT,
                           WINDOW_WIDTH, i * CELL_HEIGHT);
    }
}

void render_cell_content(SDL_Renderer *renderer,
                         const int row,
                         const int column,
                         const int *corr_board)
{
    switch (corr_board[row * N + column]) {
    case A:
        SDL_SetRenderDrawColor( renderer, 255, 0, 0, 255 );
        break;
    case B:
        SDL_SetRenderDrawColor( renderer, 0, 0, 255, 255 );
        break;
    case C:
        SDL_SetRenderDrawColor( renderer, 82, 30, 128, 255 );
        break;
    case D:
        SDL_SetRenderDrawColor( renderer, 110, 210, 143, 255 );
        break;
    case E:
        SDL_SetRenderDrawColor( renderer, 221, 240, 48, 255 );
        break;
    case F:
        SDL_SetRenderDrawColor( renderer, 212, 130, 36, 255 );
        break;
    case G:
        SDL_SetRenderDrawColor( renderer, 161, 141, 118, 255 );
        break;
    case H:
        SDL_SetRenderDrawColor( renderer, 240, 176, 176, 255 );
        break;
    default : {}
    }

    SDL_Rect r;
    r.x = column * CELL_WIDTH + CELL_WIDTH / 2 - 50 / 2;
    r.y = row * CELL_HEIGHT + CELL_HEIGHT / 2 - 50 / 2;
    r.w = 50;
    r.h = 50;

    SDL_RenderFillRect( renderer, &r );
}

void render_board(SDL_Renderer *renderer,
                  const game_t *game)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            //render_cell_content(renderer, i, j, corr_board);
            if (game->done_board[i * N + j] == OPEN)
            {
                render_cell_content(renderer, i, j, game->corr_board);
            }
        }
    }
}

void render_idle_state(SDL_Renderer *renderer, const game_t *game)
{
    render_grid(renderer);
    render_board(renderer, game);
}

void render_game_over_state(SDL_Renderer *renderer,
                            const game_t *game,
                            const SDL_Color *color)
{
    render_grid(renderer);
}

void render_game(SDL_Renderer *renderer, const game_t *game)
{
    switch(game->state) {
    case IDLE:
        render_idle_state(renderer, game);
        break;
    
    case FIRST_PICK:
        render_idle_state(renderer, game);
        break;
    /*
    case PLAYER_O_WON:
        render_game_over_state(renderer, game, &PLAYER_O_COLOR);
        break;

    case TIE:
        render_game_over_state(renderer, game, &TIE_COLOR);
        break;
    */
    default: {}
    }
}