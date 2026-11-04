
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// struct representing a coordinate in our matrix
struct node_t {
    int row = 0, col = 0;
};

int directions[4][2] = {{1,0},   // North
                        {-1,0},  // South
                        {0,1},   // East
                        {0,-1}}; // West


void
BFS_visitor (vector<vector<int> > & matrix, int num_rows, int num_cols, int start_row, int start_col)
{
    //Create a queue and populate with first coordinate
    queue<node_t> to_visit;
    to_visit.push({start_row, start_col});
    matrix[start_row][start_col] = 0;

    while (!to_visit.empty())
    {
        node_t current_node = to_visit.front();
        to_visit.pop();

        for (auto dir : directions)
        {
            int new_row = current_node.row + dir[0];
            int new_col = current_node.col + dir[1];

            if (new_row >= 0 && new_row < num_rows  &&   // <- if the new coordinates are within the boundaries of the matrix
                new_col >= 0 && new_col < num_cols &&    //    and the value is 1 (island), add it to the queue to visit  
                matrix[new_row][new_col] == 1)
            {
                to_visit.push({new_row,new_col});
                matrix[new_row][new_col] = 0;    
            }
        }
    }
}

int
count_islands (vector<vector<int> > matrix)
{
    int num_islands = 0;
    size_t rows = matrix.size();
    size_t cols = rows ? matrix[0].size : 0;


    for (int i = 0; i <= rows; ++i) {
        for (int j = 0; j <= rows; ++j) {

    }

}







#include <vector>
#include <queue>

class IslandCounter {

private:
    
    struct node_t
    {
        int row;
        int col;
    };

    int[4][2] directions = { {1, 0},    //North
                             {-1, 0},   //South
                             {0, 1},    //East
                             {0, -1} }; //West


    // Function that will do a breadth-first search on a matrix and replace all
    // connected 0s with 1s
    void BFS_visitior(std::vector<std::vector<int> > matrix, int startRow, int startCol, int numRows, int numCols) {

        // Keep a queue of nodes to visit and populate it with our starting node
        queue<node_t> toVisit;
        toVisit.push({startRow,startCol});
        matrix[startRow][startCol] = 0;


        while (!toVisit.isEmpty()) {
            // Get the next node to visit and remove it from the queue
            node_t currentNode = toVisit.front();
            toVisit.pop();
            
            for (auto dir : directions) {

                int newRow = currentNode.row + dir[0];
                int newCol = currentNode.col + dir[1];

                // If the next row is within our matrix and its value is 1, add it to our queue
                if (newRow >= 0 && newRow < numRows &&
                    newCol >= 0 && newCol < numCols &&
                    matrix[newRow][newCol] == 1) {

                    // Add the new node to the queue and set it to water
                    toVisit.push({newRow,newCol}); 
                    matrix[newRow][newCol] = 0;
                }
            }
        }


    }

};
