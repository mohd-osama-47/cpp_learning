#include <vector>
#include <stack>
#include <utility>

using namespace std;

class Solution {
public:
continuous
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int rows = heights.size();
        int cols = heights[0].size();

        // add the top right and bottom left corners as answers
        if (rows == 1)
        {
            return vector<vector<int>>{{0, cols-1}};
        }
        res.push_back({rows-1, 0});
        res.push_back({0, cols-1});
        
        for (int i{0}; i < rows; i++)
        {
            stack<pair<int, int>> searchStack;
            for (int j{0}; j < cols; j++)
            {
                searchStack.push(make_pair(i,j));
                while (!searchStack.empty())
                {
                    // start checking neighbours
                    if (searchStack.top().second < cols-1)
                    {
                        // can check right
                        if (heights[i][j+1] < heights[i][j])
                        {
                            // neighbour is LOWER, can proceed
                            searchStack.push(make_pair(i, j+1));
                        }
                    }
                    if (searchStack.top().second > 0)
                    {
                        // can check left
                        if (heights[i][j-1] < heights[i][j])
                        {
                            // neighbour is LOWER, can proceed
                            searchStack.push(make_pair(i, j-1));
                        }
                    }
                    if (searchStack.top().first < rows-1)
                    {
                        // can check down
                        if (heights[i+1][j] < heights[i][j])
                        {
                            // neighbour is LOWER, can proceed
                            searchStack.push(make_pair(i+1, j));
                        }
                    }
                    if (searchStack.top().first > 0)
                    {
                        // can check up
                        if (heights[i-1][j] < heights[i][j])
                        {
                            // neighbour is LOWER, can proceed
                            searchStack.push(make_pair(i-1, j));
                        }
                    }
                    searchStack.pop();
                }
            }
        }
        return res;
    }
};