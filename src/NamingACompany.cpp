#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;
long long distinctNames(vector<string>& ideas) 
{
        unordered_map<string, int> ideasMap;
        for (string idea : ideas)
        {
            ideasMap[idea]++;
        }
        int start{0}, end{0}, count{0};

        while (start < ideas.size()-1)
        {
            end++;
            if (end > ideas.size()-1)
            {
                start++;
                end = start + 1;
            }
            if (start >= ideas.size()-1)
            {
                break;
            }
            string idea1 = "" + ideas[end].substr(0,1);
            idea1 += ideas[start].substr(1, ideas[start].size()-1);
            if (ideasMap.find(idea1) != ideasMap.end())
            {
                //means the name ALREADY exists
                continue;
            }
            string idea2 = "" + ideas[start].substr(0,1);
            idea2 += ideas[end].substr(1, ideas[end].size()-1);
            if (ideasMap.find(idea2) != ideasMap.end())
            {
                //means the name ALREADY exists
                continue;
            }
            count+=2;
        }
        
        return count;
}

int main()
{
    vector<string> ex{{"coffee","donuts","time","toffee"}};
    cout<<distinctNames(ex)<<endl;
    return 0;
}



class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        sort(ideas.begin(), ideas.end());
        map<char, vector<string>> preMap;
        for (string idea : ideas)
        {
            preMap[idea[0]].push_back(idea.substr((1, idea.size()-1)));
        }
        cout<<"SIZE OF MAP TO ITERATE OVER: "<<preMap.size()<<endl;
        int count{0};
        for (map<char, vector<string>>::iterator key1{preMap.begin()}; key1 != preMap.end(); key1++)
        {
            cout<<"STARTING WITH SET: "<<key1->first<<" OF SIZE "<<key1->second.size()<<endl;
            for (map<char, vector<string>>::iterator key2 = next(key1); key2 != preMap.end(); key2++)
            {
                // if (key2->first == key1->first) continue;
                cout<<"COMPARING LETTERS: "<<key1->first<<" (size: "<<key1->second.size()<<") & "<<key2->first<<"(size: "<<key2->second.size()<<")\n";
                vector<string> intersect;
                sort(key1->second.begin(), key1->second.end());
                sort(key2->second.begin(), key2->second.end());
                set_intersection(key1->second.begin(),key1->second.end(),key2->second.begin(),key2->second.end(),std::inserter(intersect,intersect.begin()));
                cout<<"INTERSECTION SIZE IS "<<intersect.size()<<endl;
                if (intersect.size() >= min(key1->second.size(), key2->second.size())) 
                {
                    cout<<"INTERSECTION TOO BIG! CANCEL!"<<endl;
                    break;
                }
                if (key1->second.size() > key2->second.size())
                {
                    count += (key1->second.size() - intersect.size()) * (key2->second.size()) * 2;
                }
                else
                {
                    count += (key1->second.size()) * (key2->second.size()- intersect.size()) * 2;
                }
            }
        }
        return count;
    }
};