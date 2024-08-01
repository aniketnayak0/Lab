
#include <iostream>
#include <cstring>
using namespace std;

class Inventory 
{
    private:
        int quant;                     // number on hand
        int reorder;                   // reorder quantity
        double price;                  // price per unit
        char* descrip;                 // description of item
    public:
        Inventory (int q, int r, double p, char* d){
        quant = q;
        reorder = r;
        price = p;
        descrip = new char[strlen(d)+1];
    }                                  // initialize data members }
        ~Inventory(){
            delete [] descrip;
    }                                  //release dynamically allocated memory}
        void print(){
             cout << "Quantity: " << quant << endl;
             cout << "Reorder: " << reorder << endl;
             cout << "Price: " << price << endl;
             cout << "Description: " << descrip << endl;
        }
 };
 class Auto : public Inventory         // first derived class 
{
    char * manufacturer;
    public:
        Auto (int q, int r, double p, char * d, char *  man) : Inventory(q, r, p, d){
            manufacturer = new char[strlen(man) + 1];
            strcpy(manufacturer,d);
    }                                   //initialize base and derive members }
 
        ~Auto()
        {
            delete [] manufacturer;
        }                               //release dynamically allocated memory}
        void print(){
            Inventory::print();
            cout << "Manufacturer: " << manufacturer << endl;
        }
 };
 class Transmission : public Inventory  // Second derived class  
{
        char * vendor;
  public:
        Transmission (int q, int r, double p, char * d, char * ven) : Inventory(q, r, p, d){
            vendor = new char[strlen(ven) + 1];
            strcpy(vendor,ven);
        }
 
 ~ Transmission (){
        delete [] vendor;
    }                                   //release dynamically allocated memory}
        void print(){
            Inventory::print();
            cout << "Vendor: " << vendor << endl;
        }
        
};
int main(){
    Auto Car(5, 2, 15545.91, "Car", "Toyota");
    Car.print();
    Transmission trans(25, 10, 1789.98, "Transmission", " Aztec Inc.");
    trans.print();
    return 0;
}