#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "car.h"

/**
 * @brief Node for the linked list
 */
typedef struct Node {
    Car car;
    struct Node* next;
} Node;

/**
 * @brief Struct for the linked list
 */
typedef struct {
    Node* head; // first element
    Node* tail; // last element
    unsigned int count; // waiting car count (for statistics)
} Queue;

/**
 * @brief Initializes a new queue
 * @param[out] p_queue queue to initialize
 */
void queue_init(Queue *p_queue);

/**
 * @brief Adds a car to queue
 * 
 * @param[in, out] p_queue queue to use
 * @param[in] p_car car to add
 * @return 0 for sucess, -1 for failed allocation
 */
int enqueue(Queue *p_queue, Car *p_car);

/**
 * @brief removes the oldest car from queue (FIFO)
 * 
 * @param[in, out] p_queue queue to use 
 * @param[out] p_dequeued_car pointer to dequeued car
 * @return 0 for sucess, -1 for empty queue
 */
int dequeue(Queue *q, Car *p_dequeued_car);

/**
 * @brief Checks if queue is empty
 * 
 * @return true for empty queue, else false
 */
bool queue_is_empty(const Queue *q);

/**
 * @brief Deletes every item from queue
 * 
 * To be used after the simulation to free memory
 */
void queue_clear(Queue *q);

#endif