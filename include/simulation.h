#ifndef SIMULATION_H
#define SIMULATION_H

#include <stdlib.h>
#include "parking.h"
#include "stats.h"
#include "queue.h"


/**
 * @brief A struct to save simulation parameters
 * 
 * Values are set at start of the simulation by the user and should not be changed during the simulation.
 */
typedef struct Config{
    int num_spaces; /**< Number of spaces to be initalised in the parking garage */
    int max_parking_time; /**< Maximum time a Car can spend in the parking garage */
    int simulation_duration; /**< Pointer to an array of `Car` pointers (represent parking spots). */
    int gen_probability; /**< Probability of a new Car being generated each time step */
    int random_seed; /**< Random seed for the randomization of incoming cars */
}Config;
/*The members of the Config struct are not constant, even though they are not chnaged during the simulation.
  This is because a Config struct is initialized before the values are known, and then passed to a UI function
  which fills in the values input by the user.*/


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
 * Called by 
 *
 * @note The `srand()` function must be called in `main()` before using this function.
 *
 * @param[in] probability The probability (0-100) of generating a new car.
 * @return int `1` if a car should be generated, `0` otherwise.
 */
int car_gen_bool(const int probability);


/**
* @brief Initializes new Car struct and either parks or enqueues it
*
* Creates a new `Car` struct, then attempts to park it using `park_car()` (see `parking.h`).
* If parking fails, the `Car` is enqueued into the provided `Queue`.
*
* @param[out] p_parkhaus Pointer to Parkhaus in which the Car structshould be parked
* @param[out] p_queue Pointer to the Queue in which the Car struct can be enqueued
* @return int Status code:
*            - `0` if the operation succeeded.
*            - `-1` if an error occurred (e.g., pointer is `NULL`).
*/
int input_new_car(Parkhaus *p_parkhaus, Queue *p_queue);

/**
* @brief Runs a single timestep of the simulation
*
* Updates the `Parkhaus` struct.
* If there are `Car` structs in the Queue, as many as have space in the `Parkhaus` struct are parked in the
* `Parkhaus` struct (via their pointers).
* Randomly (using simulation parameters) determines whether a new `Car` struct is generated, and
* then parks it (if there is a free space) or else enqueues it in the `Queue`. 
* Simultaneously gets current statistics and saves them in the `Stats` struct.
*
* @param[out] p_parkhaus Pointer to the Parkhaus struct where a Car might be parked.
* @param[out] p_queue Pointer to the Queue which the Car might be added to.
* @param[in] p_config Pointer to the Config struct of the current simulation.
* @param[out] p_stats Pointer to the Stast struct where current statisctics will be saved.
* @return * @return int Status code:
*            - `0` if the operation succeeded.
*            - `-1` if an error occurred (e.g., pointer is `NULL`).
*/
int run_timestep(Parkhaus *p_parkhaus, Queue *p_queue, Config *p_config, Stats *p_stats);

#endif
