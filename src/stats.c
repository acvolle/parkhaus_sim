/**
 * THIS FILE INCLUDES THE LOGIC FOR ALL STATS FUNCTIONS
 * 
 * These functions should be called by simulation.c as well as main.c
 */

#include "stats.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUESIZE_RATIO
#define MAX_WAITING_DURATION

Stats* stats_create(void)
/* PSEUDOCODE
p_stats <- allocate memory the size of a Stats struct
IF p_stats != NULL THEN
    stats_clear(p_stats)
END IF
return p_stats      // might be NULL if allocation fails
*/
{
    Stats* p_stats = malloc(sizeof(Stats));
    if(p_stats != NULL)
    {
        stats_clear(p_stats);
    }
    return p_stats;
}

int stats_clear(Stats *p_stats)
/* PSEUDOCODE
IF p_stats = NULL THEN
    return -1
END IF
p_stats->occupancy_rate <- 0
p_stats->cars_waiting <- 0
p_stats->first_car_wait_time <- 0
p_stats->avg_wait_time <- 0
p_stats->stress_score <- 0
return 0
*/
{
    if(p_stats == NULL)
    {
        return -1;
    }
    p_stats->occupancy_rate = 0;
    p_stats->cars_waiting = 0;
    p_stats->first_car_wait_time = 0;
    p_stats->avg_wait_time = 0;
    p_stats->stress_score = 0;
    return 0;
}

int stats_delete(Stats *p_stats)
/* PSEUDOCODE
IF p_stats = NULL THEN
    return -1
END IF
stats_clear(p_stats)
free memory allocated to p_stats
return 0
*/
{
    if(p_stats == NULL)
    {
        return -1;
    }
    stats_clear(p_stats);
    free(p_stats);
    return 0;
}

int stats_occupancy_rate(int car_count, int spaces_count, Stats *p_stats)
/* PSEUDOCODE
IF p_stats = NULL OR spaces_count <= 0 THEN 
    return -1
END IF
// don't forget casting so output of division is a float !!
p_stats->occupancy_rate <- (car_count / spaces_count) * 100
return 0
*/
{
    if(p_stats == NULL || spaces_count <= 0)
    {
        return -1;
    }
    p_stats->occupancy_rate = ( (float)car_count / (float)spaces_count ) * 100;
    return 0;
}

int stats_queue_stats(const Queue *p_queue, Stats *p_stats)
/* PSEUDOCODE
IF p_stats == NULL OR p_queue == NULL THEN 
    return -1
END IF

p_stats->cars_waiting <- p_queue->count

// no cars queueing up
IF p_queue->count = 0 THEN
    p_stats->first_car_wait_time <- 0
    p_stats->avg_wait_time <- 0
    return 0
END IF

p_stats->first_car_wait_time <- p_queue->p_head->car.time_in_queue

total_wait <- 0
temp_node <- p_queue->p_head
WHILE temp_node != NULL DO
    total_wait <- total_wait + temp_node->car.time_in_queue     // sum up all the cars' waiting times
    temp_node <- temp_node->p_next
END WHILE

// don't forget casting so output of division is a float !!
p_stats->avg_wait_time <- total_wait / p_queue->count

return 0
*/
{
    
}

int stats_stress_score(Stats *p_stats)
/* PSEUDOCODE
IF p_stats = NULL OR parkhaus_size THEN 
    return -1
END IF

p_stats->calculated score
IF p_stats->stress_score > 100.0 THEN 
   p_stats->stress_score <- 100.0
END IF

return 0
*/

/*
// First 50 points depending on occupancy rate

float occupancy_part <- 50 * (p_stats->occupancy_rate / 100.0) * (p_stats->occupancy_rate / 100.0)

// Another 50 points depending on a queue
   
   // A: Anzahl-Stress (max 25 Pkt)
   // 20% der Größe gilt als "voll"
   float count_ratio <- (float)p_stats->cars_waiting / (parkhaus_size * 0.2)
   float count_part <- count_ratio * 25.0
   IF count_part > 25.0 THEN count_part <- 25.0

   // B: Zeit-Stress (max 25 Pkt)
   // Wir definieren 20 Zeitschritte als "maximalen Zeitstress"
   float time_ratio <- p_stats->avg_wait_time / 20.0
   float time_part <- time_ratio * 25.0
   IF time_part > 25.0 THEN time_part <- 25.0

p_stats->stress_score <- occupancy_part + count_part + time_part

// Limit score at 100.0
IF p_stats->stress_score > 100.0 THEN 
   p_stats->stress_score <- 100.0
END IF
*/
{
    
}