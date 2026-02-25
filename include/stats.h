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
    float occupancy;
    int cars_waiting;
    int first_car_wait_time;
    float avg_wait_time;
    float stress_score;
} Stats;

/**
 * @brief Write first two lines of text file
 *
 * @param[in] car_count number of occupied spaces
 * @param[in] spaces_count total number of parking spaces
 * @return occupancy rate percentage
 */
float get_occupancy_rate(int car_count, int spaces_count);

#endif