#ifndef STATS_H
#define STATS_H

#include <stdio.h>

/** ### HEADER FILE FOR CALCULATING STATS ###
 * 
 */

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
 * @brief Write the current occupancy rate into a struct Stats
 *
 * @param[in] car_count number of occupied spaces
 * @param[in] spaces_count total number of parking spaces
 * @param[out] p_stats reference to struct Stats
 * @return 0 for sucess, -1 for error
 */
int stats_occupancy_rate(int car_count, int spaces_count, Stats *p_stats);

/**
 * @brief Write the current number of waiting cars into a struct Stats
 *
 * @param[in] queued_cars number of waiting cars
 * @param[out] p_stats reference to struct Stats
 * @return 0 for sucess, -1 for error
 */
int stats_cars_waiting(int queued_cars, Stats *p_stats);

/**
 * @brief Write the current waiting time of the first car into a struct Stats
 *
 * @param[in] waiting_time waiting time of the next car to leave the queue
 * @param[out] p_stats reference to struct Stats
 * @return 0 for sucess, -1 for error
 */
int stats_first_car_waiting_time(int waiting_time, Stats *p_stats);

/**
 * @brief Write the current number of waiting cars into a struct Stats
 *
 * @param[in] 
 * @param[out] p_stats reference to struct Stats
 * @return 0 for sucess, -1 for error
 */
int stats_avg_wait_time(int , Stats *p_stats);


#endif