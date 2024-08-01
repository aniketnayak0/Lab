#include <iostream>
#include <cstring>
using namespace std;
class employee
{
    int static managerCount, engineerCount;
    int id;
    char name[30], designation[30];

public:
    void getDetails()
    {
        cout << "\nEnter employee Id , name, designation(post): ";
        cin >> id >> name >> designation;
        strupr(designation);
        updateCount();
    }
    void showCount()
    {
        cout << "\nEngineerCount: " << engineerCount << " ManagerCount: " << managerCount;
    }

private:
    void updateCount()
    {
        if (strcmp(designation, "MANAGER") == 0)
        {
            managerCount++;
        }
        else if (strcmp(designation, "ENGINEER") == 0)
        {
            engineerCount++;
        }
    }
};
int employee::managerCount, employee::engineerCount;

int main()
{

    employee emp[10];
    int n;
    cout << "\nEnter how many Employee do you want to add: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        emp[i].getDetails();
    }
    emp[0].showCount();
    return 0;
}