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
    ListNode *detectCycle(ListNode *head) {
        if(!head or !head -> next) return NULL;
        ListNode* slow = head, *fast = head;
        int count = 0;
        while(fast and fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            count++;
            if(slow == fast){
                fast = head;
                while(fast != slow){
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
