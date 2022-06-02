#include <array>
#include <tuple>
#include <algorithm>
#include <cmath>

struct Point
{
    double x;
    double y;
};

/**
 * @param a point a
 * @param b point b
 *
 * @return distance between a and b
*/
double distance(Point a, Point b)
{
    return std::sqrt(std::pow((a.x - b.x), 2) + std::pow((a.y - b.y), 2));
}

/**
 *  @param points array of points
 *  
 *  @return array of two point objects closest to each other
 */
template <std::size_t n>
std::array<Point, 2> bruteForceClosestPair(const std::array<Point, n> &points)
{
    std::array<Point, 2> closestPair = {points[0], points[1]};
    double d = __DBL_MAX__; // minimum distance between arbitrary points a and b
    for (int i = 0; i < points.size(); i++)
    {
        for (int j = i + 1; j < points.size(); j++)
        { // distance is the minimum between current minimum distance and distance calculated
            double cdis = distance(points[i], points[j]);
            if (d > cdis)
            {
                d = cdis;
                closestPair[0] = points[i];
                closestPair[1] = points[j];
            }
        }
    }

    return closestPair;
}

