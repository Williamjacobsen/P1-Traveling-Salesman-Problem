#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_coordinates(int num_coordinates, Coordinate* coordinates, int min_range, int max_range)
{
    // Seed for random number generation
    srand(time(NULL));

    // Generate random coordinates within the specified range
    for (int i = 0; i < num_coordinates; i++)
    {
        coordinates[i].x = rand() % (max_range - min_range + 1) + min_range;
        coordinates[i].y = rand() % (max_range - min_range + 1) + min_range;
    }
}

Coordinate* random_coordinate_generator(int* num_coordinates)
{
    // Get number of coordinates from the user
    printf("Enter the number of coordinates to generate: ");
    scanf("%d", num_coordinates);

    // Get the range for coordinates from the user
    int min_range, max_range;
    printf("Enter the minimum range: ");
    scanf("%d", &min_range);
    printf("Enter the maximum range: ");
    scanf("%d", &max_range);
    
    if (min_range > max_range)
    {
        printf("Invalid range. Minimum range cannot be greater than maximum range.\n");
        return NULL;
    }

    // Dynamically allocate memory for the coordinates array
    Coordinate* coordinates = (Coordinate*)malloc(sizeof(Coordinate) * (*num_coordinates));
    if (coordinates == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    // Call the function to generate random coordinates
    generate_coordinates(*num_coordinates, coordinates, min_range, max_range);

    // Return the dynamically allocated array of coordinates
    if (*num_coordinates == 0)
        return NULL;
    return coordinates;
}
