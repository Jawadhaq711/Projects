#include "solver.h"

int depth = 0;

Solver::Solver(std::vector<std::vector <int> > input)
{
    _board = input;
}

bool Solver::isPossible(int y, int x, int color)
{
    // check the row and column
    for(int i = 0; i < 9; ++i)
    {
        if(_board[i][x] == color || _board[y][i] == color)
        {
            return false;
        }
    }
    int corner_x = (x / 3) * 3;
    int corner_y = (y / 3) * 3;
    // check the 3x3 box
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            if(_board[corner_y + i][corner_x + j] == color) return false;
        }
    }
    return true;
}

bool Solver::isValid() {
    if (_board.size() != 9 || _board[0].size() != 9) {
        return false;
    }

    int count = 0;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (_board[i][j] != 0) {
          count++
        }
      }
    }
    if (count < 17) {
      return false;
    }

    std::vector <int> tl;
    std::vector <int> tm;
    std::vector <int> tr;
    std::vector <int> ml;
    std::vector <int> mm;
    std::vector <int> mr;
    std::vector <int> bl;
    std::vector <int> bm;
    std::vector <int> br;
    for(int i = 0; i < 9; ++i)
    {
        std::vector <int> v;
        std::vector <int> h;
        int hzero = 0;
        int vzero = 0;
        for(int j = 0; j < 9; ++j)
        {
            if (_board[i][j] < 0 || _board[i][j] > 9 || _board[j][i] < 0 || _board[j][i] > 9) {
                return false;
            }

            if (_board[i][j] == 0) {
              if (!(color(i, j))) {
                return false;
              }
            }

            for(int k = 0; k < v.size(); ++k)
            {
                if (_board[i][j] == v[k]) {
                    return false;
                }
            }

            for(int k = 0; k < h.size(); ++k)
            {
                if (_board[j][i] == h[k]) {
                    return false;
                }
            }

            if (_board[i][j] != 0) {
                v.push_back(_board[i][j]);
            }  else {
                vzero++;
            }

            if (_board[j][i] != 0) {
                h.push_back(_board[j][i]);
            } else {
                hzero++;
            }

            if (vzero > 8 || hzero > 8) {
                return false;
            }
        }
    }

    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        // top left box
        if (i >= 0 && i < 3 && j >= 0 && j < 3) {
          for(int k = 0; k < tl.size(); ++k)
          {
            if (_board[i][j] == tl[k]) {
              return false;
            }
          }
          if (_board[i][j] != 0) {
            tl.push_back(_board[i][j]);
          }
        }
        // top middle box
        if (i >= 0 && i < 3 && j >= 3 && j < 6) {
          for(int k = 0; k < tm.size(); ++k)
          {
            if (_board[i][j] == tm[k]) {
              return false;
            }
          }
          if (_board[i][j] != 0) {
            tm.push_back(_board[i][j]);
          }
        }
        // top right box
        if (i >= 0 && i < 3 && j >= 6 && j < 9) {
          for(int k = 0; k < tr.size(); ++k)
          {
            if (_board[i][j] == tr[k]) {
              return false;
            }
          }
          if (_board[i][j] != 0) {
            tr.push_back(_board[i][j]);
          }
        }
        // middle left box
        if (i >= 3 && i < 6 && j >= 0 && j < 3) {
          for(int k = 0; k < ml.size(); ++k)
          {
            if (_board[i][j] == ml[k]) {
              return false;
            }
          }
          if (_board[i][j] != 0) {
            ml.push_back(_board[i][j]);
          }
        }
        // middle middle box
        if (i >= 3 && i < 6 && j >= 3 && j < 6) {
          for(int k = 0; k < mm.size(); ++k)
          {
            if (_board[i][j] == mm[k]) {
              return false;
            }
          }
          if (_board[i][j] != 0) {
            mm.push_back(_board[i][j]);
          }
        }
        // middle right box
        if (i >= 3 && i < 6 && j >= 6 && j < 9) {
          for(int k = 0; k < mr.size(); ++k)
          {
            if (_board[i][j] == mr[k]) {
              return false;
            }
          }
          if (_board[i][j] != 0) {
            mr.push_back(_board[i][j]);
          }
        }
        // bottom left box
        if (i >= 6 && i < 9 && j >= 0 && j < 3) {
          for(int k = 0; k < bl.size(); ++k)
          {
            if (_board[i][j] == bl[k]) {
              return false;
            }
          }
          if (_board[i][j] != 0) {
            bl.push_back(_board[i][j]);
          }
        }
        // bottom middle box
        if (i >= 6 && i < 9 && j >= 3 && j < 6) {
          for(int k = 0; k < bm.size(); ++k)
          {
            if (_board[i][j] == bm[k]) {
              return false;
            }
          }
          if (_board[i][j] != 0) {
            bm.push_back(_board[i][j]);
          }
        }
        // bottom right box
        if (i >= 6 && i < 9 && j >= 6 && j < 9) {
          for(int k = 0; k < br.size(); ++k)
          {
            if (_board[i][j] == br[k]) {
              return false;
            }
          }
          if (_board[i][j] != 0) {
            br.push_back(_board[i][j]);
          }
        }
      }
    }
    return true;
} 

bool Solver::solver()
{
    depth++;
    // std::cout << "DEPTH: " << depth << "\n";
    // if(depth > 10) return true;
    for(int i = 0; i < 9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            if(_board[i][j] != 0) continue;
            // printf("Row %d, Column %d is 0 \n", i, j);
            bool did_color_work = color(i,j);
            if(did_color_work) return true;
            else return false;
        }
    }
    // std::cout << "REACHED THE TRUE STATE\n";
    std::cout << "DEPTH " << depth << "\n";
    return true; // no elements with a 0
}

bool Solver::color(int row, int col)
{
    for(int color = 1; color < 10; ++color)
    {
        // std::cout << isPossible(row, col, color) << " for " << color << "\n";
        if(!(isPossible(row, col, color))) continue;
        _board[row][col] = color;
        // std::cout << "CHANGED THE ELEMENT AT" << row << "," << col << "to be " << color << "\n";
        
        // std::cout << *this << std::endl;
        // std::cout << std::endl;
        bool valid_color = solver();
        if(!valid_color)
        {
            _board[row][col] = 0; // reset whatever color was set
            continue; // if the current color didn't work just try all of the others
        }
        return true; // the color worked
    }
    _board[row][col] = 0; // reset just in case? I don't think this is necessary though
    return false;
}

std::ostream& operator<<(std::ostream& os, const Solver& s)
{
    
    for(std::vector<int> row : s._board)
    {
        for(int i = 0; i < 9; ++i)
        {
            os << row[i] << " ";
            if(i % 3 == 2)
            {
                os << "| ";
            }
        }
        os << "\n------------------------\n";
    }
    return os;
}