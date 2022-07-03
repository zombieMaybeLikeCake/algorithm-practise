#include <iostream>    
#include<iomanip>    
#include <cmath>  
#include<string>    
using namespace std;    
const double TOL = 1e-10;  
class ERR{    
  public:    
    string msg(){    
        return "retry";    
    }    
};    
class Point{    
  private:    
    double x, y;    
  public:    
    Point(double a = 0., double b = 0.):x(a), y(b){}    
    double getx() {return x;}    
    double gety() {return y;}    
    friend istream& operator>> (istream& in, Point& pt);    
        
};    
    
istream& operator>> (istream& in , Point& pt){    
    return in >> pt.x >> pt.y;    
}    
    
    
class Triangle{    
  private:    
    Point pt1, pt2, pt3;     
  public:    
    Triangle(Point& p, Point& q, Point& r) throw(ERR)     
        :pt1(p), pt2(q), pt3(r){    
        if(area() < TOL) throw ERR();    
    }    
    double area();  
    double perimeter();
    friend ostream &operator<<(ostream &out, Triangle &foo);
}
ostream& operator<< (ostream &out,Triangle &foo)
{
    return out << "area = " << fixed << setprecision(2) << foo.area() << endl
               << "perimeter = " << fixed << setprecision(2) << foo.perimeter();
}
double Triangle::area(){
  double x1 = pt1.getx(),y1 = pt1.gety(),x2 = pt2.getx(),y2 = pt2.gety(),x3 = pt3.getx(),y3 = pt3.gety();
  double v1x = abs(x1 - x2), v1y = abs(y1 - y2), v2x = abs(x1 - x3), v2y = abs(y1 - y3);
  return   abs(v1x * v2y - v1y * v2x)/2;
}
double Triangle::perimeter(){
  double x1 = pt1.getx(),y1 = pt1.gety(),x2 = pt2.getx(),y2 = pt2.gety(),x3 = pt3.getx(),y3 = pt3.gety();
  double v1x = abs(x1 - x2), v1y = abs(y1 - y2), v2x = abs(x1 - x3), v2y = abs(y1 - y3), v3x = abs(x2 - x3), v3y = abs(y2 - y3);
  return sqrt((v1x*v1x)+(v1y*v1y))+sqrt((v2x*v2x)+(v2y*v2y))+sqrt((v3x*v3x)+(v3y*v3y));
}      
int main(){
  Point a, b, c;
  while (1)
  {
    try
    {
      cin >> a >> b >> c;
      Triangle foo(a, b, c);
      cout << foo << endl;
      break;
    }
    catch (ERR &err)
    {
      cout << err.msg() << endl;
    }    
    }
    return 0;
}   