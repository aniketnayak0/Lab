//Create a class publication that stores the title and price of a 
//publication. From this class derive two classes:book, which adds a 
//page count and tape, which adds a playing time in minutes. Each of 
//these three classes should have getdata() function to get its data 
//from the user at the keyboard and putdata() function to display its 
//data.
#include <iostream>
#include <cstring>
using namespace std;
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
	class Book : public Publication{
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
		class Tape : public Publication{
			float playing_time_in_minutes;
			public:
				void getData(){
					cout << "\nEnter Total Play Time in Minutes: ";
					cin >> playing_time_in_minutes;
					}
				void displayData(){
					cout << "Total Play Time in Minutes: "<< playing_time_in_minutes;
					}
	};
	int main(){
		Book myBook;
    	Tape myTape;

    	cout << "Enter book details:\n";
    	myBook.getData();
    	cout << "\nEnter tape details:\n";
    	myTape.getData();

    	cout << "\nBook details:";
    	myBook.displayData();
    	cout << "\n\nTape details:\n";
    	myTape.displayData();
		return 0;
		}