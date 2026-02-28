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
#include "simulation.h"

/**
 * @brief Print a visual border to separate elements on console.
 *
 * Should be changed to static and moved to ui.c
 */
void ui_print_border(void);

/**
 * @brief Print welcome message to user in the beginning.
 *
 * To be called in main.c
 */
void ui_print_welcome(void);

/**
 * @brief Get an integer value from user input.
 *
 * Should be changed to static and moved to ui.c
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
 * @param[in] p_config reference to struct Config
 * @param[in] stats_names string containing all the stats names seperated by commas
 * @param[out] fp reference to the txt file
 * @return 0 for success, -1 for error
 */
int ui_write_head(const Config *p_config, const char *stats_names, FILE *fp);

/**
 * @brief Write statistics from struct Stats into a txt file.
 *
 * To be called each cycle.
 * The statistic values are seperated by commas.
 *
 * @param[in] p_stats reference to struct Stats
 * @param[out] fp reference to the txt file
 * @return 0 for success, -1 for error
 */
int ui_write_stats(const Stats *p_stats, FILE *fp);

/**
 * @brief Print out all the stats to console.
 *
 * To be called each cycle.
 * For the percentage
 *
 * @param[in] p_stats reference to struct Stats
 */
void ui_print_stats(const Config *p_config);

/**
 * @brief Print out all the final stats to console.
 *
 * To be called after sucessful simulation.
 * The integers should be calculated by functions in the stats.h
 * and then passed to the ui.
 * This function is optional and not necessary to complete the simulation.
 *
 * @param[in] avg_parking_duration Message shown to user
 * @param[in] avg_waiting_duration Minimum defined value
 * @param[in] avg_waiting_count Maximum defined value
 */
void ui_print_final_stats(int avg_parking_duration, int avg_waiting_duration, int avg_stress_score);



#endif