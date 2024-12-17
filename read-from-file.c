#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int count_lines_in_file(FILE* fp)
{
    int lines = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        lines++;
    }

    return lines;
}

int read_coordinates_from_file(Coordinate* coordinates, int number_of_coordinates, FILE* fp)
{
    int i;
    Coordinate new_coordinate;
    for (i = 0; i < number_of_coordinates; i++)
    {
        if (fscanf(fp, " %d %d", &new_coordinate.x, &new_coordinate.y) != 2)
        {
            break;
        }
        coordinates[i] = new_coordinate;
    }
    return i;
}

Coordinate* read_from_file(int* number_of_coordinates)
{
    char Filename[256];

    // Prompt the user to enter the filename
    printf("Enter the file name of the file you want to read coordinates from.\n");
    scanf("%s", Filename);

    // Attempt to open the file for reading
    FILE* input_file = fopen(Filename, "r");
    // Checks if the input_file is able to open and if it can't open it, then it returns NULL and gives an error message.
    if (input_file == NULL)
    {
        printf("Could not open file.\n");
        //exit(EXIT_FAILURE);

        printf("Press enter to continue");
        fflush(stdin);
        getchar();
        return NULL;
    }

    // Count the number of lines (coordinates) in the file
    *number_of_coordinates = count_lines_in_file(input_file);

    // Dynamically allocate memory for the coordinates based on the number of lines in the file
    Coordinate* input_coordinates = malloc(*number_of_coordinates * sizeof(Coordinate));
    if (input_coordinates == NULL)
    {
        printf("Memory allocation failed.\n");
        fclose(input_file);
        //exit(EXIT_FAILURE);

        printf("Press enter to continue");
        fflush(stdin);
        getchar();
        return NULL;
    }

    // Rewind the file pointer to the beginning of the file to start reading coordinates
    rewind(input_file);

    // Reads the coordinates from the file
    int number_of_coordinates_read = read_coordinates_from_file(input_coordinates, *number_of_coordinates, input_file);
    fclose(input_file);

    // If not all coordinates were read, free memory and return NULL
    if (number_of_coordinates_read != *number_of_coordinates)
    {
        printf("Error reading all coordinates from the file.\n");
        free(input_coordinates);
        return NULL;
    }

    // Return the dynamically allocated array of coordinates
    return input_coordinates;
}
