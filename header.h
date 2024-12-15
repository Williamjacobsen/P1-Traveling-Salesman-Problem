#ifndef HEADER_H
#define HEADER_H

typedef struct
{
    char id;
    int x, y;
} city;

typedef struct
{
    int x;
    int y;
} Coordinate;

struct specialRoad
{
    Coordinate from;
    Coordinate to;
    int speed;
};

double travelCost(Coordinate from, Coordinate to, struct specialRoad specialRoads[], int amountOfSpecialRoads);
Coordinate* random_coordinate_generator(int* num_coordinates);
Coordinate* read_from_file(int* number_of_coordinates);
double two_opt(Coordinate* path, int length_coordinates, Coordinate* solution[length_coordinates]);
void help_input();
void help_algorithm();
Coordinate* get_coordinates_from_terminal(int* coordinate_count);
double nearest_neighbor(Coordinate* coordinates, int number_of_coordinates, int start_coordinate,
                        Coordinate* solution[number_of_coordinates]);

#endif //HEADER_H
