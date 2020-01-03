#include <stdlib.h>
#include <stdio.h>

#include <SDL2/SDL.h>

#include "./game.h"
#include "./logic.h"
#include "./rendering.h"

int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window* window = SDL_CreateWindow("w",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT,
                                          SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
                                                SDL_RENDERER_ACCELERATED |
                                                SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL)
    {
        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }

    game_t game = {
        .corr_board = { B, A, C, D,
                        A, D, C, B,
                        E, F, G, G,
                        F, H, H, E },
        .done_board = { CLOSED, CLOSED, CLOSED, CLOSED,
                        CLOSED, CLOSED, CLOSED, CLOSED,
                        CLOSED, CLOSED, CLOSED, CLOSED,
                        CLOSED, CLOSED, CLOSED, CLOSED },
        .pick = 9999,
        .state = IDLE
    };

    SDL_Event e;
    while (game.state != QUIT) {
        while(SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_QUIT:
                game.state = QUIT;
                break;

            case SDL_MOUSEBUTTONDOWN:
                click_on_cell(&game,
                              e.button.y / CELL_HEIGHT,
                              e.button.x / CELL_WIDTH);
            default: {}
        }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        // double buffering
        SDL_RenderClear(renderer);
        render_game(renderer, &game);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();

    return EXIT_SUCCESS;
}