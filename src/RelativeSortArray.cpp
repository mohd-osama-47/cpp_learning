#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        if (arr1.size() < 2){
            return arr1;
        }
        unordered_map<int, int> arr1_map;
        for (int num : arr1)
        {
            arr1_map[num] += 1;
        }
        vector<int> revisit_vector, result;
        for (int num : arr2)
        {
            if (arr1_map.find(num) != arr1_map.end())
            {
                for (int i{0}; i < arr1_map[num]; i++)
                {
                    result.push_back(num);
                }
                arr1_map.erase(num);
            }
        }
        for (unordered_map<int,int>::iterator itr{arr1_map.begin()}; itr != arr1_map.end(); itr++)
        {
            for (int i{0}; i < itr->second; i++)
            {
                revisit_vector.push_back(itr->first);
            }
        }
        sort(revisit_vector.begin(), revisit_vector.end());
        result.insert(result.end(), revisit_vector.begin(), revisit_vector.end());
        return result;
    }
};