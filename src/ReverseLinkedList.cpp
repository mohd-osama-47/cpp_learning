#include <iostream>
#include <vector>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // ListNode* reverseList(ListNode* head) {
        
    //     std::vector<int> vals;
    //     while (head->next != nullptr)
    //     {
    //         vals.push_back(head->val);
    //         head = head->next;
    //     }

    //     ListNode* temp{new ListNode};
    //     temp->val = head->val;
    //     head = temp;
    //     while (vals.size() != 0)
    //     {
    //         int curVal = vals.back();
    //         vals.pop_back();

    //         ListNode* newNode{new ListNode};
    //         temp->next = newNode;
    //         newNode->val = curVal;
    //         temp = newNode;
    //     }
        
    //     return head;
    // }
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = nullptr;
        
        while (head != nullptr)
        {
            ListNode* nex = head->next;
            head->next = prev;
            prev = head;
            head = nex;
        }
        
        return prev;
    }
    void printList(ListNode* head)
    {
        while (head->next != nullptr)
        {
            std::cout<<head->val<<std::endl;
            head = head->next;
        }
        std::cout<<head->val<<"\n--\n";
    }
};

int main()
{
    Solution sol;
    int ex1[5]{1,2,3,4,5};
    int ex2[2]{1,2};
    
    // Populating list 1
    ListNode* list1{new ListNode};
    list1->val = ex1[0];
    ListNode* head{list1};
    for (int i{1} ; i < 5; i++)
    {
        ListNode* newNode{new ListNode};
        head->next = newNode;
        newNode->val = ex1[i];
        head = newNode;
    }
    head = nullptr;
    // printing list1 to check if linked list was created correctly
    sol.printList(list1);

    //* reverse list1 here!
    list1 = sol.reverseList(list1);
    sol.printList(list1);

    // Populating list 2
    ListNode* list2{new ListNode};
    list2->val = ex2[0];
    head = list2;
    for (int i{1} ; i < 2; i++)
    {
        ListNode* newNode{new ListNode};
        head->next = newNode;
        newNode->val = ex2[i];
        head = newNode;
    }
    // printing list2 to check if linked list was created correctly
    sol.printList(list2);

    //* reverse list2 here!
    list2 = sol.reverseList(list2);
    sol.printList(list2);
}