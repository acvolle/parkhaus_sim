#include "../include/car.h";
#ifndef PARKING_H
#define PARKING_H

/**
 * @brief Represents the simulated parking garage
 * @see Car
 *
 * This struct models a parking garage with dynamically allocated parking spots.
 * The `spaces` pointer points to an array of `Car` objects, where each element
 * represents an individual parking spot. The size of the array is determined
 * at runtime based on simulation parameters
 */
typedef struct Parkhaus{
    Car *spaces; /**< Pointer to an array of `Car` objects (parking spots). */
} Parkhaus;

/**
* @brief Initialize new Parkhaus
* @see Car
* @see Simulation
*
* Ausfuehrlichere Beschreibung, falls erforderlich, was die
* Funktion genau macht.
*
* @param[in] sim Pointer to the current Simulation
* @return Pointer to the created Parkhaus
*/
Parkhaus* init_parkhaus(Simulation *sim);


#endif