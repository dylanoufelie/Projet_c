#include ".\model\model.h"
#include ".\vue_controller\vue_controller.h"


#include <SDL.h>
#include "../../../../SDL2/SDL2_gfx-1.0.4/SDL2_gfxPrimitives.h"
#include <math.h>

#define filename "config.txt"
#define MAX_SIZE 1000   

int main(int argc, char* argv[]){
    printf("%s\n", argv[1]);

    System* system = (System*)calloc(1, sizeof(System));
    system = GameSet();

///SDL

    SDLset(system);
    
    Uint32 previousTime = SDL_GetTicks();
    int current = 0, previous = 0;

    SDL_Event ev;
    while (SDL_WaitEvent(&ev) && ev.type != SDL_QUIT) {

        Uint32 currentTime = SDL_GetTicks();
        current++;
        // Calculer le delta time en millisecondes.
        Uint32 deltaTime = current - previous;

        // Mettre à jour le temps précédent pour la prochaine itération.
        previous = current;
        

        //SDLset(system);

        Planets_Update(system, deltaTime, current);
        SDL_update(system, system->renderer);

       // SDL_update(system, )
        //printf("delta time = %d\n", deltaTime);
       // printf("position planete x = %d ; y= %d\n", system->solarsystem[0].planet[0].pos.x, system->solarsystem[0].planet[0].pos.x);

        // SDL_RenderPresent(renderer); - in case of MacOS Mojave  
        /*printf("Solarsystem 0 Planet 0 radius = %d , Planet 0 orbit = %d\n", system->solarsystem[0].planet[0].radius, system->solarsystem[0].planet[0].orbit);
        printf("Solarsystem 0 Planet 1 radius = %d , Planet 1 orbit = %d\n", system->solarsystem[0].planet[1].radius, system->solarsystem[0].planet[1].orbit);
        printf("Solarsystem 0 Planet 2 radius = %d , Planet 2 orbit = %d\n\n", system->solarsystem[0].planet[2].radius, system->solarsystem[0].planet[2].orbit);
        printf("Solarsystem 1 Planet 0 radius = %d , Planet 0 orbit = %d\n", system->solarsystem[1].planet[0].radius, system->solarsystem[1].planet[0].orbit);
        printf("Solarsystem 1 Planet 1 radius = %d , Planet 1 orbit = %d\n\n\n\n", system->solarsystem[1].planet[1].radius, system->solarsystem[1].planet[1].orbit);
        */
    }

    SDL_Quit();

	return 0;
}