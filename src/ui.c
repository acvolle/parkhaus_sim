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
// No pseudocode needed
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
WHILE true DO
    OUTPUT propmt
    INPUT value
    IF min <= value <= max THEN
        return value
    ELSE
        OUTPUT error message
    END IF
END WHILE
*/
{

}

int ui_get_params(Config *p_config)
/* PSEUDOCODE
IF p_config = NULL THEN
    OUTPUT error message
    return -1
END IF
config.num_spaces           <- ui_get_int("Enter number of spaces: ",                                   1, 9999)
config.max_parking_time     <- ui_get_int("Enter max. parking duration in timesteps: ",                 1, 9999)
config.simulation_duration  <- ui_get_int("Enter how many timesteps you want to simulate: ",            1, 9999)
config.gen_probability      <- ui_get_int("Enter probability for new cars to arrive per timestep (%): ",1, 100)
config.random_seed          <- ui_get_int("Enter your seed (random number): ",                          0, 32767)
return 0
*/
{

}

int ui_write_head(const Config *p_config, const char *stats_names, FILE *fp)
/* PSEUDOCODE
// file should be opened in main.c and passed
IF p_config = NULL OR fp = NULL THEN
    OUTPUT error message
    return -1
END IF
fputs("all config parameters", fp)  //new line
fputs(stats_names, fp)              //new line
return 0
*/
{

}


int ui_write_stats(const Stats *p_stats, FILE *fp)
/* PSEUDOCODE
IF p_stats = NULL OR fp = NULL THEN
    OUTPUT error message
    return -1
END IF
write the 5 stats into txt file with fputs, seperated by commas, new line
return 0
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