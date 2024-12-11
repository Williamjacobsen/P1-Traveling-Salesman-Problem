#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include "header.h"

// Calculate the distance between two given cities
double distance_nn(const city* a, const city* b)
{
    int dx = a->x - b->x; // Calculate Delta x
    int dy = a->y - b->y; // Calculate Delta y

    return (sqrt(dx * dx + dy * dy)); // Return the distance, by using the Euclidean distance formula
}


// Nearest neighbor algorithm
double nearest_neighbor(city* cities, int number_of_cities, int start_city, city* solution[number_of_cities])
{
    double total_dist = 0;
    int current_city_index = start_city;
    int cities_added = 0;


    // Track visited cities
    bool visited[number_of_cities];

    // Initialize the visited array
    for (int i = 0; i < number_of_cities; i++)
    {
        visited[i] = false; // Mark all cities as unvisited
    }

    // Set the starting city to visited and add it to the tour
    visited[start_city] = true;
    solution[cities_added++] = &cities[start_city];

    // Repeat until all the cities are added to the solution
    for (int step = 1; step < number_of_cities; step++)
    {
        double closest_dist = 2000000.0;
        double current_dist;
        int closest_index = -1;

        // Finds the nearest unvisited city
        for (int i = 0; i < number_of_cities; i++)
        {
            if (!visited[i])
            {
                current_dist = distance_nn(&cities[current_city_index], &cities[i]);
                if (current_dist < closest_dist)
                {
                    closest_dist = current_dist;
                    closest_index = i;
                }
            }
        }

        // Set the closest city to visited
        visited[closest_index] = true;

        // Add the closest city to the tour and to the total distance
        solution[cities_added++] = &cities[closest_index];
        total_dist += closest_dist;

        // Update the current city
        current_city_index = closest_index;
    }

    // Add the distance from the last unvisited city to the starting city, to the total distance
    total_dist += distance_nn(&cities[current_city_index], &cities[start_city]);

    // Add the start city to the end of the tour, since the TSP returns back to the starting city
    solution[cities_added] = &cities[start_city];

    return total_dist; // Return the total distance of the tour
}

void print_result(city* cities, int number_of_cities, city* solution[number_of_cities])
{
    double total_dist = nearest_neighbor(cities, number_of_cities, 0, solution);

    printf("Total Distance: %lf\n\n", total_dist);
    printf("Tour:\n");

    for (int i = 0; i < number_of_cities + 1; ++i)
    {
        printf("%c: (%d, %d)\n", solution[i]->id, solution[i]->x, solution[i]->y);
    }
}
