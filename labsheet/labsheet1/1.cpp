#include <iostream>
using namespace std;

class DISTANCE {
private:
    int feet;
    int inches;

public:
    void inputDistance() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;

        while (inches >= 12) {
            inches -= 12;
            feet++;
        }
    }

    void outputDistance() {
        cout << feet << " feet " << inches << " inches" << endl;
    }

    DISTANCE addDistance(DISTANCE& d) {
        DISTANCE result;
        result.feet = feet + d.feet;
        result.inches = inches + d.inches;

        while (result.inches >= 12) {
            result.inches -= 12;
            result.feet++;
        }

        return result;
    }
};

int main() {
    DISTANCE d1, d2, d3;

    cout << "Enter first distance:" << endl;
    d1.inputDistance();

    cout << "Enter second distance:" << endl;
    d2.inputDistance();

    d3 = d1.addDistance(d2);

    cout << "Sum of distances: ";
    d3.outputDistance();

    return 0;
}
