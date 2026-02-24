#ifndef UI_H
#define UI_H

#include <stdio.h>
#include "simulation.h"

/** ### HEADER FILE FOR UI FUNCTIONALITY ###
* - all function names begin with ui
* - ui_get functions ask the user for input
* - ui_print functions print on the console
* - ui_write functions write into a txt file
*/

/**
* @brief Print a visual border to separate elements on console.
*
*/
void ui_print_border();

/**
* @brief Print welcome message to user in the beginning.
*
*/
void ui_print_welcome();

/**
* @brief Write first two lines of text file 
*
* For the beginning of the simulation, print into txt file:
* - first line stating all simulation parameters
* - second line stating all the stats seperated by commas
* @param[in] ptr_sim reference to struct Simulation
* @param[out] fp reference to the txt file
* @return 0 for sucess, -1 for error
*/
int ui_write_start_log(const Simulation *ptr_sim, FILE* fp);

/**
 * @brief Get an integer value from user input.
 * 
 * Asks the user to input an integer,
 * then checks if input is valid and integer is between min and max value.
 * If not, ask the user again and specify the min and max values.
 *
 * @param[in] prompt Message shown to user
 * @param[in] min Minimum defined value
 * @param[in] max Maximum defined value
 * @return validated input
 */
int ui_get_int(const char *prompt, int min, int max);

/**
* @brief Print out all the stats to console.
*
* @param[in] ptr_sim reference to struct Simulation
*/
void ui_print_stats(const Simulation *ptr_sim);

/**
* @brief Write statistics from struct Stats into a txt file.
*
* @param[in] ptr_sim reference to struct Simulation
* @param[out] fp reference to the txt file
* @return 0 for sucess, -1 for error
*/
int ui_write_stats(const Simulation *ptr_sim, FILE* fp);

/**
 * @brief Asks the user to input the 5 simulations parameters
 *
 * Using the ui_get_int function
 * and saves them to the struct Simulation
 * To be called before starting the simulation!
 * 
 * @param[out] ptr_sim reference to struct Simulation
 * @return 0 for sucess, -1 for error
 */
int ui_get_params(Simulation *ptr_sim);

#endif