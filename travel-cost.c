#include <math.h>
#include "header.h"

#define default_speed 50

double fdistance(const Coordinate a, const Coordinate b)
{
    return sqrt(pow(abs(b.x - a.x), 2) + pow(abs(b.y - a.y), 2));
}

// y=0.0000002711x**4-0.0001112337x**3+0.0169499556x**2-1.0643099998x+29.473711506
double fuelLitersSpentAtSpeed(int x)
{
    return (0.0000002711 * (x * x * x * x) - 0.0001112337 * (x * x * x) + 0.0169499556 * (x * x) - 1.0643099998 * x +
        29.473711506) / 100;
}

double travelCost(Coordinate from, Coordinate to/*, struct specialRoad specialRoads[], int amountOfSpecialRoads*/)
{
    int speed = default_speed;
    double distance = fdistance(from, to);

    // assume all roads are 50km/h for simplicity, and due to us not having access to a real road network
    //for (int i = 0; i < amountOfSpecialRoads; i++)
    //{
    //    if (specialRoads[i].from.x == from.x && specialRoads[i].from.y == from.y &&
    //        specialRoads[i].to.x == to.x && specialRoads[i].to.y == to.y)
    //    {
    //        speed = specialRoads[i].speed;
    //    }
    //}

    double time = distance / speed;
    int hourlyRate = 150;
    double dieselCostPerLiter = 12.55;

    double timeCost = time * hourlyRate;
    double fuelCost = distance * dieselCostPerLiter * fuelLitersSpentAtSpeed(speed);

    return timeCost + fuelCost;
}
