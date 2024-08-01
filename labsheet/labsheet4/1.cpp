//Assume class person stores the Name, Age and ID, class employee 

//stores the designation, basic salary, total overtime(hr) in a month 

//and hourly rate and class computedSalary stores the total salary of 

//the employee. Implement above concept using appropriate inheritance.

#include <iostream>
#include <cstring>
using namespace std;
class Person{
	int age,id;
	string  name;
	public:
		void getData(){
			cout << "\nEnter Name: ";
			cin >> name;
			cout << "\nEnter Age: ";
			cin >> age;
			cout << "\nEnter ID: ";
			cin >> id;
		}
		void displayData(){
			cout <<"\nName: " << name << "\nAge: " << age <<"\nID: " << id;
	}
};
	class Employee : public Person{
		string designation;
		int salary, overtime,hourly_rate;
		public:
			void getData(){
				Person :: getData();
				cout << "\nEnter Designation: ";
				cin >> designation;
				cout << "\nEnter Salary: ";
				cin >> salary;
				cout << "\nEnter Overtime in hrs: ";
				cin >> overtime;
				cout << "Enter hourly rate: ";
				cin >> hourly_rate;
			}
			int getSalary(){
				return salary;
			}
			int getOvertime(){
				return overtime;
			}
			int getHourlyRate(){
				return hourly_rate;
			}
			void displayData(){
				Person :: displayData();
				cout << "\nDesignation: " << designation;
				cout << "\nSalary: " << salary;
				cout <<"\nOvertime in hours: " << overtime;
				cout <<"\nhourly_rate: " << hourly_rate;
			}
				
		};
		class ComputedSalary : public Employee{
			int total_salary;
			public:
				void computedSalary(){
					total_salary = getSalary() * (getOvertime() * getHourlyRate());
				}
				void getData(){
					Employee :: getData();
				}
				void displayData(){
					Employee :: displayData();
					cout << "\nTotal Salary: "<< total_salary;
					}
			};
int main(){
		int n;
		ComputedSalary c[100];
		cout << "Enter Total Employee: ";
		cin >> n;
		for(int i = 0; i < n; i++){
			c[i].getData();
			cout << "\n";
		}
		for(int i=0; i<n; i++){
			c[i].computedSalary();
			c[i].displayData();
		}
		
		return 0;
		}
