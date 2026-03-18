/** ### HEADER FILE FOR UI FUNCTIONALITY ###
 * - all function names begin with ui
 * - ui_get functions ask the user for input
 * - ui_print functions print on the console
 * - ui_write functions write into a txt file
 * 
 * This header file contains functions serving two main purposes:
 * 
 * 1. Make it easier to communicate with the user by calling the dedicated ui functions:
 * There is a function ´ui_get_params´ to get all the simulation parameters in the beginning,
 * and a function ´ui_print_stats´ to print out all the statistics on the console each timestep.
 * 
 * 2. Automatically write a text file (including two header lines and values for each timestep):
 * There is a function ´ui_write_head´ to write the header lines of the text file,
 * so it can be easily used as an excel table later (each column is already labeled).
 * The fuction ´ui_write_stats´ writes the stats into the text file for each timestep.
 * 
 * This way, we ensure the simulation logic is independent from all the ui actions.
 * If we later want to change how the data looks on the screen or how the file is saved, 
 * we only need to change the code in the UI files, and the simulation logic should stay the same.
 */

#ifndef UI_H
#define UI_H

#include <stdio.h>
#include <limits.h>
#include "simulation.h"

// number of lines in the beginning of the txt file that do not contain data
#define TXT_FILE_HEADER_LINES 2
// maximal input value for some simualtion parameters, limits the user from creating too large simulations
#define MAX_USER_INPUT 9999
// minimal input for some simualtion parameters, values smaller than 1 don't make sense
#define MIN_USER_INPUT 1

/**
 * @brief Print welcome message to user in the beginning.
 *
 * To be called in main.c
 */
void ui_print_welcome(void);

/**
 * @brief Asks the user to input the 5 simulations parameters
 *
 * Using the ui_get_int function
 * and saves them to the struct Simulation.
 * To be called before starting the simulation!
 * 
 * @param[out] p_config reference to struct Config
 * @return 0 for success, -1 for error
 */
int ui_get_params(Config *p_config);

/**
 * @brief Write first two lines of text file
 *
 * For the beginning of the simulation, print into txt file:
 * - first line stating all simulation parameters
 * - second line stating all the stats seperated by commas
 * 
 * @note File has to be opened already, close the file if the function returns -1
 * 
 * @param[in] p_config reference to struct Config
 * @param[out] fp reference to the txt file
 * @return 0 for success, -1 for error, 1 for file error
 */
int ui_write_head(const Config *p_config, FILE *fp);

/**
 * @brief Write statistics from struct Stats into a txt file.
 *
 * To be called each cycle.
 * The statistic values are seperated by commas.
 * 
 * @note File has to be opened already, close the file if the function returns -1
 *
 * @param[in] p_stats reference to struct Stats
 * @param[out] fp reference to the txt file
 * @return 0 for success, -1 for error, 1 for file error
 */
int ui_write_stats(const Stats *p_stats, FILE *fp);

/**
 * @brief Print out all the stats to console.
 *
 * To be called each cycle.
 * For the percentage
 *
 * @param[in] p_stats reference to struct Stats
 * @return statsus code: 0 for success, -1 for error
 */
int ui_print_stats(const Stats *p_stats);

/**
 * @brief Calculate averages and maximums from the log file and print them on the console
 *
 * To be called after successful simulation
 *
 * @note File has to be opened already in reading mode, close the file if the function returns -1
 * @warning This function does not close the file
 * 
 * @param[in] fp reference to the txt file
 * @param[in] p_config reference to the Config struct
 * @return 0 for success, -1 for error
 */
int ui_process_final_stats(FILE *fp, const Config *p_config);

#endif