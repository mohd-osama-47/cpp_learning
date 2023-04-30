#include <vector>
#include <string>

using namespace std;

class Trie {
public:
    bool wordEnd{false};
    vector<Trie*> children;
    Trie() {
        this->children = vector<Trie*>(26, nullptr);
    }
    
    void insert(string word) {
        Trie* temp = this;
        for (const char w : word)
        {
            if (temp->children[w - 'a'] == nullptr)
            {
                temp->children[w - 'a'] = new Trie();
            }
            temp = temp->children[w - 'a'];
        }
        temp->wordEnd = true;
    }
    
    bool search(string word) {
        Trie* temp = this;
        for (const char w : word)
        {
            if (temp->children[w - 'a'] == nullptr)
            {
                return false;
            }
            temp = temp->children[w - 'a'];
        }
        return temp->wordEnd;
    }

    bool startsWith(string prefix) {
        Trie* temp = this;
        for (const char w : prefix)
        {
            if (temp->children[w - 'a'] == nullptr)
            {
                return false;
            }
            temp = temp->children[w - 'a'];
        }
        return true;
    }
    bool startsWith(char prefix) {
        Trie* temp = this;
        if (temp->children[prefix - 'a'] == nullptr) return false;
        return true;
    }
};
class Solution {
public:
    bool checkNeighbours(vector<vector<char>>& board, string word, int x, int y, Trie* node)
    {
        if (node->wordEnd) return true;
        if (x<0 || x>=board.size() || y<0 || y>=board[0].size()) return false;

        char letter = board[x][y];
        if(node->startsWith(word[letter]))
        {
            board[x][y] = '-';
            bool checker = checkNeighbours(board, word.substr(1), x-1, y, node->children[word[0]-'a']) || checkNeighbours(board, word.substr(1), x+1, y, node->children[word[0]-'a']) || checkNeighbours(board, word.substr(1), x, y-1, node->children[word[0]-'a']) || checkNeighbours(board, word.substr(1), x, y+1, node->children[word[0]-'a']);
            board[x][y] = letter;
            return checker;
        }
        return false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* root = new Trie();
        for (string& word : words)
        {
            root->insert(word);
        }
        vector<string> res;
        for (int i{0}; i < board.size(); i++)
        {
            for (int j{0}; j < board[i].size(); j++)
            {
                for (string& word:words)
                {
                    bool ans = checkNeighbours(board, word, i, j, root);
                    if (ans) res.push_back(word);
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<char>> ex{{{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}}};
    vector<string> exCont{{"oath","pea","eat","rain"}};
    
    Solution sol;
    sol.findWords(ex, exCont);

    return 0;
}