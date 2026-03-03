/**
 * THIS FILE INCLUDES THE LOGIC FOR ALL CAR FUNCTIONS
 * 
 * To initiate a new car (when a new car arrives), use ´init_car´, which allocates 
 * memory and initializes the integers stored in the structure.
 * To delete a car (when a car's parking time is over), use ´delete_car´,
 * which frees the memory previously allocated to the car.
 */

#include "../include/car.h"

Car* init_car(int  id_number, int current_time, int max_duration)
{
    /** PSEUDOCODE
     * Car Pointer <- allocate memory the size of car struct
     * IF car pointer == NULL 
     *  print "ERRROR, memory allocation for car has failed"
     *  return NULL
     * ELSE car id_number <- id_number
     *      car arrival_time <- current_time
     *      car park_span <- max_duration
     *      car time_in_queue <- 0
     * ENDIF
     *  return car pointer
     * 
     */
}

int delete_car(Car *p_Cardelete )
{
/** PSEUDOCODE
 * IF p_Cardelete pointer != NULL
 *  free(p_Cardelete)
 *  return 0 in case of success
 * ENDIF
 * return -1 in case of failure
 */
}