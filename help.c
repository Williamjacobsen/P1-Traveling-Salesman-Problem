#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void help_log()
{
    printf("Available commands:\n");
    printf("Scan coordinates from terminal: \n");
    printf("Scan coordinates from file: \n");
    printf("Generate random number of coordinates: \n");
} // flere eller færre idk

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
            help_log(); // tilkald hjælp funktion
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
