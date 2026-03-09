#include "../include/parking.h"
#include <stdio.h>
#include <stdlib.h>

Parkhaus *init_parkhaus(const unsigned int spaces_count)
/*
    Parkhaus pointer <- allocate space for Parkhaus struct
    IF Parkhaus pointer == NULL THEN
        OUTPUT error message
        return NULL
    END IF
    spaces array pointer <- allocate space for Car pointer array of size spaces_count
    IF spaces array pointer == NULL THEN
        free space allocated for Parkhaus pointer
        OUTPUT error message
        return NULL
    END IF
    Parkhaus pointer->size = spaces_count
    Parkhaus pointer->occupied_spaces = 0
    return Parkhaus pointer
*/
{
    Parkhaus *p_parkhaus = malloc(sizeof(Parkhaus));
    if(p_parkhaus == NULL)
    {
        printf("init_parkhaus: Memory allocation for Parkhaus failed.\n");
        return NULL;
    }

    Car **p_spaces = malloc(spaces_count * sizeof(*p_spaces));
    if(p_spaces == NULL)
    {
        free(p_parkhaus);
        printf("init_parkhaus: Memory allocation for Spaces Array failed.\n");
        return NULL;
    }

    p_parkhaus->size = spaces_count;
    p_parkhaus->occupied_spaces = 0;
    return p_parkhaus;
}


int close_parkhaus(Parkhaus *p_parkhaus)
/*
    IF p_parkhaus == NULL OR spaces array == NULL THEN
        OURPUT error message
        return -1
    END IF
    FOR i <- 0 TO p_parkhaus_size DO
        IF spaces array[i] != NULL THEN
            free memory allocated to Car pointer in spaces_array[i]
            spaces_array[i] <- NULL
        END IF
    END FOR
    free memory allocated to spaces array
    free memory allocated to Parkhaus struct
    return 0
*/
{
    if(p_parkhaus == NULL || p_parkhaus->p_spaces == NULL)
    {
        printf("close_parkhaus failed: pointer is NULL.\n");
        return -1;
    }
    for(int i = 0; i < p_parkhaus->size; i++)
    {
        if(p_parkhaus->p_spaces[i] != NULL)
        {
            free(p_parkhaus->p_spaces[i]);
            p_parkhaus->p_spaces[i] = NULL;
        }
    }
    free(p_parkhaus->p_spaces);
    free(p_parkhaus);
    return 0;
}


int park_car(Parkhaus *p_parkhaus, Car *p_car, int current_time)
/*
    IF p_parkhaus != NULL && (p_car != NULL) THEN
        return -1
    END IF
    IF parkhaus_is_full THEN
        return 1
    END IF
    FOR i<-0 TO p_parkhaus->size DO
        IF spaces array[i] == NULL THEN
            spaces array[i] <- p_car
            p_car->arrival_time <- current_time
            p_parkhaus->occupied_spaces + 1
            return 0
        END IF
    END FOR
    return -1 (this can only be reaches if is_full is false but there isn't actually space --> error!)
*/
{
    if(p_parkhaus == NULL || p_parkhaus->p_spaces == NULL || p_car == NULL)
    {
        printf("park_car failed: pointer is NULL.\n");
        return -1;
    }
    if(parkhaus_is_full(p_parkhaus))
    {
        return 1;
    }
    for(int i = 0; i < p_parkhaus->size; i++)
    {
        // free spot found
        if(p_parkhaus->p_spaces[i] == NULL)
        {
            p_car->arrival_time = current_time;
            p_parkhaus->p_spaces[i] = p_car;
            p_parkhaus->occupied_spaces = p_parkhaus->occupied_spaces + 1;
            // car parked successfully
            return 0;
        }
    }
    return -1;
}


int update_parkhaus(Parkhaus *p_parkhaus)
/*
    IF p_parkhaus != NULL THEN
        return -1
    END IF
    FOR i<-0 TO p_parkhaus->size DO
        IF Car pointer in spaces array[i] != NULL THEN
            Car pointer->remaining time --;
            IF remaining time == 0 THEN
                free memory of Car
                delete pointer to Car from array
                p_parkhaus->occupied_spaces - 1
            END IF
        END IF
    END FOR
    return 0
*/
{
    if(p_parkhaus == NULL || p_parkhaus->p_spaces == NULL)
    {
        printf("update_parkhaus failed: pointer is NULL.\n");
        return -1;
    }
    for(int i = 0; i < p_parkhaus->size; i++)
    {
        // parking space is occupied
        if(p_parkhaus->p_spaces[i] != NULL)
        {
            p_parkhaus->p_spaces[i]->park_span = p_parkhaus->p_spaces[i]->park_span - 1;
            if(p_parkhaus->p_spaces[i]->park_span == 0)
            {
                free(p_parkhaus->p_spaces[i]);
                p_parkhaus->p_spaces[i] = NULL;
                p_parkhaus->occupied_spaces = p_parkhaus->occupied_spaces - 1;
            }
        }
    }
    return 0;
}


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