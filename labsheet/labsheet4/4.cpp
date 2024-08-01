
#include <iostream>
using namespace std;
class Date 
{
        int day,month,year;
  public:
      Date(){
        day = 0;
        month = 0;
        year = 0;
      };
      ~Date(){};
        void display(){
            cout << month << "/" << day << "/" << year << endl;
        } // displays the date
        Date get(){
            Date obj;
            obj.month = month;
            obj.day = day;
            obj.year = year;
            return obj;
        } //  accesses the date members
        void set(int m, int d, int y){
            month = m;
            day = d;
            year = y;
        }     // sets the date members
 };
 class Time 
{
        int hour;
        int minute;
        int second;
  public:
        Time(){
            hour = 0;
            minute = 0;
            second = 0;
        };
        ~Time(){};
        void display(){
            cout << hour << ":" << minute << ":" << second << endl;
        } // displays the time
        Time get(){
            Time obj;
            obj.hour = hour;
            obj.minute = minute;
            obj.second = second;
            return obj;
        };// accesses the time members
        void set(int h, int m, int s){
            hour = h;
            minute = m;
            second = s;
        } // sets the time members
 };
 class DateAndTime : public Date, public Time 
{      
  public:
      void display(){
        Date :: display();
        Time :: display();
      } // prints date and time
 };
 int main(){
    DateAndTime Watch;
    cout << "Initial Date and Time:" << endl;
    Watch.display();
    Watch.Date::set(12, 12, 2024);
    Watch.Time::set(12, 30, 45);
    cout << "Updated Date and Time:" << endl;
    Watch.display();

    return 0;
}
 