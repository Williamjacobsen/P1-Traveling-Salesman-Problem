#include <stdio.h>
#include <string.h>
#include "header.h"

void get_coordinates_from_terminal()
{
    float x, y;
    char input[100];
    float coordinates[100][2]; // Array to store up to 100 pairs of coordinates
    int count = 0; // Counter to track the number of coordinates entered

    printf("Enter coordinates as 'x y' or type 'finished' to stop:\n");

    while (1)
    {
        printf("Enter coordinates (x y): ");
        fgets(input, sizeof(input), stdin);

        // Check if the user types "finished"
        if (strncmp(input, "finished", 8) == 0)
        {
            printf("Input ended.\n");
            break;
        }


        if (sscanf(input, "%f %f", &x, &y) == 2)
        {
            // Store the coordinates
            if (count < 100)
            {
                coordinates[count][0] = x;
                coordinates[count][1] = y;
                count++;
            }
            else
            {
                printf("Coordinate storage is full.\n");
                break;
            }
            printf("You entered: x = %.8f, y = %.8f\n", x, y);
        }
        else
        {
            printf("Invalid input. Please enter two coordinates or 'finished'.\n");
        }
    }

    // Print all stored coordinates
    printf("\nYou entered the following coordinates:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Coordinate %d: x = %.8f, y = %.8f\n", i + 1, coordinates[i][0], coordinates[i][1]);
    }
}
