#include "../include/simulation.h"
#include "../include/ui.h"

int main(){
/*
//////SETUP//////
Open new text file
OUTPUT welcome message (ui_get_welcome())
Config pointer <- new_config()
IF Get Simulation parameters (ui_get_params) == -1 THEN
    return 1
END IF
IF Write header in text file (ui_write_head) == -1 THEN
    return 1
END IF
Stats pointer <- stats_create()
Queue pointer <- queue_init()
Parkhaus pointer <- init_parkhaus(Config pointer->num_spaces)


//////LOOP//////
FOR i <- 0 TO Config pointer->simulation_duration-1 DO
    IF run_timestep == -1 THEN  //function from simulation.c that runs all operational steps
        OUTPUT error message
        return 1
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
IF Delete Stats struct (stats_delete) == -1 THEN
    return 1
END IF
Clear Queue (clear_queue)
IF Close Parkhaus (close_parkhaus) == -1 THEN
    return 1
END IF


return 0


*/
}