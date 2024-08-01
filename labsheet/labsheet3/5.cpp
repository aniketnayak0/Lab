//  Program to convert time (hour, minute and second) in 12-hr format to 
// 24-hr format

#include <iostream>
#include <cstring>
using namespace std;
class twentyfour
{
    public:
    int h, m, s;
    void display()
    {
        cout << h << ":" << m << ":" << s << endl;
    }      
};
class twelve{
    int h, m, s;
    string period;
    public:
    void getData()
    {
        cout << "Enter time:" << endl;
        cout << "Hours? ";
        cin >> h;
        cout << "Minutes? ";
        cin >> m;
        cout << "Seconds? ";
        cin >> s;
        cout << "AM or PM?: ";
        cin >> period;
    }
    operator twentyfour(){
        twentyfour t;
        if(period == "PM" || period == "pm" || period == "Pm" || period == "pM"){
            cout << "PM : ";
            if(h != 12){
            t.h = h + 12;
            }
            else{
                t.h = h;
            }
        }
        else{
            t.h = h;
        }
        if(period == "AM" || period == "am" || period == "Am" || period == "aM"){
            cout << "AM : ";
        }
        t.m = m;
        t.s = s;
        return t;
    }   
    
};

int main()
{
    twelve t;
    t.getData();
    twentyfour t1 = t;
    t1.display();
    return 0;
}
