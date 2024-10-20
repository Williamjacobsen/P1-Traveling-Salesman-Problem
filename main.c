#include <stdio.h>
#include <math.h>
#include <time.h>

#define logging 0
#define any_logging 1

typedef struct
{
    int x;
    int y;
} Coordinate;

typedef struct
{
    int x1;
    int y1;
    int x2;
    int y2;
} Path;

double distance(const Coordinate a, const Coordinate b)
{
    return sqrt(pow(abs(b.x - a.x), 2) + pow(abs(b.y - a.y), 2));
}

void generate_random_path(Path path[], int length_coordinates, Coordinate coordinates[]) {
    for (int i = 0; i < length_coordinates; i++) {
        path[i].x1 = coordinates[i].x;
        path[i].y1 = coordinates[i].y;
        path[i].x2 = coordinates[i + 1].x;
        path[i].y2 = coordinates[i + 1].y;
    }
}

void two_opt(Coordinate coordinates[], int length_coordinates)
{
    Coordinate a, b;

    Path path[length_coordinates - 1];
    generate_random_path(path, length_coordinates, coordinates);

    if (logging)
    {
        for (int i = 0; i < sizeof(path)/sizeof(path[0]); i++)
        {
            printf("start path from (%d, %d) to (%d, %d)\n", path[i].x1, path[i].y1, path[i].x2, path[i].y2);
        }
    }

    int improvement = 1;
    while (improvement)
    {
        improvement = 0;

        for (int i = 0; i < sizeof(path)/sizeof(path[0]); i++)
        {
            a = (Coordinate){path[i].x1, path[i].y1};
            b = (Coordinate){path[i].x2, path[i].y2};
            //printf("\nfrom (%d, %d) to (%d, %d)\n", path[i].x1, path[i].y1, path[i].x2, path[i].y2);
            //printf("point: %d\n", i);

            for (int j = i + 1; j < sizeof(path)/sizeof(path[0]); j++)
            {
                Coordinate c = (Coordinate){path[j].x1, path[j].y1};
                Coordinate d = (Coordinate){path[j].x2, path[j].y2};

                if (a.x == c.x && a.y == c.y || b.x == c.x && b.y == c.y || a.x == d.x && a.y == d.y || b.x == d.x && b.y == d.y)
                {
                    continue;
                }

                double cur_distance = distance(a, b) + distance(c, d);
                //printf("current distance: %lf\n", cur_distance);

                Path new_path[] = {
                    {a.x, a.y, c.x, c.y},
                    {b.x,  b.y, d.x, d.y},
                };
                Coordinate new_a = a;
                Coordinate new_b = (Coordinate){c.x, c.y};
                Coordinate new_c = b;
                Coordinate new_d = d;
                double new_distance = distance(new_a, new_b) + distance(new_c, new_d);

                //printf("new distance: %lf\n", new_distance);

                if (new_distance < cur_distance)
                {
                    improvement = 1;

                    //printf("old path from (%d, %d) to (%d, %d)\n", path[i].x1, path[i].y1, path[i].x2, path[i].y2);
                    //printf("old path from (%d, %d) to (%d, %d)\n", path[j].x1, path[j].y1, path[j].x2, path[j].y2);

                    cur_distance = new_distance;
                    a = new_a;
                    b = new_b;
                    c = new_c;
                    d = new_d;
                    path[i] = (Path){a.x, a.y, b.x, b.y};
                    path[j] = (Path){c.x, c.y, d.x, d.y};

                    //printf("new path from (%d, %d) to (%d, %d)\n", path[i].x1, path[i].y1, path[i].x2, path[i].y2);
                    //printf("new path from (%d, %d) to (%d, %d)\n\n", path[j].x1, path[j].y1, path[j].x2, path[j].y2);
                }
            }
        }
    }

    if (logging)
    {
        for (int i = 0; i < sizeof(path)/sizeof(path[0]); i++)
        {
            printf("finished path from (%d, %d) to (%d, %d)\n", path[i].x1, path[i].y1, path[i].x2, path[i].y2);
        }
    }
}

void better_two_opt()
{
    //Coordinate path[] = {
    //    {2, 1},
    //    {1, 4},
    //    {3, 2},
    //    {0, 2},
    //    {2, 4},
    //    {1, 1},
    //    {0, 3},
    //    {3, 3},
    //};
    Coordinate path[] = {
        {4, 4},
        {6, 3},
        {6, 5},
        {4, 7},
        {2, 5},
        {2, 7},
        {4, 6},
        {2, 2},
        {3, 2},
        {6, 1},
        {5, 2},
        {3, 1},
        {1, 1},
        {1, 4},
        {6, 7},
        {8, 6},
        {8, 3},
        {9, 4},
        {9, 1},
    };
    int length_coordinates = sizeof(path)/sizeof(path[0]);
    //path[length_coordinates - 1] = path[0];
    Coordinate new_path[length_coordinates - 1];

    double cur_total_distance = 0;
    for (int i = 0; i < sizeof(path)/sizeof(path[0]) - 1; i++)
    {
        Coordinate a = path[i];
        Coordinate b = path[i+1];
        double _distance = distance(a, b);
        cur_total_distance += _distance;
    }
    cur_total_distance += distance(path[length_coordinates - 1], path[0]);
    if (any_logging)
    {
        printf("current total distance is %f\n", cur_total_distance);
    }

    int improvement = 1;
    while (improvement)
    {
        improvement = 0;

        for (int i = 0; i < sizeof(path)/sizeof(path[0]) - 1; i++)
        {
            for (int j = i; j < sizeof(path)/sizeof(path[0]); j++)
            {
                Coordinate temp = path[j+1];
                path[j+1] = path[i];
                path[i] = temp;

                double new_total_distance = 0;
                for (int k = 0; k < sizeof(path)/sizeof(path[0]) - 1; k++)
                {
                    Coordinate a = path[k];
                    Coordinate b = path[k+1];
                    double _distance = distance(a, b);
                    new_total_distance += _distance;
                }
                new_total_distance += distance(path[length_coordinates - 1], path[0]);

                if (new_total_distance < cur_total_distance)
                {
                    improvement = 1;

                    cur_total_distance = new_total_distance;

                    if (logging)
                    {
                        printf("new total distance is %f\n", new_total_distance);
                        for (int k = 0; k < sizeof(path)/sizeof(path[0]); k++)
                        {
                            printf("%d, %d\n", path[k].x, path[k].y);
                        }
                    }
                }
                else
                {
                    temp = path[j+1];
                    path[j+1] = path[i];
                    path[i] = temp;
                }
            }
        }
    }

    if (any_logging)
    {
        printf("new total distance is %f\n", cur_total_distance);
        for (int k = 0; k < sizeof(path)/sizeof(path[0]); k++)
        {
            printf("%d, %d\n", path[k].x, path[k].y);
        }
    }
}

int main(void)
{
    clock_t start = clock();

    Coordinate coordinates[] = {
        {1, 1},
        {1, 3},
        {2, 2},
        {0, 2},
        {4, 3},
        {3, 4},
        {}
    };
    int length_coordinates = sizeof(coordinates) / sizeof(Coordinate);

    // connect the first and last points: // makes mistakes, do this when is algo done (maybe)
    coordinates[length_coordinates-1] = coordinates[0];

    //two_opt(coordinates, length_coordinates);
    better_two_opt();

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken: %lf seconds\n", time_spent);

    return 0;
}
