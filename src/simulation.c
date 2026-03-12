#include "../include/simulation.h"

// FOR DOCUMENTATION OF NON-STATIC FUNCTIONS, SEE SIMULATION.H

int current_timestep;

//Initializes a new Config struct
Config *new_config()
/*
    Config pointer <- allocate memory for Config struct
    IF config pointer == NULL THEN
        return NULL
    END IF
    Config pointer->num_spaces <- 0
    Config pointer->max_parking_time <- 0
    Config pointer->simulation_duration <- 0
    Config pointer->gen_probability <- 0
    Config pointer->random_seed <- 0
    return Config pointer

*/
{
    Config *p_config = malloc(sizeof(Config));
    if(p_config == NULL)
    {
        return NULL;
    }
    p_config->num_spaces = 0;
    p_config->max_parking_time = 0;
    p_config->simulation_duration = 0;
    p_config->gen_probability = 0;
    p_config->random_seed = 0;

    return p_config;
}

int free_config(Config *p_config)
/*
    IF p_config != NULL THEN
        free memory at p_config location
        return 0
    END IF
    return -1
*/
{
    if(p_config == NULL)
    {
        return -1;
    }
    free(p_config);
}


int run_timestep(Parkhaus *p_parkhaus, Queue *p_queue, Config *p_config, Stats *p_stats)
/*
    IF p_parkhaus != NULL && (p_queue != NULL) && (p_config != NULL) && (p_stats != NULL) THEN
        update_parkhaus(p_parkhaus)
        new Car pointer <- NULL
        WHILE (!parkhaus_is_full(p_parkhaus) && (!queue_is_empty(p_queue))) DO
             Car pointer <- deqeue(p_queue)
             park_car(p_parkhaus, Car pointer, current_timestep)
        END WHILE
        queue_increase_wait_time(p_queue)
        IF car_gen_bool(p_config->gen_probability) == 1 DO
            IF input_new_car (Error) DO
                OUTPUT error message
                return 1
            END IF
        IF stats_clear(p_stats) THEN
            OUTPUT error message
            return 4
        END IF
        IF stats_occupancy_rate(p_parkhaus->occupied_spaces, p_parkhaus->size, p_stats) THEN
            OUTPUT error message
            return 4
        END IF
        IF stats_queue_stats(p_queue, p_stats) THEN
             return 4
        END IF
        IF stats_stress_score(p_stats) THEN
            OUTPUT error message
            return 4
        END IF
    ELSE 
        return -1
    END IF
*/
{
    if(p_parkhaus == NULL || p_queue != NULL || p_config != NULL || p_stats == NULL)
    {
        return -1;
    }
    // remove cars with 0 remaining parking duration
    if(update_parkhaus(p_parkhaus))
    {
        return 2;
    }

    Car* p_temp_car = NULL;

    // put cars from queue into free spaces
    while (!parkhaus_is_full(p_parkhaus) && !queue_is_empty(p_queue))
    {
        if(dequeue(p_queue, p_temp_car))
        {
            return 3;
        }
        if(park_car(p_parkhaus, p_temp_car, current_timestep))
        {
            return 2;
        }
    }
    // update the waiting time of all cars in the queue
    if(queue_increase_wait_time(p_queue))
    {
        return 3;
    }

    // new car should be generated
    if(car_gen_bool(p_config->gen_probability) == 1)
    {
        if(input_new_car(p_parkhaus, p_queue, p_config))
        {
            return 1;
        }
    }

    // +++ STATISTICS +++
    if(stats_clear(p_stats))
    {
        return 4;
    }

    if(stats_occupancy_rate(p_parkhaus->occupied_spaces, p_parkhaus->size, p_stats))
    {
        return 4;
    }

    if(stats_queue_stats(p_queue, p_stats))
    {
        return 4;
    }

    if(stats_stress_score(p_stats))
    {
        return 4;
    }

    return 0;
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
    value <- (random number % 100) +1 //to allow probability of 100 
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
* If parking fails, the `Car` (pointer) is enqueued into the provided `Queue`.
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
/*
    IF p_parkhaus != NULL && (p_queue != NULL) && (p_config != NULL) THEN
        Car pointer <- init_car(current_timestep, current_timestep, gen_park_duration)
        IF(park_car(p_parkhaus, p_car, current_timestep)) == 1 THEN
            enqueue(p_queue, Car pointer)
        END IF
        return 0
    ELSE
        return -1
    END IF
*/
}

/**
 * @brief Randomly generates the duration a Car will spend in the Parkhaus
 * 
 * Generates the park_span time of a Car struct using rand() and the max_parking_time
 * of the Config struct.
 * The returned timespan is be at least one (no 0 timestep parking) and at most the 
 * max_parking_time.
 * 
 * @note The `srand()` function must be called in `main()` before using this function.
 * 
 * @param[in] max_time Maximum number of timesteps a Car may spend in the struct
 * @return integer value of the park_span number of timesteps
 */
static int gen_park_duration(int max_time){
/*
    Generate random number
    parking time <- (random number % max_time)+1 //values between 1 and 100

    return parking time
*/
}
/*Note: it is unnecessary to check for e.g. negative numbers etc. as ui_get_params 
already has safeguards to ensure that the simulation cannot be started with erroneous
parameters*/

