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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next == nullptr) return head;
        ListNode* curr = head;
        int len =1;
        while(curr!=nullptr && curr->next != nullptr){
            len++;
            curr=curr->next;
        }
        ListNode* head1 = head;
        ListNode* end = curr;
        k = k%len;
        for(int i=0;i<len-k;i++){
            ListNode* newhead = head1->next;
            end->next=head1;
            head1->next = nullptr;
            end=head1;
            head1=newhead;
        }


        return head1;
    }
};