/**
 * THIS FILE INCLUDES THE LOGIC FOR ALL QUEUE FUNCTIONS
 * 
 * This file includes two static help functions ´ui_print_border´ and ´ui_get_int´
 * as well as the functions from ui.h that are called by the ´main.c´.
 */

#include <stdio.h>
#include <stdbool.h>
#include "../include/queue.h"
#include "../include/car.h"

void queue_init(Queue *p_queue)
/* PSEUDOCODE
IF p_queue != NULL THEN
    p_queue <- allocate memory the size of a struct Queue
ELSE
    OUTPUT error message
END IF
*/
{

}

bool queue_is_empty(const Queue *p_queue)
/* PSEUDOCODE
IF p_queue->count = 0 THEN
    return true
ELSE
    return false
END IF
*/
{

}

int enqueue(Queue *p_queue, Car *p_car)
/* PSEUDOCODE
IF p_queue = NULL OR p_car = NULL THEN
    return -1
END IF

new_node <- allocate memory the size of a Node
IF new_node = NULL THEN 
    return -1 (Memory Error)
END IF

new_node->car <- *p_car
new_node->p_next <- NULL

IF queue_is_empty THEN
    p_queue->p_head <- new_node
ELSE
    p_queue->p_tail->p_next <- new_node
END IF

p_queue->p_tail <- new_node                 // new_node is now the tail of the queue
p_queue->count <- p_queue->count + 1        // count up
return 0
*/
{

}

int dequeue(Queue *p_queue, Car *p_dequeued_car)
/* PSEUDOCODE
IF p_queue = NULL OR p_car = NULL THEN
    return -1
END IF
*/
{

}

int queue_increase_wait_time(Queue *p_queue)
/* PSEUDOCODE
IF p_queue is NULL THEN
    return -1
END IF
Node* current <- p_queue->p_head
WHILE current != NULL DO
    current->car.time_in_queue++
    current <- current->p_next
END WHILE
return 0
*/
{

}

void queue_clear(Queue *p_queue)
/* PSEUDOCODE
*/
{

}