#include <stdlib.h>
#include <assert.h>
#include "car.h"

int main(){
    
}

void test_init_car(){
    
    Car *p_car = init_car(1, 1, 1);

    //asserts that init_car returns a pointer to something the size of a Car (presumably a Car struct)
    assert(sizeof (struct Car) == (sizeof *p_car));

    // asserts that assigning the ID number works
    assert(p_car->id_number == 1);

    //
    assert(p_car->time_in_queue == 0);

    free(p_car);

}