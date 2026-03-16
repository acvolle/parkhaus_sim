#include "../include/parking.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_init_parking()
{
    Parkhaus *p_parkhaus = init_parkhaus(90);
    if (p_parkhaus!=NULL )
    {
        assert(p_parkhaus->occupied_spaces == 0);
        assert(p_parkhaus->p_spaces != NULL );
        assert(p_parkhaus->size == 90);

    }
    else
    {
        printf("Error: init_Parkhaus Null, test failed");
    }
    free(p_parkhaus);

}
void test_close_parking()
{
    Parkhaus *p_parkhaus = init_parkhaus(90);
    if(p_parkhaus!=NULL)
    {
        assert(close_parkhaus(p_parkhaus) == 0);
    }
    else
    {
        printf("Close Parkhaus failed");
    }
}

void test_park_car()
{
    //setup parkhaus and two new cars
    Parkhaus *p_parkhaus = init_parkhaus(1);
    if(p_parkhaus == NULL){
        return;
    }
    Car *p_newcar = init_car(1,1,1);
    if(p_newcar == NULL){
        close_parkhaus(p_parkhaus);
        return;
    }
    Car *p_newcar2 = init_car(2,2,2)
    if(p_newcar2 == NULL){
        close_parkhaus(p_parkhaus);
        delete_car(p_newcar);
        return;
    }
    
    //test that adding the first car works
    assert(park_car(p_parkhaus,p_newcar,1)==0);
    //tests that now the parkhaus is full and paking the car doesn't work
    assert(park_car(p_parkhaus,p_newcar2,1)== 1);
    //assert that attempting to park a null pointer doesn't work
    assert(park_car(p_parkhaus,NULL,1)==-1);
    
    //free the not-parked newcar2 and close the parkhaus
    delete_car(p_newcar2);
    close_parkhaus(p_parkhaus);
    p_newcar == NULL;
    p_newcar2 == NULL;
}

void test_update_parkhaus()
{
    Parkhaus *p_parkhaus = init_parkhaus(1);
    Car *p_newcar = init_car(1,1,2);

    if(p_parkhaus!=NULL&&p_newcar!=NULL)
    {
        park_car(p_parkhaus,p_newcar,1);
        assert(update_parkhaus(p_parkhaus)==0);
        p_newcar->park_span=0;
        assert(update_parkhaus(p_parkhaus)==0);
        assert(update_parkhaus(NULL)==-1);
    }
    else
    {
        printf("Error, Test for update_car failed");
    }
    close_parkhaus(p_parkhaus);
    delete_car(p_newcar);
}

void test_parkhaus_is_full()
{
    Parkhaus *p_parkhaus = init_parkhaus(1);
    Car *p_newcar = init_car(1,1,2);
    if(p_parkhaus!=NULL&&p_newcar != NULL)
    {
        assert(parkhaus_is_full(p_parkhaus)==0);
        park_car(p_parkhaus,p_newcar,1);
        assert(parkhaus_is_full(p_parkhaus)==1);
        assert(parkhaus_is_full(NULL)==-1);
    }
    else
    {
        printf("Error: Test for parkaus_is_full failed");
    }
    close_parkhaus(p_parkhaus);
}

int main()
{
    test_init_parking();
    test_close_parking();
    test_park_car();
    test_update_parkhaus();
    test_parkhaus_is_full();
    printf("Test successfull");

    return 0;
}