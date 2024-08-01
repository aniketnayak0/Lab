   
//  Create a 'MATRIX' class of size m X n. Overload the ‘+’ operator to  
//  Add Two MATRIX objects. Write a main function to implement it.

#include <iostream>
using namespace std;
class MATRIX
{
    int m, n;
    int a[10][10];
    public:
    void getdata()
    {
        cout<<"Enter the number of rows and columns of the matrix: ";
        cin>>m>>n;
        cout<<"Enter the elements of the matrix: ";
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
    }
    
    void displayData()
    {
        cout<<"The sum of the two matrices is: "<<endl;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
friend MATRIX operator +(MATRIX m1, MATRIX m2);
};
MATRIX operator +(MATRIX m1, MATRIX m2)
    {
        MATRIX temp;
        temp.m=m1.m;
        temp.n=m1.n;
        for(int i=0;i<temp.m;i++)
        {
            for(int j=0;j<temp.n;j++)
            {
                temp.a[i][j]=m1.a[i][j]+m2.a[i][j];
            }
        }
        return temp;
    }
int main()
{
    MATRIX m1, m2, m3;
    m1.getdata();
    m2.getdata();
    m3=m1+m2;
    m3.displayData();
    return 0;
}