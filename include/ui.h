#ifndef UI_H
#define UI_H

#include <stdio.h>
#include "simulation.h"

/** ### HEADER FILE FOR UI FUNCTIONALITY ###
 * - all function names begin with ui
 * - ui_get functions ask the user for input
 * - ui_print functions print on the console
 * - ui_write functions write into a txt file
 * 
 * This header file contains functions serving two main purposes
 */

/**
 * @brief Print a visual border to separate elements on console.
 *
 */
void ui_print_border(void);

/**
 * @brief Print welcome message to user in the beginning.
 *
 */
void ui_print_welcome(void);

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
int ui_write_start_log(const Config *p_config, const char *stats_names, FILE *fp);

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
 * To be called each cycle.
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
 * @brief Asks the user to input the 5 simulations parameters
 *
 * Using the ui_get_int function
 * and saves them to the struct Simulation
 * To be called before starting the simulation!
 * 
 * @param[out] p_config reference to struct Config
 * @return 0 for success, -1 for error
 */
int ui_get_params(Config *p_config);

#endif