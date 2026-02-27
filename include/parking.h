#ifndef PARKING_H
#define PARKING_H

#include "car.h"

/* HEADER FILE FOR PARKING GARAGE
This module includes the struct Parkhaus, which represents the parking garage to be
simulated. Its main feature is an array of Car pointers, which represents all the individual 
parking spaces. The Cars are accessed via the pointers as their memory will be dynamically 
allocated. The Parkhaus struct also includes the size of the array, as defined by the user,
which is used to iterate through it. The number of occupied spaces is also saved as an integer,
this is updated every time a change is made and eliminates the need for repeated iterations through
the array any time the current number of occupied spaces is needed. 
A Parkhaus struct is accessed and changed by a number of functions, wherefore its memory is allocated
dynamically; it is passed to different functions and accessed via pointers.
The following functions are defined to manage the Parkhaus struct during the simulation:
- init_parkhaus(): dynamically allocates memory for the Parkhaus struct based on the size defined by
  the user and returns a pointer to it
- close_parkhaus(): frees the memory allocated to the Parkhaus struct
- park_car(): places a pointer to a Car struct in the array if there is space
- update_parkhaus(): updates the remaining tieme of all the Cars whose pointers are in the array and
  removes those whose parking time is up.
- parkhaus_is_full(): checks whether or not there are still free spaces (this is a very easy operation
   but provides increased modularization).
*/

/**
 * @brief Represents the simulated parking garage
 * @see Car
 *
 * This struct models a parking garage with dynamically allocated parking spots.
 * The `spaces` pointer points to an array of `Car` objects, where each element
 * represents an individual parking spot. The size of the array is determined
 * at runtime based on simulation parameters
 */
typedef struct Parkhaus
{
    const int size; /**< Size of the spaces array */
    int occupied_spaces; /**< Number of occupied spaces in the spaces array */
    Car **p_spaces; /**< Pointer to an array of `Car` pointers (represent parking spots). */
} Parkhaus;
/*Note: the spaces array is never sorted. Cars pointers are input into the first free spot while
  iteration through. Since adding a new car has a runtime of O(n) anyways, it would not be efficient
  to additionally move together all the pointers when a Car from the middle of the array is removed*/

/**
 * @brief Initialize new Parkhaus
 *
 * This function creates and initializes a new `Parkhaus` struct, allocating memory for itself and
 * its `spaces` array based on the parameters of the provided `Simulation`.
 * To be called at the beginning of the simulation, once the simulation parameters are known.
 *
 * @param[in] spaces_count number of parking spaces
 * @return Pointer to the created Parkhaus (return `NULL` in case of error)
 *
 * @note The allocated memory for the parkhaus must be freed with the close_parkhaus() function
 */
Parkhaus *init_parkhaus(unsigned int spaces_count);

/**
 * @brief Delete Parkhaus and free allocated memory
 *
 * This function releases all dynamically allocated memory associated with the provided
 * `Parkhaus` struct, including the `spaces` array.
 * To be called at the end of the simulation.
 *
 * @param[in] p_parkhaus Pointer to the `Parkhaus` that will be freed (cannot be `NULL`)
 * @return int Status code:
 *            - `0` if the operation succeeded.
 *            - `-1` if an error occurred (e.g., `p` is `NULL` or memory could not be freed).
 *
 * @warning After calling this function, the pointer `p` is invalid. Do not dereference it.
 */
int close_parkhaus(Parkhaus *p_parkhaus);

/**
 * @brief Inserts new Car into the spaces array of a Parkhaus
 *
 * Inserts a pointer to a `Car` into the first free space of the `spaces` array of the specified struct
 * `Parkhaus` if there is space. Sets the `Car` structs time remaining and time of entry variables and 
 * reduces the empty_spaces count of the `Parkhaus` struct by one.
 * Returns `1` if there are no free spaces in the `Parkhaus` and then doesn't insert the car.
 * Call this function when a new `Car` has been generated. If necessary can be called even if
 * there are no free spaces.
 *
 * @param[out] p_parkhaus Pointer to Parkhaus in which the car should be parked (cannot be `NULL`)
 * @param[out] p_car Pointer to Car which will be parked
 * @return int Status code:
 *            - `0` if the operation succeeded.
 *            - `1` if there are no free spaces
 *             - `-1` if an error occurred (e.g., `p` is `NULL`).
 */
int park_car(Parkhaus *p_parkhaus, Car *p_car);


/**
 * @brief Updates all Car structs in a Parkhaus struct
 *
 * Iterates through every `Car` pointer in the `spaces` array of the `Parkhaus` struct and decreses the
 * stucts its remaining time value by 1 (if it is not NULL). If the remaining time value thereby 
 * reaches 0, the `Car` is removed from the array and the empty_spaces count of the `Parkhaus` struct is 
 * increased by 1.
 * This function must be called exactly once in every simulation step.
 *
 *
 * @param[out] p_parkhaus Pointer to Parkhaus struct which is to be updated
 * @return int Status code:
 *            - `0` if the operation succeeded.
 *            - `-1` if an error occurred (e.g., `p` is `NULL`).
 */
int update_parkhaus(Parkhaus *p_parkhaus);
/*This function is necessary because each Car struct seperately saves its own remaining time (the time until it
 leaves the Parkhaus). It is necessary to iterate through each one of them and decrease this value by one until
 the time runs out once every timestep of the simulation*/


/**
 * @brief Checks if a Parkhaus is full
 * 
 * Checks if all the spaces in the `spaces` array of a `Parkhaus` are occupied.
 * Returns `1` if all of them are, else `0`.
 * 
 * @param[in] p_parkhaus Pointer to the Parkhaus which should be checked
 * @return int 
 *            - `0` if there are still free spaces
 *            - `1` if the array is full of pointers
 */
int parkhaus_is_full(Parkhaus *p_parkhaus);

 #endif