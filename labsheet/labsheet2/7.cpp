
//  Overload >> and << operators to input and display time.

#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    friend istream &operator>>(istream &input, Time &time);
    friend ostream &operator<<(ostream &output, Time &time); 
};
istream &operator>>(istream &input, Time &time) {
    input >> time.hours >> time.minutes >> time.seconds;
    return input;
}
ostream &operator<<(ostream &output, Time &time) {
    output << time.hours << ":" << time.minutes << ":" << time.seconds;
    return output;
}   
int main() {
    Time time;
    cout << "Enter time in hours, minutes and seconds: ";
    cin >> time;
    cout << time;
    return 0;
}
