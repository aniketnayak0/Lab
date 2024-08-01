//  To write a C++ program to overload all relational operators to compare 
// US currency with Nepalese currency. Use conversion rate $1=NRs 
// 101.36(Note: make two classes to represent each currency)


#include<iostream>
using namespace std;
class USD
{
    public:
        int dollor;
    void getDollor(){
        cout<<"Enter Dollor: "<<endl;
        cin>>dollor;
    }
};
class NEPALESE{
    public:
        int nrs;
    bool operator<(USD obj){
        int dollorinnrs = obj.dollor * 101.36;
        nrs<obj.dollor;
    }
    bool operator>(USD obj){
        int dollorinnrs = obj.dollor * 101.36;
        nrs>obj.dollor;
    }
    bool operator==(USD obj){
        int dollorinnrs = obj.dollor * 101.36;
        nrs==obj.dollor;
    }
    void getNrs(){
        cout<<"Enter Nrs: "<<endl;
        cin>>nrs;
    }
    
};
int main(){
    USD obj;
    NEPALESE obj2;
    obj.getDollor();
    obj2.getNrs();
    if((obj2.nrs>obj.dollor)==1){
        cout<<"Nrs is greater than Dollor"<<endl;
    }
    if((obj2.nrs>obj.dollor)==1){
        cout<<"Nrs is less than Dollor"<<endl;
    }
    if((obj2.nrs==obj.dollor)==1){
        cout<<"Nrs is equal to dollor"<<endl;
    }

}
 
