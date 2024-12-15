#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void help_input()
{
    printf("\nIn order to run the algorithms you first need to input your coordinates.\n");
    printf("Coordinate format is (x, y)\n");

    printf("Available commands & How to use:\n");

    printf("Scan coordinates from terminal:\n");
    printf("    This function will ask for input x y until you write 'finished'\n");
    printf("    Example:\n");
    printf("        3 4\n");
    printf("        7 2\n");
    printf("        2 8\n");
    printf("        finished\n");

    printf("Scan coordinates from file:\n");
    printf("    This function will ask for a filename, it will read coordinate with format x y.\n");
    printf("    Example of file format:\n");
    printf("    coordinates.txt\n");
    printf("        3 4\n");
    printf("        7 2\n");
    printf("        2 8\n");

    printf("Generate random number of coordinates:\n");
    printf("    This function will ask for a amount of coordinates and a range\n");
    printf("    Example:\n");
    printf("        amount: 100\n");
    printf("        min range: 0\n");
    printf("        max range: 20\n\n");

    printf("\nPress any key to continue...\n");
    getchar();
}

void help_algorithm()
{
    printf("Todo: yap om algo shi\n");
}

void help()
{
    char command;

    printf("Type 'h' to see the list of commands.\n");

    while (69)
    {
        printf("\nEnter command: ");
        command = getchar(); // indlæs hjælp-funktion
        getchar(); // opbevaring

        if (command == 'h')
        {
            //help_log(); // tilkald hjælp funktion
        }
        else if (command == 'q')
        {
            printf("Exiting program. Goodbye!\n");
            exit(0); // luk loopet og programmet ved q (ved ikke om det er nødvendigt)
        }
        else
        {
            printf("Unknown command. Type 'h' for menu of possible commands or 'q' to quit.\n");
        } // sikkert også ligegyldigt men altså det er her
    }
}
