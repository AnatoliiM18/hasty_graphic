#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL3/SDL.h>

#define WND_TITLE "My application"

SDL_Window* g_wnd;

void init_screen(const char* wnd_title, int w, int h)
{
    if (!SDL_InitSubSystem(SDL_INIT_VIDEO)) {
        printf("Unable to initialize SDL: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    atexit(SDL_Quit);

    SDL_PropertiesID wnd_props = SDL_CreateProperties();
    if (!wnd_props) {
        printf("Unable to create properties: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_SetStringProperty(wnd_props, SDL_PROP_WINDOW_CREATE_TITLE_STRING, wnd_title);
    SDL_SetNumberProperty(wnd_props, SDL_PROP_WINDOW_CREATE_WIDTH_NUMBER, w);
    SDL_SetNumberProperty(wnd_props, SDL_PROP_WINDOW_CREATE_HEIGHT_NUMBER, h);
    SDL_SetNumberProperty(wnd_props, SDL_PROP_WINDOW_CREATE_X_NUMBER, SDL_WINDOWPOS_CENTERED);
    SDL_SetNumberProperty(wnd_props, SDL_PROP_WINDOW_CREATE_Y_NUMBER, SDL_WINDOWPOS_CENTERED);

    SDL_Window* g_wnd = SDL_CreateWindowWithProperties(wnd_props);

    if (!g_wnd) {
        printf("Unable to create window: %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char* argv[])
{
    int scr_w = 640;
    int scr_h = 480;

    init_screen(WND_TITLE, scr_w, scr_h);

    SDL_Event event;

    while (true) {

        if (SDL_PollEvent(&event)) {

            if (event.type == SDL_EVENT_QUIT)
                break;

            if (event.type == SDL_EVENT_KEY_DOWN) {

                if (event.key.key == SDLK_ESCAPE) {
                    break;
                }
            }
        }
    }

    SDL_DestroyWindow(g_wnd);

    return EXIT_SUCCESS;
}
