/*
  needs point class ***************

  will use two points and create a linesegment which

  */

#ifndef _LINESEG_H
#define _LINESEG_H

#include <string>
#include "point.h"
using namespace std;

class LineSeg 
{
public:
  //Class constructors
  LineSeg();  //Default constructor
  LineSeg(Point first, Point second);

  //Method Functions
  double slope();

  //Public members
  Point fpoint;
  Point spoint;

};

  LineSeg::LineSeg(Point first, Point second)
  {
    fpoint = first;
    spoint = second;
  }

  double LineSeg::slope()
  {
    double s = (fpoint.gety+spoint.gety) / (fpoint.getx+spoint.getx);
    return s;
  }

#endif