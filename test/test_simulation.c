#include "../include/simulation.h"
#include <assert.h>

void test_new_config(){
    Config *p_config = new_config();
    
    //test that new_config returned a valid pointer
    assert(p_config != NULL);

    if(p_config == NULL){
        return;
    }
    
    //test if all elements were zero-initialized
    assert(p_config->gen_probability == 0);
    assert(p_config->max_parking_time == 0);
    assert(p_config->num_spaces == 0);
    assert(p_config->random_seed == 0);
    assert(p_config->simulation_duration == 0);
    
}

void test_free_config(){

}

void test_run_timestep(){

}


int main(){

}