#include "hasty_graphic.h"
#include "hasty_shapes.h"
#include <SDL3/SDL.h>

#define WND_TITLE "My application"

int main(int argc, char* argv[])
{
    int scr_w = 640;
    int scr_h = 480;
    SDL_Event event;
    rect r = { 60, 30, 100, 180 };
    rect r2 = { 150, 200, 600, 180 };

    init_graphics(WND_TITLE, scr_w, scr_h);

    /* Main loop */
    while (1) {

        /* Event handling */
        if (SDL_PollEvent(&event)) {

            if (event.type == SDL_EVENT_QUIT)
                break;

            if (event.type == SDL_EVENT_KEY_DOWN) {

                if (event.key.key == SDLK_ESCAPE) {
                    break;
                }
                if (event.key.key == SDLK_B) {
                    clear_back_buffer(BLUE);
                }
                if (event.key.key == SDLK_G) {
                    clear_back_buffer(GREEN);
                }
                if (event.key.key == SDLK_R) {
                    uint32_t color_red = pack_color_rgb(0xff, 0x00, 0x00);
                    clear_back_buffer(color_red);
                }
            }
        } /* End of event handling */

        /* Draw here */
        draw_rect_fill(&r, CYAN);
        draw_line(50, 20, 150, 200, GREEN);
        draw_line_h(50, 150, 20, YELLOW);
        draw_line_h(50, 150, 200, RED);
        draw_line_v(50, 20, 200, BLACK);
        draw_line_v(150, 20, 200, BLACK);
        draw_line_h(650, 40, 300, MAGENTA);
        draw_line_v(100, 500, 20, MAGENTA);

        draw_rect(&r, WHITE);

        draw_rect_fill(&r2, BLUE);
        draw_rect(&r2, WHITE);

        /* Clear and redraw screen */
        redraw_screen();
    }

    shutdown_graphics();

    return EXIT_SUCCESS;
}
