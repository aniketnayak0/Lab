//  Program to convert time (hour, minute and second) in 24-hr format to 
// 12-hr format
#include <iostream>
using namespace std;
class twentyfour
{
    int h, m, s;
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
    }
    int getH()
    {
        return h;
    }
    int getM()
    {
        return m;
    }
    int getS()
    {
        return s;
    }
};
class twelve{
    int h, m, s;
    public:
    twelve(twentyfour t)
    {
        if(t.getH() >= 12){
            cout << "PM : ";
        }
        else{
            cout << "AM : ";
        }
        if(t.getH() > 12){
            h = t.getH() - 12;
        }
        else{
            h = t.getH();
        }
        m = t.getM();
        s = t.getS();
    }
    void display()
    {
        cout << h << ":" << m << ":" << s << endl;
    }
};
int main()
{
    twentyfour t;
    t.getData();
    twelve t1(t);
    t1.display();
    return 0;
}
