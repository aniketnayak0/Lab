

//  To write a C++ program to swap two private data members using friend 
// functions.


#include<iostream>
using namespace std;

class B;

class A
{
private:
    int a;
public:
    void getdata()
    {
        cout<<"Enter a: ";
        cin>>a;
    }
    void display()
    {
        cout<<"a = "<<a<<endl;
    }
    friend void swap(A &obj, B &obj2);
    
};
class B
{
private:
    int b;
public:
    void getdata()
    {
        cout<<"Enter b: ";
        cin>>b;
    }
    void display()
    {
        cout<<"b = "<<b<<endl;
    }
    friend void swap(A &obj, B &obj2);
    
};
void swap(A &obj, B &obj2){
    int temp;
    temp=obj.a;
    obj.a=obj2.b;
    obj2.b=temp;

}
int main()
{
    A obj;
    B obj2;
    obj.getdata();
    obj2.getdata();
    cout<<"Before Swapping: "<<endl;
    obj.display();
    obj2.display();
    swap(obj, obj2);
    cout<<"After Swapping: "<<endl;
    obj.display();
    obj2.display();
    return 0;
}