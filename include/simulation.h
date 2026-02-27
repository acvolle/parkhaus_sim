#ifndef SIMULATION_H
#define SIMULATION_H

#include <stdlib.h>
#include "parking.h"
#include "stats.h"
#include "queue.h"

/* SIMULATION OPERATIONS HEADER FILE
   This module includes all the structs and functions that are needed to actually run the simulation step by 
   step. It includes the Config struct, which saves the parameters of the simulation (the number of spaces in 
   the garage the longest time a car can park, the length of the simulation, the probability of a new car being 
   generated, and a random seed) as integers. 
   Because the Config struct is passed to a UI function to have the parameters set after being initialised, 
   its memory is dynamically allocated on the heap. Therefore Config structs are created with the new_config() 
   function and their memory freed with the free_config() function.
   The Config parameters are used by the run_timestep() function which executes the actual simulation steps:
    - Updating the Parkhaus via update_parkhaus() in Parkhaus.h
    - Emptying the queue as much as possible
    - Randomly seeing if a car should be added and then sorting it into the Parkhaus or Queue
    - Writing the statistics for the timestep
   The module also includes two static functions in its source file(car_gen_bool() and input_new_car()) that 
   run_timestep() outsources some functionalities to. 

*/

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
* @return the created Config struct (NULL if error)
*/
Config new_config();

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
/*This function serves as a unified interface for other operations to the main function, and
primarily calls other functions from this and other modules. This reduces the number of function
calls in main and increases modularity*/

#endif
