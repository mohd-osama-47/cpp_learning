#include <vector>
#include <iostream>
#include <queue>

#define INF INT16_MAX

using namespace std;



class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create an adjacency matrix representing the graph
        // index is the node, pairs in said index are its neighbours (id , weight)
        vector<pair<int,int>> adjacencyMtx[n];

        for (vector<int> flight : flights)
        {
            adjacencyMtx[flight[0]].push_back({flight[1], flight[2]});
        }

        // Generate a queue to represent the order at which the nodes will be visited, starting with src
        // {amount of steps taken/stops, {neighbour node, weight to neighbour}}
        queue<pair<int, pair<int,int>>> nodeQueue;

        // Costs vector representing the weights of paths leading to each node (initialized to INF util updates)
        vector<int> costs(n, INF);

        nodeQueue.push({0, {src, 0}});
        costs[src] = 0;

        while (!nodeQueue.empty())
        {
            int steps{nodeQueue.front().first};
            int curNode{nodeQueue.front().second.first};
            int curNodeCost{nodeQueue.front().second.second};
            nodeQueue.pop();

            if (steps > k){
                // current node you are visiting is OUTSIDE the allowed stepping range of k
                continue;
            }

            // Next, start checking curNode's connected neighbours and update their costs.
            // Also, add new nodes to the queue to continue the search for dst. 
            for (pair<int, int> nextNodes : adjacencyMtx[curNode])
            {

                int nextConnectedNode{nextNodes.first};
                int nextConnectedCost{nextNodes.second};

                // Update cost if the current one is lower than the previously computed cost
                // and only do that if you are within the allowed amount of steps.
                if (costs[nextConnectedNode] > (curNodeCost + nextConnectedCost) && steps <=k)
                {
                    costs[nextConnectedNode] = curNodeCost + nextConnectedCost;
                    nodeQueue.push({steps+1, {nextConnectedNode, costs[nextConnectedNode]}});
                }

            }
        }

        return (costs[dst] == INF)? -1 : costs[dst];
    }
};

int main()
{
    Solution sol;
    
    std::vector<std::vector<int>> flights1 = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    int src{0}, dst{3}, k{1}, n{4};
    sol.findCheapestPrice(n, flights1, src, dst, k);
    
    std::vector<std::vector<int>> flights2 = {{0,1,100},{1,2,100},{0,2,500}};
    n = 3;
    src = 0;
    dst = 2;
    k = 1;
    sol.findCheapestPrice(n, flights2, src, dst, k);

    
    std::vector<std::vector<int>> flights3 = {{0,1,100},{1,2,100},{0,2,500}};
    n = 3;
    src = 0;
    dst = 2;
    k = 0;
    sol.findCheapestPrice(n, flights3, src, dst, k);

    
    std::vector<std::vector<int>> flights4 = {{1,2,10},{2,0,7},{1,3,8},{4,0,10},{3,4,2},{4,2,10},{0,3,3},{3,1,6},{2,4,5}};
    n = 5;
    src = 0;
    dst = 4;
    k = 1;
    sol.findCheapestPrice(n, flights4, src, dst, k);

    
    std::vector<std::vector<int>> flights5 = {{0,1,2},{1,2,1},{2,0,10}};
    n = 3;
    src = 1;
    dst = 2;
    k = 1;
    sol.findCheapestPrice(n, flights5, src, dst, k);

    std::vector<std::vector<int>> flights6 = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    n = 3;
    src = 0;
    dst = 3;
    k = 1;
    sol.findCheapestPrice(n, flights6, src, dst, k);
}