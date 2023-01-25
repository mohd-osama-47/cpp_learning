/**
 * @file CoverStatesGreedy.cpp
 * @author Mohammed Osama
 * @brief covers Chapter 8's set-covering problem from the book "Grokking Algorithms"
 * @version 0.1
 * @date 2023-01-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main()
{
    // std::string states_needed[8] = {"mt", "wa", "or", "id", "nv", "ut", "ca", "az"};
    std::set<std::string> states_needed = {"mt", "wa", "or", "id", "nv", "ut", "ca", "az"}, final_stations;
    std::unordered_map<std::string, std::set<std::string>> stations{
        {"kone"   , {"id", "nv", "ut"}},
        {"ktwo"   , {"wa", "id", "mt"}},
        {"kthree" , {"or", "nv", "ca"}},
        {"kfour"  , {"nv", "ut"}      },
        {"kfive"  , {"ca", "az"}      },
    };

    std::string best_station{""};
    std::set<std::string> covered_states{}, curCovered{};

    while (states_needed.size() != 0)
    {
        best_station = "";
        curCovered = {};
        covered_states = {};
        for (std::unordered_map<std::string, std::set<std::string>>::iterator itr{stations.begin()}; itr != stations.end(); itr++)
        {
            std::set_intersection(states_needed.begin(), states_needed.end(), itr->second.begin(), itr->second.end(), std::inserter(curCovered, curCovered.begin()));

            if (curCovered.size() > covered_states.size())
            {
                best_station = itr->first;
                covered_states = curCovered;
                // states_needed.erase(covered_states.begin(), covered_states.end());
                for (std::string state : covered_states)
                {
                    states_needed.erase(state);
                }
                final_stations.insert(best_station);
            }
        }
    }
    
    std::cout << "FINAL STATIONS TO CONSIDER ARE:\n";
    for (std::string station : final_stations)
    {
        std::cout<<station<<" ";
    }
}