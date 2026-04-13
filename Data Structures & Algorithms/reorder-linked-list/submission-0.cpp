/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        ListNode* prev = nullptr;
        ListNode* curr = slow;
        
        while(curr != nullptr){
            ListNode* nextPtr = curr -> next;

            curr -> next = prev;
            prev = curr;
            curr = nextPtr;
        }

        while(head -> next != nullptr && prev -> next != nullptr){
            ListNode* headNext = head -> next;
            ListNode* prevNext = prev -> next;

            head -> next = prev;
            prev -> next = headNext;

            head = headNext;
            prev = prevNext;
        }


    }
};
