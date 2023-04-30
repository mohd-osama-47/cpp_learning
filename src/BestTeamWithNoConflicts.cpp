#include <vector>    // for vector
#include <utility>   // for pair and make_pair
#include <functional>
#include <algorithm> // for sort and greater
#include <iostream>

class Solution {
public:
    int bestTeamScore(std::vector<int>& scores, std::vector<int>& ages) {
        std::vector<std::pair<int, int>> players(scores.size());
        // generate a vector of pairs for the player's age and their score
        for (int i{0}; i < scores.size(); i++)
        {
            players[i] = std::make_pair(ages[i], scores[i]);
        }

        // sort the vector of pairs based on the first value (age), in a ascending manner
        std::sort(players.begin(), players.end());

        std::vector<int> playerScores(scores.size(), 0);
        int score{0};

        for (int i{0}; i < scores.size(); i++)
        {
            playerScores[i] = players[i].second;
            for (int j{0}; j < i; j++)
            {
                if (players[j].second <= players[i].second)
                {
                    playerScores[i] = (playerScores[i] > (playerScores[j] + players[i].second))? playerScores[i] : (playerScores[j] + players[i].second);
                }
            }
            score = (score > playerScores[i])? score : playerScores[i];
        }
        return score;
    }
};

int main()
{
    // Solution sol;

    // // case 2
    // std::vector<int>ex{{319776,611683,835240,602298,430007,574,142444,858606,734364,896074}};
    // std::vector<int>ex_{{1,1,1,1,1,1,1,1,1,1}};
    // sol.bestTeamScore(ex, ex_);

    int temp{121};
    std::string xStr{""};

    if (temp < 0)
    {
        xStr.push_back('-');
        temp *= -1;
    }
    while (temp >= 1)
    {
        xStr.push_back(temp%10 + '0');
        temp /= 10;
    }
    std::string str1{xStr.begin(), xStr.end()};
    std::string str2{xStr.rbegin(), xStr.rend()};
    return str1 == str2;
}

