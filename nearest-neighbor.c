#include <stdbool.h>
#include "header.h"

double nearest_neighbor(Coordinate* coordinates, int number_of_coordinates, int start_coordinate,
                        Coordinate* solution[number_of_coordinates])
{
    double total_cost = 0;
    int current_coordinate_index = start_coordinate;
    int coordinates_added = 0;

    // Track visited coordinates
    bool visited[number_of_coordinates];

    // Initialize the visited array
    for (int i = 0; i < number_of_coordinates; i++)
    {
        visited[i] = false; // Mark all coordinates as unvisited
    }

    // Set the starting coordinate to visited and add it to the tour
    visited[start_coordinate] = true;
    solution[coordinates_added++] = &coordinates[start_coordinate];

    // Repeat until all the coordinates are added to the solution
    for (int step = 1; step < number_of_coordinates; step++)
    {
        double closest_cost = 2000000.0;
        double current_cost;
        int closest_index = -1;

        // Finds the cheapest unvisited coordinate
        for (int i = 0; i < number_of_coordinates; i++)
        {
            if (!visited[i])
            {
                current_cost = travelCost(coordinates[current_coordinate_index], coordinates[i]);
                if (current_cost < closest_cost)
                {
                    closest_cost = current_cost;
                    closest_index = i;
                }
            }
        }

        // Set the closest coordinate to visited
        visited[closest_index] = true;

        // Add the closest coordinate to the tour and to the total cost
        solution[coordinates_added++] = &coordinates[closest_index];
        total_cost += closest_cost;

        // Update the current coordinate
        current_coordinate_index = closest_index;
    }

    // Add the cost from the last unvisited coordinate to the starting coordinate, to the total cost
    total_cost += travelCost(coordinates[current_coordinate_index], coordinates[start_coordinate]);

    // Add the start coordinate to the end of the tour, since the TSP returns back to the starting coordinate
    solution[coordinates_added] = &coordinates[start_coordinate];

    return total_cost; // Return the total cost of the tour
}

