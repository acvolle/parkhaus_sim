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

    free(p_config);

}

void test_free_config(){
    Config *p_config = new_config();

    if(p_config == NULL){
        printf("test_free_config: null pointer");
        return;
    }
    //tests that freeing a real Config pointer works
    assert(free_config(p_config) == 0);

    p_config = NULL;
    //tests that freeing a null pointer returns a legitimate error message
    assert(free_config(p_config) == -1);
    
}


void test_car_gen_bool(){

    for(int i = 0; i < 100; i++){
        //tests that over 100 attempts a zero probability means car_gen_bool always returns 0
        assert(tw_car_gen_bool(0) == 0);
        //tests that over 100 attempts a 100% probability means car_gen_bool always return 1
        assert(tw_car_gen_bool(100) == 1);
        //tests that over 100 attempts car_gen_bool doesn't return anything except 1 or 0
        assert(tw_car_gen_bool(50) == (0 || 1));
        
    }
    
}

void test_gen_park_duration(){

}

void test_input_new_car(){

}


void test_run_timestep(){

}


int main(){

    srand(5);

}