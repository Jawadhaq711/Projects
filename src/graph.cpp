#include <iostream>
#include "graph.h"

// redefine to make more concise code
using pair_int = std::pair<int,int>;

Graph::Graph()
{
    _puzzle = std::vector <std::vector<int>>(9, std::vector<int>(9, 0));
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            std::list<pair_int > p{pair_int(i,j)};
            _adj[pair_int(i,j)] = p;
        }
    }
}


void Graph::initRow()
{
    for(int x = 0; x < 9; ++x)
    {
        for(int y = ; y < 9; ++y)
        {
            for(int j = y + 1; j < 9; ++j)
            {
                // add the points to the adjacency list
                auto list_ = _adj[pair_int(x,y)];
                list_.push_back(pair_int(x, j));
                _adj[pair_int(x,y)] = list;
                _adj[pair_int(x,j)] = _adj[pair_int(x,j)].push_back(pair_int(x,y));
            }
        }
    }
}