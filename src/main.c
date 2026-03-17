#include "../include/simulation.h"
#include "../include/ui.h"


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
        printf("Error: Could not create txt file!\n");
        return 1;
    }

    ui_print_welcome();

    // Create simulation config
    Config *p_config = new_config();
    if (p_config == NULL)
    {
        printf("Error: Config creation failed!\n");
        fclose(fp_log);
        return 1;
    }

    // Parameters -> Config
    if (ui_get_params(p_config) == -1)
    {
        printf("Error: Parameter input failed!\n");
        free_config(p_config);
        fclose(fp_log);
        return 1;
    }

    // Write log file header
    if (ui_write_head(p_config, fp_log) == -1)
    {
        printf("Error: Writing into log file failed!\n");
        free_config(p_config);
        fclose(fp_log);
        return 1;
    }

    // Initialize stats struct
    Stats *p_stats = stats_create();
    if (p_stats == NULL)
    {
        printf("Error: Stats structure creation failed!\n");
        free_config(p_config);
        fclose(fp_log);
        return 1;
    }

    // Initialize queue
    Queue q;
    queue_init(&q);

    // Initialize Parkhaus
    Parkhaus *p_rauenegg = init_parkhaus(p_config->num_spaces);
    if (p_rauenegg == NULL)
    {
        printf("Error: Parkhaus creation failed!\n");
        free_config(p_config);
        stats_delete(p_stats);
        fclose(fp_log);
        return 1;
    }

    // Set seet for rand() function
    srand((unsigned int)p_config->random_seed);

    ////// LOOP //////

    printf("\nNow simulating %d timesteps...\n\n", p_config->simulation_duration);

    // Run loop for the amount of times input by the user
    for (int i = 0; i < p_config->simulation_duration; i++)
    {

        // Status code for execution of run_timestep function
        int run_timestep_status_code = run_timestep(p_rauenegg, &q, p_config, p_stats);
        switch (run_timestep_status_code)
        {
        case 0:
            break;
        case 1:
            printf("Error at run_timestep: A simulation function failed at timestep %d!\n", current_timestep);
            break;
        case 2:
            printf("Error at run_timestep: A parkhaus function failed at timestep %d!\n", current_timestep);
            break;
        case 3:
            printf("Error at run_timestep: A queue function failed at timestep %d!\n", current_timestep);
            break;
        case 4:
            printf("Error at run_timestep: A stats function failed at timestep %d!\n", current_timestep);
            break;
        case -1:
            printf("\nError: running timestep no. %d failed!\n", current_timestep);
            break;
        default:
            printf("\nError: running timestep no. %d failed!\n", current_timestep);
            break;
        }

        // Break the for loop if any error occured at running timestep
        if (run_timestep_status_code)
        {
            break;
        }

        // Stats -> console
        if (ui_print_stats(p_stats) == -1)
        {
            printf("\nError: Printing stats failed at timestep %d!\n", current_timestep);
            break;
        }

        // Stats -> log file
        if (ui_write_stats(p_stats, fp_log) == -1)
        {
            printf("\nError: Writing into log file failed at timestep %d!\n", current_timestep);
            break;
        }
        // increase timestep count
        current_timestep++;
    }

    ////// SHUTDOWN //////

    // close log file (writing mode)
    fclose(fp_log);
    printf("Done simulating %d timesteps\n", current_timestep);

    // open log file (reading mode)
    FILE *fp_results = fopen("parkhaus_sim_log.txt", "r");
    if (fp_results == NULL)
    {
        printf("Error: Could not read results from log file!\n");
    }
    else // file was opened in reading mode
    {
        if (ui_process_final_stats(fp_results, p_config) == -1)
        {
            printf("Error: Could not process results from log file!\n");
        }
        fclose(fp_results);
    }

    // Delete config struct
    if (free_config(p_config))
    {
        printf("Error: free_config failed!\n");
    }
    p_config = NULL;

    // Delete stats struct
    if (stats_delete(p_stats))
    {
        printf("Error: stats_delete failed!\n");
    }
    p_stats = NULL;

    // Delete parkhaus struct
    if (close_parkhaus(p_rauenegg))
    {
        printf("Error: close_parkhaus failed!\n");
    }
    p_rauenegg = NULL;

    queue_clear(&q);

    return 0;
}