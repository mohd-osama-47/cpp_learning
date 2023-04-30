#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>

using namespace std;

    int minJumps(vector<int>& arr) {
        if (arr.size() < 2) return 0;
        int ans{0}, goal = arr.size()-1;
        unordered_map<int, vector<int>> graph;
        unordered_map<int, vector<int>> repeatedVals;
        queue<pair<int, int>> q;
        int jumps;
        for (int i{0}; i < arr.size(); i++)
        {
            if (repeatedVals.find(arr[i]) == repeatedVals.end())
            {
                // first time meeting this value, populate it!
                // graph[arr[i]].push_back({i, -1});
                repeatedVals[arr[i]].push_back(i);
            }
            else
            {
                // update each instance of this repeated value to have the 
                // indices of the newly found repeated val
                repeatedVals[arr[i]].push_back(i);
                for (int index : repeatedVals[arr[i]])
                {
                    if (index == i) continue;
                    graph[i].push_back(index);
                    graph[index].push_back(i);
                }
            }
            if (i+1 < arr.size() && arr[i] != arr[i+1])
            {
                graph[i].push_back(i+1);
                q.push({i+1, jumps+1});
            }
            if (i-1 >= 0 && arr[i] != arr[i-1])
            {
                graph[i].push_back(i-1);
                q.push({i-1, jumps+1});
            }
        }

        // graph is now ready!
        // start a Breadth First Search (BFS) to find the answer...
        queue<pair<int, int>> q;
        vector<bool> history(arr.size(), false);
        history[0] = true;
        for (int id : graph[0])
        {
            q.push({id, 0});
        }


        while(!q.empty())
        {
            int curId = q.front().first;
            int jumps = q.front().second;
            q.pop();
            if (!history[curId])
            {
                // explore this node since it has not been visited.
                history[curId] = true;
                
                if (curId == goal)
                {
                    // stop here!
                    // cout<<"FOUND THE GOAL AT ID: "<<curId<<endl;
                    ans = jumps + 1;
                    break;
                }
                else
                {
                    // for (int next : graph[curId])
                    // {
                    //     if (next == goal) return jumps+2;
                    //     if (!history[next]) q.push({next, jumps+1});
                    // }
                    for (int i = graph[curId].size()-1; i > -1; i --)
                    {
                        if (graph[curId][i] == goal) return jumps+2;
                        if (!history[graph[curId][i]]) q.push({graph[curId][i], jumps+1});
                    }
                    graph[curId].clear();
                }
            }
        }

        return ans;
    }

int main()
{
    vector<int> ex{{100,-23,-23,404,100,23,23,23,3,404}};
    // vector<int> ex{{7}};
    // vector<int> ex{{7,6,9,6,9,6,9,7}};
    cout<<minJumps(ex);
}