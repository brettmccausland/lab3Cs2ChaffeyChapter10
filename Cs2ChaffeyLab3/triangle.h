#ifndef TRIANGLE
#define TRIANGLE
#include <iostream>

using namespace std;

class Triangle
{
public:
   Triangle(int x1, int y1,int x2,int y2,int y3,int x3);
   int get_area() const;
private:
   int area;
};
Triangle::Triangle(int x1, int y1, int x2, int y2, int y3, int x3)
{
   // corners (x1,y1), (x2,y2), (x3,y3)
   int temp1= (x1*y2 )+ (x2* y3) + (x3*y1);
   int temp2= -1*( y1*x2);
   int temp3= temp2-( y2*x3);
   int temp4= temp3-(y3*x1);
   area= (temp1-temp4)/2;
}
int Triangle::get_area() const
{
   return area;
}

#endif // TRIANGLE

