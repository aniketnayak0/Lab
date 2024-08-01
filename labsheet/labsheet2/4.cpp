//   Create a class called 'TIME' that has
//   -three integer data members for hours, minutes and seconds
//   - constructor to initialize the object to zero
//   - constructor to initialize the object to some constant value
//   - overload +,- to add and subtract two TIME objects
//   - overload > function to compare two time
//   - member function to display time in HH:MM:SS format


#include <iostream>
using namespace std;
class Time{
    int hours,minutes,seconds;
    public:
     Time(){
         hours=0;
         minutes=0;
         seconds=0;
     }
    Time(int h,int m,int s){
        hours=h;
        minutes=m;
        seconds=s;
    }
    void displayTime(){
        cout<<hours<<":"<<minutes<<":"<<seconds<<endl;
    
    }
    Time operator+(Time t){
        Time AddTime;
        AddTime.hours=hours+t.hours;
        AddTime.minutes=minutes+t.minutes;
        AddTime.seconds=seconds+t.seconds;
        if(AddTime.seconds>=60){
            AddTime.minutes++;
            AddTime.seconds-=60;
        }
        if(AddTime.minutes>=60){
            AddTime.hours++;
            AddTime.minutes-=60;
        }
        return AddTime;
    }
        Time operator-(Time t){
        Time SubTime;
        SubTime.hours=hours-t.hours;
        SubTime.minutes=minutes-t.minutes;
        SubTime.seconds=seconds-t.seconds;
        if(SubTime.seconds<0){
            SubTime.minutes--;
            SubTime.seconds+=60;
        }
        if(SubTime.minutes<0){
            SubTime.hours--;
            SubTime.minutes+=60;
        }
        return SubTime;

    }
    bool operator>(Time t){
        if(hours>t.hours){
            return true;
        }
        else if(hours==t.hours){
            if(minutes>t.minutes){
                return true;
            }
            else if(minutes==t.minutes){
                if(seconds>t.seconds){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
    Time t1(1,30,45);
    Time t2(10,45,30);
    Time t3;
    t3=t1+t2;
    cout << "sum: ";
    t3.displayTime();
    cout<<"difference: ";
    if (t2 > t1) {
        t3 = t2 - t1;
        cout << "Difference (t2 - t1): ";
    } else {
        t3 = t1 - t2;
        cout << "Difference (t1 - t2): ";
    }
    t3.displayTime();
    if(t1>t2){
        cout<<"t1 is greater than t2"<<endl;
    }
    else{
        cout<<"t2 is greater than t1"<<endl;
    }
    return 0;
}