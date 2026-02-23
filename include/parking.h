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
* 
* This function creates and initializes a new `Parkhaus` struct, allocating memory for itself
* its `spaces` array based on the parameters of the provided `Simulation`.
* To be called at the beginning of he simulation, once the simulation parameters are known.
*
* @param[in] s Pointer to the current Simulation (cannot be `NULL`)
* @return Pointer to the created Parkhaus (return `NULL` in case of error)
*
* @note The allocated memory for the parkhaus must be freed with the close_parkhaus() function
*/
Parkhaus* init_parkhaus(Simulation *s);

/**
* @brief Delete Parkhaus and free allocated memory
* 
* This function releases all dynamically allocated memory associated with the provided
* `Parkhaus` struct, including the `spaces` array.
* To be called at the end of the simulation.
* 
* @param[in] p Pointer to the Parkhaus that will be freed (cannot be `NULL`)
* @return int Status code:
*            - `0` if the operation succeeded.
*            - `-1` if an error occurred (e.g., `p` is `NULL` or memory could not be freed).
*
* @warning After calling this function, the pointer `p` is invalid. Do not dereference it.
*/
int close_parkhaus(Parkhaus *p);

/**
* @brief Inserts new car into the spaces array of a Parkhaus
*
* Inserts a struct Car into the `spaces` array of the specified struct Parkhaus if there
* is space. Sets the Car structs time remaining and time of entry variables.
* Returns `1` if there are no free spaces in the Parkhaus and then doesn't insert the car.
*
* @param[out] p Pointer to Parkhaus in which the car should be parked (cannot be `NULL`)
* @param[out] c Pointer to Car which will be parked
* 
* @return int Status code:
*            - `0` if the operation succeeded.
             - `1` if there are no free spaces
*            - `-1` if an error occurred (e.g., `p` is `NULL` or memory could not be freed).
*/
int park_car(Parkhaus *p, Car *c);


#endif