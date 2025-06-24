#include<iostream>
#include<cstdlib> // library that include functions like rand(), srand() to generate random numbers
#include<ctime>
using namespace std;

int main(){
    srand(time(0));
    int userGuess;
    int chances;
    int secretNumber = 1+(rand()%100); // Secret number is between 1 to 100
    cout<<"Enter number of chances to guess the correct number: ";
    cin>>chances;

    while(chances>0){
        cout<<"Enter your guess between 1 to 100 : ";
        cin>>userGuess;

        if(userGuess>secretNumber){
            cout<<"Your guess is too high "<<endl;
            chances--;
        }else if(userGuess<secretNumber){
            cout<<"Your guess is too low"<<endl;
            chances--;
        }else{
            cout<<"Congratulations !! you have guessed the correct number. "<<endl;
            break;
        }

        if(chances==0){
            cout<<" Opps you have lost! \n Your guess is wrong.\n The secret number is "<<secretNumber<<endl;
            break;
        }
    }
    return 0;
}