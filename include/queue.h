/**
 *  ### HEADER FILE FOR QUEUE FUNCTIONALITY ###
 * This header file includes the logic for a linked list (FIFO-logic)
 * which stores Car structs representing the Cars queueing up in front of 
 * the parking lot entrance.
 * Therefore two structures are defined:
 * 1. Node, which stores thea pointer to the car and a pointer to the next node
 * 2. Queue, which consists of pointers to the first and last element 
 *    as well as the count of cars currently queueing up.
 * To ensure the queue is seen as empty in the beginning of the simulation, 
 * the queue has to be initialized with the ´queue_init´ function.
 * ´enqueue´ is used to add a new car to the end of the queue
 * and ´dequeue´ removes the first car of the queue.
 * Because the struct Queue includes pointers to the first AND last element
 * these functions can be executed in the time O(1).
 * To free the allocated memory after the simulation, ´queue_clear´ is used
 * We also added dedicated functions
 * - ´queue_is_empty´ to check if there are cars queueing up.
 * - ´queue_increase_wait_time´ to be called every timestep
 *    to increase the stored waiting time of all the cars queueing up.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "car.h"
#include <stdio.h>

/**
 * @brief Node for the linked list
 */
typedef struct Node {
    Car *p_car;
    struct Node* p_next;
} Node;

/**
 * @brief Struct for the linked list
 */
typedef struct {
    Node* p_head; // first element
    Node* p_tail; // last element
    unsigned int count; // waiting car count (for statistics)
} Queue;

/**
 * @brief Initializes a new queue
 * 
 * The queue should be declared in main.c and then
 * passed to this function to work properly.
 * Sets head and tail pointers to NULL and count to 0
 * 
 * @param[in,out] p_queue queue to initialize
 * @return 0 for success, -1 for error
 */
int queue_init(Queue *p_queue);

/**
 * @brief Checks if queue is empty
 * 
 * @return 1 for empty queue, 0 for queue containing elements or error
 */
int queue_is_empty(const Queue *p_queue);

/**
 * @brief Adds a car to queue
 * 
 * @note Dont forget to count up
 * @param[in, out] p_queue queue to use
 * @param[in] p_car car to add
 * @return 0 for sucess, -1 for failed allocation
 */
int enqueue(Queue *p_queue, Car *p_car);

/**
 * @brief removes the oldest car from queue (FIFO)
 * 
 * This function recieves a pointer to a Car pointer as an input. This
 * allows the ar pointer to be set to the address of the dequeued Car in the
 * function.
 * 
 * @note Dont forget to count down
 * @param[in, out] p_queue queue to use 
 * @param[out] pp_dequeued_car pointer to a pointer to the dequeued car
 * @return 0 for sucess, 1 for empty queue, -1 for error
 */
int dequeue(Queue *p_queue, Car **pp_dequeued_car);

/**
 * @brief Increases the wait time of every car in the queue by 1
 * 
 * p_car->time_in_queue is increased by 1
 * 
 * @return 0 for success, -1 for error
 */
int queue_increase_wait_time(Queue *p_queue);

/**
 * @brief Deletes every item from queue
 * 
 * To be used after the simulation to free memory
 * 
 * @return 0 for success, -1 for error
 */
int queue_clear(Queue *p_queue);

#endif