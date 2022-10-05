////ctrl + k + u uncomments, ctrl + k + c comments
//
//
//
//#include <cmath>              /* for sqrt() */
//#include <iostream>           /* for io */
//#include <iomanip>             /* for setprecision */
//#include <map>                /* for map */
//#include <tuple>              /* for get() */
//
//using std::map;               /* for just map in std */
//using std::tuple;             /* for just tuple in std */
//using std::get;               /* for get() in std */
//using std::cout;              /* for screen output */
//using std::cin;               /* for user input */
//using std::endl;              /* for endlines*/
//using std::fixed;             /* for rounding output */
//using std::setprecision;      /* for rounding output */
//
//// Define some constants of the shell.
//const long double M_PI = 3.14159265358979323846;
//const long double INITIAL_VELOCITY = 827.0;   // m/s
//const long double SHELL_MASS = 46.7;    // kg
//const long double SHELL_DIAMETER = 0.15489; // m
//const long double ELAPSED_TIME = 0.5;    // s
//enum motionIndexes { TIME, X, Y, DX, DY };
//map <long double, long double> dragValues
//{
//   {0.300,   0.1629},
//   {0.500,   0.1659},
//   {0.700,   0.2031},
//   {0.890,   0.2597},
//   {0.920,   0.3010},
//   {0.960,   0.3287},
//   {0.980,   0.4002},
//   {1.000,   0.4258},
//   {1.020,   0.4335},
//   {1.060,   0.4483},
//   {1.240,   0.4064},
//   {1.530,   0.3663},
//   {1.990,   0.2897},
//   {2.870,   0.2297},
//   {2.890,   0.2306},
//   {5.000,   0.2656}
//};
//map <long double, long double> gravityValues
//{
//   {0,      9.807},
//   {1000,   9.804},
//   {2000,   9.801},
//   {3000,   9.797},
//   {4000,   9.794},
//   {5000,   9.791},
//   {6000,   9.788},
//   {7000,   9.785},
//   {8000,   9.782},
//   {9000,   9.779},
//   {10000,  9.776},
//   {15000,  9.761},
//   {20000,  9.745},
//   {25000,  9.730}
//};
//map <long double, long double> machValues
//{
//   {0,      340},
//   {1000,   336},
//   {2000,   332},
//   {3000,   328},
//   {4000,   324},
//   {5000,   320},
//   {6000,   316},
//   {7000,   312},
//   {8000,   308},
//   {9000,   303},
//   {10000,  299},
//   {15000,  295},
//   {20000,  295},
//   {25000,  295},
//   {30000,  305},
//   {40000,  324}
//};
//map <long double, long double> airDensityValues
//{
//   {0.0,      1.2250000},
//   {1000.0,   1.1120000},
//   {2000.0,   1.0070000},
//   {3000.0,   0.9093000},
//   {4000.0,   0.8194000},
//   {5000.0,   0.7364000},
//   {6000.0,   0.6601000},
//   {7000.0,   0.5900000},
//   {8000.0,   0.5258000},
//   {9000.0,   0.4671000},
//   {10000.0,  0.4135000},
//   {15000.0,  0.1948000},
//   {20000.0,  0.0889100},
//   {25000.0,  0.0400800},
//   {30000.0,  0.0184100},
//   {40000.0,  0.0039960},
//   {50000.0,  0.0010270},
//   {60000.0,  0.0003097},
//   {70000.0,  0.0000828},
//   {80000.0,  0.0000185}
//};
//
///******************************************************
// * COMPUTE DRAG
// * Computes the drag force in Newtons acting
// * on an object using d = 1/2 * c * p * v^2 * a
// ******************************************************/
//long double computeDrag(long double dragCoeff, long double density, long double velocity, long double area)
//{
//   return 0.5 * dragCoeff * density * velocity * velocity * area;
//}
//
///******************************************************
//* CIRCLE AREA FROM RADIUS
//* Computes the area of a circle given the circle's
//* radius using a = PI * r * r
//*******************************************************/
//long double circleAreaFromRadius(long double radius)
//{
//   return M_PI * radius * radius;
//}
//
///******************************************************
//* CIRCLE AREA FROM DIAMETER
//* Computes the area of a circle given the circle's
//* diameter using a = PI * (d/2) * (d/2)
//*******************************************************/
//long double circleAreaFromDiameter(long double diameter)
//{
//   long double radius = diameter / 2.0;
//   return circleAreaFromRadius(radius);
//}
//
///******************************************************
//* COMPUTE ACCELERATION
//* Computes the acceleration of an object given its mass
//* and the force acting on it using a = f / m
//*******************************************************/
//long double computeAcceleration(long double mass, long double force)
//{
//   return force / mass;
//}
//
///******************************************************
//* DEGREES FROM RADIANS
//* Converts radians to degrees using d = 360 * r / (2 * PI)
//*******************************************************/
//long double degreesFromRadians(long double radians)
//{
//   return 360.0 * radians / (2.0 * M_PI);
//}
//
///******************************************************
//* RADIANS FROM DEGREES
//* Converts degrees to radians using r = d * 2 * PI / 360
//*******************************************************/
//long double radiansFromDegrees(long double degrees)
//{
//   return degrees * 2.0 * M_PI / 360.0;
//}
//
///******************************************************
//* HYPOTENUSE FROM COMPONENTS
//* Computes the magnitude of the hypotenuse from the
//* given orthogonal components using c = sqrt(a^2 + b^2)
//*******************************************************/
//long double hypotenuseFromComponents(long double a, long double b)
//{
//   return sqrt(a * a + b * b);
//}
//
///******************************************************
//* INTERPOLATE
//* Performs linear interpolation given two points (x0, y0)
//* and (x1, y1) and a known x-value using
//*  (y1-y0)/(x1-x0) = (yU-y0)/(xU-x0)
//* where xU is the known x-value.
//*******************************************************/
//long double interpolate(long double x0, long double y0, long double x1, long double y1, long double current_x)
//{
//   if (y1 == y0)
//   {
//      // They gave us one point twice, or a constant function.
//      return y1;
//   }
//   else
//   {
//      return (y1 - y0) * (current_x - x0) / (x1 - x0) + y0;
//   }
//}
//
///*******************************************************************
// *  CALCULATE VERTICAL COMPONENT
// *  A function to calculate the vertical component of the bullet.
// *
// *  dy = s cos(a)
// *  Where:
// *    dy = vertical component of speed (m/s)
// *    s = overall speed (m/s)
// *    a = directon of travel where 0 is pointing up (radians)
// * *******************************************************************/
//long double calcVertComp(long double speed, long double angle)
//{
//   return speed * cos(angle);
//}
//
///*******************************************************************
// *  CALCULATE HORIZONTAL COMPONENT
// *  A function to calculate the horizontal component of the bullet.
// *
// *  dx = s sin(a)
// *  Where:
// *    s = overall speed (m/s)
// *    a = directon of travel where 0 is pointing up (radians)
// * *******************************************************************/
//
//long double calcHorComp(long double speed, long double angle)
//{
//   return speed * sin(angle);
//}
//
///********************************************************************
// * CALCULATE ANGLE
// *  A function to calculate an angle. The
// *  angle is  expected in degrees and returned in radians.
// *
// *  a = atan(dx, dy)
// *  Where:
// *    a = directon of travel where 0 is pointing up (radians)
// *    dx = horizontal component of speed (m/s)
// *    dy = vertical component of speed (m/s)
// *********************************************************************/
//long double calcAngle(long double dx, long double dy)
//{
//   return atan2(dx, dy);
//}
//
///********************************************************************
// *  SEARCH TABLE
// *  A function that will take in a key not contained in the table
// *  as a parameter and will return the keys just before and
// *  just after the not found key's theoretical place.
// *
// *  In other words, of all the keys that are lower than the key
// *  not contained in the table, we want to return the greatest
// *  which must be the key just under the not contained key.
// *
// *  And of all the keys that are greater than the key not
// *  contained in the table, we want to return the least
// *  which must be the key just above the not contained key
// *********************************************************************/
//tuple<long double, long double> searchTable(long double nckey, map<long double, long double> table)
//{
//   // assign the map iterator to the begining of the table
//   map<long double, long double>::iterator it = table.begin();
//
//   // assign high and low values to the first and last keys in the map
//   long double high = table.begin()->first;
//   long double low = table.begin()->first;
//
//   // Loop through the map
//   bool searching = true;
//   while (it != table.end() && searching)
//   {
//      // If the current key is less than the not contained key
//      if (it->first < nckey)
//      {
//         // and it is greater than the current low
//         if (it->first > low)
//         {
//            // It becomes the new low
//            low = it->first;
//         }
//      }
//      else
//      {
//         // Our previous iterator was the highest value below the one we want.
//         // The current iterator is the lowest value above the one we want.
//         // That means we're done searching.
//         high = it->first;
//         searching = false;
//      }
//      it++;
//   }
//
//   tuple<long double, long double> keys(low, high);
//
//   return keys;
//}
//
//
///*********************************************************************
// *  LOOK UP AIR DENSITY
// *  A function to look up the density of the air at a given
// *  altitude.
// *  Altitude is expected in meters.
// *
// *  The look up tables are imported from airDensity.h
// *********************************************************************/
//long double luAirDensity(long double altitude)
//{
//   if (airDensityValues.find(altitude) == airDensityValues.end())
//   {
//      // Find the value just under the missing key and the value just over
//      tuple <long double, long double> keys = searchTable(altitude, airDensityValues);
//
//      // Use those keys to get the two points around the missing point
//      long double x0 = get<0>(keys);
//      long double y0 = airDensityValues[x0];
//      long double x1 = get<1>(keys);
//      long double y1 = airDensityValues[x1];
//      long double x = altitude;
//
//      // Interpolate for y
//      return interpolate(x0, y0, x1, y1, x);
//   }
//   else
//   {
//      return airDensityValues[altitude];
//   }
//}
//
//
///*********************************************************************
// *  LOOK UP MACH
// *  A function to look up the mach speed at a given altitude.
// *  Altitude is expected in meters.
// *
// *  The look up tables are imported from mach.h
// *********************************************************************/
//long double luMach(long double altitude)
//{
//   if (machValues.find(altitude) == machValues.end())
//   {
//      // Find the value just under the missing key and the value just over
//      tuple <long double, long double> keys = searchTable(altitude, machValues);
//
//      // Use those keys to get the two points around the missing point
//      long double x0 = get<0>(keys);
//      long double y0 = machValues[x0];
//      long double x1 = get<1>(keys);
//      long double y1 = machValues[x1];
//      long double x = altitude;
//
//      // Interpolate for y
//      return interpolate(x0, y0, x1, y1, x);
//   }
//   else
//   {
//      return machValues[altitude];
//   }
//}
//
//
///*********************************************************************
// *  LOOK UP GRAVITY
// *  A function to look up gravity at  a given altitude.
// *  Altitude is expected in meters.
// *
// *  The look up tables are imported from gravity.h
// *********************************************************************/
//long double luGravity(long double altitude)
//{
//   if (gravityValues.find(altitude) == gravityValues.end())
//   {
//      // Find the value just under the missing key and the value just over
//      tuple <long double, long double> keys = searchTable(altitude, gravityValues);
//
//      // Use those keys to get the two points around the missing point
//      long double x0 = get<0>(keys);
//      long double y0 = gravityValues[x0];
//      long double x1 = get<1>(keys);
//      long double y1 = gravityValues[x1];
//      long double x = altitude;
//
//      // Interpolate for y
//      return interpolate(x0, y0, x1, y1, x);
//   }
//   else
//   {
//      return gravityValues[altitude];
//   }
//}
//
//
///*********************************************************************
// * LOOK UP DRAG COEFFICIENT
// * A function to look up drag coefficient at a given mach
// *
// * The look up tables are imported from drag.h
// *********************************************************************/
//long double luDragCoeff(long double mach)
//{
//   if (dragValues.find(mach) == dragValues.end())
//   {
//      // Find the value just under the missing key and the value just over
//      tuple <long double, long double> keys = searchTable(mach, dragValues);
//
//      // Use those keys to get the two points around the missing point
//      long double x0 = get<0>(keys);
//      long double y0 = dragValues[x0];
//      long double x1 = get<1>(keys);
//      long double y1 = dragValues[x1];
//      long double x = mach;
//
//      // Interpolate for y
//      return interpolate(x0, y0, x1, y1, x);
//   }
//   else
//   {
//      return dragValues[mach];
//   }
//}
//
///************************************************************
// * COMPUTE NEW MOTION
// * Takes in a reference to the previous motion values and the
// * current motion values so that it can save memory by only
// * updating the current motion values instead of returning a
// * new set of values. Uses prebuilt functions, as well as
// * the distance-acceleration formula
// * d1 = d0 + v*t + 1/2 * a * t^2
// * and the velocity-acceleration formula
// * v1 = v0 + a*t
// ************************************************************/
//void computeNewMotion(long double(&previousValues)[5], long double(&currentValues)[5])
//{
//   // Calculate previous acceleration from previous position, velocity, and constants
//   long double altitude = previousValues[Y];
//   long double velocityX = previousValues[DX];
//   long double velocityY = previousValues[DY];
//   long double speed = hypotenuseFromComponents(velocityX, velocityY);
//   long double computedDrag = computeDrag(luDragCoeff(speed / luMach(altitude)), luAirDensity(altitude),
//      speed,
//      circleAreaFromDiameter(SHELL_DIAMETER));
//   long double dragAcceleration = computeAcceleration(SHELL_MASS, computedDrag);
//
//   long double accelerationX = calcHorComp(dragAcceleration, calcAngle(velocityX, velocityY) + M_PI);
//   long double accelerationY = calcVertComp(dragAcceleration, calcAngle(velocityX, velocityY) + M_PI) - luGravity(altitude);
//
//
//   // Calculate current velocity from previous acceleration and velocity.
//   currentValues[DX] = previousValues[DX] + accelerationX * ELAPSED_TIME;
//   currentValues[DY] = previousValues[DY] + accelerationY * ELAPSED_TIME;
//
//   // Calculate current position from previous acceleration, velocity, and position.
//   currentValues[X] = previousValues[X] + previousValues[DX] * ELAPSED_TIME + 0.5 * accelerationX * ELAPSED_TIME * ELAPSED_TIME;
//   currentValues[Y] = previousValues[Y] + previousValues[DY] * ELAPSED_TIME + 0.5 * accelerationY * ELAPSED_TIME * ELAPSED_TIME;
//
//   // Calculate current time from previous time.
//   currentValues[TIME] = previousValues[TIME] + ELAPSED_TIME;
//}
//
///**************************************
// * MAIN
// * Calculates how long the shell of the Howitzer is in the air
// * and how far it travels horizontally based on the user's input
// * of what angle the Howitzer is aimed at (where zero degrees is up).
// **************************************/
//int main()
//{
//   while (true)
//   {
//      double x;
//      double y;
//      double dx;
//      double dy;
//      cout << "x position: ";
//      cin >> x;
//      cout << "y position: ";
//      cin >> y;
//      cout << "x velocity: ";
//      cin >> dx;
//      cout << "y velocity";
//      cin >> dy;
//      long double values1[5] = { 0, x, y, dx, dy };
//      long double values2[5] = { 0, x, y, dx, dy };
//      computeNewMotion(values1, values2);
//      cout << values2[0] << ", " << values2[1] << ", " << values2[2] << ", " << values2[3] << ", " << values2[4] << endl;
//      cout << luAirDensity(values1[Y]) << ", " << luGravity(values1[Y]) << ", " << luMach(values1[Y]) << ", " << luDragCoeff(hypotenuseFromComponents(values1[DX], values1[DY]) / luMach(values1[Y])) << endl << endl;
//
//   }
//   while (true)
//   {
//      // Get user input.
//      cout << "What is the angle of the howitzer where 0 is up ? ";
//      long double angleDegrees = 0;
//      cin >> angleDegrees;
//      long double angleRadians = radiansFromDegrees(angleDegrees);
//
//      // Initialize the two arrays of shell motion information.
//      // time, x, y, dx, dy, 
//      long double initialDX = calcHorComp(INITIAL_VELOCITY, angleRadians);
//      long double initialDY = calcVertComp(INITIAL_VELOCITY, angleRadians);
//
//      long double values1[5] = { 0, 0, 0, initialDX, initialDY };
//      long double values2[5] = { 0, 0, 0, initialDX, initialDY };
//      bool use1 = true;
//
//      // Let's get crackin!
//      // Keep mathing until one altitude is less than or equal to zero.
//      while (values1[Y] >= 0 and values2[Y] >= 0)
//      {
//         if (use1)
//         {
//            computeNewMotion(values1, values2);
//         }
//         else
//         {
//            computeNewMotion(values2, values1);
//         }
//         // Switch to using the other values next time.
//         use1 = !use1;
//      }
//
//      // Okay, at this point one of the value arrays is for a negative altitude
//      // and the other is for a positive or zero altitude.
//      // values1 will be the negative if use1, otherwise it's values2
//      long double distance = 0.0; //m
//      long double time = 0.0;     //s
//      if (use1)
//      {
//         if (values2[Y] == 0)
//         {
//            distance = values2[X];
//            time = values2[TIME];
//         }
//         else
//         {
//            distance = interpolate(values2[Y], values2[X], values1[Y], values1[X], 0.0);
//            time = interpolate(values2[Y], values2[TIME], values1[Y], values1[TIME], 0.0);
//         }
//      }
//      else
//      {
//         if (values1[Y] == 0)
//         {
//            distance = values1[X];
//            time = values1[TIME];
//         }
//         else
//         {
//            distance = interpolate(values1[Y], values1[X], values2[Y], values2[X], 0.0);
//            time = interpolate(values1[Y], values1[TIME], values2[Y], values2[TIME], 0.0);
//         }
//      }
//      cout << fixed << setprecision(1);
//      cout << "Distance:\t" << distance << "m\tHang Time:\t" << time << "s\n";
//   }
//}