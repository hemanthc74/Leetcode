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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        if (!head || !head->next || !head->next->next) return {-1, -1};

        int mini = INT_MAX;
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int firstCritical = -1; 
        int prevCritical = -1;  
        int index = 1;          
        
        while (curr->next != nullptr) {
            ListNode* nextNode = curr->next;
            
            bool isMinima = (prev->val > curr->val && nextNode->val > curr->val);
            bool isMaxima = (prev->val < curr->val && nextNode->val < curr->val);

            if (isMinima || isMaxima) {
                if (firstCritical == -1) {
                   
                    firstCritical = index;
                } else {
                    
                    mini = min(mini, index - prevCritical);
                }
                
                prevCritical = index;
            }

            index++;
            prev = curr;
            curr = curr->next;
        }

        
        if (firstCritical == prevCritical) {
            return {-1, -1};
        }

        int maxi = prevCritical - firstCritical;

        return {mini, maxi};
    }
};
