#include <iostream>
using namespace std;

int main() {
    int storeQuantity, orderQuantity;
    cout << "Enter the store quantity: ";
    cin >> storeQuantity;
    cout << "Enter the order quantity: ";
    cin >> orderQuantity;
    if (orderQuantity > storeQuantity) {
        cout << "No enough quantity" << endl;
    } else {
        if (orderQuantity > 16 && storeQuantity <= 40) {
            cout << "You cannot order more than 16 item" << endl;
        } else {
            cout << "Your order is accepted" << endl;
        }
    }

    return 0;
}
