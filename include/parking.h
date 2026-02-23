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
    Car *ptr_spaces; /**< Pointer to an array of `Car` objects (parking spots). */
} Parkhaus;

/**
* @brief Initialize new Parkhaus
* 
* This function creates and initializes a new `Parkhaus` struct, allocating memory for itself
* its `spaces` array based on the parameters of the provided `Simulation`.
* To be called at the beginning of he simulation, once the simulation parameters are known.
*
* @param[in] ptr_simulation Pointer to the current Simulation (cannot be `NULL`)
* @return Pointer to the created Parkhaus (return `NULL` in case of error)
*
* @note The allocated memory for the parkhaus must be freed with the close_parkhaus() function
*/
Parkhaus* init_parkhaus(Simulation *ptr_simulation);


/**
* @brief Delete Parkhaus and free allocated memory
* 
* This function releases all dynamically allocated memory associated with the provided
* `Parkhaus` struct, including the `spaces` array.
* To be called at the end of the simulation.
* 
* @param[in] ptr_parkhaus Pointer to the Parkhaus that will be freed (cannot be `NULL`)
* @return int Status code:
*            - `0` if the operation succeeded.
*            - `-1` if an error occurred (e.g., `p` is `NULL` or memory could not be freed).
*
* @warning After calling this function, the pointer `p` is invalid. Do not dereference it.
*/
int close_parkhaus(Parkhaus *ptr_parkhaus);


/**
* @brief Inserts new car into the spaces array of a Parkhaus
*
* Inserts a struct Car into the `spaces` array of the specified struct Parkhaus if there
* is space. Sets the Car structs time remaining and time of entry variables.
* Returns `1` if there are no free spaces in the Parkhaus and then doesn't insert the car.
* Call this function when a new car has been generated. If necessary can be called even if
* there are no free spaces.
*
* @param[out] ptr_parkhaus Pointer to Parkhaus in which the car should be parked (cannot be `NULL`)
* @param[out] ptr_car Pointer to Car which will be parked
* @return int Status code:
*            - `0` if the operation succeeded.
*            - `1` if there are no free spaces
*            - `-1` if an error occurred (e.g., `p` is `NULL`).
*/
int park_car(Parkhaus *ptr_parkhaus, Car *ptr_car);

/**
* @brief Updates all Car structs in a Parkhaus struct
*
* Iterates through every Car struct in the `spaces` array of the Parkhaus struct and decreses its 
* remaining time value by 1. If the remaining time value theeby reaches 0, the Car is removed from
* the array.
* This function must be called exactly once in every simulation step.
* 
*
* @param[out] ptr_parkhaus Pointer to Parkhaus struct which is to be updated
* @return int Status code:
*            - `0` if the operation succeeded.
*            - `-1` if an error occurred (e.g., `p` is `NULL`).
*/
int update_parkhaus(Parkhaus *ptr_parkhaus);

#endif