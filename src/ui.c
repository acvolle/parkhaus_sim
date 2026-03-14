/**
 * THIS FILE INCLUDES THE LOGIC FOR ALL UI FUNCTIONS
 *
 * This file includes two static help functions ´ui_print_border´ and ´ui_get_int´
 * as well as the functions from ui.h that are called by the ´main.c´.
 */

#include <stdio.h>
#include "../include/ui.h"
#include "../include/simulation.h"

// number of lines in the beginning of the txt file that do not contain data
#define TXT_FILE_HEADER_LINES 2
// maximal input value for some simualtion parameters, limits the user from creating too large simulations
static int MAX_INPUT = 9999;
// minimal input for some simualtion parameters, values smaller than 1 don't make sense
static int MIN_INPUT = 1;

/**
 * @brief Print a visual border to separate elements on console.
 *
 * Something like ´---------------------------´
 */
static void ui_print_border(void)
/*  PSEUDOCODE
OUTPUT visual border
*/
{
    printf("-----------------------------------------------\n");
}

void ui_print_welcome(void)
/*  PSEUDOCODE
OUTPUT welcome message
*/
{
    printf("Welcome to the Parkhaus P4 Rauenegg simultion tool!\n");
    ui_print_border();
    printf("- You will be asked to input simulation parameters\n");
    printf("- The simulation will run, and statistics for each timeste pwill be printed\n");
    printf("- Final statistics will be printed at the end\n");
    printf("- The simulation will end and all stats will be readable in a stats.txt file\n");
    ui_print_border();
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
    IF min <= value <= max AND input is an ´int´ THEN
        return value
    ELSE
        OUTPUT error message
    END IF
END WHILE
*/
{
    int value;
    char input[100];
    char *end_of_value = input;
    while (1)
    {
        printf("%s", prompt);
        if (fgets(input, sizeof input, stdin) == NULL)
        {
            clearerr(stdin);
            printf("Error reading input: Try again!\n");
            continue;
        }

        long input_val = strtol(input, end_of_value, 10);

        if (end_of_value == input || (*end_of_value != '\n'))
        {
            printf("Not an integer! Try again!\n");
            continue;
        }

        if (input_val < INT_MIN || input_val > INT_MAX)
        {
            printf("Value out of range for integer. Try again.\n");
            continue;
        }

        value = (int)input_val;
        if (value < min || (value > max))
        {
            printf("Not in bounds! Enter a value between %d and %d!\n", min, max);
            continue;
        }

        return value;
    }
}

int ui_get_params(Config *p_config)
/* PSEUDOCODE
IF p_config = NULL THEN
    OUTPUT error message
    return -1
END IF
p_config->num_spaces           <- ui_get_int("Enter number of spaces: ",                                   1, 9999)
p_config->max_parking_time     <- ui_get_int("Enter max. parking duration in timesteps: ",                 1, 9999)
p_config->simulation_duration  <- ui_get_int("Enter how many timesteps you want to simulate: ",            1, 9999)
p_config->gen_probability      <- ui_get_int("Enter probability for new cars to arrive per timestep (%): ",1, 100)
p_config->random_seed          <- ui_get_int("Enter your seed (random number): ",                          0, 32767)
return 0
*/
{
    if (p_config == NULL)
    {
        printf("ui_get_pasams: null pointer");
        return -1;
    }

    p_config->num_spaces = ui_get_int("Enter number of spaces: ", MIN_INPUT, MAX_INPUT);
    p_config->max_parking_time = ui_get_int("Enter max. parking duration in timesteps: ", MIN_PARKING_DURATION, MAX_INPUT);
    p_config->simulation_duration = ui_get_int("Enter how many timesteps should be simulated: ", MIN_INPUT, MAX_INPUT);
    p_config->gen_probability = ui_get_int("Enter probability for new cars to arrive per timestep (%%): ", MIN_INPUT, 100);
    p_config->random_seed = ui_get_int("Enter your seed (random number): ", 0, 32767);

    return 0;
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
    if (p_config == NULL || (fp == NULL))
    {
        printf("ui_write_head: null pointer\n");
        return -1;
    }

    if (fprintf(fp, "Number of spaces: %d, Max. parking time: %d, Duration: %d, Gen. probability: %d, Seed: %d\n",
                p_config->num_spaces,
                p_config->max_parking_time,
                p_config->simulation_duration,
                p_config->gen_probability,
                p_config->random_seed) < 0)
    {
        printf("ui_write_head: failed to write in file\n");

        return 1;
    }
    if (fprintf(fp, "Timestamp,Occupancy rate,Cars waiting,Max wait time,Avg wait time,Stress score\n") < 0)
    {
        printf("ui_write_head: failed to write in file\n");

        return 1;
    }

    return 0;
}

int ui_write_stats(const Stats *p_stats, FILE *fp)
/* PSEUDOCODE
IF p_stats = NULL OR fp = NULL THEN
    OUTPUT error message
    return -1
END IF
with fprintf(), write the current timestep and the 5 stats into txt file, seperated by commas, new line
return 0
*/
{
    if (p_stats == NULL || (fp == NULL))
    {
        printf("ui_write_stats: null pointer\n");
        return -1;
    }

    if (fprintf(fp, "%d,%.2f,%d,%d,%.2f,%.2f\n",
                current_timestep,
                p_stats->occupancy_rate,
                p_stats->cars_waiting,
                p_stats->first_car_wait_time,
                p_stats->avg_wait_time,
                p_stats->stress_score) < 0)
    {
        printf("ui_write_stats: failed to write in file\n");
        return 1;
    }

    return 0;
}

int ui_print_stats(const Stats *p_stats)
/* PSEUDOCODE
IF p_stats = NULL THEN
    OUTPUT error message
    return -1
END IF
OUTPUT current_timestep                 // global variable
OUTPUT p_stats->occupancy_rate
OUTPUT p_stats->cars_waiting
OUTPUT p_stats->first_car_wait_time
OUTPUT p_stats->avg_wait_time
OUTPUT p_stats->stress_score            // new line
return 0

*/
{
    if (p_stats == NULL)
    {
        printf("ui_print_stats: null pointer\n");
        return -1;
    }

    printf("Timestep: %04d | ", current_timestep);
    printf("Occ. Rate (%%): %05.2f | ", p_stats->occupancy_rate);
    printf("Cars waiting: %04d | ", p_stats->cars_waiting);
    printf("Max. wait time: %04d | ", p_stats->first_car_wait_time);
    printf("Avg. wait time: %05.2f | ", p_stats->avg_wait_time);
    printf("Score: %05.2f\n", p_stats->stress_score);

    return 0;
}

int ui_process_final_stats(FILE *fp)
{
    if (fp == NULL)
    {
        return -1;
    }

    // buffer for characters per line
    char buffer[256];

    // variables to be added up for each line
    float sum_occ = 0.0f;
    float sum_wait = 0.0f;
    float sum_stress = 0.0f;
    // variables for temporary data extraction
    int timestamp = 0;
    int waiting = 0;
    float occ = 0;
    float avg_wait = 0;
    float stress = 0;
    float max_wait_f = 0;
    int max_wait = 0;

    // Skip the header of txt file
    for (int i = 0; i < TXT_FILE_HEADER_LINES; i++)
    {
        if (fgets(buffer, sizeof(buffer), fp) == NULL)
        {
            // file is shorter than TXT_FILE_HEADER_LINES
            fclose(fp);
            return -1;
        }
    }

    // Read data from every line
    while (fgets(buffer, sizeof(buffer), fp))
    {
        // extract data
        if (sscanf(buffer, "%d, %f, %d, %d, %f, %f",
                   &timestamp, &occ, &waiting, &max_wait, &avg_wait, &stress) == 6)
        {
            sum_occ += occ;
            sum_wait += (float)max_wait;
            sum_stress += stress;
        }
    }

    // no data was logged
    if (timestamp == 0)
    {
        return -1;
    }

    // calculate averages to be printed
    ui_print_final_stats(
        sum_occ / (float)timestamp,
        sum_wait / (float)timestamp,
        sum_stress / (float)timestamp
    );

    return 0;
}

/**
 * @brief Print out all the final stats to console.
 *
 * To be called by the ui_process_final_stats
 *
 * @param[in] avg_occupancy
 * @param[in] avg_waiting_duration
 * @param[in] avg_waiting_count
 */
static void ui_print_final_stats(float avg_occupancy, float avg_waiting_duration, float avg_stress_score)
{
    ui_print_border();
    printf("End of P4 Rauenegg simulation\n\n");
    printf("Overall statistics:\n");
    printf("Average occupancy rate:     %.2f %%\n", avg_occupancy);
    printf("Average wait time in Queue: %.2f timesteps\n", avg_waiting_duration);
    printf("Average stress score:       %.2f out of 100\n", avg_stress_score);
    ui_print_border();
    printf("(c) Rolls-Royce Power Solutions\n");
}