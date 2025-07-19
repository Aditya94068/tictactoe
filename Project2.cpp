#include<iostream>
using namespace std;
char board[3][3];
void initializeBoard(){
    char num = '1';
    for(int i = 0;i<3;i++){
        for(int j =0;j<3;j++){
            board[i][j] = num++;
        }
    }
}
void displayBoard(){
    cout<<"\n";
    for(int i =0;i<3;i++){
        for(int j =0;j<3;j++){
            cout<<board[i][j];
            if(j<2) cout<<" | ";
        }
        if(i<2)cout<<"\n---------\n";
    }
    cout<<"\n";
}
bool checkWin(char currentPlayer){
    for(int i = 0;i<3;i++){
        if((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) || 
          (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)){
            return true;
          }
          if((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)){
            return true;
        }
    }
    return false;
}
bool checkDraw(){
    for(int i =0;i<3;i++){
        for(int j = 0;j<3;j++){
            if(board[i][j] !='X' && board[i][j] !='O')
            return false;
        }
    }
    return true;
}
bool makeMove(char currentPlayer){
    int move;
    cout<<"Enter move frome 1 to 9 "<<currentPlayer<<":";
    cin>>move;
    if(move<1 || move>9){
        cout<<"Invalid move please again"<<endl;
        return false;
    }
    int row = (move - 1)/3;
    int col = (move - 1)%3;
    if(board[row][col] == 'X' || board[row][col] == 'O')
    {
        cout<<"Cell already taken "<<endl;
        return false;
    }
    board[row][col] = currentPlayer;
    return true;
}
int main(){
    char currentPlayer = 'X';
    initializeBoard();

    while(true){
        displayBoard();
        if(!makeMove(currentPlayer)){
            continue;
        }
        if(checkWin(currentPlayer))
        {
            displayBoard();
            cout<<"Player "<<currentPlayer<<" win\n"<<endl;
            break;
        }
        if(checkDraw()){
            displayBoard();
            cout<<"Its Draw "<<endl;
            break;
        }
        if(currentPlayer == 'X')
            currentPlayer = 'O';
        else{
            currentPlayer = 'X';
        }
    }
    return 0;
}