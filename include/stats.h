#ifndef STATS_H
#define STATS_H

#include <stdio.h>

/** ### HEADER FILE FOR CALCULATING STATS ###
* 
*/

/**
* @brief Write first two lines of text file
*
* @param[in] car_count number of occupied spaces
* @param[in] spaces_count total number of parking spaces
* @return occupancy rate percentage
*/
float get_occupancy_rate(int car_count, int spaces_count);

#endif