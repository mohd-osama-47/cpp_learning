#include <vector>
#include <iostream>
using namespace std;

vector<int> addToArrayForm(vector<int>& num, int k) {
    vector<int> num2;
    int kCopy = k;
    while(kCopy > 0)
    {
        num2.push_back(kCopy%10);
        kCopy/=10;
    }
    num2 = vector<int>(num2.rbegin(), num2.rend());
    if (num.size() > num2.size())
    {
        int zerosToAdd = num.size() - num2.size();
        for (int i{0}; i < zerosToAdd; i++)
        {
            num2.insert(num2.begin(), 0);
        }
    }
    if (num.size() < num2.size())
    {
        int zerosToAdd = num2.size() - num.size();
        for (int i{0}; i < zerosToAdd; i++)
        {
            num.insert(num.begin(), 0);
        }
    }
    cout<<num.size()<<" "<<num2.size()<<endl;
    int sum{0}, carry{0};
    vector<int> res;
    for (int j = num.size()-1; j > -1; j--)
    {
        sum = num[j] + num2[j] + carry;
        if (sum == 10)
        {
            sum = 0;
            carry = 1;
        }
        else if (sum > 10)
        {
            sum -= 10;
            carry = 1;
        }
        else carry = 0;
        res.push_back(sum);
    }
    if (carry > 0) res.push_back(carry);
    return vector<int>(res.rbegin(), res.rend());
}

int main()
{
    vector<int> ex{{2,1,5}};
    addToArrayForm(ex, 806);
    return 0;
}