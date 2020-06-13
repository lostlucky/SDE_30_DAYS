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
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode *temp1 =  NULL, *temp2;
        while(1){
            temp2 = head -> next;
            head -> next = temp1;
            if(!temp2) break; 
            temp1 = head;
            head = temp2;
        }
        return head;
    }
};
