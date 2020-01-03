#ifndef RENDERING_H
#define RENDERING_H

void render_grid(SDL_Renderer *renderer);
void render_board(SDL_Renderer *renderer, const int *board);
void render_game(SDL_Renderer *renderer, const game_t *game);
void render_cell_content(SDL_Renderer *renderer, const int row, const int column, const int *board);

#endif