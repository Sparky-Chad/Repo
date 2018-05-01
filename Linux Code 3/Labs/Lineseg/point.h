/*
  point class which can be used to output and store the values of points


  as a call for constructors

  Point() simply constructs a blank points
  Point(double x, double y) constructs a point with the x and y values

  Method Functions

  The gets and sets will use only doubles in this and if calling to an int be
  sure to concatonate as well

  void setx(double x) set or get the x value
  double getx()

  void sety(double y) set or get the x value
  double gety()

  the tostring function will return a formated point

  */

  #ifndef _POINT_H
  #define _POINT_H
  #include <string>
  #include <sstream>
  #include <iomanip>
  #include <cassert>

  class Point
  {
  public:
    //constructors
    Point();
    Point(double x, double y);

    //Method Functions
    void setx(double x);  //set x
    double getx();    //return x

    void sety(double y);  //set y
    double gety();      //return y

    std::string tostring();

    //Data Values
  private:
    double myX;
    double myY;
  };

  Point::Point()
  {
    myX = 0;
    myY = 0;
  }
  Point::Point(double x, double y)
  {
    myX = x;
    myY = y;
  }

  //Method Function Implementation
  void Point::setx(double x)
  {
    myX = x;
  }
  double Point::getx()
  {
    return myX;
  }

  void Point::sety(double y)
  {
    myY = y;
  }
  double Point::gety()
  {
    return myY;
  }

  std::string Point::tostring()
  {
    std::ostringstream ss;
    std::string str;
    ss.setf(std::ios::showpoint | std::ios::fixed);
    ss << std::setprecision(2);
    ss << "( " << myX << ", " << myY << ")";

    str = ss.str();
    return str;

  }



#endif  //close class
