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

}