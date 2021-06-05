#include "gtest/gtest.h"
#include "maze.h"

int main()
{
    Maze M;
    std::cin >> M ;
    M.reset();
    try
    {
    M.bidirectional();
    M.reset();
    M.dfs();
    throw 2 ;
    }
    catch (std::exception& e)
    {
    std::cerr << "Exception caught : "  << std::endl;
    }
    // M.reset();
    // M.bfs();
    // Maze M2;
    // std::cin >> M2;
    // srand((unsigned) time(NULL));
    // std::cout << "hello world \n" ;
    return 0;
}

