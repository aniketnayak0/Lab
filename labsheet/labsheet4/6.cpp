#include <iostream>
#include <string>
using namespace std;
class Student{
    int rn;
    string name;
    public:
        void getData(){
            cout << "Enter Roll Number: ";
            cin >> rn;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
        }
        void displayData(){
            cout << "Roll Number: " << rn << endl;
            cout << "Name: " << name << endl;
        }
};
class Internal_Exam : public Student{
    int m[7];
    public:
        void getData(){
            Student :: getData();
            cout << "Enter Marks in 7 Subjects of internal exam: ";
            for(int i = 0; i < 7; i++){
                cin >> m[i];
            }
        }
        int getM(int i){
            return m[i];
        }
        void displayData(){
            Student :: displayData();
            cout << "Marks in 7 Subjects in internal exam: ";
            for(int i = 0; i < 7; i++){
                cout << m[i] << " ";
            }
            cout << endl;
        }
};
class Final_Exam : public Internal_Exam{
    int n[7];
    public:
        void getData(){
            Internal_Exam :: getData();
            cout << "Enter Marks in 7 Subjects of final exam: ";
            for(int i = 0; i < 7; i++){
                cin >> n[i];
            }
        }
        int getN(int i){
            return n[i];
        }
        void displayData(){
            Internal_Exam :: displayData();
            cout << "Marks in 7 Subjects in final exam: ";
            for(int i = 0; i < 7; i++){
                cout << n[i] << " ";
            }
            cout << endl;
        }
};
class Result : public Final_Exam{
    float avgmark;
    public:
        void getData(){
            Final_Exam :: getData();
            avgmark = 0;
            for(int i = 0; i < 7; i++){
                avgmark += ((getM(i) * 40 / 100) + getN(i));
            }
            avgmark /= 7;
        }
        void displayData(){
            Final_Exam :: displayData();
            cout << "Average Marks: " << avgmark << endl;
        }
};
int main(){
    Result r;
    r.getData();
    r.displayData();
    return 0;
}

