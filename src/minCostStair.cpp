#include <vector>

using namespace std;

int recHelper(vector<int>& cost, vector<int>& dp, int step)
{
    if (dp[step] != 0) return dp[step];
    if (step < 2) return cost[step];
    return dp[step] = cost[step] + min(recHelper(cost, dp, step-1), recHelper(cost, dp, step-2));
}

int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n-1, 0);
    dp[0] = 0;
    // dp[1] = min(1, nums[0]);
    for (int i{0}; i < n; i++)
    {
        for (int j{i+1}; j < min(n, i+nums[i]+1); j++)
        {
            dp[j]+= 1;
        }
    }
    return 0;
}
int main()
{
    // vector<int>cost{{10,15,20}};
    // vector<int>cost{{1,100,1,1,1,100,1,1,100,1}};
    // vector<int> dp(cost.size(),0);
    // dp[0] = cost[0];
    // dp[1] = cost[1];
    // recHelper(cost, dp, cost.size()-1);
    
    
    vector<int> ex{{2,3,1,1,4}};
    jump(ex);
    return 0;
}