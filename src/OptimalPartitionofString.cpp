#include <iostream>
#include <vector>
#include <string>

using namespace std;

int partitionString(string s) {
    if (s.size() < 2) return 1;
    int start{0}, end{0}, count{0};
    vector<int> letters(26,0);
    letters[s[start]-'a']++;
    while (end < s.size())
    {
        // cout<<"START:"<<start<<",END:"<<end<<endl;
        letters[s[end]-'a']++;
        if (s[start] != s[end] && letters[s[end]-'a'] <= 1)
        {
            end++;
        }
        else
        {
            start = end;
            end++;
            count++;
            letters = vector<int>(26,0);
            letters[s[start]-'a']++;
        }
    }
    return count;
}

int main() 
{
    cout<<partitionString("cuieokbs");
    return 0;
}