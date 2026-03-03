#include "../include/car.h"

// intiate new car
Car* init_car(int  id_number, int current_time, int max_duration)
{
    /**
     * Car Pointer <- allocate memory the size of car struct
     * IF car pointer == NULL 
     *  print "ERRROR, memory allocation for car has failed"
     *  return NULL
     * ELSE car id_number = id_number
     *      car arrival_time = current_time
     *      car park_span = max duration
     *      car time_in_queue = 0
     * ENDIF
     *  return car pointer
     * 
     */
}
int delete_car(Car *p_Cardelete )
{
/**
 * IF p_Cardelete pointer != NULL
 *  free(p_Cardelete)
 *  return 0 in case of success
 * ENDIF
 * return -1 in case of failure
 */
};