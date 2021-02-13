#include <vector>
#include <iostream>
#include <fstream>
#include <string>




void CreateBoard();
void DisplayBoard();
char GetPlayerChoice();

int main(){
    CreateBoard();
    DisplayBoard();
    GetPlayerChoice();
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
    // char output = board.at(1).at(2); // reference for indxing to a specific board position

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

    std::fstream my_file("board.txt");
    if(my_file.is_open()){
        while(getline (my_file,line)){
            std::cout << line << '\n';
        }
        my_file.close();
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