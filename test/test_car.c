#include <stdlib.h>
#include <assert.h>
#include "car.h"

int main(){
    //unit test init_car function
    test_init_car();
    //unit test delete_car function
    test_delete_car();

    return 0;
    
}

void test_init_car(){
    
    Car *p_car = init_car(1, 1, 1);

    if(p_car == NULL){
        return;
    }

    //asserts that init_car returns a pointer to something the size of a Car (presumably a Car struct)
    assert(sizeof(Car) == (sizeof *p_car));

    // asserts that assigning the ID number works
    assert(p_car->id_number == 1);

    //asserts that the time in queue is zero-initialized
    assert(p_car->time_in_queue == 0);

    free(p_car);

}

void test_delete_car(){
    Car *p_car = init_car(2, 3, 5);

    if(p_car == NULL){
        return;
    }
    
    //asserts that delete_car successfully frees the memory of a Car pointer
    assert(delete_car(p_car) == 0);

    p_car = NULL;

    //asserts that passing a null pointer returns a managable error message
    assert(delete_car(p_car) == -1);

}