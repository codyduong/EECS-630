#ifndef _MY_CLOSEST_PAIR_POINTS_H_
#define _MY_CLOSEST_PAIR_POINTS_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>
#include <fstream>

typedef 
    struct 
    {
        unsigned int ID;    // the ID of the point
        float x;              // the x-coordinate of the point
        float y;              // the y-coordinate of the point
    }
PointType;

/*------------------------------------------------------------------------------
    ClosestPairOfPoints: find the closest pair of points from a set of points in a 2D plane 
    
        points: the set of points
        p1: the first point of the closest pair of points; should have a smaller ID
        p2: the second point of the closest pair of points; should have a larger ID
        
        returns the distance between the two points (round to 3-digit precision)
------------------------------------------------------------------------------*/
float ClosestPairOfPoints
(
    std::vector<PointType> & points,
    PointType & p1,
    PointType & p2
)
{
  /*------ CODE BEGINS ------*/


  /*------ CODE ENDS ------*/
}



#endif
