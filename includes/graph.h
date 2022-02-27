#include <list>
#include <vector>
#include <pair>
#include <map>



struct Graph 
{
    std::map<std::pair<int,int>, std::list<std::pair<int,int> > _adj;
    std::vector< std::vector<int>> _puzzle;
    const std::vector<int> colors{1,2,3,4,5,6,7,8,9};
    
    Graph();
    void initRow();
    void initCol();

};