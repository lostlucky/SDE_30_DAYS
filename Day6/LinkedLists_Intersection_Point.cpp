/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode *p1 = headA, *p2 = headB;
        
        if(!p1 or !p2) return NULL;
        
        while(p1 != p2){
            if(!p1 and !p2) return NULL;
            p1 = p1 == NULL ? headB : p1 -> next;
            p2 = p2 == NULL ? headA : p2 -> next;
        }
        
        return p1;
    }
};
