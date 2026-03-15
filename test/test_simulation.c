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
    
    for(int i = 0; i < 100; i++){
        //tests that over 100 attempts gen_park_duration never returns anything higher than the input maximum
        assert(tw_gen_park_duration(30) <= 31);
        //tests that over 100 attempts gen_park_duration never returns anything lower than the predefined min of 5
        assert(tw_gen_park_duration(30) >= 5);
    }

}

void test_input_new_car(){
    //SETUP
    Parkhaus *p_parkhaus = init_parkhaus(1);
    if(p_parkhaus == NULL){
        printf("parkhaus error\n");
        return;
    }
    Queue q;
    if(queue_init(&q) == -1){
        printf("queue init error\n");
        return;
    }
    Config *p_config = new_config();
    if(p_config == NULL){
        printf("config error\n");
        return;
    }
    //fill Config with random values for test purposes, usually this would be done by the user via the UI
    p_config->gen_probability = 50;
    p_config->max_parking_time = 50;
    p_config->num_spaces = 1;
    p_config->random_seed = 5;
    p_config->simulation_duration = 5;

    //TEST
    //tests that inputting a new car was successful
    assert(tw_input_new_car(p_parkhaus, &q, p_config) == 0);
    //tests that after calling input_new_car there is now 1 Car in the Parkhaus (now full!) but none in the queue
    assert(p_parkhaus->occupied_spaces == 1);
    assert(q.count == 0);
    //tests that inputting a new car was successful
    assert(tw_input_new_car(p_parkhaus, &q, p_config) == 0);
    //tests that, since the parkhaus was full, calling input_new_car didn't change the number of cars in the parkhaus
    // but added a new car to the queue
    assert(p_parkhaus->occupied_spaces == 1);
    assert(q.count == 1);

    //END
    queue_clear(&q);
    close_parkhaus(p_parkhaus);

}


void test_run_timestep(){

}


int main(){

    srand(5);

}