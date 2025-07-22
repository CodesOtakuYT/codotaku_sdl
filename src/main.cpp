#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>

#include "App.h"


SDL_AppResult SDL_AppInit(void **appstate, const int argc, char **argv) {
    const auto app = new App{argc, argv};
    *appstate = app;
    return app->Init();
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    const auto app = static_cast<App *>(appstate);
    return app->Iterate();
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    const auto app = static_cast<App *>(appstate);
    return app->Event(event);
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    const auto app = static_cast<App *>(appstate);
    app->Quit(result);
}
