/**
 * THIS FILE INCLUDES THE LOGIC FOR ALL QUEUE FUNCTIONS
 * 
 * This file includes the basic function for a FIFO queue logic
 * - queue_init
 * - enqueue
 * - dequeue
 * - queue_clear
 * as well as additional functions to simplify code
 * - queue_is_empty
 * - queue_increase_wait_time
 */

#include <stdio.h>
#include <stdbool.h>
#include "../include/queue.h"
#include "../include/car.h"

int queue_init(Queue *p_queue)
/* PSEUDOCODE
IF p_queue = NULL THEN
    return -1
END IF
p_queue->p_head = NULL
p_queue->p_tail = NULL
p_queue->count = 0
return 0
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

IF queue_is_empty(p_queue) THEN
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
IF p_queue = NULL OR p_dequeued_car = NULL OR queue_is_empty THEN
    return -1
END IF

p_dequeued_car <- p_queue->p_head->car
Node *p_temp <- p_queue->p_head             // store pointer before deleting

p_queue->p_head <- p_queue->p_head->p_next  // former second node is now the head of the queue

IF p_head = NULL THEN                       // dequeued the last element, queue is now empty
    p_tail <- NULL
END IF

free memory allocated to p_temp
p_queue->count <- p_queue->count - 1        // count down
return 0
*/
{

}

int queue_increase_wait_time(Queue *p_queue)
/* PSEUDOCODE
IF p_queue = NULL THEN
    return -1
END IF
Node *p_temp <- p_queue->p_head
WHILE p_temp != NULL DO
    p_temp->car.time_in_queue++         // "car.h" needs to be included
    p_temp <- p_temp->p_next            // go to next element
END WHILE
return 0
*/
{

}

int queue_clear(Queue *p_queue)
/* PSEUDOCODE
IF p_queue = NULL THEN
    return -1
END IF
IF p_queue->p_head != NULL
    Node *p_temp <- p_queue->p_head
    Node *p_next_temp
    WHILE p_temp != NULL DO
        p_next_temp <- p_temp->next
        free memory allocated to p_temp         // also deletes stored Car struct
        p_temp <- p_next_temp                   // go to next element
    END WHILE
END IF

// queue now contains zero nodes
queue_init(p_queue)                             // sets pointers to NULL and count to 0
return 0
*/
{

}