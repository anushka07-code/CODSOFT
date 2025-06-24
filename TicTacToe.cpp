#include<iostream>
using namespace std;

int row, col; bool draw;
char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';

void Display_board(){
    system("cls");

    cout<<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  "<<endl; 
    cout<<"     |     |     "<<endl;
}

void player_turn(){
    int choice;
     
    if(turn=='X'){
       cout<<"Player1 enter your choice ";
    }
    else if(turn=='O'){
       cout<<"Player2 enter your choice ";
    }
    cin>>choice;
    switch (choice)
    {
        case 1: row=0; col=0; break;
        case 2: row=0; col=1; break;
        case 3: row=0; col=2; break;
        case 4: row=1; col=0; break;
        case 5: row=1; col=1; break;
        case 6: row=1; col=2; break;
        case 7: row=2; col=0; break;
        case 8: row=2; col=1; break;
        case 9: row=2; col=2; break;
                
    default:
        break;
    }
    if(turn=='X' && board[row][col]!='X' && board[row][col]!='O'){
        board[row][col]='X';
        turn='O';
    }
    else if(turn=='O'  && board[row][col]!='X' && board[row][col]!='O'){
        board[row][col]='O';
        turn='X';
    }
    else{
        cout<<"Wrong input already taken !\n Please try again!!"<<endl;
        player_turn();
    }
    Display_board();
}

bool gameover(){
    // check win
    for(int i=0; i<3; i++){
        if(board[i][0]== board[i][1] && board[i][1]== board[i][2]){
            return false;
        }
         if(board[0][i]== board[1][i] && board[1][i]== board[2][i]){
            return false;
        }
    }
    if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){
        return false;
    }
    if(board[0][2]==board[1][1] && board[1][1]==board[2][0]){
        return false;
    }

    // if there is any box not filled (game continue)
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(board[i][j]!='X' && board[i][j]!='O'){
                return true;
            }
        }
    }
    // if game draw
     draw = true;
    return false;
}

int main(){ 
    char playAgain;
    
    do{
        char temp='1';
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                board[i][j]=temp++;
            }
        }
        turn='X';
        draw=false;

        cout<<"Player1 [X]"<<endl;
        cout<<"Player2 [O]"<<endl;
     
        while(gameover()){
           Display_board();
           player_turn();
           gameover();
        }
        if(turn =='X' && draw == false){
        cout<<"Player2 [O] Wins!! Congratulations\n";
        }
        else if(turn =='O' && draw == false){
        cout<<"Player1 [X] Wins!! Congratulations\n";
        }
        else{
        cout<<"Game Draw !!"<<endl;
        }
        cout<<"Do you want to play again ? (y / n) :";
        cin>>playAgain;
    }while(playAgain=='Y'|| playAgain=='y');
    return 0;
}