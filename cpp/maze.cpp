#include "maze.h"
#include <iostream>

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
        for(int j{} ; j<static_cast<int>(this->size) ; j++){
            std::cout << "0";
        }
        std::cout << std::endl << " ";
    }
    // std::cout<<"1";
}