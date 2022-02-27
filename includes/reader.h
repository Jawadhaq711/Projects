#ifndef READER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Reader 
{
    std::string _filename;
    std::vector<std::vector<int> > v;

    public:

        void read();

};


#endif 