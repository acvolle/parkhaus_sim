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




int main(){

}