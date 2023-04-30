#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int maxW{0};
    string Word;
    bool exist(vector<vector<char>>& board, string word) {
        maxW = word.size()-1;
        Word = word;
        for (int i{0}; i < board.size(); i++)
        {
            for (int j{0}; j < board[i].size(); j++)
            {
                if (dfs(board,i,j,0)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board,int x, int y, int w)
    {
        if (w > maxW) return true;
        if (x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y] != Word[w]) return false;

        char letter = board[x][y];
        board[x][y] = '-';
        bool a1 = dfs(board, x-1, y, w+1);
        bool a2 = dfs(board, x+1, y, w+1);
        bool a3 = dfs(board, x, y-1, w+1);
        bool a4 = dfs(board, x, y+1, w+1);
        bool ans = a1 || a2 || a3 || a4;
        board[x][y] = letter;
        return ans;
    }
};

int main()
{
    vector<vector<char>> ex = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    Solution sol;
    sol.exist(ex, "ABCCED");
    return 0;
}