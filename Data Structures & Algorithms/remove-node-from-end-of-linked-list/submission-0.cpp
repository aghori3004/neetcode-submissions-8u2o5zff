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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ahead = head;
        while(n > 0){
            ahead = ahead -> next;
            n--;
        }
        ListNode* prev = nullptr;
        ListNode* behind = head;

        if (ahead == nullptr) {
            return head -> next;
        }
        
        while(ahead != nullptr){
            ahead = ahead -> next;
            prev = behind;
            behind = behind -> next;

        }
        prev -> next = behind -> next;
        behind->next = nullptr;
        return head;
    }

    
};
