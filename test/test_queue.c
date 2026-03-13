#include <stdio.h>
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

    return 0;

}

void test_enqueue(){
    Queue q;
    queue_init(&q);

    Car *p_car = init_car(1, 1, 5);
    
    //test that p_car was enqueued into the empty queue
    assert(enqueue(&q, p_car) == 0);
    //test that the enqueued car is now the header
    assert(q.p_head == p_car);

    Car *p_second_car = init_car(2, 2, 8);
    
    //test that a second car could be enqueued
    assert(enqueue(&q, p_second_car) == 0);
    //test that the first car is still at front
    assert(q.p_head == p_car);
    //test that the second car is now at the tail
    assert(q.p_tail == p_second_car);
    //test that count has been upped to 2 (2 cars in queue!)
    assert(q.count == 2);

    free(p_car);
    free(p_second_car);

    return 0;
}


int main(){

}