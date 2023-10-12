#include "vue_controller.h"

void SDL_update(System* system){


   
    SDL_SetRenderDrawColor(system->renderer, 0, 0, 0, 0);
     SDL_RenderClear(system->renderer);
    rectangleRGBA(system->renderer, (system->spaceship->start.x + 5), (system->spaceship->start.y + 5), (system->spaceship->start.x - 5), (system->spaceship->start.y - 5), 255, 255, 255, 255);
    rectangleRGBA(system->renderer, (system->spaceship->end.x + 5), (system->spaceship->end.y + 5), (system->spaceship->end.x - 5), (system->spaceship->end.y - 5), 255, 255, 255, 255);
    boxRGBA(system->renderer, (system->spaceship->current.x + 5), (system->spaceship->current.y + 5), (system->spaceship->current.x - 5), (system->spaceship->current.y - 5), 255, 0, 0, 255);


    int nbSS = system->nbsolarsystem;
    for (int i = 0; i < nbSS; i++) {
        filledCircleRGBA(system->renderer, system->solarsystem[i].star.pos.x, system->solarsystem[i].star.pos.y, system->solarsystem[i].star.radius, 255, 255, 0, 255);
        int nbP = system->solarsystem[i].nbPlanets;
        for (int j = 0; j < nbP; j++) {
            filledCircleRGBA(system->renderer, system->solarsystem[i].planet[j].pos.x, system->solarsystem[i].planet[j].pos.y, system->solarsystem[i].planet[j].radius, 0, 0, 255, 255);
        }
    }

    SDL_RenderPresent(system->renderer);
}

void SDLset(System* system) {

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("SDl cant start %s", SDL_GetError());
        exit(1);
    }

    SDL_Window* window = SDL_CreateWindow("SDL example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, system->windo->x, system->windo->y, 0);
    if (window == NULL) {
        SDL_Log("Window cant be generated %s", SDL_GetError());
        exit(1);
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == NULL) {
        SDL_Log("Renderer cannot be generated %s", SDL_GetError());
        exit(1);
    }
    system->renderer = renderer;


    SDL_RenderClear(system->renderer);

    int nbSS = system->nbsolarsystem;
    for (int i = 0; i < nbSS; i++) {
        filledCircleRGBA(system->renderer, system->solarsystem[i].star.pos.x, system->solarsystem[i].star.pos.y, system->solarsystem[0].star.radius, 255, 255, 0, 255);
        int nbP = system->solarsystem[i].nbPlanets;
        for (int j = 0; j < nbP; j++) {
            filledCircleRGBA(system->renderer, system->solarsystem[i].star.pos.x, (system->solarsystem[i].star.pos.y + abs(system->solarsystem[i].planet[j].orbit)), system->solarsystem[i].planet[j].radius, 0, 0, 255, 255);
        }
    }


    rectangleRGBA(system->renderer, (system->spaceship->start.x + 5), (system->spaceship->start.y + 5), (system->spaceship->start.x - 5), (system->spaceship->start.y - 5), 255, 255, 255, 255);
    rectangleRGBA(system->renderer, (system->spaceship->end.x + 5), (system->spaceship->end.y + 5), (system->spaceship->end.x - 5), (system->spaceship->end.y - 5), 255, 255, 255, 255);
    boxRGBA(system->renderer, (system->spaceship->current.x + 5), (system->spaceship->current.y + 5), (system->spaceship->current.x - 5), (system->spaceship->current.y - 5), 255, 0, 0, 255);

    SDL_RenderPresent(system->renderer);

}
