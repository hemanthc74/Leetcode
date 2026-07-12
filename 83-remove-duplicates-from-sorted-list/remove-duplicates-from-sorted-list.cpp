class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        
        while (curr && curr->next) {
            // If we find a duplicate, skip all identical nodes in one go
            if (curr->val == curr->next->val) {
                ListNode* nextDistinct = curr->next;
                
                // Fast-forward to find the next unique value
                while (nextDistinct && curr->val == nextDistinct->val) {
                    ListNode* temp = nextDistinct;
                    nextDistinct = nextDistinct->next;
                    delete temp; // Free memory instantly
                }
                
                curr->next = nextDistinct; // Link to the next unique node
            }
            
            curr = curr->next; // Always safe to move forward now
        }
        
        return head;
    }
};
