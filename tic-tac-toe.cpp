#include <vector>
#include <iostream>
#include <fstream>
#include <string>


char player_turn = 'X';

void CreateBoard();
void DisplayBoard();
char GetPlayerChoice();
void PlaceMarker();


int main(){
    // CreateBoard(); // not needed since we have the function placeMarker reading txt file to get board.
    // DisplayBoard();
    int count = 0;
    while(count < 9){
        PlaceMarker();
        count++;
    }
    return 0;
}

void CreateBoard(){

    std::ofstream myfile;
    myfile.open ("board.txt");
    
    std::vector<std::vector<char>> board {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            myfile << board[i][j];
        }
        myfile << std::endl;
    }
    myfile.close();
}


void DisplayBoard(){
    std::string line = "";

    std::ifstream my_file_in("board.txt");
    if(my_file_in.is_open()){
        while(getline (my_file_in,line)){
            std::cout << line << '\n';
        }
        my_file_in.close();
    }
    else{
        std::cout << "Unable to open file. Please check file name for any mismatch." << std::endl;
    }
}

char GetPlayerChoice() {
    DisplayBoard();
    char playersChoice;

    std::cout << "Where on the board would you like to place your marker? :" << std::endl;
    std::cin >> playersChoice;
    
    if(playersChoice == 'X' || playersChoice == 'O') {
        std::cout << "Invalid placement, please try again." << std::endl;
        GetPlayerChoice();
    }
    return playersChoice;   
}

void PlaceMarker(){
    char player_choice = GetPlayerChoice();
    std::vector<std::vector<char>> board {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == player_choice){
                board[i][j] = player_turn;
            }
        }
    }



    std::ofstream my_file_out;
    my_file_out.open ("board.txt");

    for(int m = 0; m < board.size(); m++){
        for(int n = 0; n < board.size(); n++){
            my_file_out << board[m][n];
        }
        my_file_out << std::endl;
    }
    my_file_out.close();

}