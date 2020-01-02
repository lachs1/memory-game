#ifndef RENDERING_H
#define RENDERING_H

void render_grid(SDL_Renderer *renderer);
void render_board(SDL_Renderer *renderer, const int *board, const SDL_Color *player_x_color, const SDL_Color *player_o_color);
void render_game(SDL_Renderer *renderer, const game_t *game);

#endif