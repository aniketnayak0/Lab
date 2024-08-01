
//  To write a C++ program to manipulate complex numbers using operator 
// overloading. (addition,subtraction,multiplication,division)


#include<iostream>
using namespace std;
class ComplexNumber
{
private:
    int real, img;

public:
    void getData()
    {
        cout << "Enter real part: " << endl;
        cin >> real;
        cout << "Enter imaginary part: " << endl;
        cin >> img;
    }
    void displayData()
    {
        cout << real << "+i" << img << endl;
    }
    ComplexNumber operator+(ComplexNumber obj)
    {
        ComplexNumber sum;
        sum.real = real + obj.real;
        sum.img = img + obj.img;
        return sum;
    }
    ComplexNumber operator-(ComplexNumber obj)
    {
        ComplexNumber sub;
        sub.real = real - obj.real;
        sub.img = img - obj.img;
        return sub;
    }
    ComplexNumber operator*(ComplexNumber obj)
    {
        ComplexNumber mul;
        mul.real = real * obj.real;
        mul.img = img * obj.img;
        return mul;
    }
    ComplexNumber operator/(ComplexNumber obj)
    {
        ComplexNumber div;
        div.real = real / obj.real;
        div.img = img / obj.img;
        return div;
    }
};
int main()
{
    ComplexNumber obj1, obj2 ,sum, sub, mul, div;;
    
    obj1.getData();
    obj2.getData();
    obj1.displayData();
    obj2.displayData();
    sum = obj1 + obj2;
    sub = obj1 - obj2;
    mul = obj1 * obj2;
    div = obj1 / obj2;
    cout << "Sum: ";
    sum.displayData();
    cout << "Sub: ";
    sub.displayData();
    cout << "Mul: ";
    mul.displayData();
    cout << "Div: ";
    div.displayData();
    return 0;
}
