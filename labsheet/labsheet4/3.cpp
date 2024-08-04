// Modify Q.2 to add base class sales that holds an array of three 
// floats so that it can record the dollar sales of a particular 
// publication for the last three months. Include getdata() function to 
// get three Sales amount from the user and a putdata() function to 
// display sales figures. Alter the book and tape classes so they are 
// derived from both publication and sales. An object of class book or 
// tape should input and output sales data along with its other data
#include <iostream>
#include <cstring>
using namespace std;
class Sales{
    float sales[3];
    public:
        void getData(){
            cout << "\nEnter Sales for last 3 months: ";
            for(int i = 0; i < 3; i++){
                cin >> sales[i];
                }
            }
        void displayData(){
            cout << "\nSales for last 3 months: ";
            for(int i = 0; i < 3; i++){
                cout << sales[i] << " ";
                }
            }
    };
class Publication{
	string title;
	int price;
	public:
		void getData(){
			cout << "\nEnter Title: ";
			cin >> title;
			cout << "\nEnter Price: ";
			cin >> price;
			}
		void displayData(){
			cout << "\nTitle: " << title;
			cout << "\nPrice: " << price;
			}
	};
	class Book : public Publication , public Sales{
		int page_count;
		public:
			void getData(){
				Publication :: getData();
				cout << "\nEnter Total Page Count: ";
				cin >> page_count;
				}
			void displayData(){
				Publication :: displayData();
				cout << "Page Count: " << page_count;
				}
		};
		class Tape : public Publication , public Sales{
			float playing_time_in_minutes;
			public:
				void getData(){
					cout << "\nEnter Total Play Time in Minutes: ";
					cin >> playing_time_in_minutes;
                    Sales :: getData();
					}
				void displayData(){
					cout << "Total Play Time in Minutes: "<< playing_time_in_minutes;
                    Sales :: displayData();
					}
	};
	int main(){
		Book myBook;
    	Tape myTape;

    	cout << "Enter book details:\n";
    	myBook.getData();
    	myTape.getData();

    	cout << "\nBook details:";
    	myBook.displayData();
    	myTape.displayData();
		return 0;
		}