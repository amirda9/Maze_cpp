#ifndef MAZE_H
#define MAZE_H


#include <iostream>
#include <vector>

class Maze{

    public:
        Maze();
        // Maze();
        void build();
        friend std::istream& operator>>(std::istream &input, Maze&);

    private:
        size_t size;
        std::vector<std::vector<char>> vec;

        
};


#endif