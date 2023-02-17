#include <iostream>
#include <conio.h> 

using namespace std;

void PrintInputMatrix();
void printboard();
int addmark();
int check();
char board[3][3] = {' ',' ',' ',
                    ' ',' ',' ',
                    ' ',' ',' '};

int turn=0; // 1 for Player 1 and 0  for Player 2
char mark='O'; // O for Player 1 and X for Player 2
int input;

int main(){
    int won=0;
    int validInput = 0;
    for(int i=0; i<9; i++){
		system("cls");
		printboard();
		if(turn) cout<<"Player 1 Turn (Symbol: O)"<<endl;
        else cout<<"Player 2 Turn (Symbol: X)"<<endl;
		PrintInputMatrix();
        cout<<"Enter Input from Input Matrix: ";
        cin>>input;
        while(input<0 || input>9){
            cout<<"Invalide Input. Please Re-Enter input: ";
            cin>>input;
        }
        if(turn) mark='O';
        else mark = 'X';
        validInput = addmark();
        if(!validInput){
            i--;
            continue;
        }
        won = check();
        if(won){
            system("cls");
            printboard();
            if(turn) cout<<endl<<"*** Player 1- You Won ***";
            else cout<<endl<<"*** Player 2- You Won ***";
            getch();
            break;
            break;
        }
        if(i==8){
            system("cls");
            printboard();
            cout<<endl<<"*** MATCH DRAW ***";
        }
		turn = !turn;
	}	
    return 0;
}

void PrintInputMatrix(){
    cout<<endl<<endl<<"INPUT MATRIX"<<endl;
    cout<<" 1 | 2 | 3 "<<endl;
    cout<<"-----------"<<endl;
    cout<<" 4 | 5 | 6 "<<endl;
    cout<<"-----------"<<endl;
    cout<<" 7 | 8 | 9 "<<endl;
};

void printboard(){
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" "<<endl;
	cout<<"-----------"<<endl;
	cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" "<<endl;
	cout<<"-----------"<<endl;
	cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" "<<endl;
};

int addmark(){
	for(int i=0, k=1; i<3; i++){
		for(int j=0; j<3; j++, k++){
			if(k == input){
				if(board[i][j]==' '){
					board[i][j] = mark;
					return 1;
				}
				else{
                   cout<<"INVALID INPUT!!!";
                   getch();
                   return 0; 
                } 
			}
		
		}
	}
};

int check(){
    //checking column
    if( board[0][0]==mark && board[1][0]==mark &&board[2][0]==mark )
		return 1;
    if( board[0][1]==mark && board[1][1]==mark &&board[2][1]==mark )
		return 1;
	if( board[0][2]==mark && board[1][2]==mark &&board[2][2]==mark )
		return 1;
				
	// checking row
	if( board[0][0]==mark && board[0][1]==mark && board[0][2]==mark )
		return 1;
	if( board[1][0]==mark && board[1][1]==mark && board[1][2]==mark )
		return 1;
	if( board[2][0]==mark && board[2][1]==mark && board[2][2]==mark )
	    return 1;
			
	//diagonals
	if( board[0][0]==mark && board[1][1]==mark && board[2][2]==mark )
		return 1;
	if( board[0][2]==mark && board[1][1]==mark && board[2][0]==mark )
		return 1;
    return 0;
}
		