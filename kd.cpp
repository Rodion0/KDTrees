//--------------------------------------------------------------------
//				CS315-001  Assignment 3
//--------------------------------------------------------------------
// Author: Justin Hamilton
// Date: 3/30/21
// Description: KD Trees
// Assistance: We'll see
//--------------------------------------------------------------------
#include <vector>
#include <iostream>

//Node Class
//Wrap all things into k dimensional values

class node
{
private:
    int x;
    int y;

public:
    node(int value);
};

//KD Tree Class

class kdTree
{
private:
    std::vector<int> bucket;

public:
    kdTree(/* args */);
    //insert method
    void buildTree(std::vector<node> listOfPoints);
    //Search method
    int search(int probe);
    //Find Best Axis
};

//Main
int main(int argc, char const *argv[])
{

    std::vector<node> keeper;

    return 0;
}
