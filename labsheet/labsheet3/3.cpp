//  Program to convert Cartesian coordinate to Polar
#include <iostream>
#include <cmath>
using namespace std;
class Coordinate
{
    float x, y, r, theta, r2, theta2;
    public:
    Coordinate(float x,float y){
        r = sqrt(x*x + y*y);
        theta = atan(y/x);
        r2 = -r;
        theta2 = theta + 3.14159;
    }
    void display(){
        cout << "The polar coordinates are: " << r << "," << theta << " or " << r2 << "," << theta2 << endl;
    }
    

};
int main()
{
    float x, y;
    cout << "Enter the Cartesian coordinates: ";
    cin >> x >> y;
    Coordinate c(x, y);
    c.display();
    return 0;
}