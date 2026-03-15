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
#include "../include/queue.h"

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
    if (p_queue == NULL)
    {
        printf("queue_init: null pointer");
        return -1;
    }

    p_queue->p_head = NULL;
    p_queue->p_tail = NULL;
    p_queue->count = 0;

    return 0;
}

int queue_is_empty(const Queue *p_queue)
/* PSEUDOCODE
IF p_queue = NULL THEN
    return 0
ELSE IF p_queue->count = 0 THEN
    return 1
ELSE
    return 0
END IF
*/
{
    if (p_queue == NULL)
    {
        printf("queue_is_empty: null pointer\n");
        return 0;
    }
    else if (p_queue->count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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
    if (p_queue == NULL || (p_car == NULL))
    {
        printf("enqueue: null pointer");
        return -1;
    }

    Node *p_new_node = malloc(sizeof *p_new_node);
    if (p_new_node == NULL)
    {
        printf("enqueue: memory allocation error");
        return -1;
    }

    p_new_node->p_car = p_car;
    p_new_node->p_next = NULL;

    if (queue_is_empty(p_queue))
    {
        p_queue->p_head = p_new_node;
    }
    else
    {
        p_queue->p_tail->p_next = p_new_node;
    }

    p_queue->p_tail = p_new_node;
    p_queue->count++;
    return 0;
}

int dequeue(Queue *p_queue, Car **pp_dequeued_car)
/* PSEUDOCODE
IF p_queue = NULL OR p_dequeued_car = NULL THEN
    return -1
ELSE IF queue_is_empty THEN
    return 1
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
    if (p_queue == NULL || (pp_dequeued_car == NULL))
    {
        printf("dequeue: null pointer");
        return -1;
    }
    if (queue_is_empty(p_queue))
    {
        return 1;
    }

    if (p_queue->p_head->p_car == NULL)
    {
        printf("dequeue: incomplete node");
        return -1;
    }
    *pp_dequeued_car = p_queue->p_head->p_car;
    Node *p_temp = p_queue->p_head;

    p_queue->p_head = p_queue->p_head->p_next;

    if (p_queue->p_head == NULL)
    {
        p_queue->p_tail = NULL;
    }
    free(p_temp);
    p_queue->count--;

    if (p_queue->count < 0)
    {
        printf("dequeue: arithmetic error");
        return -1;
    }

    return 0;
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
    if (p_queue == NULL)
    {
        printf("queue_increase_wait_time: null pointer");
        return -1;
    }

    Node *p_temp = p_queue->p_head;

    while (p_temp != NULL)
    {
        if (p_temp->p_car != NULL)
        {
            p_temp->p_car->time_in_queue++;
        }
        p_temp = p_temp->p_next;
    }

    return 0;
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
    if (p_queue == NULL)
    {
        printf("queue_clear: null pointer");
        return -1;
    }
    int status_code = 0;

    Car *p_temp = NULL;
    while (status_code == 0)
    {
        status_code = dequeue(p_queue, &p_temp);
        if (status_code == -1)
        {
            printf("queue_clear: dequeue error");
            return -1;
        }
        delete_car(p_temp);
        p_temp = NULL;
    }
    queue_init(p_queue); //resets all queue values
    return 0;
}
// function changed to reduce redundancy by calling dequeue