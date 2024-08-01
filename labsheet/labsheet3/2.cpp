//  Program to convert Polar Coordinate to Cartesian.
#include <iostream>
#include <cmath>
using namespace std;
class Coordinate
{
    float x, y, r, theta;
    public:
    Coordinate(float r,float theta){
        x = r*cos(theta);
        y = r*sin(theta);
    }
    void display(){
        cout<<"Cartesian Coordinates: ("<<x<<","<<y<<")";
    }
    

};
int main()
{
    float r, theta;
    cout << "Enter the value of r and theta: ";
    cin >> r >> theta;
    Coordinate c(r,theta);
    c.display();
    return 0;
}
