#ifndef _MY_CLOSEST_PAIR_POINTS_H_
#define _MY_CLOSEST_PAIR_POINTS_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
// this should be in MainTest.cpp, but works fine here as well...
#include <fstream>

// typedef 
//     struct 
//     {
//         unsigned int ID;    // the ID of the point
//         float x;              // the x-coordinate of the point
//         float y;              // the y-coordinate of the point
//     }
// PointType;

// we need an actual constructor for sorting
struct PointType {
        unsigned int ID;    // the ID of the point
        float x;              // the x-coordinate of the point
        float y;              // the y-coordinate of the point
};

// this sucks!
// float euclideanDistance(const PointType& a, const PointType& b) {
//     return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
// }

/*
float euclideanDistanceSquared(const PointType& a, const PointType& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

// start sort predicates
bool compareX(const PointType& a, const PointType& b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

bool compareY(const PointType& a, const PointType& b) {
    return a.y < b.y;
}
// end sort predicates

float closestInStrip(std::vector<PointType>& strip, float d_squared, PointType& p1, PointType& p2) {
    float min = d_squared;

    std::sort(strip.begin(), strip.end(), compareY);

    // try all segments between two points until it is less than d
    for (size_t i = 0; i < strip.size(); ++i)
        // this took forever to find, forgot to square here
        // for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < min; ++j)
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < min; ++j)
            if (euclideanDistanceSquared(strip[i], strip[j]) < min) {
                min = euclideanDistanceSquared(strip[i], strip[j]);
                if (strip[i].ID < strip[j].ID) {
                    p1 = strip[i];
                    p2 = strip[j];
                } else {
                    p1 = strip[j];
                    p2 = strip[i];
                }
            }

    return min;
}

float closestUtilSquared(std::vector<PointType>& points, size_t left, size_t right, PointType& p1, PointType& p2) {
    if (right - left <= 3) { // use normal closet points algo under 3 points
        float minDist = std::numeric_limits<float>::max();
        for (size_t i = left; i <= right; ++i)
            for (size_t j = i + 1; j <= right; ++j)
                if (euclideanDistanceSquared(points[i], points[j]) < minDist) {
                    minDist = euclideanDistanceSquared(points[i], points[j]);
                    if (points[i].ID < points[j].ID) {
                        p1 = points[i];
                        p2 = points[j];
                    } else {
                        p1 = points[j];
                        p2 = points[i];
                    }
                }
        return minDist;
    }

    // mid point
    size_t mid = (left + right) / 2;
    PointType midPoint = points[mid];

    PointType pl1, pl2, pr1, pr2;
    float dl_squared = closestUtilSquared(points, left, mid, pl1, pl2);
    float dr_squared = closestUtilSquared(points, mid + 1, right, pr1, pr2);

    // smaller of two SQUARED distances
    float d_squared = std::min(dl_squared, dr_squared);
    PointType p1l = dl_squared <= dr_squared ? pl1 : pr1;
    PointType p2l = dl_squared <= dr_squared ? pl2 : pr2;

    // build a vector strip that contains points close closer than d to the middle point
    std::vector<PointType> strip;
    // for (size_t i = left; i <= right; i++)
    //     if (std::abs(points[i].x - midPoint.x) < d_squared)
    //         strip.push_back(points[i]);
    for (size_t i = left; i <= right; i++) {
        if ((points[i].x - midPoint.x) * (points[i].x - midPoint.x) < d_squared)
            strip.push_back(points[i]);
    }

    // return the minimum
    float stripDist = closestInStrip(strip, d_squared, p1, p2);
    if (stripDist < d_squared) {
        d_squared = stripDist;
        p1 = p1l;
        p2 = p2l;
    } else {
        p1 = p1l;
        p2 = p2l;
    }

    return d_squared;
}
*/

double SquaredDist(const PointType& a, const PointType& b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

// Recursive function to find the closest pair of points
std::pair<float, std::pair<PointType, PointType>> ClosestPairRecursive(
    std::vector<PointType>::iterator begin,
    std::vector<PointType>::iterator end)
{
    int distance = std::distance(begin, end);
    if (distance <= 3) {
        float minDist = std::numeric_limits<float>::max();
        std::pair<PointType, PointType> minPair;
        for (auto i = begin; i != end; ++i) {
            for (auto j = i + 1; j != end; ++j) {
                float dist = SquaredDist(*i, *j);
                if (dist < minDist) {
                    minDist = dist;
                    minPair = { *i, *j };
                }
            }
        }
        return { minDist, minPair };
    }

    // Divide the points around the middle point
    auto mid = begin + distance / 2;
    double midX = mid->x;

    // Recursively find the smallest distances in both halves
    auto left = ClosestPairRecursive(begin, mid);
    auto right = ClosestPairRecursive(mid, end);
    auto result = left.first < right.first ? left : right;

    // Consider the strip around the mid point in the x-axis
    std::vector<PointType> strip;
    for (auto i = begin; i != end; ++i) {
        if (std::fabs(i->x - midX) < result.first) {
            strip.push_back(*i);
        }
    }

    // Sort strip by the y-coordinate
    std::sort(strip.begin(), strip.end(), [](const PointType& a, const PointType& b) {
        return a.y < b.y;
    });

    // Check for the closest points in the strip
    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < result.first; ++j) {
            float dist_sq = SquaredDist(strip[i], strip[j]);
            if (dist_sq < result.first) {
                result.first = dist_sq;
                result.second = { strip[i], strip[j] };
            }
        }
    }

    return result;
}

/*------------------------------------------------------------------------------
    ClosestPairOfPoints: find the closest pair of points from a set of points in a 2D plane 
    
        points: the set of points
        p1: the first point of the closest pair of points; should have a smaller ID
        p2: the second point of the closest pair of points; should have a larger ID
        
        returns the distance between the two points (round to 3-digit precision)
------------------------------------------------------------------------------*/
float ClosestPairOfPoints
(
    const std::vector<PointType> & points,
    PointType & p1,
    PointType & p2
)
{
  /*------ CODE BEGINS ------*/
//   std::vector<PointType> pointsSorted(points);
//   std::sort(pointsSorted.begin(), pointsSorted.end(), compareX);

//   // we avoid using sqrt until the final step
//   float result_squared = closestUtilSquared(pointsSorted, 0, pointsSorted.size() - 1, p1, p2);
//   // return sqrt(result_squared);
//   return std::round(sqrt(result_squared) * 1000) / 1000.0;
    std::vector<PointType> sortedPoints(points);
    std::sort(sortedPoints.begin(), sortedPoints.end(), [](const PointType& a, const PointType& b) {
        return a.x < b.x;
    });

    auto result = ClosestPairRecursive(sortedPoints.begin(), sortedPoints.end());
    p1 = result.second.first;
    p2 = result.second.second;
    // return std::sqrt(result.first);
     return std::round(sqrt(result.first) * 1000) / 1000.0;
  /*------ CODE ENDS ------*/
}



#endif
