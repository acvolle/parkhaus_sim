#include "../include/simulation.h"
#include "../include/ui.h"

// initialize global variable
int current_timestep = 0;

int main()
/* PSEUDOCODE
//////SETUP//////
Open new text file
OUTPUT welcome message (ui_get_welcome())
Config pointer <- new_config()
IF Get Simulation parameters (ui_get_params) == -1 THEN
    free_config(Config pointer)
    close text file
    return 1
END IF
IF Write header in text file (ui_write_head) == -1 THEN
    free_config(Config pointer)
    close text file
    return 1
END IF
Stats pointer <- stats_create()
New Queue
queue_init(pointer to Queue)
Parkhaus pointer <- init_parkhaus(Config pointer->num_spaces)
srand(p_config->random_seed)


//////LOOP//////
FOR i <- 0 TO Config pointer->simulation_duration-1 DO
    IF run_timestep(Parkhaus pointer, Queue pointer, Config pointer, Stats pointer) == -1 THEN  //function from simulation.c that runs all operational steps
        OUTPUT error message
        break for loop //shuts down the simulation, doesn't return as allocated memory must still be freed
    END IF
    IF ui_print_stats(Stats pointer)) == -1 THEN
        OUTPUT error message
        break for loop //shuts down the simulation, doesn't return as allocated memory must still be freed
    END IF
    IF ui_write_stats(Stats pointer, text file) == -1 THEN
        OUTPUT error message
        break for loop //shuts down the simulation, doesn't return as allocated memory must still be freed
    END IF

    current_timestep++
END FOR


//////SHUTDOWN//////
ui_print_final_stats()
IF Close text file == -1 THEN
    return 1
END IF
IF Delete Config stuct (free_config) == -1 THEN
    return 1
END IF
Config pointer <- NULL
IF Delete Stats struct (stats_delete) == -1 THEN
    return 1
END IF
Stats pointer <- NULL
Clear Queue (clear_queue)
IF Close Parkhaus (close_parkhaus) == -1 THEN
    return 1
END IF
Parkhaus pointer <- NULL


return 0


*/
{
    ////// SETUP //////

    // Open new text file
    FILE *fp_log = fopen("parkhaus_sim_log.txt", "w");
    if (fp_log == NULL)
    {
        printf("Error: Could not create txt file\n");
        return 1;
    }

    ui_print_welcome();

    // Create simulation config
    Config *p_config = new_config();
    if(p_config == NULL)
    {
        printf("Error: Config creation failed.\n");
        fclose(fp_log);
        return 1;
    }

    // Parameters -> Config
    if (ui_get_params(p_config) == -1)
    {
        printf("Error: Parameter input failed.\n");
        free_config(p_config);
        fclose(fp_log);
        return 1;
    }

    // Write log file header
    if (ui_write_head(p_config, fp_log) == -1)
    {
        free_config(p_config);
        fclose(fp_log);
        return 1;
    }

    // Initialize stats struct
    Stats *p_stats = stats_create();
    if(p_stats == NULL)
    {
        printf("Error: Stats structure creation failed.\n");
        free_config(p_config);
        fclose(fp_log);
        return 1;
    } 
    


    return 0;
}