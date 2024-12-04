#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_coordinates(int num_coordinates, int x_coordinate[], int y_coordinate[])
{
    // Seed så det bliver random koordinat hver gang
    srand(time(NULL));

    // Generate random coordinates
    for (int i = 0; i < num_coordinates; i++)
    {
        x_coordinate[i] = rand() % 100;
        // Tilfældigt nummer mellem 0 og 99 da koordinater går så langt, men er sku ikke sikker på hvordan koordinater fungerer så måske ik
        y_coordinate[i] = rand() % 100;
    }
}

int random_coordinate_generator()
{
    int num_coordinates;
    printf("Enter the number of coordinates to generate: ");
    scanf("%d", &num_coordinates);

    // Initialiser ints så den opbevarer som arrays
    int x_coords[num_coordinates];
    int y_coords[num_coordinates];

    // Kald funktionen
    generate_coordinates(num_coordinates, x_coords, y_coords);

    // Print, men kan fjernes hvis de ikke skal printes bare bruges
    printf("Generated coordinates:\n");
    for (int i = 0; i < num_coordinates; i++)
    {
        printf("Coordinate %d: (%d, %d)\n", i + 1, x_coords[i], y_coords[i]);
    }

    return 0;
}
