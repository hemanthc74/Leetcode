class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy; 
        
        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* curr1 = prev->next;
            ListNode* curr2 = prev->next->next;
            
            curr1->next = curr2->next; 
            curr2->next = curr1;       
            prev->next = curr2;        
            
            prev = curr1;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};
