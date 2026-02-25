#include <stdlib.h>
#ifndef SIMULATION_H
#define SIMULATION_H

/**
 * @brief A struct to save simulation parameters
 * 
 * Values are set at start of the simulation by the user and cannot be changed during the simulation.
 */
typedef struct Config{
    int num_spaces; /**< Number of spaces to be initalised in the parking garage */
    int max_parking_time; /**< Maximum time a Car can spend in the parking garage */
    int simulation_duration; /**< Pointer to an array of `Car` pointers (represent parking spots). */
    int gen_probability; /**< Probability of a new Car being generated each time step */
    int random_seed; /**< Random seed for the randomization of incoming cars */
}Config;


/**
* @brief Initializes a new Config struct
* 
* Creates a new zero-initialized, dynamically allocated Config struct. Passes it to the ui_get_params()
* functions to let the user set the config parameters. Returns a pointer to the config if getting
* the parameters worked.
* To be called at the beginning of the simulation.
* The allocated memory for the Condig struct must be cleared at the end of the simulation!
* Use free_config()
* 
* @return pointer to the created Config struct (NULL if error)
*/
Config* new_config();



#endif

