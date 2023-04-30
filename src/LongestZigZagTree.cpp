#include <vector>
#include <unordered_map>

using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// Create this function maxZigZag(node, direction) maximum zigzag given a node and direction (right or left).
unordered_map<TreeNode*, pair<int,int>>dp;
//                              ^  ^
//                              |  |
//                              l  r
int maxZigZag(TreeNode* node, char direction)
{
    if (node == nullptr) return 0;
    if (dp.find(node) != dp.end())
    {
        if (direction == 'l') return dp[node].first;
        else return dp[node].second;
    }
    if (direction == 'r')
    {
        return dp[node].first = max(dp[node].first+1, maxZigZag(node->left, 'l'));
    }
    else
    {
        return dp[node].second = max(dp[node].second+1, maxZigZag(node->right, 'r'));;
    }
}
int longestZigZag(TreeNode* root) {
    maxZigZag(root, 'r');
    maxZigZag(root, 'l');
    return max(dp[root].first, dp[root].second);
}

int main()
{
    TreeNode* root = new TreeNode();
    root->right = new TreeNode();
}