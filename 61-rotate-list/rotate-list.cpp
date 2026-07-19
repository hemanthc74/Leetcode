class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode* curr = head;
        int len = 1;
        while(curr != nullptr && curr->next != nullptr){
            len++;
            curr = curr->next;
        }
        
        ListNode* head1 = head;
        ListNode* end = curr;
        k = k % len;
        
        for(int i = 0; i < k; i++){
            ListNode* prev = head1;
            while(prev->next != end) {
                prev = prev->next;
            }
            
            end->next = head1;
            head1 = end;
            
            prev->next = nullptr;
            
            end = prev;
        }

        return head1;
    }
};
