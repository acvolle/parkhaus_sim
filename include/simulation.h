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

/**
* @brief Frees the memory allocated to the config struct
*
* @param[out] p_config Pointer to the Config struct to be freed
* @return int Status code:
*            - `0` if the operation succeeded.
*            - `-1` if an error occurred (e.g., `p_config` is `NULL`).
*/
int free_config(Config *p_config);


/**
* @brief Determines whether a new car should be generated
* 
* Uses rand() to generate a random number between 1 and 100. Will, based on that, return either
* either 1 if a Car should be generated, else 0. 
*
* @param[in] seed const int seed the randomizer should use
* @param[in] probability const int probability of a new car being generated.
* @return int should car be generated?:
*            - `0` if no Car should be generated.
*            - `1` if a car should be generated.
*/
int car_gen_bool(const int probability);


#endif

