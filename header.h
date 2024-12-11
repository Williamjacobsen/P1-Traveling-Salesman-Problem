#ifndef HEADER_H
#define HEADER_H

// todo: make functions work together

typedef struct
{
    char id;
    int x, y;
} city;



int random_coordinate_generator();
void run_two_opt();
void help();
void get_coordinates_from_terminal();
void path_finding();
void print_result(city* cities, int number_of_cities, city* solution[number_of_cities]);
double nearest_neighbor(city* cities, int number_of_cities, int start_city, city* solution[number_of_cities]);

#endif //HEADER_H
