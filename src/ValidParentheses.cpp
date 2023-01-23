/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Constraints:
    1 <= s.length <= 104
    s consists of parentheses only '()[]{}'.
*/


#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <unordered_map>

class Solution {
public:
    bool isValid(std::string s) {
        // Check if its an odd-sized string, meaning braces are not closed properly.
        if (s.size() % 2 != 0){
            return false;
        }
        // Check if any open brace starts the string, thus return false directly!
        if (s[0] == ')' || s[0] == ']' || s[0] == '}'){
            return false;
        }
        std::vector<char> braces_order{{0}};
        std::unordered_map<char, char> braces_map;
        braces_map['('] = ')';  
        braces_map['['] = ']';
        braces_map['{'] = '}';
        for (int i{0}; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
                braces_order.push_back(s[i]);
            }

            if (s[i] == braces_map[braces_order.back()]){
                if (braces_order.size() == 0){
                    return true;
                }
                braces_order.pop_back();
                braces_order.at(0)++;
                // std::cout<<braces_order.size()<<"\n";
            }
        }
        if (braces_order.size() == 1 && braces_order.at(0) == s.size()/2){
            return true;
        }
        else {
            return false;
        }
    }
};


int main(){
    Solution sol;

    std::string ex1{{"()"}};
    std::string ex2{{"()[]{}"}};
    std::string ex3{{"(]"}};
    std::string ex4{{"{[]}"}};
    std::string ex5{{"(){}}{"}};
    std::string ex6{{"([}}])"}};
    std::string ex7;
    ex7 = {"dsds"};

    std::cout<<sol.isValid(ex1)<<"\n";      //return 1
    std::cout<<sol.isValid(ex2)<<"\n";      //return 1
    std::cout<<sol.isValid(ex3)<<"\n";      //return 0
    std::cout<<sol.isValid(ex4)<<"\n";      //return 1
    std::cout<<sol.isValid(ex5)<<"\n";      //return 0
    std::cout<<sol.isValid(ex6)<<"\n";      //return 0
}