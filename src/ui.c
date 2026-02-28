/**
 * THIS FILE INCLUDES THE LOGIC FOR ALL UI FUNCTIONS
 */

#include <stdio.h>
#include "ui.h"
#include "simulation.h"

/**
 * @brief Print a visual border to separate elements on console.
 *
 * Something like ---------------------------
 */
static void ui_print_border(void)
{

}


void ui_print_welcome(void)
{

}

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
static int ui_get_int(const char *prompt, int min, int max)
/* PSEUDOCODE

*/
{

}

int ui_get_params(Config *p_config)
/* PSEUDOCODE

*/
{

}

int ui_write_head(const Config *p_config, const char *stats_names, FILE *fp)
/* PSEUDOCODE

*/
{

}


int ui_write_stats(const Stats *p_stats, FILE *fp)
/* PSEUDOCODE

*/
{

}


void ui_print_stats(const Stats *p_stats)
/* PSEUDOCODE

*/
{

}


void ui_print_final_stats(int avg_parking_duration, int avg_waiting_duration, int avg_stress_score)
/* PSEUDOCODE

*/
{

}