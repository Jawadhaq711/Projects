#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "solver.h"
#include<iostream>

TEST_CASE("Testing the isPossible function for the Sudoku solver")
{
    std::vector< std::vector<int> > v{
    {0, 0, 6, 5, 0, 8, 4, 0, 0},
    {5, 2, 0, 0, 0, 1, 0, 0, 0},
    {0, 7, 8, 0, 0, 0, 0, 0, 1},
    {0, 0, 4, 0, 1, 0, 0, 8, 0},
    {9, 0, 0, 8, 2, 3, 0, 0, 5},
    {0, 5, 0, 0, 9, 0, 6, 0, 0},
    {1, 3, 0, 0, 0, 0, 2, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 7, 4},
    {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    Solver s(v);
    SECTION("NOT ALLOWED VALUES")
    {
        REQUIRE(s.isPossible(1, 0, 6) == false);
        REQUIRE(s.isPossible(1,2,4) == false);
        REQUIRE(s.isPossible(0,4,6) == false);
        REQUIRE(s.isPossible(7,5,7) == false);
    }
    SECTION("ALLOWS PLACEMENT")
    {
        REQUIRE(s.isPossible(0,0,3) == true);
        REQUIRE(s.isPossible(0,1,1) == true);
    }
}
TEST_CASE("DIFFERENT CASES FOR THE SOLVER")
{
    SECTION("PUZZLE 1: HAS A SOLUTION ")
    {
            auto medium_test = std::vector<std::vector<int> >{ { 0, 9, 0, 0, 0, 0, 8, 5, 3 },
						   { 0, 0, 0, 8, 0, 0, 0, 0, 4 },
						   { 0, 0, 8, 2, 0, 3, 0, 6, 9 },
						   { 5, 7, 4, 0, 0, 2, 0, 0, 0 },
						   { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
						   { 0, 0, 0, 9, 0, 0, 6, 3, 7 },
						   { 9, 4, 0, 1, 0, 8, 5, 0, 0 },
						   { 7, 0, 0, 0, 0, 6, 0, 0, 0 },
						   { 6, 8, 2, 0, 0, 0, 0, 9, 0 } };
            Solver medium_solver(medium_test);
            REQUIRE(medium_solver.solver() == true);
            std::cout << medium_solver << "\n";
    }

    SECTION("TEST PUZZLE FROM NORVING: https://norvig.com/sudoku.html")
    {
        auto norvig_test = std::vector<std::vector<int> >(9, std::vector<int>(9,0));
        norvig_test[0][0] = 4;
        norvig_test[0][6] = 8;
        norvig_test[0][8] = 5;
        norvig_test[1][1] = 3;
        norvig_test[2][3] = 7;
        norvig_test[3][1] = 2;
        norvig_test[3][7] = 6;
        norvig_test[4][4] = 8;
        norvig_test[5][4] = 1;
        norvig_test[4][6] = 4;
        norvig_test[6][3] = 6;
        norvig_test[6][5] = 3;
        norvig_test[6][7] = 7;
        norvig_test[7][0] = 5;
        norvig_test[7][3] = 2;
        norvig_test[8][0] = 1;
        norvig_test[8][2] = 4;
        Solver norvig(norvig_test);
        REQUIRE(norvig.solver() == true);
        std::cout << norvig << std::endl;

    }
}
TEST_CASE("Testing the isValid function for the Sudoku solver") {
    SECTION("Empty") {
        std::vector< std::vector<int> > v{
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Solver s(v);
    REQUIRE_FALSE(s.isValid());
    }
    SECTION("Single Given") {
        std::vector< std::vector<int> > v{
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Solver s(v);
    REQUIRE_FALSE(s.isValid());
    }
    SECTION("Insufficient Givens") {
        std::vector< std::vector<int> > v{
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 0, 0, 9, 0},
    {0, 0, 4, 0, 0, 0, 0, 1, 0},
    {2, 0, 0, 0, 0, 3, 0, 5, 0},
    {0, 0, 0, 7, 0, 0, 0, 0, 0},
    {4, 3, 8, 0, 0, 0, 2, 0, 0},
    {0, 0, 0, 0, 9, 0, 0, 0, 0},
    {0, 1, 0, 4, 0, 0, 0, 6, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Solver s(v);
    REQUIRE_FALSE(s.isValid());
    }
    SECTION("Duplicate Given - Box") {
        std::vector< std::vector<int> > v{
    {0, 0, 9, 0, 7, 0, 0, 0, 5},
    {0, 0, 2, 1, 0, 0, 9, 0, 0},
    {1, 0, 0, 0, 2, 8, 0, 0, 0},
    {0, 7, 0, 0, 0, 5, 0, 0, 1},
    {0, 0, 8, 5, 1, 0, 0, 0, 0},
    {0, 5, 0, 0, 0, 0, 3, 0, 0},
    {0, 0, 0, 0, 0, 3, 0, 0, 6},
    {8, 0, 0, 0, 0, 0, 0, 0, 0},
    {2, 1, 0, 0, 0, 0, 0, 8, 7}
    };
    Solver s(v);
    REQUIRE_FALSE(s.isValid());
    }
    SECTION("Duplicate Given - Column") {
        std::vector< std::vector<int> > v{
    {6, 0, 1, 5, 9, 0, 0, 0, 0},
    {0, 9, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 4},
    {0, 7, 0, 3, 1, 4, 0, 0, 6},
    {0, 2, 4, 0, 1, 0, 0, 0, 5},
    {0, 0, 3, 0, 0, 0, 0, 1, 0},
    {0, 0, 6, 0, 0, 0, 0, 0, 3},
    {0, 0, 0, 9, 0, 2, 0, 4, 0},
    {0, 0, 0, 0, 0, 1, 6, 0, 0}
    };
    Solver s(v);
    REQUIRE_FALSE(s.isValid());
    }
    SECTION("Duplicate Given - Row") {
        std::vector< std::vector<int> > v{
    {0, 4, 0, 1, 0, 0, 3, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 2, 0, 5, 0, 0, 0},
    {0, 0, 0, 4, 0, 8, 9, 0, 0},
    {2, 6, 0, 0, 0, 0, 0, 1, 2},
    {0, 5, 0, 3, 0, 0, 0, 0, 7},
    {0, 0, 4, 0, 0, 0, 1, 6, 0},
    {6, 0, 0, 0, 0, 7, 0, 0, 0},
    {0, 1, 0, 0, 8, 0, 0, 2, 0}
    };
    Solver s(v);
    REQUIRE_FALSE(s.isValid());
    }
    SECTION("Unsolvable Square") {
        std::vector< std::vector<int> > v{
    {0, 0, 9, 0, 2, 8, 7, 0, 0},
    {8, 0, 6, 0, 0, 4, 0, 0, 5},
    {0, 0, 3, 0, 0, 0, 0, 0, 4},
    {6, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 2, 0, 7, 1, 3, 4, 5, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 2},
    {3, 0, 0, 0, 0, 0, 5, 0, 0},
    {9, 0, 0, 4, 0, 0, 8, 0, 7},
    {0, 0, 1, 2, 5, 0, 3, 0, 0}
    };
    Solver s(v);
    REQUIRE_FALSE(s.isValid());
    }
    SECTION("Unsolvable Box") {
        std::vector< std::vector<int> > v{
    {0, 9, 0, 3, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 8, 0, 0, 4, 6},
    {0, 0, 0, 0, 0, 0, 8, 0, 0},
    {4, 0, 5, 0, 6, 0, 0, 3, 0},
    {0, 0, 3, 2, 7, 5, 6, 0, 0},
    {0, 6, 0, 0, 1, 0, 9, 0, 4},
    {0, 0, 1, 0, 0, 0, 0, 0, 0},
    {5, 8, 0, 0, 2, 0, 0, 0, 0},
    {2, 0, 0, 0, 0, 7, 0, 6, 0}
    };
    Solver s(v);
    REQUIRE_FALSE(s.isValid());
    }
    SECTION("Unsolvable Column") {
        std::vector< std::vector<int> > v{
    {0, 0, 0, 0, 4, 1, 0, 0, 0},
    {0, 6, 0, 0, 0, 0, 0, 2, 0},
    {0, 0, 2, 0, 0, 0, 0, 0, 0},
    {3, 2, 0, 6, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 5, 0, 0, 4, 1},
    {7, 0, 0, 0, 0, 0, 0, 0, 2},
    {0, 0, 0, 0, 0, 0, 2, 3, 0},
    {0, 4, 8, 0, 0, 0, 0, 0, 0},
    {5, 0, 1, 0, 0, 2, 0, 0, 0}
    };
    Solver s(v);
    REQUIRE_FALSE(s.isValid());
    }
    SECTION("Unsolvable Row") {
        std::vector< std::vector<int> > v{
    {9, 0, 0, 1, 0, 0, 0, 0, 4},
    {0, 1, 4, 0, 3, 0, 8, 0, 0},
    {0, 0, 3, 0, 0, 0, 0, 9, 0},
    {0, 0, 0, 7, 0, 8, 0, 0, 1},
    {8, 0, 0, 0, 0, 3, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 3, 0},
    {0, 2, 1, 0, 0, 0, 0, 7, 0},
    {0, 0, 9, 0, 4, 0, 5, 0, 0},
    {5, 0, 0, 0, 1, 6, 0, 0, 3}
    };
    Solver s(v);
    REQUIRE_FALSE(s.isValid());
    }
    SECTION("Not Unique - 2 Solutions") {
        std::vector< std::vector<int> > v{
    {0, 3, 9, 0, 0, 0, 1, 2, 0},
    {0, 0, 0, 9, 0, 7, 0, 0, 0},
    {8, 0, 0, 4, 0, 1, 0, 0, 6},
    {0, 4, 2, 0, 0, 0, 7, 9, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 9, 1, 0, 0, 0, 5, 4, 0},
    {5, 0, 0, 1, 0, 9, 0, 0, 3},
    {0, 0, 0, 8, 0, 5, 0, 0, 0},
    {0, 1, 4, 0, 0, 0, 8, 7, 0}
    };
    Solver s(v);
    REQUIRE_FALSE(s.isValid());
    }
    SECTION("Not Unique - 3 Solutions") {
        std::vector< std::vector<int> > v{
    {0, 0, 3, 0, 0, 0, 0, 0, 6},
    {0, 0, 0, 9, 8, 0, 0, 2, 0},
    {9, 4, 2, 6, 0, 0, 7, 0, 0},
    {4, 5, 0, 0, 0, 6, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 9, 0, 5, 0, 4, 7, 0},
    {0, 0, 0, 0, 2, 5, 0, 4, 0},
    {6, 0, 0, 0, 7, 8, 5, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Solver s(v);
    REQUIRE_FALSE(s.isValid());
    }
    SECTION("Not Unique - 4 Solutions") {
        std::vector< std::vector<int> > v{
    {0, 0, 0, 0, 9, 0, 0, 0, 0},
    {6, 0, 0, 4, 0, 7, 0, 0, 8},
    {0, 4, 0, 8, 1, 2, 0, 3, 0},
    {7, 0, 0, 0, 0, 0, 0, 0, 5},
    {0, 0, 4, 0, 0, 0, 9, 0, 0},
    {5, 0, 0, 3, 7, 1, 0, 0, 4},
    {0, 5, 0, 0, 6, 0, 0, 4, 0},
    {2, 0, 1, 7, 0, 8, 5, 0, 9},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Solver s(v);
    REQUIRE_FALSE(s.isValid());
    }
    SECTION("Not Unique - 10 Solutions") {
        std::vector< std::vector<int> > v{
    {5, 9, 0, 0, 0, 0, 0, 4, 8},
    {6, 0, 8, 0, 0, 0, 3, 0, 7},
    {0, 0, 0, 2, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 4, 0, 0, 0, 0},
    {0, 7, 5, 3, 0, 6, 9, 8, 0},
    {0, 0, 0, 0, 9, 0, 0, 0, 0},
    {0, 0, 0, 8, 0, 3, 0, 0, 0},
    {2, 0, 6, 0, 0, 0, 7, 0, 9},
    {3, 4, 0, 0, 0, 0, 0, 6, 5}
    };
    Solver s(v);
    REQUIRE_FALSE(s.isValid());
    }
    SECTION("Not Unique - 125 Solutions") {
        std::vector< std::vector<int> > v{
    {0, 0, 0, 3, 1, 6, 5, 0, 0},
    {8, 0, 0, 5, 0, 0, 1, 0, 0},
    {0, 1, 0, 8, 9, 7, 2, 4, 0},
    {9, 0, 1, 0, 8, 5, 0, 2, 0},
    {0, 0, 0, 9, 0, 1, 0, 0, 0},
    {0, 4, 0, 2, 6, 3, 0, 0, 1},
    {0, 5, 0, 0, 0, 0, 0, 1, 0},
    {1, 0, 0, 4, 0, 9, 0, 0, 2},
    {0, 0, 6, 1, 0, 8, 0, 0, 0}
    };
    Solver s(v);
    REQUIRE_FALSE(s.isValid());
    }
    SECTION("Completed Puzzle") {
        std::vector< std::vector<int> > v{
    {9, 7, 4, 2, 3, 6, 1, 5, 8},
    {6, 3, 8, 5, 9, 1, 7, 4, 2},
    {1, 2, 5, 4, 8, 7, 9, 3, 6},
    {3, 1, 6, 7, 5, 4, 2, 8, 9},
    {7, 4, 2, 9, 1, 8, 5, 6, 3},
    {5, 8, 9, 3, 6, 2, 4, 1, 7},
    {8, 6, 7, 1, 2, 5, 3, 9, 4},
    {2, 5, 3, 6, 4, 9, 8, 7, 1},
    {4, 9, 1, 8, 7, 3, 6, 2, 5}
    };
    Solver s(v);
    REQUIRE(s.isValid());
    }
    SECTION("Last Empty Square") {
        std::vector< std::vector<int> > v{
    {9, 7, 4, 2, 3, 6, 1, 5, 8},
    {6, 3, 8, 5, 9, 1, 7, 4, 2},
    {1, 2, 5, 4, 8, 7, 9, 3, 6},
    {3, 1, 6, 7, 5, 4, 2, 8, 9},
    {7, 4, 2, 9, 0, 8, 5, 6, 3},
    {5, 8, 9, 3, 6, 2, 4, 1, 7},
    {8, 6, 7, 1, 2, 5, 3, 9, 4},
    {2, 5, 3, 6, 4, 9, 8, 7, 1},
    {4, 9, 1, 8, 7, 3, 6, 2, 5}
    };
    Solver s(v);
    REQUIRE(s.isValid());
    }
    SECTION("Naked Singles") {
         std::vector< std::vector<int> > v{
    {3, 0, 5, 4, 2, 0, 8, 1, 0},
    {4, 8, 7, 9, 0, 1, 5, 0, 6},
    {0, 2, 9, 0, 5, 6, 3, 7, 4},
    {8, 5, 0, 7, 9, 3, 0, 4, 1},
    {6, 1, 3, 2, 0, 8, 9, 5, 7},
    {0, 7, 4, 0, 6, 5, 2, 8, 0},
    {2, 4, 1, 3, 0, 9, 0, 6, 5},
    {5, 0, 8, 6, 7, 0, 1, 9, 2},
    {0, 9, 6, 5, 1, 2, 4, 0, 8}
    };
    Solver s(v);
    REQUIRE(s.isValid());
    }
    SECTION("Hidden Singles") {
        std::vector< std::vector<int> > v{
    {0, 0, 2, 0, 3, 0, 0, 0, 8},
    {0, 0, 0, 0, 0, 8, 0, 0, 0},
    {0, 3, 1, 0, 2, 0, 0, 0, 0},
    {0, 6, 0, 0, 5, 0, 2, 7, 0},
    {0, 1, 0, 0, 0, 0, 0, 5, 0},
    {2, 0, 4, 0, 6, 0, 0, 3, 1},
    {0, 0, 0, 0, 8, 0, 6, 0, 5},
    {0, 0, 0, 0, 0, 0, 0, 1, 3},
    {0, 0, 5, 3, 1, 0, 4, 0, 0}
    };
    Solver s(v);
    REQUIRE(s.isValid());
    }
}