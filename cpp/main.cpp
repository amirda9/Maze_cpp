#include "gtest/gtest.h"
#include "maze.h"

int main()
{
    Maze M;
    std::cin >> M ;
    M.dfs();
    M.reset();
    // Maze M2;
    // std::cin >> M2;
    M.bfs();
    // srand((unsigned) time(NULL));
    // std::cout << "hello world \n" ;
    return 0;
}

