#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

double two_opt(Coordinate* path, int length_coordinates, Coordinate* solution[length_coordinates])
{
    //Coordinate path[] = {
    //    {4, 4}, {6, 3}, {6, 5}, {4, 7}, {2, 5},
    //    {2, 7}, {4, 6}, {2, 2}, {3, 2}, {6, 1},
    //    {5, 2}, {3, 1}, {1, 1}, {1, 4}, {6, 7},
    //    {8, 6}, {8, 3}, {9, 4}, {9, 1}, {4,5},
    //    {4,4}
    //};

    //int length_coordinates = sizeof(path) / sizeof(path[0]);

    int amountOfSpecialRoads = 0;
    struct specialRoad specialRoads[amountOfSpecialRoads];

    //specialRoads[0].from = path[0];
    //specialRoads[0].to = path[1];
    //specialRoads[0].speed = 70; // 70 to 80, not used to used, cheap to expensive

    double cur_total_cost = 0;
    for (int i = 0; i < length_coordinates - 1; i++)
    {
        cur_total_cost += travelCost(path[i], path[i+1], specialRoads, amountOfSpecialRoads);
    }
    cur_total_cost += travelCost(path[length_coordinates - 1], path[0], specialRoads, amountOfSpecialRoads);;

    int improvement = 1;
    while (improvement)
    {
        improvement = 0;

        for (int i = 0; i < length_coordinates - 1; i++)
        {
            for (int j = i + 1; j < length_coordinates; j++) // not sure about -1 or j+1%len
            {
                double old_cost =
                    travelCost(path[i], path[i + 1 % length_coordinates], specialRoads, amountOfSpecialRoads)
                    + travelCost(path[j], path[j + 1 % length_coordinates], specialRoads, amountOfSpecialRoads);

                double new_cost =
                    travelCost(path[i], path[j], specialRoads, amountOfSpecialRoads)
                    + travelCost(path[i + 1 % length_coordinates], path[j + 1 % length_coordinates], specialRoads, amountOfSpecialRoads);


                if (new_cost < old_cost)
                {
                    for (int k = 0; k < (j - i) / 2; k++)
                    {
                        Coordinate temp = path[i + 1 + k];
                        path[i + 1 + k] = path[j - k];
                        path[j - k] = temp;
                    }

                    cur_total_cost += new_cost - old_cost;
                    improvement = 1;
                }
            }
        }
    }

    for (int i = 0; i < length_coordinates; i++)
    {
        solution[i] = &path[i];
    }

    return cur_total_cost;
}