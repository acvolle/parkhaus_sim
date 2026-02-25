#ifndef CAR_H
#define CAR_H
#include "../include/simulation.h"

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
} Car;
/**
 * @brief Functions that creates car
 * 
 * based on the the parameters of the simulation
 * a car is created, utilizing the time of arrival as
 * both the ID and point of reference for time
 * 
 */

 
Car* init_car(int *pSimulation, int *pTime);

/**
 * @brief deletes a struct of the type car
 * 
 * removes the dynamically created car as it no longer serves
 * any porpuse after it exits the garage (Parkhaus)
 */

Car* remove_car(Car *pCardelete );



#endif