#include <vector>
#include <iostream>
#include <fstream>




void CreateBoard();

int main(){
    CreateBoard();
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

    for(int i =0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            myfile << board[i][j];
        }
        myfile << std::endl;
    }
    myfile.close();
}