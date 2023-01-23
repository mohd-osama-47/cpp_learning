#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

#define INF INT32_MAX

template <typename T> bool findInVec(std::vector<T>& array, T itemToFind)
{
    for(int i{0}; i < array.size(); i++){
        if(array[i] == itemToFind){
            return true;
        }
    }
    return false;

}

std::string getLowestNode(std::unordered_map<std::string, int>& costs, std::vector<std::string>& processed)
{
    int lowestCost{INF};
    std::string lowestCostNode{""};

    for (std::unordered_map<std::string, int>::iterator itr{costs.begin()}; itr != costs.end(); itr++)
    {
        if (!findInVec<std::string>(processed, itr->first) && itr->second < lowestCost)
        {
            lowestCost = itr->second;
            lowestCostNode = itr->first;
        }
    }

    return lowestCostNode;
}

int main()
{

    // Create a graph containing nodes and neighbours. Each value is a hashmap showing the vertices and their respective weights
    // std::unordered_map<std::string, std::unordered_map<std::string, int>> graph{
    //     {"start", {{"a", 6}, {"b", 2}}},
    //     {"a", {{"fin", 1}}},
    //     {"b", {{"a", 3}, {"fin", 5}}},
    //     {"fin", {{}}},
    // };

    std::unordered_map<std::string, std::unordered_map<std::string, int>> graph{
        {"start", {{"b", 4}, {"c", 2}}},
        {"b", {{"c", 3}, {"d",2}, {"e",3}}},
        {"c", {{"b", 1}, {"d", 4}, {"e",5}}},
        {"e", {{"fin", 1}}},
        {"fin", {{}}}
    };

    // std::unordered_map<std::string, std::unordered_map<std::string, int>> graph{
    //     {"start", {{"a", 5}, {"b", 2}}},
    //     {"a", {{"c", 4}, {"d", 2}}},
    //     {"b", {{"a", 8}, {"d",7}}},
    //     {"c", {{"d", 6}, {"fin", 3}}},
    //     {"d", {{"fin",1}}},
    //     {"fin", {{}}},
    // };
    // std::unordered_map<std::string, std::string> parents{
    //     {"a","start"},
    //     {"b","start"},
    //     {"fin",""}
    // };
    std::unordered_map<std::string, std::string> parents;

    std::unordered_map<std::string, int> costs;
    std::unordered_map<std::string, std::unordered_map<std::string, int>>::iterator itr_g{graph.begin()};
    // Loop to generate the costs hash_map with all nodes having ing costs for now
    for (itr_g; itr_g != graph.end(); itr_g++)
    {
        if (itr_g->first !="start")
        {
            costs[itr_g->first] = INF;
            // Set the parent of said node to be empty since we do not know the parent yet.
            parents[itr_g->first] = "";
        }
        else
        {
            // Check the start node's children and set their parent to be start in the parents hashmap
            for (std::unordered_map<std::string, int>::iterator itr{itr_g->second.begin()}; itr != itr_g->second.end(); itr++)
            {
                parents[itr->first] = "start";
            }
        }
    }

    // std::unordered_map<std::string, int> costs{
    //     {"a",6},
    //     {"b",2},
    //     {"fin",INF}
    // };
    std::unordered_map<std::string, int>::iterator itr{graph["start"].begin()};
    // Update the costs hash_map to only have finite costs for nodes directly connected to start
    for (itr; itr != graph["start"].end(); itr++)
    {
        costs[itr->first] = itr->second;
    }

    std::vector<std::string> processed;
    std::unordered_map<std::string, int> neighbours;
    int curCost;

    std::string curNode{getLowestNode(costs, processed)};
    while (curNode != "")
    {
        curCost = costs[curNode];
        neighbours = graph[curNode];

        for (std::unordered_map<std::string, int>::iterator itr{neighbours.begin()}; itr != neighbours.end(); itr++)
        {
            int newCost{curCost + itr->second};
            if (newCost < costs[itr->first])
            {
                costs[itr->first] = newCost;
                parents[itr->first] = curNode;
            }
        }
        processed.push_back(curNode);
        curNode = getLowestNode(costs, processed);
    }



    // THE FOLLOWING ARE JUST PRINT STATEMENTS TO VISUALIZE THE RESULTS!
    std::cout<<"---------\n";
    std::cout<<"Node \tCost\n";
    std::cout<<"---------\n";
    for (std::unordered_map<std::string, int>::iterator itr{costs.begin()}; itr != costs.end(); itr++)
    {   
        // Print the wights of each path
        std::cout<<itr->first<<"\t"<<itr->second<<"\n";
    }

    std::cout<<"---------\n";
    std::cout<<"Node \tParent\n";
    std::cout<<"---------\n";
    for (std::unordered_map<std::string, std::string>::iterator itr{parents.begin()}; itr != parents.end(); itr++)
    {   
        // Print the each node and its parent
        std::cout<<itr->first<<"\t"<<itr->second<<"\n";
    }

    curNode = parents["fin"];
    std::cout<<"Most effective path to reach the final node is:\n";
    std::cout<<"fin";
    while (curNode != "start")
    {
        std::cout<<"<--"<<curNode;
        curNode = parents[curNode];
    }
    std::cout<<"<--start\n";

}