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
 * @brief Randomly determines if a new car should be generated.
 *
 * Uses `rand()` to generate a random number between 1 and 100.
 * Returns `1` if a car should be generated (random number <= probability),
 * otherwise returns `0`.
 *
 * @note The `srand()` function must be called in `main()` before using this function.
 *
 * @param[in] probability The probability (0-100) of generating a new car.
 * @return int `1` if a car should be generated, `0` otherwise.
 */
static int car_gen_bool(const int probability);


#endif

