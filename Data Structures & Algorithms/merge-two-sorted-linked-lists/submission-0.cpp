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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. Create a dummy node to easily build the new list
        ListNode dummy; 
        ListNode* curr = &dummy;
        
        // 2. Weave the lists together by rewiring pointers
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                curr->next = list1;   // Point to the existing node in list1
                list1 = list1->next;  // Move list1 forward
            } else {
                curr->next = list2;   // Point to the existing node in list2
                list2 = list2->next;  // Move list2 forward
            }
            curr = curr->next;        // Move our merged list pointer forward
        }
        
        // 3. Attach any remaining leftovers from either list
        if (list1 != nullptr) {
            curr->next = list1;
        } else {
            curr->next = list2;
        }
        
        // 4. Return the head of the merged list (the node after our dummy)
        return dummy.next;
    }
};
