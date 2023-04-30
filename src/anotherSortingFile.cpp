#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums, int l, int m, int r)
    {
        vector<int> arr1;
        vector<int> arr2;
        for (int i{0}; i < m-l+1; i++)
        {
            arr1.push_back(nums[i+l]);
        }
        for (int i{0}; i < r-m; i++)
        {
            arr2.push_back(nums[i+m+1]);
        }
        // cout<<"ARRAY1:"<<arr1.size()<<",ARRAY2:"<<arr2.size()<<endl;
        int i = 0, j = 0, k = l;
        while (i < arr1.size() && j < arr2.size())
        {
            if (arr1[i] <= arr2[j])
            {
                nums[k] = arr1[i];
                i++;
            }
            else
            {
                nums[k] = arr2[j];
                j++;
            }
            k++;
        }
        while (i < arr1.size())
        {
            nums[k] = arr1[i];
            i++;
            k++;
        }
        while (j < arr2.size())
        {
            nums[k] = arr2[j];
            j++;
            k++;
        }

    }
    void mergeSort(vector<int>& nums, int start, int end)
    {
        if(start>=end) return;
        int m = start + (end-start)/2;
        mergeSort(nums,start, m);
        mergeSort(nums,m+1, end);
        merge(nums, start, m, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n =  nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};

int main()
{
    Solution sol = Solution();

    vector<int> ex = {5,2,3,1};
    sol.sortArray(ex);
    return 0;
}