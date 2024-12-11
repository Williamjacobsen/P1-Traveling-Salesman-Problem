#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

#define logging 0
#define any_logging 1
#define default_speed 50

typedef struct
{
    int x;
    int y;
} Coordinate;

double fdistance(const Coordinate a, const Coordinate b)
{
    return sqrt(pow(abs(b.x - a.x), 2) + pow(abs(b.y - a.y), 2));
}

struct specialRoad
{
    Coordinate from;
    Coordinate to;
    int speed;
};

double travelCost(Coordinate from, Coordinate to, struct specialRoad specialRoads[], int amountOfSpecialRoads)
{
    int speed = default_speed;
    double distance = fdistance(from, to);

    for (int i = 0; i < amountOfSpecialRoads; i++)
    {
        if (specialRoads[i].from.x == from.x && specialRoads[i].from.y == from.y &&
            specialRoads[i].to.x == to.x && specialRoads[i].to.y == to.y)
        {
            speed = specialRoads[i].speed;
        }
    }

    double time = distance / speed;
    int hourlyRate = 150;
    double costOfDieselPerKm = 0.32;

    double timeCost = time * hourlyRate;
    double fuelCost = distance * costOfDieselPerKm;

    double cost = timeCost + fuelCost;
    return cost;
}


void two_opt()
{
    Coordinate path[] = {
        {0, 0}, {2, 3}, {5, 1}, {1, 4}, {3, 3}, {0, 0}
    };

    int amountOfSpecialRoads = 1;
    struct specialRoad specialRoads[amountOfSpecialRoads];

    specialRoads[0].from = path[0];
    specialRoads[0].to = path[1];
    specialRoads[0].speed = 130;

    /*Coordinate path[] = {
        {4, 4}, {6, 3}, {6, 5}, {4, 7}, {2, 5},
        {2, 7}, {4, 6}, {2, 2}, {3, 2}, {6, 1},
        {5, 2}, {3, 1}, {1, 1}, {1, 4}, {6, 7},
        {8, 6}, {8, 3}, {9, 4}, {9, 1}, {4,5}
    };*/

    int length_coordinates = sizeof(path) / sizeof(path[0]);

    double cur_total_cost = 0;
    for (int i = 0; i < length_coordinates - 1; i++)
    {
        cur_total_cost += travelCost(path[i], path[i+1], specialRoads, amountOfSpecialRoads);
    }
    cur_total_cost += travelCost(path[length_coordinates - 1], path[0], specialRoads, amountOfSpecialRoads);;

    if (any_logging)
    {
        printf("Current total cost: %f\n", cur_total_cost);
    }

    int improvement = 1;
    while (improvement)
    {
        improvement = 0;

        for (int i = 0; i < length_coordinates - 1; i++)
        {
            for (int j = i + 1; j < length_coordinates - 1; j++) // not sure about -1 or j+1%len
            {
                double old_cost =
                    travelCost(path[i], path[i + 1], specialRoads, amountOfSpecialRoads)
                    + travelCost(path[j], path[j + 1], specialRoads, amountOfSpecialRoads);

                double new_cost =
                    travelCost(path[i], path[j], specialRoads, amountOfSpecialRoads)
                    + travelCost(path[i + 1], path[j + 1], specialRoads, amountOfSpecialRoads);


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

                    if (logging)
                    {
                        for (int k = 0; k < length_coordinates; k++)
                        {
                            printf("%d, %d\n", path[k].x, path[k].y);
                        }
                    }
                }
            }
        }
    }

    if (any_logging)
    {
        printf("Final total cost: %f\n", cur_total_cost);
        for (int k = 0; k < length_coordinates; k++)
        {
            printf("%d, %d\n", path[k].x, path[k].y);
        }
    }
}

void run_two_opt()
{
    clock_t start = clock();

    two_opt();

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken: %lf seconds\n", time_spent);
}