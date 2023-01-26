/**
 * @file LinkedLists.cpp
 * @author Mohammed Osama
 * @brief My attempt at understanding Linked Lists in cpp, 
 *        some resources are: https://www.geeksforgeeks.org/data-structures/linked-list/
 * @version 0.1
 * @date 2023-01-25
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void printList(ListNode* head)
    {
        while (head != nullptr)
        {
            std::cout<<head->val<<"\n";
            head = head->next;
        }
    }
    
    /**
     * @brief Pushes a new link to the beginning of the linked list, 
     * and updates the passed head pointer to point to the 
     * newly added link.
     * 
     * @param head pointer of the first link in the list
     * @param data what to populate the new link with
     */
    void push(ListNode* &head, int data)
    {
        // Have to pass by reference the old head 
        // to make sure you are overwriting and not locally changing stuff
        ListNode* newHead{new ListNode};
        newHead->next = head;
        newHead->val = data;
        head = newHead;
    }

    /**
     * @brief Pushes new node to where the user desires
     * 
     * @param head 
     * @param data 
     * @param pointOfInsertion 
     */
    void push(ListNode* head, int data, int pointOfInsertion)
    {
        ListNode* nodeFromList{new ListNode};
        nodeFromList->val = data;
        for (int i{0}; i<pointOfInsertion; i++)
        {
            head = head->next;
        }
        nodeFromList->next = head->next;
        head->next = nodeFromList;
    }

};

int main()
{
    Solution sol;

    // Creating a new linked list that contains three links
    ListNode* head{new ListNode};   // use the "new" keyword to generate a pointer to a memory address
    ListNode* second{new ListNode};
    ListNode* third{new ListNode};

    // Populate the first link with a value of 1 and have it point to the next ("second") link.
    head->val = 1;
    head->next = second;
    
    // Populate second and point to third
    second->val = 2;
    second->next = third;
    
    // Populate third and dont point to anything.
    third->val = 3;
    sol.printList(head);
    std::cout<<std::endl;

    // Test adding a new link to the beginning of the list
    sol.push(head, 0);
    sol.printList(head);
    std::cout<<std::endl;

    // Test pushing a number at a certain point
    sol.push(head, 22, 2);
    sol.printList(head);
    std::cout<<std::endl;

}