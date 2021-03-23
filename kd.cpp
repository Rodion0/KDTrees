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
//Wrap all things into k dimensional pairs
class node
{
private:
    std::vector<int> values;
    node *rightChild;
    node *leftChild;

public:
    friend class kdTree;
    node(int value);
};

node::node(int value)
{
    values.push_back(value);
}

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
    int search(node *current, int probe);
    //Find Best Axis
    int findDimension(std::vector<node> listOfPoints);
    //Find the Pivot Value
    int findPivot(std::vector<node> listOfPoints, int index);
};

//Find Max in list of nodes
int kdTree::findDimension(std::vector<node> listOfPoints)
{
    int dim;
    //Loop through all nodes and insert maxes into maxes
    //Find max element, set equal to iter
    //return iter - listOfPoints.begin()
    return dim;
}

int kdTree::findPivot(std::vector<node> listOfPoints, int index)
{
    int pivot;
    //Put all values at given index into vector
    //Find median value of vector using Lomuto's
    //return pivot
    return pivot;
}

void kdTree::buildTree(std::vector<node> listOfPoints)
{
    //Find best Dimension
    //Find pivot
    //Seperate based on pivot
    //Recuse until bucket is filled
}

//Main
int main(int argc, char const *argv[])
{
    //Parameters

    std::vector<node> keeper;

    return 0;
}
