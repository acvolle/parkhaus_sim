/** ### HEADER FILE FOR CALCULATING STATS ###
 * This header file defines a structure "Stats"
 * which stores the int/float statistics
 * that are updated everey timestep.
 * The memory for this struct is allocated dynamically,
 * therefore the functions ´stats_create´ and ´stats_delete´ are needed.
 * Additionally, stats_clear can be used to set all the stored stats 0.
 * The "stress score" is a score 0-100, which represents the overall
 * stress of the current parking situation.
 * To update the statistics for each timestep correctly,
 * the functions ´stats_occupancy_rate´ and ´stats_queue_stats´ have to
 * be called first before ´stats_stress_score´, so that the stress score
 * is calculated with the updated latest values.
 */
#ifndef STATS_H
#define STATS_H

#include <stdio.h>
#include "queue.h"

/**
 * @brief Stores the stats that are logged every timestep
 *
 */
typedef struct {
    float occupancy_rate;
    int cars_waiting;
    int first_car_wait_time;
    float avg_wait_time;
    float stress_score;
} Stats;

/**
 * @brief Allocate and initialize a new struct Stats
 * 
 * @warning return might be NULL if allocation fails, has to be checked!
 * @return Pointer to struct or NULL
 */
Stats* stats_create(void);

/**
 * @brief Sets all values inside a struct Stats to 0
 * 
 * @param[in] p_stats reference to struct Stats
 * @return 0 for success, -1 for error
 */
int stats_clear(Stats *p_stats);

/**
 * @brief Frees memory from a struct Stats
 * 
 * @param[in] p_stats reference to struct Stats
 * @return 0 for success, -1 for error
 */
int stats_delete(Stats *p_stats);

/**
 * @brief Write the current occupancy rate into a struct Stats
 *
 * The function calculates the ratio of parked cars / available spaces
 * and stores it into stats.
 * 
 * @param[in] car_count number of occupied spaces
 * @param[in] spaces_count total number of parking spaces
 * @param[out] p_stats reference to struct Stats
 * @return 0 for success, -1 for error
 */
int stats_occupancy_rate(int car_count, int spaces_count, Stats *p_stats);

/**
 * @brief Write the current queue-based stats into struct Stats
 *
 * This function reads from the queue and calculates
 * - waiting time of the next car to leave the queue 
 * - number of cars waiting
 * - average waiting time of all cars in the queue
 * and writes the values into the struct Stats
 * @param[in] p_queue reference to struct Queue
 * @param[out] p_stats reference to struct Stats
 * @return 0 for success, -1 for error
 */
int stats_queue_stats(const Queue *p_queue, Stats *p_stats);

/**
 * @brief Update the stress score
 *
 * This function reads the gathered stats,
 * calculates the stress score
 * (exact formula tbd!!!!!!!!!!)
 * and writes the new score into the struct Stats
 * 
 * @param[in,out] p_stats reference to struct Stats
 * @return 0 for success, -1 for error
 */
int stats_stress_score(Stats *p_stats, int spaces_count);

#endif