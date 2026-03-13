#include <assert.h>
#include "../include/stats.h"

void test_stats_create(void)
{
    Stats *p_s = stats_create();

    // Test if the struct Stats is allocated successfully
    assert(p_s != NULL);
    // Test if all the variables of the struct were zero-initialized
    assert(p_s->avg_wait_time == 0);
    assert(p_s->cars_waiting == 0);
    assert(p_s->first_car_wait_time == 0);
    assert(p_s->occupancy_rate == 0);
    assert(p_s->stress_score == 0);

    free(p_s);
}

void test_stats_clear(void)
{
    Stats *p_s = stats_create();

    assert(p_s != NULL);

    // Test NULL pointer handling
    assert(stats_clear(NULL) == -1);

    p_s->avg_wait_time = 3.6;
    p_s->cars_waiting = 69;
    p_s->first_car_wait_time = 187;
    p_s->occupancy_rate = 4.44;
    p_s->stress_score = 55.3;

    assert(stats_clear(p_s) == 0);
    // Test if all the values were set to zero
    assert(p_s->avg_wait_time == 0);
    assert(p_s->cars_waiting == 0);
    assert(p_s->first_car_wait_time == 0);
    assert(p_s->occupancy_rate == 0);
    assert(p_s->stress_score == 0);

    free(p_s);
}

void test_stats_delete(void)
{
    Stats *p_s = stats_create();

    assert(p_s != NULL);

    // Test return values
    assert(stats_delete(p_s) == 0);

    p_s = NULL;
    assert(stats_delete(p_s) == -1);
}

void test_stats_occupancy_rate(void)
{
    Stats* p_s = stats_create();
    
    // Test inputs that lead to error
    assert(stats_occupancy_rate(5, 0, p_s) == -1);
    assert(stats_occupancy_rate(5, -10, p_s) == -1);
    assert(stats_occupancy_rate(3, 4, NULL) == -1);

    // Test 25% occupied parkhaus
    assert(stats_occupancy_rate(50, 200, p_s) == 0);
    assert(p_s->occupancy_rate == 25.0);

    // Test full parkhaus
    stats_occupancy_rate(40, 40, p_s);
    assert(p_s->occupancy_rate == 100.0);

    stats_delete(p_s);
}

void test_stats_queue_stats(void)
{
    Stats* p_s = stats_create();
    Queue q;
    queue_init(&q);

    // Test empty queue
    assert(stats_queue_stats(&q, p_s) == 0);
    assert(p_s->cars_waiting == 0);
    assert(p_s->avg_wait_time == 0.0);

    // Enqueue two cars
    Car *c1 = init_car(1, 0, 10);
    c1->time_in_queue = 20;
    Car *c2 = init_car(2, 0, 10);
    c2->time_in_queue = 10;

    enqueue(&q, c1);
    enqueue(&q, c2);

    // Test for correct stats 
    assert(stats_queue_stats(&q, p_s) == 0);
    assert(p_s->cars_waiting == 2);
    assert(p_s->first_car_wait_time == c1->time_in_queue); 
    assert(p_s->avg_wait_time == 15.0);    // (10+20)/2

    queue_clear(&q);
    stats_delete(p_s);
}

void test_stats_stress_score(void)
{
    Stats* p_s = stats_create();
    int size = 100;

    // Test null pointer handling
    assert(stats_stress_score(NULL, 0) == -1);

    // Test score for 50% occupancy
    p_s->occupancy_rate = 50.0;
    stats_stress_score(p_s, size);
    assert(p_s->stress_score == 12.5); // 50 * (0.5 * 0.5) = 12.5

    // Test max queue score
    p_s->occupancy_rate = 0.0;
    p_s->cars_waiting = 20; 
    stats_stress_score(p_s, size);

    // 20 cars in queue (over 15% of total available spaces) 
    // should lead to the maximum score of 25 for queue
    assert(p_s->stress_score == 25.0);

    // Test queue score
    p_s->occupancy_rate = 100.0;
    p_s->cars_waiting = 9; 
    stats_stress_score(p_s, size);

    // 9 cars in queue (equal to 3/5 of the max queue length of 15 cars) 
    // should lead to the score of 25 * (3/5) = 15 for queue
    // and thus to a total score of 50 + 15 = 65
    assert(p_s->stress_score == 65.0); 

    // Test max wait time score
    p_s->occupancy_rate = 0; 
    p_s->cars_waiting = 0;
    p_s->avg_wait_time = 17.0;

    // a waiting time >= 15 should lead to the max score of 25
    stats_stress_score(p_s, size);
    assert(p_s->stress_score == 25.0);

    // Test total score
    p_s->occupancy_rate = 100.0; 
    p_s->cars_waiting = 12;
    p_s->avg_wait_time = 6;

    // total score should be 50 (occupancy) + 20 (queue) + 10 (time) = 80 (total)
    stats_stress_score(p_s, size);
    assert(p_s->stress_score == 80.0);

    // Test max total score
    p_s->occupancy_rate = 100.0; 
    p_s->cars_waiting = 80;
    p_s->avg_wait_time = 90;

    // total score should be capped at 100
    stats_stress_score(p_s, size);
    assert(p_s->stress_score == 100.0);

    stats_delete(p_s);
}

int main()
{
    test_stats_create();
    test_stats_clear();
    test_stats_delete();
    test_stats_occupancy_rate();
    test_stats_queue_stats();
    test_stats_stress_score();

    return 0;
}