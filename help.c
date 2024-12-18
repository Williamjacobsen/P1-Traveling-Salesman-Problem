#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void help_input()
{
    printf("In order to run the algorithms you first need to input your coordinates.\n");
    printf("Coordinate format is (x, y)\n");

    printf("Available commands & How to use:\n");

    printf("\nScan coordinates from terminal:\n");
    printf("    This function will ask for input x y until you write 'finished'\n");
    printf("    Example:\n");
    printf("        3 4\n");
    printf("        7 2\n");
    printf("        2 8\n");
    printf("        finished\n");

    printf("\nScan coordinates from file:\n");
    printf("    This function will ask for a filename, it will read coordinate with format x y.\n");
    printf("    Example of file format:\n");
    printf("    coordinates.txt\n");
    printf("        3 4\n");
    printf("        7 2\n");
    printf("        2 8\n");

    printf("\nGenerate random number of coordinates:\n");
    printf("    This function will ask for a amount of coordinates and a range\n");
    printf("    Example:\n");
    printf("        amount: 100\n");
    printf("        min range: 0\n");
    printf("        max range: 20\n\n");

    printf("\nPress enter to continue...");
    getchar();
}

void help_algorithm()
{
    printf("The Nearest Neighbor algorithm is recommended if working with 2000+ data points, due to a faster runtime.\n");
    printf("The Two-Opt algorithm is recommended if working with less than 2000 data points, due to better accuracy.\n");

    printf("\nPress enter to continue...");
    getchar();
}
