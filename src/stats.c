/**
 * THIS FILE INCLUDES THE LOGIC FOR ALL STATS FUNCTIONS
 * 
 * These functions should be called by simulation.c as well as main.c
 */

#include "stats.h"
#include <stdio.h>
#include <stdlib.h>

#define RATIO_QUEUE_TO_SPACES 0.15
#define MAX_WAIT_TIME 15

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
    if(p_stats == NULL || p_queue == NULL)
    {
        return -1;
    }

    p_stats->cars_waiting = p_queue->count;

    if(p_queue->count == 0)
    {
        p_stats->first_car_wait_time = 0;
        p_stats->avg_wait_time = 0;
        return 0;
    }

    p_stats->first_car_wait_time = p_queue->p_head->p_car->time_in_queue;

    float total_wait = 0;
    Node *p_temp_node = p_queue->p_head;

    // iterate through the queue and sum up all the car's waiting times
    while (p_temp_node != NULL)
    {
        total_wait += p_temp_node->p_car->time_in_queue;
        p_temp_node = p_temp_node->p_next;
    }

    // calculate average
    p_stats->avg_wait_time = total_wait / p_queue->count;

    return 0;
}


int stats_stress_score(Stats *p_stats, int spaces_count)
/*  STRESS SCORE EXPLANATION:
This score is a value between 0 and 100, representing how critical
the situation at the parking garage is at the moment.

Half the points can be achieved by the current occupancy without any cars queuing up.
To ensure that low occupancy has less of an impact and to specifically overweight the last 20%, 
these 50 points are calculated proportionally to the square
of the occupancy rate.

The other half of the points can only be collected at 100% occupancy
and consists of two components:

1. The ratio of waiting cars to 15% of the number of parking spaces (defined under “RATIO_QUEUE_TO_SPACES”)
Example: In a parking garage with 100 spaces, 15 waiting cars would correspond to the full 25 points.

2. The ratio of the average waiting time in the queue to the time defined under “MAX_WAIT_TIME” (15 time steps).
Example: An average waiting time of 6 Minutes would correspond to 10 points.

Note: These partial scores are capped at 25, although they can reach higher values mathematically.
Example: When the average waiting time is 21 time steps, the partial time score is maxed out at 25.
(Although the mathematical score would be 35)

In summary, the stress score consists of:
- 50 points for occupancy
- 25 points for queue
- 25 points for waiting time
This allows the user to assess the current parking situation at a glance.

    PSEUDOCODE
IF p_stats = NULL OR parkhaus_size THEN 
    return -1
END IF

p_stats->calculated score
IF p_stats->stress_score > 100.0 THEN 
   p_stats->stress_score <- 100.0
END IF

return 0
*/
{
    if(p_stats == NULL || spaces_count <= 0)
    {
        return -1;
    }
    // Calculate the max. 50 points for occupancy
    float occ_ratio = p_stats->occupancy_rate / 100.0;
    float occ_part = 50.0 * occ_ratio * occ_ratio;

    // Calculate the max. 25 points for queue
    float queue_part = 25.0 * (float)p_stats->cars_waiting / (spaces_count * RATIO_QUEUE_TO_SPACES);
    if (queue_part > 25.0) 
    {
        queue_part = 25.0;
    }
    
    // Calculate the max. 25 points for waiting time
    float time_part = 25.0 * (p_stats->avg_wait_time / MAX_WAIT_TIME);
    if(time_part > 25.0)
    {
        time_part = 25.0;
    }

    // Calculate sum of partial scores
    p_stats->stress_score = occ_part + queue_part + time_part;

    // Limit score at 100
    if(p_stats->stress_score > 100.0)
    {
        p_stats->stress_score = 100.0;
    }
    return 0;
}