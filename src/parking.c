#include "../include/parking.h"

// Initialize new Parkhaus

Parkhaus *init_parkhaus(unsigned int spaces_count){

}



//Delete Parkhaus and free allocated memory
int close_parkhaus(Parkhaus *p_parkhaus){

}



// Inserts new Car into the spaces array of a Parkhaus
int park_car(Parkhaus *p_parkhaus, Car *p_car){

}



//Updates all Car structs in a Parkhaus struct
int update_parkhaus(Parkhaus *p_parkhaus){
/*
    IF p_parkhaus != NULL THEN
        FOR i<-0 TO p_parkhaus->size DO
            IF Car pointer in array[i] != NULL THEN
                Car pointer->remaining time --;
                IF remaining time == 0 THEN
                    free memory of Car
                    delete pointer to Car from array
                END IF
            END IF
        END FOR
        return 0
    ELSE
        return -1
    END IF
*/
}



//Checks if a Parkhaus is full
int parkhaus_is_full(Parkhaus *p_parkhaus){

}