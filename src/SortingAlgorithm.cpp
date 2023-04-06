#include <vector>
#include <iostream>
#include <queue>

template <typename T> void merge(T in1[], int l, int m, int r)
{
    int n1{m - l + 1};
    int n2{r - m};

    T temp1[n1], temp2[n2];

    for(int i{0}; i < n1; i++)
    {
        temp1[i] = in1[l + i];
    }
    for(int i{0}; i < n2; i++)
    {
        temp2[i] = in1[m + 1 + i];
    }

    int idArr1{0}, idArr2{0}, idIn1{l};

    while (idArr1 < n1 && idArr2 < n2)
    {
        if (temp1[idArr1] <= temp2[idArr2])
        {
            in1[idIn1] = temp1[idArr1];
            idArr1++;
        }
        else
        {
            in1[idIn1] = temp2[idArr2];
            idArr2++;
        }
        idIn1++;
    }

    while (idArr1 < n1)
    {
        in1[idIn1] = temp1[idArr1];
        idArr1++;
        idIn1++;
    }
    while (idArr2 < n2)
    {
        in1[idIn1] = temp2[idArr2];
        idArr2++;
        idIn1++;
    }
}
template<typename T> void mergeSort(T input[], int n, int l, int r)
{
    if (l >= r) return;
    int m = l + (r - l)/2;
    mergeSort(input, n, l, m);
    mergeSort(input, n, m+1, r);
    merge(input, l, m, r);
}
template <typename T> void swap(T* val1, T* val2)
{
    T temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

template <typename T> void bubbleSort(T input[], int n)
{
    bool swapped{false};
    for (int i{0}; i < n-1; i++)
    {
        if (input[i] > input[i+1])
        {
            swap<T>(&input[i], &input[i+1]);
            swapped = true;
        }
    }
    if (swapped) bubbleSort(input, n);
    
}

template <typename T> void heapSort(T input[], int n)
{
    std::priority_queue<T> pq;
    for (int i {0}; i < n; i++)
    {
        pq.push(input[i]);
    }
    for (int i {n-1}; i > -1; i--)
    {
        input[i] = pq.top();
        pq.pop();
    }
}
    
int main()
{
    // char exp[] = {'a','j','f','b','z','l'};     // expected output is: a,b,f,j,l,z
    int exp[] =  {1,54,3,1,6,7,9,23,0};     // expected output is: 0,1,1,3,6,7,9,23,54
    int n = sizeof(exp) / sizeof(exp[0]);
    // mergeSort<int>(exp, n, 0, n-1);
    // bubbleSort<int>(exp, n);
    // heapSort<int>(exp,n);
    std::cout<<"DONE!\n";
    return 0;
}
