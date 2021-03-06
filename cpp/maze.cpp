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
    // std::cout << "\n";
    for(int i{} ;i<static_cast<int>(this->size) ; i++){
        for(int j{} ; j<static_cast<int>(this->size) ; j++){
            if(this->vec[i][j]=='*'){
                std::cout << "\033[31m"<<  this->vec[i][j] << "\033[0m" ;
            }
            else if(this->vec[i][j]=='#'){
                std::cout << "\033[33m"<<  this->vec[i][j] << "\033[0m" ;
            }
            else if(this->vec[i][j]=='|'){
                std::cout << "\u001b[34m"<<  this->vec[i][j] << "\u001b[37m" ;
            }
            else{
            std::cout << this->vec[i][j];
            }
        }
        std::cout << std::endl;
    }
}

void Maze::rand_adj(int a , int b){
    // srand(time(NULL));
        int r = rand()%10;
        // std::cout << "r is : "<< r << std::endl;
        if(r==0){
            // std::cout << "left" << std::endl;
            this->x = a; 
            this->y = b-1;
      }
        else if(r==1){
            // std::cout << "right" << std::endl;
            this->x = a;
            this->y = b+1;
      }
        else if(r==2){
            // std::cout << "up" << std::endl;
            this->x = a-1;
            this->y = b;
      }

      else if(r==3){
            // std::cout << "down" << std::endl;
            this->x = a+1;
            this->y = b;
      }
        else if(r==4){
            // std::cout << "left" << std::endl;
            this->x = a; 
            this->y = b-1;
      }
      else if(r==5){
            // std::cout << "right" << std::endl;
            this->x = a;
            this->y = b+1;
      }
      else if(r==6){
            // std::cout << "up" << std::endl;
            this->x = a-1;
            this->y = b;
      }
      else if(r==7){
            // std::cout << "down" << std::endl;
            this->x = a+1;
            this->y = b;
      }
      else if(r==8){
            // std::cout << "right" << std::endl;
            this->x = a;
            this->y = b+1;
      }
        else{
            // std::cout << "down" << std::endl;
            this->x = a+1;
            this->y = b;
      }
      
    if(0 > x || x > static_cast<int>(this->size)-1 || y < 0 || y > static_cast<int>(this->size)-1 ){
                // std::cout << "\n ------" << a << b<< "\n";
                // std::cout << "\n ------*" << this->x << this->y<< "\n";
                this->rand_adj(a,b);
                // this->rand_dfs();
    }
    else{
        // if(this->visited[x][y] == 1 ){
        // // std::cout << "injuri shod \n";
        // // this->rand_adj(0,1);
        // this->rand_adj(a,b);
        // }
    }
    //  this->x = x;
    //  this->y = y;
}

void Maze::reset(){
    x_s =0 ;
    y_s = 0;
    for(int i{} ;i<static_cast<int>(this->size) ; i++){
        for(int j{} ; j<static_cast<int>(this->size) ; j++){
            if(this->vec[i][j]=='*' || this->vec[i][j]=='#' || this->vec[i][j]=='H'){
                this->vec[i][j] =' ';
            }
            // if(this->visited[i][j]==1){
                this->visited[i][j] =0;
            // }
        }
    }
}

void Maze::bfs(){
    std::cout << "\n ---------- bfs ---------- \n" ;
    while(true){
        if(x_s == static_cast<int>(this->size)-1 && y_s==static_cast<int>(this->size)-1){
            // std::cout << "amir won" << std::endl;
            // this->show();
            for(int i{} ;i<static_cast<int>(this->size) ; i++){
        for(int j{} ; j<static_cast<int>(this->size) ; j++){
            if(this->vec[i][j]=='*'){
                std::cout << "\033[32m"<<  this->vec[i][j] << "\033[0m" ;
            }
            else if(this->vec[i][j]=='|'){
                std::cout << "\u001b[33m"<<  this->vec[i][j] << "\u001b[37m" ;
            }
            else{
            std::cout << this->vec[i][j];
            }
        }
        std::cout << std::endl;
            }
            break;
        }
        if(x_s == static_cast<int>(this->size)-1 ){
            x_s = x_s-1;
            y_s = y_s +1;
            this->vec[x_s][y_s] = '*';
        }
        if(this->vec[x_s+1][y_s]!='|'){
        x_s = x_s+1;
        // std::cout << "to the right -- " << x_s << y_s << std::endl;
        this->vec[x_s][y_s] = '*';
        }
        else if(this->vec[x_s+1][y_s]=='|'){
            // x_s = x_s  ;
            y_s = y_s + 1 ; 
        // if(this->vec[x_s+1][y_s]!='|'){
        //     x_s = x_s + 1 ; 
        // }
        // else{
        //     y_s = y_s - 1;
        // }
            // std::cout << "to the left -- " << x_s << y_s << std::endl;
            this->vec[x_s][y_s] = '*';
    }
    }
}

void Maze::bidirectional(){
    std::cout << "\n------------ bidirectional ----------- \n";
    this->reset();
    x_e = (this->size - 1);
    y_e = (this->size - 1);
    // std::cout << "im here" ;

    int i = 0 ;
    bool ud = false;
    bool ud2 = false;
    while(true){
        i++;
        ud = false;
        ud2 = false;
        //// won
        if((x_e == x_s && y_e == y_s) || i ==100 ){
            std::cout << "amir won by i" << std::endl;
            // this->show();
            // i = i+100;
            break;
        }

        //////// not won 
        else{
            // std::cout << x_s << y_s << x_e << y_e ; 
            if( y_e == 0 ){
                if(this->vec[x_e-1][y_e]!='|'){
                    if(this->visited[x_e-1][y_e]==1){
                        // std::cout << "amir won" << std::endl;
                        this->vec[x_e-1][y_e] = 'H';
                        break;
                    }
                    x_e = x_e -1 ;
                    this->vec[x_e][y_e] = '#';
                    this->visited[x_e][y_e] = 2;
            }
            else if(this->vec[x_e-1][y_e]=='|'){
                y_e = y_e +1 ;
                
            }

            }
            else if(y_s == static_cast<int> ((this->size) - 1)){
                 if(this->vec[x_s+1][y_s]!='|'){
                    x_s = x_s +1 ;
                    this->vec[x_s][y_s] = '*';
                    this->visited[x_s][y_s] = 1;
                }
                else if(this->vec[x_s+1][y_s]=='|'){
                    y_s = y_s -1 ;
                    this->vec[x_s][y_s] = '*';
                    this->visited[x_s][y_s] = 1;
                }
            }

            //// not a critical point
            else{
                if(this->vec[x_s][y_s+1]!='|'){
                    if(this->visited[x_s][y_s+1]==2 ){
                        this->vec[x_s][y_s+1] = 'H';
                        break;
                    }
                    else if(this->visited[x_s][y_s+1]==0){
                    y_s = y_s +1 ;
                    this->visited[x_s][y_s] = 1;
                    this->vec[x_s][y_s] = '*';
                    }
                    ///// right tested and not the way
                    else{   
                        if(this->visited[x_s+1][y_s]==2 ){
                        this->vec[x_s+1][y_s] = 'H';
                        break;
                        }
                        else{
                        if(this->vec[x_s+1][y_s]!= '|'){
                        x_s = x_s + 1 ;
                        this->vec[x_s][y_s] = '*';
                        this->visited[x_s][y_s] = 1;
                        }
                        /////// right tested and down is filled
                        else if(this->vec[x_s][y_s-1]!= '|'){
                            if(y_s != 0){
                            y_s = y_s - 1;
                            this->vec[x_s][y_s] = '*';
                            this->visited[x_s][y_s] = 1;
                            }
                            else{
                                if(this->vec[x_s-1][y_s]!= '|'){
                                    x_s = x_s - 1 ;
                                    this->vec[x_s][y_s] = '*';
                                    this->visited[x_s][y_s] = 1;
                                }
                            }

                        }
                        
                    }
                    }
                        // y_s = y_s +1;
                    
                }
                
        else if(this->vec[x_s][y_s+1]=='|') {
            if((this->vec[x_s+1][y_s]!= '|') && (this->visited[x_s+1][y_s]==0)){
                if(this->visited[x_s+1][y_s]==2){
                        this->vec[x_s+1][y_s+1] = 'H';
                        break;
                }
                else{
                    x_s = x_s + 1 ;
                    this->vec[x_s][y_s] = '*';
                    this->visited[x_s][y_s] = 1;
                    ud = true;
                    // std::cout << "here" << x_s << y_s;
                }
                
            }
            else if(this->vec[x_s-1][y_s]!= '|'){
                    if(this->visited[x_s-1][y_s]==0){
                    x_s = x_s - 1 ;
                    this->vec[x_s][y_s] = '*';
                    this->visited[x_s][y_s] = 1;
                    ud= true;
                    // std::cout << "here" << x_s << y_s;
                    }
                    else{
                    for(int j = 1 ; j <= x_s ; j++) {
                            if(this->visited[x_s-j][y_s]==0){
                                if(this->vec[x_s-j][y_s]!= '|'){
                                // myboolean =true ;
                                x_s = x_s - j ;
                                this->vec[x_s][y_s] = '*';
                                this->visited[x_s][y_s] = i;
                                ud = true;
                                break;
                                j+=100;
                                }
                                else{
                                    break;
                                    j+= 100;
                                }
                            }
                        }
                    }
        }
            

            if(!ud){
                if(y_s !=0){
                // x_s = x_s+1;
                y_s = y_s -1;
                this->vec[x_s][y_s] = '*';
                this->visited[x_s][y_s] = 1;
                }
            }
        }
        
        
        if((this->vec[x_e][y_e-1]!='|')){
            if(this->visited[x_e][y_e-1]==1){
                // std::cout << "amir won" << std::endl;
                this->vec[x_e][y_e-1] = 'H';
                break;
            }
            if(this->visited[x_e][y_e-1]==0){
                // std::cout << "\n e to the left \n";
            y_e = y_e -1 ;
            this->vec[x_e][y_e] = '#';
            this->visited[x_e][y_e] = 2;
            }
            ///// left tested but not the way
            else{
                    if(this->vec[x_e-1][y_e]!= '|'){
                    x_e = x_e - 1 ;
                    this->vec[x_e][y_e] = '#';
                    this->visited[x_e][y_e] = 2;
                    }

                    //// left tested and up is filled
                    else{
                        if(this->vec[x_e][y_e+1]!= '|'){
                            if(y_e != static_cast<int>(this->size - 1)){
                            y_e = y_e+1;
                            this->vec[x_e][y_e] = '#';
                            this->visited[x_e][y_e] = 2;
                            }
                            else{
                                if(this->vec[x_e+1][y_e]!= '|'){
                                    x_e = x_e + 1 ;
                                    this->vec[x_e][y_e] = '#';
                                    this->visited[x_e][y_e] = 2;
                                }
                            }

                        }
                    }
            }
        }
        if((this->vec[x_e][y_e-1]=='|')){
            if((this->vec[x_e-1][y_e]!= '|') && (this->visited[x_e-1][y_e]==0)){
                if(this->visited[x_e-1][y_e]==1){
                        this->vec[x_e-1][y_e] = 'H';
                        break;
                }
                else{
                    x_e = x_e - 1 ;
                    this->vec[x_e][y_e] = '#';
                    this->visited[x_e][y_e] = 2;
                    ud2 = true;
                    // std::cout << "here" << x_s << y_s;
                }
                
            }
            else if(this->vec[x_e+1][y_e]!= '|'){
                    if(this->visited[x_e+1][y_e]==1){
                        this->vec[x_e+1][y_e] = 'H';
                        break;
                    }
                    else if(this->visited[x_e+1][y_e]==0){
                    x_e = x_e+ 1 ;
                    this->vec[x_e][y_e] = '#';
                    this->visited[x_e][y_e] = 2;
                    ud2 = true;
                    // std::cout << "here" << x_s << y_s;
                    }
                    else{
                    for(int j = 0 ; j < (static_cast<int>(this->size - 1) - x_e) ; j++) {
                            if(this->visited[x_e+j][y_e]==0){
                                if(this->vec[x_e+j][y_e]!= '|'){
                                // myboolean =true ;
                                x_e = x_e + j ;
                                this->vec[x_e][y_e] = '#';
                                this->visited[x_e][y_e] = 2;
                                ud2 = true;
                                break;
                                j+=100;
                                }
                                else{
                                    break;
                                    j+= 100;
                                }
                            }
                        }
                    }
        }
            

            if(!ud2){
                if(y_s != static_cast<int>(this->size - 1)){
                // x_s = x_s+1;
                y_e = y_e + 1;
                this->vec[x_e][y_e] = '#';
                this->visited[x_e][y_e] = 2;
                }
            }
        }




            }



        }//// not won



    }///// end of while
            
            



this->show();
// for(int i{} ;i<static_cast<int>(this->size) ; i++){
//         for(int j{} ; j<static_cast<int>(this->size) ; j++){
//             std::cout << this->visited[i][j];
//         }
//         std::cout << std::endl;
//     }

    // while(true){
        // std::cout << x_e << y_e ;
        // if(x_e == x_s && y_e == y_s){
        //     // std::cout << "amir won" << std::endl;
        //     this->show();
        //     break;
        // }

    //     if(y_s == static_cast<int>(this->size)-1 ){
    //     y_s = y_s-1;
    //     x_s = x_s + 1 ;
    //     this->vec[x_s][y_s] = '*';
    //     }
    // if(this->vec[x_s][y_s+1]!='|'){
    //     y_s = y_s+1;
    //     // std::cout << "to the right -- " << x_s << y_s << std::endl;
    //     this->vec[x_s][y_s] = '*';
    // }

    

    // else if(this->vec[x_s][y_s+1]=='|'){
    //     y_s = y_s - 1 ;
    //     x_s = x_s + 1 ; 
    //     // if(this->vec[x_s+1][y_s]!='|'){
    //     //     x_s = x_s + 1 ; 
    //     // }
    //     // else{
    //     //     y_s = y_s - 1;
    //     // }
    //     // std::cout << "to the left -- " << x_s << y_s << std::endl;
    //     this->vec[x_s][y_s] = '*';
    // }

    // if(y_e == 0 ){
    //     // break;
    //     y_e = y_e + 1;
    //     x_e = x_e - 1;
    // //     this->vec[x_e][y_e] = '#';
    // }

    
    // if(this->vec[x_e][y_e-1]!='|'){
    //     if(this->y_e > 1) {
    //         this->y_e = this->y_e-1;
    //         this->vec[x_e][y_e] = '#';
    //     }
    // //     // std::cout << "to the left -- " << x_s << y_s << std::endl;
    // }

    // else if(this->vec[x_e][y_e-1]=='|'){
    //     // y_e = y_e + 1 ;
    //     // x_e = x_e - 1 ; 
    // // //     // if(this->vec[x_s+1][y_s]!='|'){
    // // //     //     x_s = x_s + 1 ; 
    // // //     // }
    // // //     // else{
    // // //     //     y_s = y_s - 1;
    // // //     // }
    // // //     // std::cout << "to the left -- " << x_s << y_s << std::endl;
    // // //     this->vec[x_e][y_e] = '#';
    // }

    
        }



void Maze::dfs(){
    std::cout << "\n ---------- dfs ---------- \n" ;

    int i =0 ;
    // bool myboolean = false;
    bool ud = false;
    while(true){
        i++;
        // myboolean = false;
        ud = false;
        if((x_s == static_cast<int>(this->size)-1 && y_s==static_cast<int>(this->size)-1) || (i==static_cast<int>(this->size*5))){
            // std::cout << "amir won" << std::endl;
            this->show();
            break;
        }
        // if(x_s == static_cast<int>(this->size)-1){
        //     std::cout << "test";
        // }
        if(y_s == static_cast<int>(this->size)-1 ){
                if(this->vec[x_s+1][y_s]!='|'){
                    x_s = x_s +1 ;
                    this->vec[x_s][y_s] = '*';
                    this->visited[x_s][y_s] = 1;
                }
                else if(this->vec[x_s+1][y_s]=='|'){
                    y_s = y_s -1 ;
                    this->vec[x_s][y_s] = '*';
                    this->visited[x_s][y_s] = 1;
                }

        }
    if(this->vec[x_s][y_s+1]!='|'){
        // y_s = y_s+1;
        // // std::cout << "to the right -- " << x_s << y_s << std::endl;
        // this->vec[x_s][y_s] = '*';
                    if(this->visited[x_s][y_s+1]==0){
                    y_s = y_s +1 ;
                    this->visited[x_s][y_s] = i;
                    this->vec[x_s][y_s] = '*';
                    }
                    ///// right tested and not the way
                    else{   
                        if(this->vec[x_s+1][y_s]!= '|'){
                        x_s = x_s + 1 ;
                        this->vec[x_s][y_s] = '*';
                        this->visited[x_s][y_s] = i;
                        }
                        else if(this->vec[x_s-1][y_s]!= '|'){
                        x_s = x_s - 1 ;
                        this->vec[x_s][y_s] = '*';
                        this->visited[x_s][y_s] = i;
                        }
                        /////// right tested and down is filled
                        else if(this->vec[x_s][y_s-1]!= '|'){
                            if(y_s != 0){
                            y_s = y_s - 1;
                            this->vec[x_s][y_s] = '*';
                            this->visited[x_s][y_s] = i;
                            }
                            else{
                                if(this->vec[x_s-1][y_s]!= '|'){
                                    x_s = x_s - 1 ;
                                    this->vec[x_s][y_s] = '*';
                                    this->visited[x_s][y_s] = i;
                                }
                            }

                        }
                        
                    }
    }
    else if(this->vec[x_s][y_s+1]=='|'){
        // y_s = y_s - 1 ;
        // x_s = x_s + 1 ; 
        // if(this->vec[x_s+1][y_s]!='|'){
        //     x_s = x_s + 1 ; 
        // }
        // else{
        //     y_s = y_s - 1;
        // }
        // std::cout << "to the left -- " << x_s << y_s << std::endl;
        // this->vec[x_s][y_s] = '*';
        if((this->vec[x_s+1][y_s]!= '|') && (this->visited[x_s+1][y_s]==0)){

                    x_s = x_s + 1 ;
                    this->vec[x_s][y_s] = '*';
                    this->visited[x_s][y_s] = i;
                    ud = true;
                    // std::cout << "here" << x_s << y_s;
                
        }
        else if(this->vec[x_s-1][y_s]!= '|'){
                    if(this->visited[x_s-1][y_s]==0){
                    x_s = x_s - 1 ;
                    this->vec[x_s][y_s] = '*';
                    this->visited[x_s][y_s] = i;
                    ud= true;
                    // std::cout << "here" << x_s << y_s;
                    }

                    ///// up is visited and right and down are filled
                    else{
                        
                        for(int j = 1 ; j <= x_s ; j++) {
                            if(this->visited[x_s-j][y_s]==0){
                                if(this->vec[x_s-j][y_s]!= '|'){
                                // myboolean =true ;
                                x_s = x_s - j ;
                                this->vec[x_s][y_s] = '*';
                                this->visited[x_s][y_s] = i;
                                ud = true;
                                break;
                                j+=100;
                                }
                                else{
                                    break;
                                    j+= 100;
                                }
                            }
                        }
                        
                    }
        }
        if(!ud) {
                if(y_s !=0){
                // x_s = x_s+1;
                y_s = y_s -1;
                this->vec[x_s][y_s] = '*';
                this->visited[x_s][y_s] = i;
                }
        }

    }
    }

    for(int i{} ;i<static_cast<int>(this->size) ; i++){
        for(int j{} ; j<static_cast<int>(this->size) ; j++){
            std::cout << this->visited[i][j];
        }
        std::cout << std::endl;
    }
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

    this->visited[0][0]=1;
    this->vec[0][0]=' ';
    std::cout << "Filled Matrix \n";

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
    this->x_s = 0;
    this->y_s = 0;
    
    if(this->visited[a][b] == 0){
        // if(a == static_cast<int>(this->size) -1 && b == static_cast<int>(this->size)-1){
        // std::cout << "\n resid  \n";
        // this->visited[a][b] = 1;
        // this->vec[a][b] = ' ';
        // }
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
    else{
        // std::cout << "im here \n";
        if(a == static_cast<int>(this->size) -1 && b == static_cast<int>(this->size)-1){
        std::cout << "\n resid  \n";
        this->visited[a][b] = 1;
        this->vec[a][b] = ' ';
        }
        else{
        this->rand_adj(a,b);
        if(0 <= x && x < static_cast<int>(this->size)){
            if( 0<= y  && y <static_cast<int>(this->size)){
                this->rand_dfs(this->x,this->y);
            }
        }
        }
    }


}

