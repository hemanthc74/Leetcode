class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* temp = &dummy;

        unordered_set<int> hash;
        for(int i = 0; i < nums.size(); i++){
            hash.insert(nums[i]); 
        }

        while(temp->next != nullptr){
            if(hash.count(temp->next->val) > 0){
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        return dummy.next;
    }
};
