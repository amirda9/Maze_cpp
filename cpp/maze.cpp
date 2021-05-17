#include "maze.h"
#include <iostream>
#include <vector>

Maze::Maze(){
    std::cout << "Maze constructor is called \n" ;
}


std::istream& operator>>(std::istream &input, Maze& M){
    std::cout << "\u001b[34m" << "Please enter size of your Maze :" << "\u001b[37m" << std::endl;
    input >> M.size;
    std::cout << "\033[31m Your Choice is : "<< M.size << "\n \033[0m" ;
    M.build();
    return input;
}

void Maze::build(){


    for(int i{} ;i<static_cast<int>(this->size) ; i++){
        std::vector<char> temp;
        for(int j{} ; j<static_cast<int>(this->size) ; j++){
            temp.push_back('0');
        }
        // std::cout << std::endl << " ";
        this->vec.push_back(temp);
    }

    std::cout << " Filled Matrix \n";

    

    // int x = 1;
	// int y = 4;
	// char block = '+';
	// this->vec[ x ][ y ] = block; //set block at 1,4
	// this->vec[ ++x ][ y ] = block; //set block at 2,4
	// this->vec[ ++x ][ y ] = block; //set block at 3,4
	// this->vec[ x ][ --y ] = block; //set block at 3,3
	// --y; //y = 2
	// this->vec[ x ][ --y ] = block; //set block at 3,1
	// this->vec[ x ][ --y ] = block; //set block at 3,0
	// --x; //x = 2
	// this->vec[ --x ][ ++y ] = block; //set block at 1,1
	// this->vec[ --x ][ ++y ] = block; //set block at 0,2	
    // // std::cout<<"1";

    for(int i{} ;i<static_cast<int>(this->size) ; i++){
        for(int j{} ; j<static_cast<int>(this->size) ; j++){
            std::cout << this->vec[i][j];
        }
        std::cout << std::endl;
    }
}