/**
 * @file isSequenceTest.cpp
 * @author Mohammed Osama Elnour
 * @brief Checks two character arrays, pattern and test, to see if patter is a sub-sequence of test
 * @version 0.1
 * @date 2023-05-11
 * 
 * 
 */

#include <iostream>

bool isSequence(char* P, char* T)
{
    while (*T != '\0')
    {
        // while the test string is not at the end:
        if (*P == *T++ && *++P == '\0')
        {
            //The if condition will move the two test pointer up every iteration
            //and the pattern pointer will also move up until we reach the end
            return true;    // means the end of the pattern has been reached, so IT IS a valid subsequence!
        }
    }
    return false;
}

int main()
{
    char test[6] = {'h', 'e', 'l', 'l', 'i', '\0'};
    char pattern[3] = {'h', 'i', '\0'};
    bool res = isSequence(pattern, test);
    std::cout<<res;
    return 0;
}
