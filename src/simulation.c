#include "../include/simulation.h"

// FOR DOCUMENTATION OF NON-STATIC FUNCTIONS, SEE SIMULATION.H

//Initializes a new Config struct
Config *new_config(){

}


// Frees the memory allocated to the config struct
int free_config(Config *p_config){

}


// Runs a single timestep of the simulation
int run_timestep(Parkhaus *p_parkhaus, Queue *p_queue, Config *p_config, Stats *p_stats){

}


/**
 * @brief Randomly determines if a new car should be generated.
 *
 * Uses `rand()` to generate a random number between 1 and 100.
 * Returns `1` if a car should be generated (random number <= probability),
 * otherwise returns `0`.
 * Called by run_timestep()
 *
 * @note The `srand()` function must be called in `main()` before using this function.
 *
 * @param[in] probability The probability (0-100) of generating a new car.
 * @return int `1` if a car should be generated, `0` otherwise.
 */
static int car_gen_bool(const int probability){
/*
    Generate random number
    value <- random number % 100
    IF value <= probability THEN
        return 1
    ELSE
        return 0
    ENDIF
*/
}


/**
* @brief Initializes new Car struct and either parks or enqueues it
*
* Creates a new `Car` struct, then attempts to park it using `park_car()` (see `parking.h`).
* If parking fails, the `Car` is enqueued into the provided `Queue`.
* Called by run_timestep()
*
* @param[out] p_parkhaus Pointer to Parkhaus in which the Car structshould be parked
* @param[out] p_queue Pointer to the Queue in which the Car struct can be enqueued
* @param[in] p_config Pointer to the Config file, from which information is read
* @return int Status code:
*            - `0` if the operation succeeded.
*            - `-1` if an error occurred (e.g., pointer is `NULL`).
*/
static int input_new_car(Parkhaus *p_parkhaus, Queue *p_queue, Config *p_config){
    
}
