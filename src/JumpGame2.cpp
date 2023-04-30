#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        if (n < 2) return 0;
        vector<int> visitHistory(n,0);
        queue<pair<int,int>> searchQueue;
        int jumps = 0, minJumps = 3200;
        // pair represents index and jumps taken to reach this index
        searchQueue.push(make_pair(0, 0));
        pair<int, int> curId;
        while (!searchQueue.empty())
        {
            curId = searchQueue.front();
            searchQueue.pop();
            if (visitHistory[curId.first] < 1)
            {
                //not visited yet!
                jumps = curId.second;
                visitHistory[curId.first] = 1;
                if (curId.first < n-1)
                {
                    for (int i = min(nums[curId.first], n-2); i > 0; i--)
                    {   
                        if (curId.first+i < n)
                        {
                            searchQueue.push(make_pair(curId.first+i, jumps + 1));
                        }
                    }
                    if (curId.first + nums[curId.first] >= n-1)
                    {
                        // This current ID can reach the end.
                        minJumps = min(jumps+1, minJumps);
                    }
                }
                else
                {
                    minJumps = min(jumps, minJumps);
                }
            }
        }
        return minJumps;
    }

int main()
{
    // vector<int> ex{{2,3,1,1,4}};
    // vector<int> ex{{2,3,0,1,4}};
    // vector<int> ex{{10,9,8,7,6,5,4,3,2,1,1,0}};
    // vector<int> ex{{1,1,1,1}};
    // vector<int> ex{{1,2,3}};
    // vector<int> ex{{1,2,1,1,1}};
    vector<int> ex{{1,2,3,4}};
    int val = jump(ex);
    cout<<val<<endl;
    return 0;
}