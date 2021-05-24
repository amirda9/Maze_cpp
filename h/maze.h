#ifndef MAZE_H
#define MAZE_H


#include <iostream>
#include <vector>

class Maze{

    public:
        Maze();
        // Maze();
        void dfs();
        void bfs();
        void reset();
        void build();
        void show();
        void rand_dfs(int a, int b);
        void rand_adj(int a , int b);
        friend std::istream& operator>>(std::istream &input, Maze&);

    private:
        size_t size;
        std::vector<std::vector<char>> vec;
        std::vector<std::vector<int>> visited;
        int x ;
        int y ;
        int x_s;
        int y_s;
};


#endif