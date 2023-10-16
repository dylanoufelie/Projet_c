#include "model.h"

#define filename "config.txt"
#define MAX_SIZE 1000 

System* GameSet() {

    //printf("%s\n", argv[1]);
    FILE* file = fopen(filename, "r");

    char buffer[MAX_SIZE] = "";

    if (file == NULL) {
        printf("Unable to open filename file. \n");
        abort(); // kills the program.
    }

    int count = 0, count2 = 0, count3 = 0, i = 0, j = 0;
    System* system = (System*)calloc(1, sizeof(System));
    system->windo = (WindowSize*)calloc(1, sizeof(WindowSize));
    system->spaceship = (Spaceship*)calloc(1, sizeof(Spaceship));

    while (fgets(buffer, MAX_SIZE, file) != NULL) { //read until end of file
        char chain[20];
        for (int i = 0; i < 20; i++) {
            chain[i] = "\0";
        }
        int x = 0, y = 0;

        if (sscanf(buffer, "%s %d %d", chain, &x, &y) == 3) {

            if (strcmp(chain, "WIN_SIZE") == 0) {
                system->windo->x = x;
                system->windo->y = y;
            }

            else if (strcmp(chain, "START") == 0) {
                system->spaceship->start.x = x;
                system->spaceship->start.y = y;
                system->spaceship->current.x = x;
                system->spaceship->current.y = y;
            }

            else if (strcmp(chain, "END") == 0) {
                system->spaceship->end.x = x;
                system->spaceship->end.y = y;
            }

            else if (strcmp(chain, "STAR_POS") == 0) {
                system->solarsystem[count].star.pos.x = x;
                system->solarsystem[count].star.pos.y = y;
                count++;
            }
        }

        else if (sscanf(buffer, "%s %d", chain, &x) == 2) {

            if (strcmp(chain, "NB_SOLAR_SYSTEM") == 0) {
                system->nbsolarsystem = x;
                system->solarsystem = (SolarSystem*)calloc(system->nbsolarsystem, sizeof(SolarSystem));
            }

            else if (strcmp(chain, "STAR_RADIUS") == 0) {
                if (x < 0) {
                    printf("star radius is not viable: %d\n", x);
                    abort();
                }
                system->solarsystem[count - 1].star.radius = x;
            }

            else if (strcmp(chain, "NB_PLANET") == 0) {
                system->solarsystem[count - 1].nbPlanets = x;
                //system->solarsystem[count].planet = (Planets*)calloc(x, sizeof(Planets));
            }

            else if (strcmp(chain, "PLANET_RADIUS") == 0) {
                if (count - 1 != i) {
                    count2 = 0;
                }
                i = count - 1;
                if (x < 0) {
                    printf("planete radius is not viable: %d\n", x);
                    abort();
                }
                
                if (!(system->solarsystem[i].planet)) {
                    int nbplanet = (system->solarsystem[i].nbPlanets);
                    system->solarsystem[i].planet = (Planets*)calloc(nbplanet, sizeof(Planets));
                }
                else if (system->solarsystem[i].planet) system->solarsystem[i].planet[count2].radius = x;
                else {
                    printf("ERROR: there is no planet in this solar system");
                    abort();
                }
                count2++;
            }

            else if (strcmp(chain, "PLANET_ORBIT") == 0) {
                if (count - 1 != j) {
                    count3 = 0;
                }
                j = count - 1;
                if (x > 250 || x < -250) {
                    printf("planete orbit is not viable: %d\n", x);
                    abort();
                }
                if (x < 0) x = -x;
                system->solarsystem[j].planet[count3].orbit = x;
                count3++;
            }
        }
    }


    printf("Taille de la fenetre : x = %d , y = %d\n", system->windo->x, system->windo->y);
    printf("point de depart : x = %d, y = %d\n", system->spaceship->start.x, system->spaceship->start.y);
    printf("point de d'arrivee : x = %d, y = %d\n", system->spaceship->end.x, system->spaceship->end.y);
    printf("Nombre de systeme solaire = %d\n", system->nbsolarsystem);
    printf("Position du soleil 1 : x = %d , y = %d\n", system->solarsystem[0].star.pos.x, system->solarsystem[0].star.pos.y);
    printf("Position du soleil 2 : x = %d , y = %d\n\n", system->solarsystem[1].star.pos.x, system->solarsystem[1].star.pos.y);
    printf("Rayon du soleil 1 = %d\n", system->solarsystem[0].star.radius);
    printf("Rayon du soleil 2 = %d\n", system->solarsystem[1].star.radius);
    printf("Nbr de planette du syst sol 1 = %d\n", system->solarsystem[0].nbPlanets);
    printf("Nbr de planette du syst sol 2 = %d\n", system->solarsystem[1].nbPlanets);
    printf("Solarsystem 0 Planet 0 radius = %d , Planet 0 orbit = %d\n", system->solarsystem[0].planet[0].radius, system->solarsystem[0].planet[0].orbit);
    printf("Solarsystem 0 Planet 1 radius = %d , Planet 1 orbit = %d\n", system->solarsystem[0].planet[1].radius, system->solarsystem[0].planet[1].orbit);
    printf("Solarsystem 0 Planet 2 radius = %d , Planet 2 orbit = %d\n", system->solarsystem[0].planet[2].radius, system->solarsystem[0].planet[2].orbit);
    printf("Solarsystem 1 Planet 0 radius = %d , Planet 0 orbit = %d\n", system->solarsystem[1].planet[0].radius, system->solarsystem[1].planet[0].orbit);

    fclose(file);
    return system;
}