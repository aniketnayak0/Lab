//  Program to convert Nepalese Currency (Rupees and Paisa) to US 
// Currency (Dollar and Cents). (Rs. 98.51=1$)
#include <iostream>
using namespace std;
class Currency{
    int dollor,cent;
    public:
        Currency(float temp){
            temp = temp/98.51;
            dollor = temp;
            cent = (temp - dollor)*100;

        }
        void displayData(){
            cout << "Dollor: " << dollor << " Cent: " << cent;
        }

};
int main(){
    float temp;
    cout << "Enter the amount in Rupees(eg = 100.55): ";
    cin >> temp;
    Currency c(temp);
    c.displayData();
    return 0;
}