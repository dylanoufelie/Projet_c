#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#include "..\vue_controller\vue_controller.h"



/// @brief Structure representing the object's position (x,y) in space.
typedef struct Position_s {
    /// @brief position coordinates x.
    int x;

    /// @brief position coordinates y.
    int y;
} Position;

/// @brief Structure representing the sun (position and radius).
typedef struct Star_s {
    /// @brief Position of the sun in space.
    Position pos;

    /// @brief Radius of the sun.
    int radius;
} Star;

/// @brief Structure representing the planets (position, radius and orbit).
typedef struct Planets_s {
    /// @brief Position of the planet in space.
    Position pos;

    /// @brief Radius of the planet.
    int radius;

    /// @brief Planet orbit.
    int orbit;
} Planets;

/// @brief Structure representing the solar system (sun and planet)
typedef struct SolarSystem_S {
    /// @brief Sun of the solar system 
    Star star;

    /// @brief Planets in the solar system
    Planets* planet;

    /// @brief Number of planets in the solar system 
    int nbPlanets;
}SolarSystem;

/// @brief Window size (width and height).
typedef struct WindowSize_S {
    /// @brief Window width 
    int x;

    /// @brief Window height 
    int y;
}WindowSize;

/// @brief Structure representing the spaceship (start point, finish point and speed).
typedef struct Spaceship_S {
    /// @brief Starting position of the spaceship.
    Position start;

    /// @brief Arrival position of the spaceship.
    Position end;

    /// @brief Current position of the spaceship.
    Position current;

    /// @brief Spaceship speed.
    int speed;
}Spaceship;

/// @brief Structure containing all the solar systems.
typedef struct System_S {
    /// @brief Create a solar system.
    SolarSystem* solarsystem;

    /// @brief number of solar systems.
    int nbsolarsystem;

    /// @brief Create a Spaceship.
    Spaceship* spaceship;

    /// @brief Create a WindowSize.
    WindowSize* windo;
}System;

System* GameSet();