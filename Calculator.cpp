#include<iostream>
using namespace std;

int main(){
    int a, b, c, operation ;
    cout<<"Enter First Number : "; 
    cin>>a;
    cout<<"Enter Second Number : "; 
    cin>>b;
   
    cout<<"Operation 1 is Addition    Operation 2 is Subtraction    Operation 3 is Multiplication    Operation 4 is Division\nChoose an operation : "; 
    cin>>operation;

    switch (operation)
    {
    case 1:
        c=a+b;
        cout<<"Addition is : "<<c;
        break;
    
        case 2:
        c=a-b;
        cout<<"Subtraction is : "<<c;
        break;
    
        case 3:
        c=a*b;
        cout<<"Multiplication is : "<<c;
        break;
    
        case 4:
        c=a/b;
        cout<<"Division is : "<<c;
        break;
    
    default:
        cout<<"Wrong choice";
        break;
    }

    return 0;
}