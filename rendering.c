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

void render_board(SDL_Renderer *renderer,
                  const int *board,
                  const SDL_Color *player_x_color,
                  const SDL_Color *player_o_color)
{
    
}

void render_idle_state(SDL_Renderer *renderer, const game_t *game)
{
    render_grid(renderer);
    
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
    /*
    case PLAYER_X_WON:
        render_game_over_state(renderer, game, &PLAYER_X_COLOR);
        break;

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