#ifndef SOLVER_H
#include <iostream>
#include <vector>
#include <map>
#include "reader.h"




class Solver
{
    private:
        std::vector <std::vector<int>> _board;
    
    public:

        bool isPossible(int y, int x, int color); // determines if a color is possible
        bool isValid(); //determines if the board is a valid one
        bool solver(); // does the backtracking for me
        bool color(int row, int col);
        Solver(Reader& r); // maps the array in the reader to the _board
        Solver(std::vector<std::vector<int> > input); // takes the board in and maps it to _board
        friend std::ostream& operator<<(std::ostream& os, const Solver& s);
        const std::vector <std::vector<int> >& getBoard(){return _board;}
        
};

// std::ostream& operator<<(const std::ostream& os, Solver s);
#endif