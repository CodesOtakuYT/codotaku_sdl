#pragma once
#include <memory>
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>

class App {
public:
    App(int argc, char **argv);

    SDL_AppResult Init();

    SDL_AppResult Iterate();

    SDL_AppResult Event(const SDL_Event *event);

    void Quit(SDL_AppResult result) const;

    enum AppLogCategory {
        APP_LOG_CATEGORY_GENERIC = SDL_LOG_CATEGORY_CUSTOM,
    };

private:
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
    std::unique_ptr<SDL_GPUDevice, decltype(&SDL_DestroyGPUDevice)> m_gpuDevice;

    SDL_AppResult OnQuit() const;

    SDL_AppResult OnRender() const;

    SDL_AppResult OnUpdate();
};
