#include <queue>
#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>


template <typename T> bool findInVec(std::vector<T>& array, T& itemToFind)
{
    for(int i{0}; i < array.size(); i++){
        if(array[i] == itemToFind){
            return true;
        }
    }
    return false;

}

bool isSeller(std::string& name)
{
    return (*(name.end()-1) == 'm') ? true : false ;
}

int main()
{
    std::unordered_map<std::string, std::vector<std::string>> graph{
        {"you", {"alice", "bob", "claire"}},
        {"bob", {"anuj", "peggy"}},
        {"alice", {"peggy"}},
        {"claire", {"thom", "jonny"}},
        {"anuj", {}},
        {"peggy", {}},
        {"thom", {}},
        {"jonny", {}},
    };

    std::queue<std::string> search_queue;
    for (std::string names : graph["you"])
    {
        search_queue.push(names);
    }

    std::string person, lastParent;
    std::vector<std::string> visitHistory;
    
    while (!search_queue.empty())
    {
        person = search_queue.front();
        search_queue.pop();
        if (!findInVec<std::string>(visitHistory, person))
        {
            visitHistory.push_back(person);
            if (isSeller(person))
            {
                std::cout<<person<<" is a mango seller!\n"<<"Parent node is: "<<lastParent<<"\n";
                return 0;
            }
            else
            {
                if (graph[person].size() >= 1) lastParent = person;
                for (std::string names : graph[person])
                {
                    search_queue.push(names);
                }
            }
        }
    }
    std::cout<<"NO MANGO SELLER FOUND!\n";
    return 0;
}