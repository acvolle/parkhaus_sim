#include <assert.h>
#include "../include/stats.h"

void test_stats_create(void)
{
    Stats *p_stats = stats_create();

    // Test if the struct Stats is allocated successfully
    assert(p_stats != NULL);
    // Test if all the variables of the struct were zero-initialized
    assert(p_stats->avg_wait_time == 0);
    assert(p_stats->cars_waiting == 0);
    assert(p_stats->first_car_wait_time == 0);
    assert(p_stats->occupancy_rate == 0);
    assert(p_stats->stress_score == 0);

    free(p_stats);
}

void test_clear_stats(void)
{
    Stats *p_stats = stats_create();

    assert(p_stats != NULL);

    // Test NULL pointer handling
    assert(stats_clear(NULL) == -1);

    p_stats->avg_wait_time = 3.6;
    p_stats->cars_waiting = 69;
    p_stats->first_car_wait_time = 187;
    p_stats->occupancy_rate = 4.44;
    p_stats->stress_score = 55.3;

    assert(stats_clear(p_stats) == 0);
    // Test if all the values were set to zero
    assert(p_stats->avg_wait_time == 0);
    assert(p_stats->cars_waiting == 0);
    assert(p_stats->first_car_wait_time == 0);
    assert(p_stats->occupancy_rate == 0);
    assert(p_stats->stress_score == 0);

    free(p_stats);
}

void test_stats_delete(void)
{
    Stats *p_stats = stats_create();

    assert(p_stats != NULL);

    // Test return values
    assert(stats_delete(p_stats) == 0);

    p_stats = NULL;
    assert(stats_delete(p_stats) == -1);
}