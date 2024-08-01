//  Create a 'STRING' class which char* and length as data member and  
// overloads  ‘+’ ,’=’ and ‘ = = ‘  to perform respective operations. Use 
// constructor and destructor whenever suitable.
#include <iostream>
#include <cstring>
using namespace std;
class STRING
{
    char *str;
    int len;
    public:
    void getData(){
        char temp[100];
        cout<<"Enter the string: ";
        cin>>temp;
        len = strlen(temp);
        str = new char[len+1];
        strcpy(str,temp);
    }
    void displayData(){
        cout<<"The string is: "<<str<<endl;
    }
       STRING operator+(STRING s)
       {
            STRING temp;
            temp.len = len + s.len;
            temp.str = new char[temp.len+1];
            strcpy(temp.str,str);
            strcat(temp.str,s.str);
            return temp;

       }
        STRING operator=(STRING s)
        {
          STRING temp;
            temp.len = s.len;
            temp.str = s.str;
            return temp;  
        }
        bool operator==(STRING s)
        {
            if(len == s.len)
            {
                return true;
            }
            else
            {
                return false;
           
            }
        }   
        STRING()
        {
            str = NULL;
            len = 0;
        }
        ~STRING()
        {
            delete[] str;
        }
};
int main() {
    STRING s1,s2,s3,s4;
    s1.getData();
    s2.getData();
    s3 = s1 + s2;
    s3.displayData();
    s4 = s1;
    s4.displayData();
    if(s1 == s2)
    {
        cout<<"The strings are of equal length"<<endl;
    }
    else
    {
        cout<<"The strings are not of equal length"<<endl;
    }


    return 0;
}