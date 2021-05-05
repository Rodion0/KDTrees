//--------------------------------------------------------------------
//				CS315-001  Assignment 3
//--------------------------------------------------------------------
// Author: Justin Hamilton
// Date: 3/30/21
// Description: Create a k-dimensional tree and output search values
// Assistance: Tau Beta Pi Tutoring
//--------------------------------------------------------------------
#include <vector>
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

const int BUCKET_SIZE = 10;

//Node Class
class node
{
private:
public:
    std::vector<int> values;
    std::vector<node *> bucket;
    node *rightChild;
    node *leftChild;
    int largest_number;
    int index_of_largest_number;
    friend class kdTree;
    node();
    void insert(int value);
};

//--------------------------------------------------------------------------------------
//                                      node()
//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
node::node()
{
    rightChild = NULL;
    leftChild = NULL;
    largest_number = INT_MIN;
}

//--------------------------------------------------------------------------------------
//                                      insert()
//--------------------------------------------------------------------------------------
// Given: some int
// If int is larger than stored largest number then set the value to that
//--------------------------------------------------------------------------------------
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
    node *root;
    vector<int> dimensions;

public:
    kdTree();
    //Get root
    node *getRoot();
    //insert method
    node *buildTree(std::vector<node *> listOfPoints, node *current, int depth, int max_depth);
    //Search method
    void search(node *current, vector<node *> probes);
    //Find Best Dimension
    int findDimension(std::vector<node *> listOfPoints);
    //Find the Pivot Value using Lomuto's
    int findPivot(std::vector<node *> listOfPoints, int dimension);
    //Swap method
    void swap(std::vector<int> &values, int first, int second);
    //Quickeselct
    int quickSelect(std::vector<int> values, int low, int high, int index);
    //Lomuto's for Quickselect
    int lomuto(std::vector<int> values, int low, int high);
    node *travel(node *traveler, int depth);
};

//--------------------------------------------------------------------------------------
//                                      kdTree()
//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
kdTree::kdTree()
{
    root = NULL;
}
//--------------------------------------------------------------------------------------
//                                      getRoot()
//--------------------------------------------------------------------------------------
// Returns: root
//--------------------------------------------------------------------------------------
node *kdTree::getRoot()
{
    return root;
}
//--------------------------------------------------------------------------------------
//                                      quickSelect()
//--------------------------------------------------------------------------------------
// Given: vector of ints, some int, some int, some int
// Returns: value in values based on index
// Performs quickslect algorithim
//--------------------------------------------------------------------------------------
int kdTree::quickSelect(std::vector<int> values, int low, int high, int index)
{
    if (low == high)
    {
        return values[low];
    }
    int pivotIndex = lomuto(values, high, low);
    if (index == pivotIndex)
    {
        return values[index];
    }
    else if (index < pivotIndex)
    {
        return quickSelect(values, low, pivotIndex - 1, index);
    }
    else
    {
        return quickSelect(values, pivotIndex + 1, high, index);
    }
}
//--------------------------------------------------------------------------------------
//                                      lomuto()
//--------------------------------------------------------------------------------------
// Given: vector of ints, some int, some int
// Returns: int
// Does a partion based on lomuto's algorithim
//--------------------------------------------------------------------------------------
int kdTree::lomuto(std::vector<int> values, int high, int low)
{
    int pivotValue = values[high];
    int lowPointer = low;
    for (int i = low; i < high - 1; i++)
    {
        if (values[i] <= pivotValue)
        {
            swap(values, lowPointer, i);
            lowPointer++;
        }
    }
    swap(values, high, lowPointer);
    return lowPointer;
}
//--------------------------------------------------------------------------------------
//                                     swap()
//--------------------------------------------------------------------------------------
// Given: vector of ints, some int, some int
// Swaps the values at the given ints in the vector
//--------------------------------------------------------------------------------------
void kdTree::swap(std::vector<int> &values, int first, int second)
{
    int temp = values[first];
    values[first] = values[second];
    values[second] = temp;
}

//--------------------------------------------------------------------------------------
//                                      findDimension()
//--------------------------------------------------------------------------------------
// Given: vector of nodes
// Returns: dimension with greatest range
//--------------------------------------------------------------------------------------
int kdTree::findDimension(std::vector<node *> listOfPoints)
{
    int dim = 0, highest_number = INT_MIN;
    //Loop through all nodes
    for (int i = 0; i < listOfPoints.size(); i++)
    //Keep track of highest number and record its index in values array
    {
        if (listOfPoints[i]->index_of_largest_number > highest_number)
        {
            dim = listOfPoints[i]->index_of_largest_number;
        }
    }
    dimensions.push_back(dim);
    //return index
    return dim;
}
//--------------------------------------------------------------------------------------
//                                      findPivot()
//--------------------------------------------------------------------------------------
// Given: vector of nodes, some int
// Returns: median value in the vector
// Uses quickselect to find the median
//--------------------------------------------------------------------------------------
int kdTree::findPivot(std::vector<node *> listOfPoints, int dimension)
{
    int pivot;
    //Put all values at given dimension into vector
    vector<int> valuesAtDimension;
    for (int i = 0; i < listOfPoints.size(); i++)
    {
        valuesAtDimension.push_back(listOfPoints[i]->values[dimension]);
    }
    //Find median value of vector using Lomuto's
    pivot = quickSelect(valuesAtDimension, 0, valuesAtDimension.size(), valuesAtDimension.size() / 2);
    //return pivot
    return pivot;
}
//--------------------------------------------------------------------------------------
//                                      buildTree()
//--------------------------------------------------------------------------------------
// Given: vector of nodes, node, some int, some int
// Returns: node
// Builds kd tree according to a maximum depth from a given vector of nodes
//--------------------------------------------------------------------------------------
node *kdTree::buildTree(std::vector<node *> listOfPoints, node *current, int depth, int max_depth)
{
    if (listOfPoints.size() == 0)
    {
        return NULL;
    }
    if (depth == max_depth)
    {
        if (root == NULL)
        {
            root = current;
            return root;
        }
        current->bucket.push_back(current);
        return current;
    }
    vector<node *> smaller;
    vector<node *> larger;
    //Find best Dimension
    int dimension = findDimension(listOfPoints);
    //Find pivot
    int pivot = findPivot(listOfPoints, dimension);
    //Seperate based on pivot
    for (int i = 0; i < listOfPoints.size(); i++)
    {
        if (listOfPoints[i]->values[dimension] < pivot)
        {
            smaller.push_back(listOfPoints[i]);
        }
        else
        {
            larger.push_back(listOfPoints[i]);
        }
    }
    if (current->values[dimension] <= pivot)
    {
        current->leftChild = buildTree(smaller, current, depth + 1, max_depth);
    }
    else
    {
        current->rightChild = buildTree(larger, current, depth + 1, max_depth);
    }
}
//--------------------------------------------------------------------------------------
//                                      travel()
//--------------------------------------------------------------------------------------
// Given: some node, some int
// Returns: The node at bottom of the tree that is associted with temp
// Travels the tree according to set parameters
//--------------------------------------------------------------------------------------
node *kdTree::travel(node *traveler, int depth)
{
    node *temp = root;
    while (temp->leftChild != NULL && temp->rightChild != NULL)
    {
        if (temp->values[dimensions[depth]] < temp->leftChild->values[dimensions[depth]])
        {
            temp = temp->leftChild;
            depth++;
        }
        else
        {
            temp = temp->rightChild;
            depth++;
        }
    }
    return temp;
}
//--------------------------------------------------------------------------------------
//                                      search()
//--------------------------------------------------------------------------------------
// Given: some node, vector of nodes
// Searches tree and outputs bucket where probe would go in tree
//--------------------------------------------------------------------------------------
void kdTree::search(node *current, std::vector<node *> probes)
{
    node *temp = new node();
    for (int i = 0; i < probes.size(); i++)
    {
        temp = probes[i];
        int depth = 0;
        temp = travel(temp, depth);
        cout << "Probe ";
        for (auto i : temp->values)
        {
            cout << i << " ";
        }
        cout << " has " << temp->bucket.size() - 1 << " elements" << endl;
        for (int j = 0; j < temp->bucket.size(); i++)
        {
            for (int k = 0; k < temp->bucket[j]->values.size(); k++)
            {
                cout << temp->bucket[j]->values[k] << " ";
            }
            cout << endl;
        }
    }
}
//--------------------------------------------------------------------------------------
//                                      main()
//--------------------------------------------------------------------------------------
int main(int argc, char const *argv[])
{
    //Parameters
    int numOfDim = std::stoi(argv[1]), numOfData = std::stoi(argv[2]), numOfProbes = std::stoi(argv[3]), data;
    std::vector<node *> holding_cells;
    std::vector<node *> probes;
    kdTree tree = kdTree();

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
    int max_depth = floor(log2(float((holding_cells.size() + 1) / BUCKET_SIZE)));
    //Zero out holding cells
    //Build Trees with whats in holding
    for (int i = 0; i < holding_cells.size(); i++)
    {
        tree.buildTree(holding_cells, holding_cells[i], 0, max_depth);
    }
    holding_cells.resize(0);
    //Fill some nodes for Probing from input
    for (int i = 0; i < numOfProbes; i++)
    {
        node *temp = new node();
        for (int i = 0; i < numOfDim; i++)
        {
            std::cin >> data;
            temp->insert(data);
        }
        holding_cells.push_back(temp);
    }
    //Do the Search
    tree.search(tree.getRoot(), holding_cells);
    return 0;
}
