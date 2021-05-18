#include "maze.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

Maze::Maze(){
    std::cout << "Maze constructor is called \n" ;
    srand((unsigned) time(NULL));
}


std::istream& operator>>(std::istream &input, Maze& M){
    std::cout << "\u001b[34m" << "Please enter size of your Maze :" << "\u001b[37m" << std::endl;
    input >> M.size;
    std::cout << "\033[31m Your Choice is : "<< M.size << "\n \033[0m" ;
    M.build();
    return input;
}

void Maze::show(){
    for(int i{} ;i<static_cast<int>(this->size) ; i++){
        for(int j{} ; j<static_cast<int>(this->size) ; j++){
            std::cout << this->vec[i][j];
        }
        std::cout << std::endl;
    }
}

void Maze::rand_adj(int a , int b){
    // srand(time(NULL));
        int r = rand()%4;
        // std::cout << "r is : "<< r << std::endl;
        if(r==0){
            // std::cout << "left" << std::endl;
            this->x = a; 
            this->y = b-1;
      }
        if(r==1){
            // std::cout << "right" << std::endl;
            this->x = a;
            this->y = b+1;
      }
        if(r==2){
            // std::cout << "up" << std::endl;
            this->x = a-1;
            this->y = b;
      }
        if(r==3){
            // std::cout << "down" << std::endl;
            this->x = a+1;
            this->y = b;
      }
      
    
    if(0 > x || x > this->size-1 || y < 0 || y > this->size-1 ){
                // std::cout << "\n ------" << a << b<< "\n";
                // std::cout << "\n ------*" << this->x << this->y<< "\n";
                this->rand_adj(a,b);
                // this->rand_dfs();
        }
    
    if(this->visited[x][y] == 1 ){
        // std::cout << "injuri shod";
        // this->rand_adj(0,1);
    }
    //  this->x = x;
    //  this->y = y;
}

void Maze::build(){


    for(int i{} ;i<static_cast<int>(this->size) ; i++){
        std::vector<char> temp;
        std::vector<int> temp2;
        for(int j{} ; j<static_cast<int>(this->size) ; j++){
            temp.push_back('|');
            temp2.push_back(0);
        }
        // std::cout << std::endl << " ";
        this->vec.push_back(temp);
        this->visited.push_back(temp2);
    }

    std::cout << " Filled Matrix \n";

    // this->show();

    this->rand_dfs(0,1);
    // while(1){
    //     this->rand_dfs(this->x,this->y);
    //     if(this->visited[this->size-1][this->size-1] == 1){
    //         break;
    //     }
    // }


    for(int i{} ;i<static_cast<int>(this->size) ; i++){
        for(int j{} ; j<static_cast<int>(this->size) ; j++){
            std::cout << this->visited[i][j];
        }
        std::cout << std::endl;
    }


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

    
}


void Maze::rand_dfs(int a , int b){
    if(this->visited[a][b] == 0){
        this->x = a;
        this->y = b;
        this->visited[a][b] = 1;
        this->vec[a][b] = ' ';
        // int x{},y{};
        this->rand_adj(a,b);
        this->show();
        std::cout << this->x <<  this->y  << std::endl;
        this->rand_dfs(this->x,this->y);
    }

    else if(a == this->size -1 && b == this->size-1){
        
    }
    
    else{
        // std::cout << "im here \n";
        this->rand_adj(a,b);
        if(0 <= x < this->size){
            if( 0<= y <this->size){
                this->rand_dfs(this->x,this->y);
            }
        }
    }


}

