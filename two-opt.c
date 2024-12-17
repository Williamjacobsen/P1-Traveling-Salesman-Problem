#include "header.h"

double two_opt(Coordinate* path, int length_coordinates, Coordinate* solution[length_coordinates])
{
    double cur_total_cost = 0;

    for (int i = 0; i < length_coordinates - 1; i++)
    {
        cur_total_cost += travelCost(path[i], path[i + 1]);
    }
    cur_total_cost += travelCost(path[length_coordinates - 1], path[0]);

    int improvement = 1;

    while (improvement)
    {
        improvement = 0;

        for (int i = 0; i < length_coordinates - 1; i++)
        {
            for (int j = i + 1; j < length_coordinates; j++)
            {
                double old_cost =
                    travelCost(path[i], path[(i + 1) % length_coordinates]) +
                    travelCost(path[j], path[(j + 1) % length_coordinates]);

                double new_cost =
                    travelCost(path[i], path[j]) +
                    travelCost(path[(i + 1) % length_coordinates], path[(j + 1) % length_coordinates]);

                if (new_cost < old_cost)
                {
                    for (int k = 0; k <= (j - i - 1) / 2; k++)
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
