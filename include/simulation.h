#include <stdlib.h>
#ifndef SIMULATION_H
#define SIMULATION_H

/**
 * @brief A strcut to save simulation parameters
 * 
 * Values are set at start of the simulation by the user and cannot be changed during the simulation.
 */
typedef struct Config{
    const int num_spaces; /**< Number of spaces to be initalised in the parking garage */
    const int max_parking_time; /**< Maximum time a Car can spend in the parking garage */
    const int simulation_duration; /**< Pointer to an array of `Car` pointers (represent parking spots). */
    const float gen_probability; /**< Probability of a new Car being generated each time step */
    const int random_seed; /**< Random seed for the randomization of incoming cars */
}Config;