class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        // Step 1: Interweave the copied nodes
        Node* curr = head;
        while (curr != nullptr){
            Node* ogNext = curr->next;
            Node* currNew = new Node(curr->val);
            
            curr->next = currNew;
            currNew->next = ogNext;
            
            curr = ogNext;
        }
        
        // Step 2: Assign random pointers
        curr = head;
        while (curr != nullptr ){
            if (curr->random != nullptr) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the lists and restore the original
        curr = head;
        Node* newHead = head->next;
        
        while (curr != nullptr) {
            Node* copy = curr->next;
            Node* ogNext = copy->next;
            
            curr->next = ogNext; // Restore original
            if (ogNext != nullptr) {
                copy->next = ogNext->next; // Link copies
            }
            
            curr = ogNext;
        }

        return newHead;
    }
};