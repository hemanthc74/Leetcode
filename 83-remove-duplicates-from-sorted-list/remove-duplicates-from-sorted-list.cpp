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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr ) return nullptr ;
        ListNode * dummy = head ;
        while(dummy != nullptr  && dummy->next != nullptr){
            if(dummy->val == dummy->next->val){
                ListNode* nextdummy = dummy->next;
                while(nextdummy && dummy->val == nextdummy->val ){
                    ListNode* temp = nextdummy ;
                    nextdummy = nextdummy->next;
                    delete temp;
                }
                dummy->next = nextdummy;
            }

            dummy = dummy->next;
        }

        return head;
    }


};