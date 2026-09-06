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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minPQ;
        for(int i = 0; i < lists.size(); i++){
            ListNode* curr = lists[i];
            while(curr != nullptr){
                minPQ.push({curr->val, curr});
                curr = curr->next;
            }
        }

        ListNode dummy(0);
        ListNode* temp = &dummy;
        while(!minPQ.empty()){
            pair<int, ListNode*> mini = minPQ.top();
            minPQ.pop();
            temp->next = mini.second;
            temp = temp->next;
        }
        temp->next = nullptr;

        return dummy.next;
    }
};
