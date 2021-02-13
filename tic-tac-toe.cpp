#include <vector>
#include <iostream>
#include <fstream>
#include <string>




void CreateBoard();
void DisplayBoard();

int main(){
    CreateBoard();
    DisplayBoard();
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


void DisplayBoard(){
    std::string line = "";

    std::fstream my_file("board.txt");
    if(my_file.is_open()){
        while(getline (my_file,line)){
            std::cout << line;
            std::cout << std::endl;
        }
        my_file.close();
    }
    else{
        std::cout << "Unable to open file. Please check file name for any mismatch." << std::endl;
    }
}