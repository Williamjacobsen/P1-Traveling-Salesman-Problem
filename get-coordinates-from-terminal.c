#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

Coordinate* get_coordinates_from_terminal(int* coordinate_count)
{
    int x, y;
    char input[100];
    Coordinate* coordinates = NULL; // Dynamically allocated array for coordinates
    int capacity = 10; // Initial capacity for the array
    int count = 0; // Counter to track the number of coordinates entered

    coordinates = malloc(capacity * sizeof(Coordinate));
    if (!coordinates)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    while (1)
    {
        printf("Enter coordinates as 'x y' or type 'finished' to stop:\n");
        printf("Enter coordinates (x y): ");
        fgets(input, sizeof(input), stdin);

        // Check if the user types "finished"
        if (strncmp(input, "finished", 8) == 0)
        {
            printf("Input ended.\n");
            break;
        }

        // Parse the input into integers x and y
        if (sscanf(input, "%d %d", &x, &y) == 2)
        {
            // Expand the array if necessary
            if (count >= capacity)
            {
                capacity *= 2;
                Coordinate* temp = realloc(coordinates, capacity * sizeof(Coordinate));
                if (!temp)
                {
                    fprintf(stderr, "Memory reallocation failed.\n");
                    free(coordinates);
                    exit(1);
                }
                coordinates = temp;
            }

            // Store the coordinates
            coordinates[count].x = x;
            coordinates[count].y = y;
            count++;

            clear_terminal();

            printf("You entered: x = %d, y = %d\n", x, y);
        }
        else
        {
            clear_terminal();

            printf("Invalid input. Please enter two integer coordinates or 'finished'.\n");
        }
    }

    if (*coordinate_count == 0)
        return NULL;

    *coordinate_count = count;
    return coordinates;
}
