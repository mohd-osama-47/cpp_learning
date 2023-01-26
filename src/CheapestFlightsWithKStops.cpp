#include <vector>
#include <unordered_map>
#include <iostream>

#define INF INT16_MAX

template <typename T> bool findInVec(std::vector<T>& array, T itemToFind)
{
    for(int i{0}; i < array.size(); i++){
        if(array[i] == itemToFind){
            return true;
        }
    }
    return false;

}

int getLowestNode(std::unordered_map<int, int>& costs, std::vector<int>& processed)
{
    int lowestCost{INF};
    int lowestCostNode{-1};

    for (std::unordered_map<int, int>::iterator itr{costs.begin()}; itr != costs.end(); itr++)
    {
        if (!findInVec<int>(processed, itr->first) && itr->second < lowestCost)
        {
            lowestCost = itr->second;
            lowestCostNode = itr->first;
        }
    }

    return lowestCostNode;
}

void printer(std::unordered_map<int,int> costs, std::unordered_map<int,int> parents, int src, int dst)
{
    // THE FOLLOWING ARE JUST PRINT STATEMENTS TO VISUALIZE THE RESULTS!
    std::cout<<"---------\n";
    std::cout<<"Node \tCost\n";
    std::cout<<"---------\n";
    for (std::unordered_map<int, int>::iterator itr{costs.begin()}; itr != costs.end(); itr++)
    {   
        // Print the wights of each path
        std::cout<<itr->first<<"\t"<<itr->second<<"\n";
    }

    std::cout<<"---------\n";
    std::cout<<"Node \tParent\n";
    std::cout<<"---------\n";
    for (std::unordered_map<int, int>::iterator itr{parents.begin()}; itr != parents.end(); itr++)
    {   
        // Print the each node and its parent
        std::cout<<itr->first<<"\t"<<itr->second<<"\n";
    }

    int curNode = parents[dst];
    std::cout<<"Most effective path to reach the final node is:\n";
    std::cout<<dst;
    while (curNode != src)
    {
        std::cout<<"<--"<<curNode;
        curNode = parents[curNode];
    }
    std::cout<<"<--start\n";
}

void tester(std::unordered_map<int, std::unordered_map<int, int>>& graph, int src, int dst, int k)
{
    // Test case 1
    // std::vector<std::vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};

    // Test case 2
    // std::vector<std::vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    // src = 0;
    // dst = 2;
    // k = 1;

    // Test case 3
    // std::vector<std::vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
    // src = 0;
    // dst = 2;
    // k = 0;

    // Test case 4
    // std::vector<std::vector<int>> flights = {{1,2,10},{2,0,7},{1,3,8},{4,0,10},{3,4,2},{4,2,10},{0,3,3},{3,1,6},{2,4,5}};
    // src = 0;
    // dst = 4;
    // k = 1;

    // Test case 5
    // std::vector<std::vector<int>> flights = {{0,1,2},{1,2,1},{2,0,10}};
    // src = 1;
    // dst = 2;
    // k = 1;

    // std::vector<std::vector<int>> flights = {{0,1,1},{0,2,5},{1,2,1},{2,3,1}};
    // src = 0;
    // dst = 3;
    // k = 1;



    // Generate the graph
    for (std::vector<int> connection : flights)
    {
        graph[connection[0]].insert({connection[1], connection[2]});
    }
    
    // holds all possible paths to reach dst in different k steps
    std::vector<std::vector<int>> paths_to_dst;

    std::unordered_map<int, int> costs;
    std::unordered_map<int, int> parents;

    std::unordered_map<int, std::unordered_map<int, int>>::iterator itr_g{graph.begin()};
    // Loop to generate the costs hash_map with all nodes having inf costs for now
    for (itr_g; itr_g != graph.end(); itr_g++)
    {
        if (itr_g->first != src)
        {
            costs[itr_g->first] = INF;
            // Set the parent of said node to be empty since we do not know the parent yet.
            parents[itr_g->first] = -1;
        }
        else
        {
            // Check the start node's children and set their parent to be start in the parents hashmap
            for (std::unordered_map<int, int>::iterator itr{itr_g->second.begin()}; itr != itr_g->second.end(); itr++)
            {
                parents[itr->first] = src;
            }
        }
    }
    costs[dst] = INF;
    // Set the parent of src to be empty since we do not know the parent yet.
    parents[dst] = -1;

    // Graph, costs, and parents are now set and ready for Dijkstra's!
    std::unordered_map<std::string, int>::iterator itr{};
    // Update the costs hash_map to only have finite costs for nodes directly connected to start
    for (std::unordered_map<int, int>::iterator itr{graph[src].begin()}; itr != graph[src].end(); itr++)
    {
        parents[itr->first] = src;
        costs[itr->first] = itr->second;
        if (itr->first == dst)
        {
            int tempNode = parents[dst];
            std::vector<int> path;
            path.push_back(src);
            while (tempNode != src)
            {
                // path.push_back(tempNode);
                tempNode = parents[tempNode];
            }
            path.push_back(costs[dst]);
            paths_to_dst.push_back(path);
        }
    }

    std::vector<int> processed;
    std::unordered_map<int, int> neighbours;
    int curCost;

    int curNode{getLowestNode(costs, processed)};
    while (curNode != -1)
    {
        curCost = costs[curNode];
        neighbours = graph[curNode];

        for (std::unordered_map<int, int>::iterator itr{neighbours.begin()}; itr != neighbours.end(); itr++)
        {
            int newCost{curCost + itr->second};
            if (newCost < costs[itr->first])
            {
                costs[itr->first] = newCost;
                parents[itr->first] = curNode;
                if (itr->first == dst)
                {
                    int tempNode = parents[dst];
                    std::vector<int> path;
                    path.push_back(src);
                    while (tempNode != src)
                    {
                        path.push_back(tempNode);
                        tempNode = parents[tempNode];
                    }
                    path.push_back(costs[dst]);
                    paths_to_dst.push_back(path);
                }
            }
        }
        processed.push_back(curNode);
        curNode = getLowestNode(costs, processed);
    }

    for (std::vector<int> path : paths_to_dst)
    {   
        std::cout<<"FOR A BATH OF SIZE "<<path.size()<<"\n";
        for (int node : path)
        {
            std::cout<<node<<" ";
        }
        std::cout<<std::endl;
    }
    // printer(costs, parents, src, dst);

}


int main()
{
    std::unordered_map<int, std::unordered_map<int, int>> graph;
    tester(graph, 0, 3, 1);
    return 0;
}