#include "../include/simulation.h"
#include "../include/ui.h"

int main(){
/*
//////SETUP//////
Open new text file
OUTPUT welcome message (ui_get_welcome())
Config pointer <- new_config()
Get Simulation parameters (ui_get_params)
Write header in text file (ui_write_head)
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
Close text file 
Delete Config stuct (free_config)
Delete Stats struct (stats_delete)
Clear Queue (clear_queue)
Close Parkhaus (close_parkhaus)
return 0


*/
}