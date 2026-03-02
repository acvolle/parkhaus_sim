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
IF p_queue != NULL
    p_queue <- allocate memory the size of a struct Queue
ELSE
    OUTPUT error message
END IF
*/
{

}

bool queue_is_empty(const Queue *p_queue)
/* PSEUDOCODE
*/
{

}

int enqueue(Queue *p_queue, Car *p_car)
/* PSEUDOCODE
IF queue_is_sm
*/
{

}

int dequeue(Queue *p_queue, Car *p_dequeued_car)
/* PSEUDOCODE
*/
{

}

int queue_increase_wait_time(Queue *p_queue)
/* PSEUDOCODE
*/
{

}

void queue_clear(Queue *p_queue)
/* PSEUDOCODE
*/
{

}