#ifndef CAR_H
#define CAR_H

/**## HEADER FILE FOR CARS 
 * - all functions include the word car
 * - defines struct car for use
 * - init_car creates a car based on the parameters from the Simulation
 * - remove_car deletes car after parking span ends
 */


 /**
  * @brief Struct represents Cars that enter the garage
  * 
  * This struct represents the cars that park in the garage with
  * their given ID, time of arrival, and the span of their stay
  * created dynanically as once the car exits it has no further
  * need to exist
  */
typedef struct Car 
{
    int id_number;
    int arrival_time;
    int park_span;
    int used_span;
} Car;
/**
 * @brief Functions that creates car
 * 
 * based on the the parameters of the simulation
 * a car is created, utilizing the time of arrival as
 * both the ID and point of reference for time
 * 
 */

 
Car init_car(int max_duration, int current_time);

/**
 * @brief deletes a struct of the type car
 * 
 * removes the dynamically created car as it no longer serves
 * any porpuse after it exits the garage (Parkhaus)
 * expect return 0 when succesful, return -1 when functions has faile
 */

int remove_car(Car *pCardelete );



#endif