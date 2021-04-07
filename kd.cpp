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
#include <cmath>

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
    int index_of_largest_number;

public:
    friend class kdTree;
    node();
    void insert(int value);
};

node::node()
{
    rightChild = NULL;
    leftChild = NULL;
    largest_number = INT_MIN;
}

void node::insert(int value)
{
    if (value > largest_number)
    {
        largest_number = value;
        index_of_largest_number = values.size() - 1;
    }
    values.push_back(value);
}

//KD Tree Class

class kdTree
{
private:
    std::vector<int> bucket;
    node *root;

public:
    kdTree();
    //Get root
    node *getRoot();
    //insert method
    kdTree *buildTree(std::vector<node *> listOfPoints);
    //Search method
    int search(node *current, std::vector<node *> listOfProbes);
    //Find Best Dimension
    int findDimension(std::vector<node *> listOfPoints);
    //Find the Pivot Value using Lomuto's
    int findPivot(std::vector<node *> listOfPoints, int dimension);
    //Fill the Buckets
};

//Get Root
node *kdTree::getRoot()
{
    return root;
}

//Find Max in list of nodes
int kdTree::findDimension(std::vector<node *> listOfPoints)
{
    int dim, highest_number = INT_MIN;
    //Loop through all nodes
    for (int i = 0; i < listOfPoints.size(); i++)
    //Keep track of highest number and record its index in values array
    {
        if (listOfPoints[i]->index_of_largest_number > highest_number)
        {
            dim = listOfPoints[i]->index_of_largest_number;
        }
    }
    //return index
    return dim;
}

int kdTree::findPivot(std::vector<node *> listOfPoints, int dimension)
{
    int pivot;
    //Put all values at given dimension into vector
    //Find median value of vector using Lomuto's
    //https://gist.github.com/hmenn/79bc66d660cc1dbc1f6f8db319275cd6
    //return pivot
    return pivot;
}

kdTree *kdTree::buildTree(std::vector<node *> listOfPoints)
{

    //Find best Dimension
    int dimension = findDimension(listOfPoints);
    //Find pivot
    int pivot = findPivot(listOfPoints, dimension);
    //Seperate based on pivot

    //Recuse until bucket is filled (size 10)
}

int kdTree::search(node *current, std::vector<node *> probes)
{
    //For All probes in Probes vector
    //Put into Tree
    //List all numbers in bucket
}

//Main
int main(int argc, char const *argv[])
{
    //Parameters
    int numOfDim = std::stoi(argv[1]), numOfData = std::stoi(argv[2]), numOfProbes = std::stoi(argv[3]), data;
    std::vector<node *> holding_cells;
    std::vector<node *> probes;
    kdTree *tree;

    //Fill Up Nodes/Store in Holding
    //Use Nested For Loops
    for (int i = 0; i < numOfData; i++)
    {
        node *temp = new node();
        for (int i = 0; i < numOfDim; i++)
        {
            std::cin >> data;
            temp->insert(data);
        }
        holding_cells.push_back(temp);
    }

    //Build Trees with whats in holding
    tree = tree->buildTree(holding_cells);
    //Fill some nodes for Probing from input
    for (int i = 0; i < numOfProbes; i++)
    {
        node *temp = new node();
        for (int i = 0; i < numOfDim; i++)
        {
            std::cin >> data;
            temp->insert(data);
        }
        probes.push_back(temp);
    }
    //Do the Search
    tree->search(tree->getRoot(), probes);
    return 0;
}
