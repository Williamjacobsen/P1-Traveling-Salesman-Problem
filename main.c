
/*
    Recommend running the exe file instead of running in a code editor,
    due to code editors not keeping up with printf outputs.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "header.h"

void clear_input_buffer()
{
    while (getchar() != '\n') {}
}

void intro()
{
    system("cls");
    fflush(stdout);
    printf("\n    === Menu ===\n\n");
}

void print_options(int count, const char* options[], int current)
{
    intro();
    for (int i = 0; i < count; i++)
    {
        if (i == current) {
            printf(" >  \x1B[7m%s\x1B[0m\n", options[i]); // Highlight selected option
        } else {
            printf("    %s\n", options[i]);
        }
    }
}

int menu(const char *options[], int count)
{
    int current = -1;
    int loop = 1;

    while (loop)
    {
        print_options(count, options, current);

        int choice = _getch();
        switch (choice)
        {
            case 13: // Enter key
                loop = 0;
                break;
            case 80: // Down arrow
                current = (current + 1) % count;
                break;
            case 72: // Up arrow
                current = (current - 1 + count) % count;
                break;
            default:
                if (choice >= '1' && choice <= '9')
                {
                    int selected = choice - '1';
                    if (selected < count)
                    {
                        current = selected;
                        loop = 0;
                    }
                }
                break;
        }
    }

    return current;
}

void print_result(int number_of_coordinates, Coordinate* solution[number_of_coordinates], double total_cost);

int main(void)
{
    const char *inputOptions[] = {
        "Get Input from Terminal",
        "Read Input from File",
        "Generate N Random Data Points",
        "Help"
    };

    const char *algorithmOptions[] = {
        "Nearest Neighbor",
        "Two Opt",
        "Redo Input / Back",
        "Help",
    };

    while (1)
    {
        int option = -1;
        Coordinate *coordinates;
        int lengthOfInput = 0;
        while (option == -1)
        {
            option = menu(inputOptions, sizeof(inputOptions) / sizeof(const char *));

            system("cls");

            switch (option)
            {
            case 0:
                coordinates = get_coordinates_from_terminal(&lengthOfInput);
                break;
            case 1:
                coordinates = read_from_file(&lengthOfInput);
                break;
            case 2:
                coordinates = random_coordinate_generator(&lengthOfInput);
                break;
            case 3:
                help_input();
                option = -1;
                break;
            default:
                printf("Invalid option\n");
                break;
            }
        }

        fflush(stdout);

        int cost;
        option = -1;
        Coordinate** solution = malloc((lengthOfInput + 1) * sizeof(Coordinate*));
        while (option == -1)
        {
            option = menu(algorithmOptions, sizeof(algorithmOptions) / sizeof(const char *));
            switch (option)
            {
            case 0:
                cost = nearest_neighbor(coordinates, lengthOfInput, 0, solution);
                if (solution != NULL)
                {
                    print_result(lengthOfInput, solution, cost);
                }
                break;
            case 1:
                cost = two_opt(coordinates, lengthOfInput, solution);
                if (solution != NULL)
                {
                    print_result(lengthOfInput, solution, cost);
                }
                break;
            case 2:
                continue;
            case 3:
                help_algorithm();
                break;
            default:
                printf("Invalid option\n");
                break;
            }
        }

        fflush(stdin);
        getchar();
    }

    return 0;
}

void print_result(int number_of_coordinates, Coordinate* solution[number_of_coordinates], double total_cost)
{
    printf("Total Cost: %lf\n\n", total_cost);
    printf("Tour:\n");

    for (int i = 0; i < number_of_coordinates + 1; ++i)
    {
        printf("(%d, %d)\n", solution[i%number_of_coordinates]->x, solution[i%number_of_coordinates]->y);
    }
}
