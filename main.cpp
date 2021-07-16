#include <iostream>
#include <iomanip>
using namespace std;

void display_board(char board[9]){

    cout << "\n " << board[0] << " | " << board[1] << " | " <<  board[2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " <<  board[5] << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}


char P1Marker, P2Marker {' '};


void player_input(){
    char marker {' '};

    while (marker != 'X' && marker != 'O'){
        cout << "Player 1, do you want to be X or O " << endl;
        cin >> marker;
        marker = toupper(marker);

        if (marker == 'X'){
            P1Marker = 'X';
            P2Marker = 'O';
        }

        else if (marker == 'O'){
            P1Marker = 'O';
            P2Marker = 'X';
        }

        else 
        {
            cout << "Invalid Marker " << endl;
        }
    }
}       


void place_marker(char board[9], char marker, int position){
    board[position-1] = marker;
}


bool win_check(char board[9], char mark){
    return ((board[6] == mark && board[7] == mark && board[8] == mark) ||
    (board[3] == mark && board[4] == mark && board[5] == mark) ||
    (board[0] == mark && board[1] == mark && board[2] == mark) ||
    (board[6] == mark && board[3] == mark && board[0] == mark) ||
    (board[1] == mark && board[4] == mark && board[7] == mark) ||
    (board[8] == mark && board[5] == mark && board[2] == mark) ||
    (board[6] == mark && board[4] == mark && board[2] == mark) ||
    (board[8] == mark && board[4] == mark && board[0] == mark));
}


bool space_check(char board[9], int position){
    return board[position] == ' ';
}


bool full_board_check(char board[9]){
    bool flag {false};
    // count is used to check how many spaces are not empty
    int count {0};
    
    for (int i {0}; i < 9; i++){
        if (space_check(board,i) == 0){
            count += 1; 
        }        
    } 

    if (count == 9){
        flag = true;
    }
    else {
        flag = false;
    }
        

return flag;
}


int player_choice(char board[9]){
    int position;

    while (position > 10 || ((space_check(board, position - 1)) == false) )
    {
       cout << "Choose your next position: (1-9) " << endl;
       cin >> position;
    }

    return position;
}

int main()
{
    cout << "Welcome to Tic Tac Toe!" << endl;
    
    while(true){
        // Reset Board
        char board[] {' ',' ',' ',' ',' ',' ',' ',' ',' '};
        char guide[] {'1','2','3','4','5','6','7','8','9'};

        string turn {};
        player_input();
        cout << "Player 1 will go first." <<  endl;

        bool game_on {true};
        int position {false};
        char play_game {};

        cout << "Are you ready to play? Enter Y or N: " << endl;
        cin >> play_game;

        if (toupper(play_game) == 'Y')
        {
            game_on = true;
            turn = "Player 1";
            display_board(guide);
        }
        else
        {
            game_on = false;
        }

        while (game_on)
        {
            if (turn == "Player 1")
            {
                // Player 1 turn.

                display_board(board);
                position = player_choice(board);
                place_marker(board, P1Marker, position);
            
                if (win_check(board,P1Marker))
                {
                    display_board(board);
                    cout << "Congratulations! Player 1. You have won the game! " << endl;
                    game_on = false; 
                }
                 else
                {
                    if (full_board_check(board))
                    {
                        display_board(board);
                        cout << "The game is a draw! " << endl;
                        break;
                    }
                        else
                    {
                        turn = "Player 2";
                    }    
                } 
               
            }
            if (turn == "Player 2")
            {
                // Player 2 turn

                display_board(board);
                position = player_choice(board);
                place_marker(board, P2Marker, position);
            
                if (win_check(board,P2Marker))
                {
                    display_board(board);
                    cout << "Congratulations! Player 2. You have won the game! " << endl;
                    game_on = false;
                }
                else
                {
                    if (full_board_check(board)) 
                    {
                        display_board(board);
                        cout << "The game is a draw! " << endl;
                        break;
                    }
                    else
                    {
                        turn = "Player 1";
                    }         
                }
            }   
        }     
    return false;
    } 
return 0;
}

