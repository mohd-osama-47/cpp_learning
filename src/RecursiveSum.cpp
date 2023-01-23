#include <iostream>
#include <vector>
#include <chrono>


template <typename Type> int recurssiveTailSum(std::vector<Type> x, Type rollingSum = 0)
{
    if (x.size() == 1)
    {
        return x[0] + rollingSum;
    }
    else 
    {
        return recurssiveTailSum(std::vector<Type>(x.begin() + 1, x.end()), x[0]+rollingSum);
    }
}

template <typename Type> int recurssiveSum(std::vector<Type> x)
{
    if (x.size() == 1)
    {
        return x[0];
    }
    else 
    {
        return x[0] + recurssiveSum(std::vector<Type>(x.begin() + 1, x.end()));
    }
}


template <typename Type> int vectorLength(std::vector<Type> vec, int rollingLength = 0)
{
    if (vec.size() == 1 )
    {
        return 1 + rollingLength;
    }
    else 
    {
        return vectorLength(std::vector<Type>(vec.begin()+1, vec.end()), 1+rollingLength);
    }
}

template <typename Type> int vectorLength2(std::vector<Type> vec, int rollingLength = 0)
{
    if (vec.size() == 1 )
    {
        return 1 ;
    }
    else 
    {
        return vectorLength(std::vector<Type>(vec.begin()+1, vec.end())) + 1;
    }
}


template <typename Type> int findMax(std::vector<Type> input)
{
    int curMax{0};
    int in_length{vectorLength(input)};
    for (int i{0}; i < in_length; i++)
    {
        if (input[i] > input[curMax])
        {
            curMax = i;
        }
    }
    return curMax;
}

template <typename Type> Type recfindMax(std::vector<Type> input)
{
    if (input.size() == 1)
    {
        return input[0];
    }
    else
    {   
        Type rm{recfindMax(std::vector<Type>(input.begin()+1, input.end()))};
        return (input[0] > rm) ? input[0] : rm;
    }
}


template <typename Type> int findMin(std::vector<Type> input)
{
    int curMin{0};
    int in_length{vectorLength(input)};
    for (int i{0}; i < in_length; i++)
    {
        if (input[i] < input[curMin])
        {
            curMin = i;
        }
    }
    return curMin;
}

template <typename Type> void SelectionSort(std::vector<Type>& input)
{
    Type placeHolder{input[0]};
    int idToChange{0};
    int in_length{vectorLength<Type>(input)};
    for (int i{0}; i < in_length; i++)
    {
        idToChange = findMin<Type>(std::vector<Type>(input.begin()+i, input.end())) + i;
        placeHolder = input[i];
        input[i] = input[idToChange];
        input[idToChange] = placeHolder;
    }

}

template <typename T> int BinarySearch(std::vector<T> input, T target)
{
    if (input.size() == 1)
    {
        return (input[0] == target)? 0 : -1;
    }
    else
    {
        int start{0}, end = input.size()-1, mid{(end+start)/2};
        if (input[mid] == target)
        {
            return mid;
        }
        else if (input[mid] > target)
        {
            BinarySearch(std::vector<T>(input.begin()+start, input.begin()+mid-1), target);
        }
        else if (input[mid] < target)
        {
            BinarySearch(std::vector<T>(input.begin()+mid+1, input.begin()+end), target);
        }
    }
    return -1;

}

int main()
{
    // std::vector<int> ex{{1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,7,8,9}};
    // std::vector<int> ex{{9,8,7,6,5,4,13,2,1}};
    // std::vector<int> ex{{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17}};
    std::vector<int> ex{{1,2,3,4,5}};
    int result{0};
    std::cout<<BinarySearch<int>(ex, 6);
    // int maxVal{findMax<int>(ex)};
    // SelectionSort(ex);

    // for (int num : ex)
    // {
    //     std::cout<<num<<"\n";
    // }
    // std::cout<<"MAX INDEX IS: "<<maxVal<<", WHICH CONTAINS VALUE: "<<ex[maxVal]<<"\n";
    // auto start = std::chrono::high_resolution_clock::now();
    // result = recurssiveSum<int>(ex);
    // auto stop = std::chrono::high_resolution_clock::now();
    // std::cout<<result<<"\n";
    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    // std::cout<<"NON TAIL RECURSION TOOK : "<<duration.count()<<"\n";

    // start = std::chrono::high_resolution_clock::now();
    // result = recurssiveTailSum<int>(ex);
    // stop = std::chrono::high_resolution_clock::now();
    // std::cout<<result<<"\n";
    // duration = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    // std::cout<<"TAIL RECURSION TOOK : "<<duration.count()<<"\n";

    return 0;
}