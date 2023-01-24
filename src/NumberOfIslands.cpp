#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int no_of_elements{m*n}, islands{0};
        queue<int> search_queue;
        vector<int> checkedIds(no_of_elements, 0);
        int r{0},c{0}, rLocal{0}, cLocal{0}, checkId{0}, idNeighbour{0};
        
        for (int i{0}; i < no_of_elements; i++)
        {
            r = i/n;
            c = i%n;
            if (grid[r][c] == '1' && checkedIds[i] == 0)
            {
                // means this id is not visited, so consider it!
                search_queue.push(i);
                checkedIds[i] = 1;
                islands += 1;
            }

            while (!search_queue.empty())
            {
                checkId = search_queue.front();
                search_queue.pop();

                rLocal = checkId/n;
                cLocal = checkId%n;

                // check all four directions here:
                if ( cLocal > 0)
                {
                    // can check left
                    idNeighbour = (n)*(rLocal) + (cLocal-1);
                    if (checkedIds[idNeighbour] == 0)
                    {
                        checkedIds[idNeighbour] = 1;
                        if (grid[rLocal][cLocal-1] == '1')
                        {
                            search_queue.push(idNeighbour);
                        }
                    }
                }
                if ( cLocal < n-1)
                {
                    // can check right
                    idNeighbour = (n)*(rLocal) + (cLocal+1);
                    if (checkedIds[idNeighbour] == 0)
                    {
                        checkedIds[idNeighbour] = 1;
                        if (grid[rLocal][cLocal+1] == '1')
                        {
                            search_queue.push(idNeighbour);
                        }
                    }
                }
                
                if ( rLocal > 0)
                {
                    // can check up
                    idNeighbour = (n)*(rLocal-1) + (cLocal);
                    if (checkedIds[idNeighbour] == 0)
                    {
                        checkedIds[idNeighbour] = 1;
                        if (grid[rLocal-1][cLocal] == '1')
                        {
                            search_queue.push(idNeighbour);
                        }
                    }
                }
                if ( rLocal < m-1)
                {
                    // can check down
                    idNeighbour = (n)*(rLocal+1) + (cLocal);
                    if (checkedIds[idNeighbour] == 0)
                    {
                        checkedIds[idNeighbour] = 1;
                        if (grid[rLocal+1][cLocal] == '1')
                        {
                            search_queue.push(idNeighbour);
                        }
                    }
                }
            }
        }

        return islands;
    }
};


int main()
{
    vector<vector<char>> ex = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};

    Solution sol;
    cout<<sol.numIslands(ex)<<endl;
}