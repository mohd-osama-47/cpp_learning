#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.size() < 2)
        {
            res.push_back(vector<string>{{s[0]}});
            return res;
        }


        return res;

    }
};


int main ()
{
    Solution sol;
    string ex1{"aab"};  // ans: {{"a", "a", "b"}, {"aa", "b"}}
    string ex2{"a"};    // ans: {{"a"}}
    
    vector<vector<string>> ans{sol.partition(ex2)};
    for (vector<string> vec : ans)
    {
        for (string str : vec)
        {
            cout<<str<<"\n";
        }
    }
}