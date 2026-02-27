#include "../include/parking.h"

// Initialize new Parkhaus
Parkhaus *init_parkhaus(unsigned int spaces_count){
/*
    Parkhaus pointer <- allocate space for Parkhaus struct
    IF Parkhaus pointer == NULL THEN
        OUTPUT error message
        return NULL
    END IF
    spaces array pointer <- allocate space for Car pointer array of size spaces_count
    IF spaces array pointer == NULL THEN
        OUTPUT error message
        return NULL
    END IF
    Parkhaus pointer->size = spaces_count
    Parkhaus pointer->occupied_spaces = 0
    return Parkhaus pointer
*/
}



//Delete Parkhaus and free allocated memory
int close_parkhaus(Parkhaus *p_parkhaus){
/*
    IF p_parkhaus != NULL THEN 
        free memory allocated to spaces array
        IF free memory failed THEN
            return -1
        END IF
        free memory allocated to Parkhaus struct
        IF free memory failed THEN
            return -1
        END IF
        return 0
    ELSE 
        return -1
    END IF
*/
}



// Inserts new Car into the spaces array of a Parkhaus
int park_car(Parkhaus *p_parkhaus, Car *p_car){
/*
    IF p_parkhaus != NULL && (p_car != NULL) THEN
        IF parkhaus_is_full THEN
            return 1
        ELSE
            FOR i<-0 TO p_parkhaus->size DO
                IF spaces array[i] == NULL THEN
                   spaces array[i] <- p_car
                   return 0
                END IF
            END FOR
            return -1 (this can only be reaches if is_full is false but there isn't actually space --> error!)
        END IF
    ELSE
        return -1
    END IF
*/
}



//Updates all Car structs in a Parkhaus struct
int update_parkhaus(Parkhaus *p_parkhaus){
/*
    IF p_parkhaus != NULL THEN
        FOR i<-0 TO p_parkhaus->size DO
            IF Car pointer in spaces array[i] != NULL THEN
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
/*
    IF p_parkhaus != NULL THEN
        IF p_parkhaus->occupied spaces < p_parkhaus->size THEN
            return 0
        ELSE IF p_parkhaus->occupied spaces == p_parkhaus->size THEN
            return 1
        ELSE
            return -1
        END IF
    ELSE
        return -1
    END IF
*/

}