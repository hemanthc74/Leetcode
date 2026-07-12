class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        int lenA = 0, lenB = 0;
        ListNode* currA = headA;
        ListNode* currB = headB;
        
        while (currA) { lenA++; currA = currA->next; }
        while (currB) { lenB++; currB = currB->next; }
        
        currA = headA;
        currB = headB;
        

        if (lenA > lenB) {
            int diff = lenA - lenB;
            while (diff--) currA = currA->next;
        } else {
            int diff = lenB - lenA;
            while (diff--) currB = currB->next;
        }
        
        while (currA != currB) {
            currA = currA->next;
            currB = currB->next;
        }
        
        return currA;
    }
};
