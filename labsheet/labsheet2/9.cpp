   
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
    MATRIX operator +(MATRIX m1)
    {
        MATRIX temp;
        temp.m=m;
        temp.n=n;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                temp.a[i][j]=a[i][j]+m1.a[i][j];
            }
        }
        return temp;
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
};
int main()
{
    MATRIX m1, m2, m3;
    m1.getdata();
    m2.getdata();
    m3=m1+m2;
    m3.displayData();
    return 0;
}