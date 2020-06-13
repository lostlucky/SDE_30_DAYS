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
    void deleteNode(ListNode* node) {
        while(1){
            swap(node -> val,node -> next -> val);
            if(!node -> next -> next){
                ListNode* temp = node -> next;
                node -> next = NULL;
                temp = NULL;
                delete temp;
                return;
            }
            node = node -> next;
        }
    }
};
