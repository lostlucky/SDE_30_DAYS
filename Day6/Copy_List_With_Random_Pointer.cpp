/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

Node* f(Node* head){
    if(!head) return NULL;
    Node* copy = new Node(head -> val);
    Node* nextNode = head -> next;
    head -> next = copy;
    copy -> next = f(nextNode);
    copy -> random = head -> random ? head -> random -> next : NULL;
    return head;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *head1 = new Node(0), *head2 = new Node(0), *nextNode = f(head);
        Node *t1 = head1, *t2 = head2;
        
        while(nextNode){
            t1 -> next = nextNode;
            t1 = t1 -> next;
            nextNode = nextNode -> next;
            t2 -> next = nextNode;
            t2 = t2 -> next;
            nextNode = nextNode -> next;
        }
        
        t1 -> next = NULL;
        t2 -> next = NULL;
        
        return head2 -> next;
    }
};
