class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }

        
        vector<bool> toDelete(maxVal + 1, false);
        for (int num : nums) {
            toDelete[num] = true;
        }

        
        ListNode dummy(0);
        dummy.next = head;
        ListNode* temp = &dummy;

        while (temp->next != nullptr) {
            if (temp->next->val <= maxVal && toDelete[temp->next->val]) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        return dummy.next;
    }
};
