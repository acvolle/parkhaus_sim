#include <stdio.h>
#include <assert.h>
#include "../include/queue.h"



void test_init_queue(){
    Queue q;

    
    //test if queue_init was called without error
    assert(queue_init(&q) == 0);
    // test if the head pointer was set to NULL
    assert(q.p_head == NULL);
    //test if the tail pointer was set to NULL
    assert(q.p_tail == NULL);
    //test if the queue elements count was set to 0
    assert(q.count == 0);

}

void test_enqueue(){
    Queue q;
    queue_init(&q);

    Car *p_car = init_car(1, 1, 5);
    
    //test that p_car was enqueued into the empty queue
    assert(enqueue(&q, p_car) == 0);
    //test that the enqueued car is now the header
    assert(q.p_head->p_car == p_car);

    Car *p_second_car = init_car(2, 2, 8);
    
    //test that a second car could be enqueued
    assert(enqueue(&q, p_second_car) == 0);
    //test that the first car is still at front
    assert(q.p_head->p_car == p_car);
    //test that the second car is now at the tail
    assert(q.p_tail->p_car == p_second_car);
    //test that count has been upped to 2 (2 cars in queue!)
    assert(q.count == 2);

    free(p_car);
    free(p_second_car);

}

void test_dequeue(){
    Queue q;
    queue_init(&q);
    Car *p_car = init_car(1, 1, 5);

    enqueue(&q, p_car);

    Car *p_dequeued_car = NULL;
    //test if dequeue works
    assert(dequeue(&q, &p_dequeued_car) == 0);
    //test if the dequeued pointer is the same as what was enqueued
    assert(p_dequeued_car == p_car);
    p_dequeued_car = NULL;
    //test if dequeue works when the queue is empty
    assert(dequeue(&q, &p_dequeued_car) == 1);
    //test that dequeue on an empty queue doesn't change the Car pointer
    assert(p_dequeued_car == NULL);

    free(p_car);

}

void test_queue_is_empty(){
    Queue q;
    queue_init(&q);
    Car *p_car = init_car(1, 1, 5);
    Car *p_dequeued_car = NULL;
    
    //test that a newly initialized queue is seen as empty
    assert(queue_is_empty(&q) == 1);

    enqueue(&q, p_car);
    //test that is_empty return 0 when something has been enqueued
    assert(queue_is_empty(&q) == 0);

    dequeue(&q, &p_dequeued_car);
    //test that is empty return 1 again when the car has been dequeued
    assert(queue_is_empty(&q) == 1);

    free(p_car);

}

void test_queue_clear(){
    Queue q;
    queue_init(&q);
    Car *p_car = init_car(1, 1, 5);
    Car *p_second_car = init_car(2, 2, 10);

    enqueue(&q, p_car);
    enqueue(&q, p_second_car);
    
    queue_clear(&q);
    
    //checks that all cars have been removed
    assert(q.count == 0);
    //checks that the head is set to NULL (all nodes removed)
    assert(q.p_head == NULL);
    //checks that tail has also been set to NULL (all nodes removed)
    assert(q.p_tail == NULL);
    
    //cars have been freed by queue_clear
    p_car = NULL;
    p_second_car = NULL;

}

void test_queue_increase_wait_time(){
    Queue q;
    queue_init(&q);
    Car *p_car = init_car(1, 1, 5);
    Car *p_second_car = init_car(2, 2, 10);

    enqueue(&q, p_car);
    enqueue(&q, p_second_car);

    //tests that the car's time in queue has been set to 0
    assert(p_car->time_in_queue == 0);
    //tests that the car's time in queue has been set to 0
    assert(p_second_car->time_in_queue == 0);

    queue_increase_wait_time(&q);
    //tests that the car's time in queue has been incremented
    assert(p_car->time_in_queue == 1);
    //tests that the car's time in queue has been incremented
    assert(p_second_car->time_in_queue == 1);

    queue_clear(&q);

}

int main(){
    
    /*TESTS EACH FUNCTION IN THE QUEUE MODULE WITH AT LEAST TWO ASSERTS
    Each unit test only calls the tested function and other functions that have been 
    tested previously */
    test_init_queue();
    test_enqueue();
    test_dequeue();
    test_queue_is_empty();
    test_queue_clear();
    test_queue_increase_wait_time();

}