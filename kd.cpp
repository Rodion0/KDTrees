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
#include <climits>

const int BUCKET_SIZE = 10;

//Node Class
//Wrap all things into k dimensional pairs
class node
{
private:
    std::vector<int> values;
    node *rightChild;
    node *leftChild;
    int largest_number;

public:
    friend class kdTree;
    node();
    node(int value);
};

node::node()
{
    rightChild = NULL;
    leftChild = NULL;
    largest_number = INT_MIN;
}

node::node(int value)
{
    if (value > largest_number)
    {
        largest_number = value;
    }
    values.push_back(value);
}

//KD Tree Class

class kdTree
{
private:
    std::vector<int> bucket;

public:
    kdTree();
    //insert method
    void buildTree(std::vector<node> listOfPoints);
    //Search method
    int search(node *current, int probe);
    //Find Best Dimension
    int findDimension(std::vector<node> listOfPoints);
    //Find the Pivot Value using Lomuto's
    int findPivot(std::vector<node> listOfPoints, int dimension);
};

//Find Max in list of nodes
int kdTree::findDimension(std::vector<node> listOfPoints)
{
    int dim;
    //Loop through all nodes and insert maxes into maxes
    //When inserting into max array keep track of index of largest_max
    //If max is bigger than largest_max then change index
    //return index
    return dim;
}

int kdTree::findPivot(std::vector<node> listOfPoints, int dimension)
{
    int pivot;
    //Put all values at given dimension into vector
    //Find median value of vector using Lomuto's
    //https://gist.github.com/hmenn/79bc66d660cc1dbc1f6f8db319275cd6
    //return pivot
    return pivot;
}

void kdTree::buildTree(std::vector<node> listOfPoints)
{
    //Find best Dimension
    //Find pivot
    //Seperate based on pivot
    //Recuse until bucket is filled (size 10)
}

//Main
int main(int argc, char const *argv[])
{
    //Parameters
    int numOfDim = std::stoi(argv[1]), numOfData = std::stoi(argv[2]), numOfProbes = std::stoi(argv[3]);
    std::vector<node> holding_cells;
    std::vector<node> probes;

    //Fill Up Nodes/Store in Holding
    //Use Nested For Loops
    //Build Trees with whats in holding
    //Fill some nodes for Probing from input
    //Do the Search

    return 0;
}
